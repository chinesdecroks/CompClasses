#ifndef _MATRIZ_H
#define _MATRIZ_H

int** cria_matriz(int tam);
void libera_matriz(int** m, int tam);
void imprime_matriz(int** m, int tam);
int** le_matriz(int** m, int tam);
int** transposta(int **m, int tam);

#endif
