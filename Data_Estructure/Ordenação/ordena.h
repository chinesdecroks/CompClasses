#ifndef _ORDENA_H_
#define _ORDENA_H_

int show(int* v, int l);
int* randVector(int tam, int vlrmax);
void troca(int* a, int* b);

int paticinate(int* v, int i, int f);
void quickSort(int* v, int i, int f);

void merge(int* v, int inicio, int meio, int fim);
void mergeSort(int* v, int inicio, int fim);



#endif