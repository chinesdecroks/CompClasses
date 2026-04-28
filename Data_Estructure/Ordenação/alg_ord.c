#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particiona(int *v, int inicio, int fim);
void quick_sort(int *v, int inicio, int fim);
void troca(int *a, int *b);
void imprime (int *v, int t);


int main(void)
{
    int t = 50;
    int vetor[] = {
    42, 7, 19, 3, 88, 25, 1, 67, 14, 50,
    99, 23, 76, 5, 31, 60, 2, 81, 44, 90,
    12, 38, 55, 6, 72, 27, 84, 9, 33, 100,
    15, 48, 63, 21, 87, 4, 70, 29, 53, 11,
    95, 36, 62, 18, 79, 8, 41, 66, 24, 58
    };
    imprime(vetor, t);

    clock_t start = clock();
    quick_sort(vetor, 0, t-1);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Tempo: %f segundos\n", time_spent);
    imprime(vetor, t);


}

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void imprime (int *v, int t)
{
    for(int i = 0; i < t; i++)
        printf("%d%c", v[i], (i == t-1) ? '\n' : ' ');
}


int particiona(int *v, int inicio, int fim)
{
    //o pivô vai ser a média do elemento do inicio + o do fim + o do meio
    //A partir dele que se realizará as comparações
    // da  esquerda para direita vai buscar elementos maiores que o pivô
    //da direita para a esquerda elememtos menores que o pivô
    //permitindo a troca desses elementos até a formação de dois subvetores 
    //um com elementos menores que o pivô e o outro com elementos maiores que o pivô
    // a função faz isso até inicio == fim, ou seja, vetor se encontrará particionado
    // com elementos maiores a direita que o elemento apontado pela posição inicio e fim
    //e menores a esquerda

    int pivo = (v[inicio] +v[fim] + v[(inicio+fim)/2]) / 3;

    while (inicio < fim)
    {
        while (inicio < fim)
        {
            while (inicio < fim && v[inicio] <= pivo)
                inicio++;
            
            while (inicio < fim && v[fim] > pivo)
                fim--;

            troca(&v[inicio], &v[fim]);
        }
    }
    
    return inicio;

}

void quick_sort(int *v, int inicio, int fim)
{
    if (inicio < fim)
    {
        int posicao = particiona(v, inicio, fim);
        quick_sort(v, inicio, posicao - 1);
        quick_sort(v, posicao, fim);
    }
}