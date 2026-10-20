#ifndef HASH_H
#define HASH_H

struct aluno
{
    char nome;
    int matricula;
    float n1, n2, n3;
};

typedef struct aluno Aluno;
typedef struct hash Hash;

Hash* criaHash(int size);
void liberaHash(Hash* hashTable);

int chaveDivisao(int chave, int hashSize);
int hashingUniversal(int a, int b, int p, int chave, int tableSize);

int sondagemLinear(int pos, int i, int tableSize);
int sondagemQuadratica(int pos, int i, int tableSize);
int duploHash(int H1, int chave, int i, int tableSize);

int insereHash_EncSep(Hash* hashTable,  Aluno al);
int buscaHash_EncSep(Hash* hashTable, Aluno* al, int matricula);

void mostraHashMatricula(Hash* hashTable);

#endif