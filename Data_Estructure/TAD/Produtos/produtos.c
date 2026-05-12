#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

Produtos* cria_lista(int tam)
{
    Produtos* p = (Produtos*) malloc(tam*sizeof(Produtos)); 

    return p;
}

void libera_lista(Produtos* p)
{
    free(p);
}

Produtos insere_produto()
{
    Produtos p;

    printf("Insira o código do produto: ");
    scanf("%d", &p.codProd);
    getchar();

    printf("Insira o nome do produto: ");
    scanf("%[^\n]", p.nomeProd);

    printf("Insira o quantidade no estoque desse produto: ");
    scanf("%d", &p.qtdeEstoque);
    getchar();

    printf("Insira o valor do produto: ");
    scanf("%f", &p.valor);

    return p;

}

void imprime_produto(Produtos p)
{
    printf("Cod. : %03d\nNome: %s\nQuantidade no Estoque: %d\nValor: R$ %.2f\n", p.codProd, p.nomeProd, p.qtdeEstoque, p.valor);
}

int busca_barato(Produtos* p, int tam)
{
    int m;

    for (int i = 0; i < tam; i++)
    {
        if (tam == 1)
        {
            m = i;
            break;
        }
        else if (i == 0 && p[i].valor <= p[i+1].valor)
        {
            m = i; 
            i++;
        } else if (i == 0 && p[i].valor > p[i+1].valor)
        {
            m = i+1;
            i++;
        } else if (p[i].valor < p[m].valor)
        {
            m = i;
        }
    }

    return m;
} 
