#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


//Para construir a tabela hash é necessário do seu tamanho total(TABLE_SIZE)
//da quantidade de itens que possui e 
//da array em si de itens dado por uma array de ponteiros para aluno, oui seja,
// a array vai armazenar os endereços dos Alunos e não os itens em si

//Para evitar um número de colisões na tabela hash, utiliza-se números primos e evita 
//potências de 2 no tamanho.

typedef struct no
{
    Aluno al;
    struct no* prox;
} No;

struct hash
{
    int qnt, TABLE_SIZE;
    No** lista;
};

//cria a tabela hash
Hash* criaHash(int size)
{
    Hash* hashTable = (Hash*)malloc(sizeof(Hash));

    if (hashTable != NULL)
    {
        hashTable->qnt = 0;
        hashTable->TABLE_SIZE = size;

        hashTable->lista = (No**)malloc(size*sizeof(No*));
        if (hashTable->lista == NULL)
        {
            free(hashTable);
            return NULL;
        }
        for (int i = 0; i < size; i++)
            hashTable->lista[i] = NULL;

        return hashTable;
    }

    return NULL;
}

void liberaHash(Hash* hashTable)
{
    if (hashTable != NULL)
    {
        for (int i = 0; i < hashTable->TABLE_SIZE; i++)
            if (hashTable->lista[i] != NULL)
                free(hashTable->lista[i]);

        free(hashTable->lista);
        free(hashTable);

    }
}

//O tamanho da tabela hash melhor ser numero primo p/ evitar colisões
int chaveDivisao(int chave, int hashSize)
{
    return (chave & 0x7FFFFFFF) % hashSize;
}

int hashingUniversal(int a, int b, int p, int chave, int tableSize)
{
    return  ((a*chave + b) % p) % tableSize;
}

//Broxa quer dizer que em caso de colisão não há tratamento
/*int insereHash_Broxa(Hash* hashTable,  Aluno al)
{
    if (hashTable == NULL || hashTable->qnt == hashTable->TABLE_SIZE)
        return 0;
    
    int chave = al.matricula;
    int pos = chaveDivisao(chave, hashTable->TABLE_SIZE);

    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo == NULL)
        return 0;

    *novo = al;
    hashTable->itens[pos] = novo;
    hashTable->qnt++;
    return 1;
    
}*/

/*int buscaHash_Broxa(Hash* hashTable, Aluno* al, int matricula)
{
    if (hashTable == NULL)
        return 0;
        
    int pos = chaveDivisao(matricula, hashTable->TABLE_SIZE);
    if (hashTable->itens[pos] == NULL)
        return 0;
    
    *al = *(hashTable->itens[pos]);
    return 1;
}*/

//No endereçamento de sondagem linear apenas se intera a pos para o próximo local livre na tabela
int sondagemLinear(int pos, int i, int tableSize)
{
    return  ((pos + i) & (0x7FFFFFFF)) % tableSize;
}

//No endereçameto de sondagem quadrática utiliza-se uma expressão quadrática para definir o endereçamento caso haja conflito
int sondagemQuadratica(int pos, int i, int tableSize)
{
    pos += 3*i + 2*i*i;
    return (pos & 0x7FFFFFFF) % tableSize;
}

//No endereçamento duplo hash utiliza de duas funções de hashing para definir o novo endereçamento caso haja colisão
int duploHash(int H1, int chave, int i, int tableSize)
{
    int H2 = chaveDivisao(chave, tableSize-14) + 1;
    return ((H1 + i*H2) & 0x7fffffff) % tableSize;
}

//As colisões entram em listas encadeadas
int insereHash_EncSep(Hash* hashTable,  Aluno al)
{
    if (hashTable == NULL)
        return 0;
    
    int chave = al.nome;
    int pos = chaveDivisao(chave, hashTable->TABLE_SIZE);
    //int pos = hashingUniversal(2, 5, 101, chave, hashTable->TABLE_SIZE);

    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL)
        return 0;
        
    novo->al = al;

    novo->prox = hashTable->lista[pos];

    hashTable->lista[pos] = novo;

    hashTable->qnt++;
    return 1;
    
}

int buscaHash_EncSep(Hash* hashTable, Aluno* al, int matricula)
{
    if (hashTable == NULL)
        return 0;
        
    int pos = chaveDivisao(matricula, hashTable->TABLE_SIZE);
    //int pos = hashingUniversal(2, 5, 101, matricula, hashTable->TABLE_SIZE);
    No* atual = hashTable->lista[pos];

    while (atual != NULL && atual->al.matricula != matricula)
        atual = atual->prox;

    if (atual == NULL)
        return 0;

    *al = (atual->al);
    return 1;
    
}

void mostraHashMatricula(Hash* hashTable)
{
    printf("---------------------------------------\n");
    printf("|             Tabela Hash             |\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < hashTable->TABLE_SIZE; i++)
    {
        printf("|  %2d  |", i);

        No* atual = hashTable->lista[i];

        while (atual != NULL)
        {
            printf("  %c  ->", atual->al.nome);
            atual = atual->prox;
        }

        printf("  NULL  |\n");

    }
}