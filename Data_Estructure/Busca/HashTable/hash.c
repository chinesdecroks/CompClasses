#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

struct aluno
{
    char nome[20];
    int matricula;
    float n1, n2, n3;
};

//Para construir a tabela hash é necessário do seu tamanho total(TABLE_SIZE)
//da quantidade de itens que possui e 
//da array em si de itens dado por uma array de ponteiros para aluno, oui seja,
// a array vai armazenar os endereços dos Alunos e não os itens em si
typedef struct hash
{
    int qnt, TABLE_SIZE;
    Aluno **itens;
} Hash;

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
    }
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