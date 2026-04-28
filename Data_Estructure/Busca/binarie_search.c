#include <stdio.h>

int pesquisa_binaria(int* vetor, int tamanho, int chave); 

int main(void)
{
    int key, len;

    scanf("%d %d", &key, &len);

    int v[len];

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &v[i]);
    }

    int parameter = pesquisa_binaria(v, len, key);

    printf("%d\n", parameter);

}

int pesquisa_binaria(int* vetor, int tamanho, int chave)
{
    int min = 0;
    int max = tamanho-1;
    int meio;

    while (min <= max)
    {
        meio = (max+min) / 2;

        if (chave == vetor[meio])
        {
            return meio;
        } else if (chave > vetor[meio])
        {
            min = meio+1;
        } else if (chave < vetor[meio])
        {
            max = meio - 1;
        } 
        
    }

    return -1;
} 