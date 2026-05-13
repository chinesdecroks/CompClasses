#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

Produtos* cria_lista(int tam)
{
    Produtos* p = (Produtos*) malloc(tam*sizeof(Produtos)); 

    return p;
}

void criar_produto(Produtos* p, int tam)
{
    int a = 1, n;
    char c; 

    while (a)
    {
        printf("Deseja adicionar mais um produto na lista(S/N): ");
        scanf("%c", &c);

        if (c == 'S' || c == 's')
        {
            p = (Produtos*)realloc(p, (tam+n)*sizeof(Produtos));

            for (int i = tam; i < tam+n; i++)
            {
                p[i] = insere_produto();
            }

        } else if (c == 'N' || c == 'n')
        {
            a = 0;
        } else
        {
            printf("Opcao invalida!\nTente novamenta!\n");
        }
        
    }
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

void insere_lista(Produtos* p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        p[i] = insere_produto();
        printf("\n");
    }

}

void imprime_produto(Produtos p)
{
    printf("Cod. : %03d\nNome: %s\nQuantidade no Estoque: %d\nValor: R$ %.2f\n", p.codProd, p.nomeProd, p.qtdeEstoque, p.valor);
}

void listar_produtos(Produtos* p, int tam)
{
    printf("----------- Lista de Produtos -----------\n");

    for (int i = 0; i < tam; i++)
    {
        imprime_produto(p[i]);
    }

    printf("\n------------ Fim dos Produtos ------------\n");

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
