#include <stdio.h>


int soma(int *vet, int n);

int main(void)
{
    int qnt;
    scanf("%d", &qnt);

    int v[qnt];

    for (int i = 0; i < qnt; i++)
    {
        scanf("%d", &v[i]);
    }

    int sum = soma(v, qnt);

    printf("%d\n", sum);

}

int soma(int *vet, int n)
{
    int soma = 0;

    for (int i = 0; i < n; i++)
    {
        soma += *vet;
        vet++;
    }

    return soma;
}