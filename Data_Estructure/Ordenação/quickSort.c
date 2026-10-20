#include <stdio.h>
#include <stdlib.h>
#include "ordena.h"

int trocas = -1;

void troca(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b= temp;
}

int paticinate(int* v, int i, int f)
{
    int pivo = (v[i] + v[f] + v[(f+i)/2])/3;
    
    while (i < f)
    {
        while (i < f && v[i] <= pivo)
            i++;
        while (i < f && v[f] > pivo)
            f--;

        troca(&v[i], &v[f]);
        trocas++;
    }

    return i;
}

void quickSort(int* v, int i, int f)
{
    if (i < f)
    {
        int pos = paticinate(v, i, f);
        quickSort(v, i, pos - 1);
        quickSort(v, pos, f);
    }
}

int show(int* v, int l)
{
    for (int i = 0; i < l; i++)
        printf("%d%c", v[i], (i == l - 1) ? '\n' : ' ');

}
