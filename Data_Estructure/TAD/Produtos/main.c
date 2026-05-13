#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

int main(void)
{
    int n;

    printf("Insira quantos produtos deseja na sua lista: ");
    scanf("%d", &n);

    Produtos* p = cria_lista(n);

    insere_lista(p, n);
    listar_produtos(p, n);

    printf("O produto mais barato da lista eh:\n");
    imprime_produto(p[busca_barato(p, n)]);

    libera_lista(p);
}