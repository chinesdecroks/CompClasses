#ifndef _MATRIZ_H
#define _MATRIZ_H

int** cria_matriz(int tam);
void libera_matriz(int** m, int tam);
void imprime_matriz(int** m, int tam);
int** le_matriz(int** m, int tam);
int** transposta(int **m, int tam);
int matriz_soma(int** m, int tam);
int somaDiag_p(int** m, int tam);
int somaDiag_s(int** m, int tam);
int eh_simetrica(int** m, int** t, int tam);
int soma_linha(int** m, int tam, int l);
int soma_coluna(int** m, int tam, int c);



#endif
