#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

void inicializa_lista(Lista* l)
{
    l->dados = NULL;
    l->indice = 0;
}

Produtos* cria_lista(int tam)
{
    Produtos* p = (Produtos*) malloc(tam*sizeof(Produtos)); 

    return p;
}

Produtos* criar_produto(Produtos* p, int* tam)
{
    int a = 1, n, temp = *tam;
    char c; 

    if (p)
    {
        while (a)
        {
            printf("Deseja adicionar mais um produto na lista(S/N): ");
            scanf("%c", &c);

            if (c == 'S' || c == 's')
            {
                printf("Quantos produtos a mais deseja adicionar: ");
                scanf("%d", &n);

                *tam = *tam + n;

                p = (Produtos*)realloc(p, (*tam)*sizeof(Produtos));

                for (int i = temp; i < *tam; i++)
                    p[i] = insere_produto();
                

                return p;

            } else if (c == 'N' || c == 'n')
            {
                a = 0;
            } else
            {
                printf("Opcao invalida!\nTente novamenta!\n");
            }
            
        }
    } else 
    {
        printf("Não eh possivel adicionar produto antes de criar lista\n");
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
    getchar();

    return p;

}

void insere_lista(Produtos* p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        p[i] = insere_produto();
        
    }

}

void imprime_produto(Produtos p)
{
    printf("Cod. : %03d\nNome: %s\nQuantidade no Estoque: %d\nValor: R$ %.2f\n", p.codProd, p.nomeProd, p.qtdeEstoque, p.valor);
}

void listar_produtos(Produtos* p, int tam)
{
    if (p)
    {
    printf("\n----------- Lista de Produtos -----------\n");

    for (int i = 0; i < tam; i++)
    {
        imprime_produto(p[i]);
        printf("\n");
    }

    printf("\n------------ Fim dos Produtos ------------\n\n");
    } else 
    {
        printf("\n\nLista vazia\n\n");
    }
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

void venda(Lista* l)
{
    char nome[10];
    int qntdd;

    if (l->dados)
    {
        listar_produtos(l->dados, l->indice);

        printf("Digite o nome do produto que deseja comprar: ");
        scanf("%[^\n]", nome);

        for (int i = 0; i < l -> indice; i++)
        {
            if (!strcmp(l->dados[i].nomeProd, nome))
            {
                printf("Digite quantos unidades do produto deseja levar: ");
                scanf("%d", &qntdd);

                if ((l->dados[i].qtdeEstoque - qntdd) >= 0)
                {
                    l->dados[i].qtdeEstoque -= qntdd;
                    printf("Venda efetuada com sucesso!\n");

                } else
                {
                    printf("Estoque insuficiente para a demanda!\n");
                }

                break;
            }
        }
    } else
    {
        printf("Crie a lista para poder realizar a compra de produtos.\n");
    }
}
