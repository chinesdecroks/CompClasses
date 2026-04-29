#include <stdio.h>
#include <stdlib.h>

int trocas = -1;

int paticinate(int* v, int i, int f);
void troca(int* a, int* b);
void quickSort(int* v, int i, int f);
int show(int* v, int l);


int main(void)
{
    int t = 6;
    int v[] = {34, 7, 23, 32, 5, 62};
    show(v, t);
    quickSort(v, 0, t-1);
    show(v, t);
}

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
