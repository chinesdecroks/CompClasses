#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


//Para construir a tabela hash é necessário do seu tamanho total(TABLE_SIZE)
//da quantidade de itens que possui e 
//da array em si de itens dado por uma array de ponteiros para aluno, oui seja,
// a array vai armazenar os endereços dos Alunos e não os itens em si

//Para evitar um número de colisões na tabela hash, utiliza-se números primos e evita 
//potências de 2 no tamanho.
struct hash
{
    int qnt, TABLE_SIZE;
    Aluno **itens;
};

//cria a tabela hash
Hash* criaHash(int size)
{
    Hash* hashTable = (Hash*)malloc(sizeof(Hash));

    if (hashTable != NULL)
    {
        hashTable->qnt = 0;
        hashTable->TABLE_SIZE = size;

        hashTable->itens = (Aluno**)malloc(size*sizeof(Aluno*));
        if (hashTable->itens == NULL)
        {
            free(hashTable);
            return NULL;
        }
        for (int i = 0; i < size; i++)
            hashTable->itens[i] = NULL;

        return hashTable;
    }

    return NULL;
}

void liberaHash(Hash* hashTable)
{
    if (hashTable != NULL)
    {
        for (int i = 0; i < hashTable->TABLE_SIZE; i++)
            if (hashTable->itens[i] != NULL)
                free(hashTable->itens[i]);

        free(hashTable->itens);
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
int sondagemQuadratica(int a, int b, int pos, int i, int tableSize)
{
    pos += a*i + b*i*i;
    return (pos & 0x7FFFFFFF) % tableSize;
}

//No endereçamento duplo hash utiliza de duas funções de hashing para definir o novo endereçamento caso haja colisão
int duploHash(int H1, int chave, int i, int tableSize)
{
    int H2 = -chaveDivisao(chave, 7) + 7;
    return ((H1 + i*H2) & 0x7fffffff) % tableSize;
}

//Sigma trata o numero de colisões
int insereHash_Sigma(Hash* hashTable,  Aluno al)
{
    if (hashTable == NULL || hashTable->qnt == hashTable->TABLE_SIZE)
        return 0;
    
    int chave = al.nome;
    int pos = chaveDivisao(chave, hashTable->TABLE_SIZE);
    //int pos = hashingUniversal(2, 5, 101, chave, hashTable->TABLE_SIZE);
    int newPos;

    for (int i = 0; i < hashTable->TABLE_SIZE; i++)
    {
        newPos = sondagemLinear( pos, i, hashTable->TABLE_SIZE);
        if (hashTable->itens[newPos] == NULL)
        {
            Aluno* novo = (Aluno*)malloc(sizeof(Aluno));

            if(novo == NULL)
                return 0;
            
            *novo = al;
            hashTable->itens[newPos] = novo;
            hashTable->qnt++;
            return 1;
        }
    }

    return 0;
    
}

int buscaHash_Sigma(Hash* hashTable, Aluno* al, int matricula)
{
    if (hashTable == NULL)
        return 0;
        
    int pos = chaveDivisao(matricula, hashTable->TABLE_SIZE);
    //int pos = hashingUniversal(2, 5, 101, matricula, hashTable->TABLE_SIZE);
    int newPos;

    if (hashTable->itens[pos] == NULL)
        return 0;
    
    for (int i = 0; i < hashTable->TABLE_SIZE; i++)
    {
        newPos = sondagemLinear(pos, i, hashTable->TABLE_SIZE);
        if (hashTable->itens[newPos]->matricula == matricula)
        {
            *al = *(hashTable->itens[newPos]);
            return 1;
        }
    }

    return 0;
}

void mostraHashMatricula(Hash* hashTable)
{
    printf("---------------------------------------\n");
    printf("|             Tabela Hash             |\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < hashTable->TABLE_SIZE; i++)
    {
        printf("|%2d  |", i);
        if (hashTable->itens[i] == NULL)
            printf("  NULL  |\n");
        else
            printf("  %c  |\n", hashTable->itens[i]->nome);
    }
}