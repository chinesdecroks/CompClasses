#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"


void troca(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printVetorInt (int *v, int tam)
{
    for (int i = 0; i < tam; i++)
        printf("%d%s", v[i], (i == tam-1) ? "\n" : ", ");
}

void bubbleSort(int *v, int tam)
{
    int swap, n = 0;

    while(1)
    {
        swap = 0;

        for (int i = 0; i < tam - n - 1; i++)
            if (v[i] > v[i+1])
            {
                troca(&v[i], &v[i + 1]);
                swap = 1;
            }

        if (!swap)
            break;
        else
            n++;
    }
}

void vetoresRand(int *v, int tam, int intervalo)
{
    srand(time(NULL));

    for (int i = 0; i < tam; i++)
        v[i] = rand() % intervalo;
}