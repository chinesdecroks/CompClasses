#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

int main(void)
{
    int n;

    printf("Insira quantos produtos deseja na sua lista: ");
    scanf("%d", &n);

    Produtos* p = cria_lista(n);

    for (int i = 0; i < n; i++)
    {
        p[i] = insere_produto();
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        imprime_produto(p[i]);
        printf("\n");
    }


    printf("O produto mais barato da lista eh:\n");
    imprime_produto(p[busca_barato(p, n)]);

    libera_lista(p);
}