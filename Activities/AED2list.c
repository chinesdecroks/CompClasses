#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


/*1) Um dos principais problemas é a busca de dados (podendo esses serem maiore sou menores)
para que a busca de conjuntos muitos grandes se efetue de forma rápida e
eficiente é necessário que os dados estejam ordenados*/

/*2) Escreva um algoritmo que receba valores em um vetor e imprima
ORDENADO se o vetor estiver em ordem crescente.*/
char* estaOrdenado(int *v, int tam)
{
    for (int i = 0; i < tam - 1; i++)
        if (v[i] > v[i+1])
            return "DESORDENADO";

    return "ORDENADO";
}

/*3. Escreva um algoritmo que ordene de maneira decrescente (do maior para o
menor).*/
void bubbleSortDecres(int *v, int tam)
{
    int swap, n = 0;

    while(1)
    {
        swap = 0;

        for (int i = 0; i < tam - n - 1; i++)
            if (v[i] < v[i+1])
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

/*4) Escreva um algoritmo que receba um vetor ordenado e um número extra e
insira esse número na sua posição correta no vetor ordenado, deslocando
os outros números se necessário. */

int* insereOrd(int *v, int *tam, int elem)
{
    if (!strcmp(estaOrdenado(v, *tam), "DESORDENADO"))
        bubbleSort(v, *tam);

    *tam += 1;
    v = realloc(v, (*tam) * sizeof(int));

    for (int i = 0; i < *tam; i++)
    {
        if (i == *tam - 1)
        {
            v[i] = elem;
        } else if (elem < v[i])
        {
            int temp = v[i];
            v[i] = elem;
            elem = temp;
        }
    }

    return v;
}

/*5) Escreva um algoritmo que procure por um dado número em vetor ordenado.*/
int buscaBinaria(int *v, int i, int f, int elem)
{
    int pos = (i+f)/2;

    if (v[pos] == elem)
        return pos;
    else if (i < f)
    {
        if (elem < v[pos])
            return buscaBinaria(v, i, pos, elem);
        else
            return buscaBinaria(v, pos+1, f, elem);
    }

    return -1;
}

/*6. Escreva o vetor resultante ao aplicar o algoritmo de particionamento em
duas partes no vetor seguinte: 26 65 45 73 10 18 78 93 70 49 23 22 . Mostre o
passo a passo do algoritmo de partição.*/

int particiona(int* v, int i, int f)
{
    int pivo = (v[i] + v[f] + v[(f+i)/2])/3;
    
    int tam = f+1;

    while (i < f)
    {
        while (i < f && v[i] <= pivo)
            i++;
        while (i < f && v[f] > pivo)
            f--;
        troca(&v[i], &v[f]);
        
        printVetorInt(v, tam);
    }

        printVetorInt(v, tam);

    return i;
}


int main(void)
{
    int tam = 5, tam1 = 5, indice;
    int *v = (int*)malloc(tam*sizeof(int));
    int a[12] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};

    particiona(a, 0, 11);

}