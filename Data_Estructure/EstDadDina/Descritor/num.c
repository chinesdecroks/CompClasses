#include <stdio.h>
#include <stdlib.h>
#include "num.h"

typedef struct no
{
    int n;
    struct no* prox;
} No;

struct descritor
{
    No* inicio;
    No* fim;
    int tam;
};

void inicializarLista(Descritor *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

Descritor* criar_lista()
{
    Descritor* l = (Descritor*)malloc(sizeof(Descritor));
    return l;

}

int adicionarNoInicio(Descritor *lista, int valor)
{
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL)
    {
        return 0;
    }
    novo->n = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;

    if (lista->fim == NULL)
        lista->fim = novo;

    lista->tam++;

    return 1;
}

int adicionarNoFinal(Descritor *lista, int valor)
{
    No* novo = (No*)malloc(sizeof(No));

    if (novo == NULL)
        return 0;

    novo->n = valor;

    if (lista->fim == NULL)
    {
        novo->prox = lista->fim;
        lista->fim = novo;
        lista->inicio = novo;
    } else
    {
        novo->prox = lista->fim->prox;
        lista->fim = novo;
    }

    lista->tam++;

    return 1;


}

void removerDoInicio(Descritor *lista)
{
    No* aux;

    if (lista->tam > 0)
    {
        if (lista->tam = 1)
        {
            aux = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            free(aux);
        } else
        {
            aux = lista->inicio;
            lista->inicio = lista->inicio->prox;
            free(aux);
        }

        lista->tam--;
    } else
    {
        printf("\nA lista esta vazia\n");
    }

}

void removerDoFinal(Descritor *lista)
{
    No *atual = lista->inicio, *ant = NULL;

    if (lista->tam > 0)
    {
        if(lista->tam == 1)
        {
            lista->inicio = NULL;
            lista->fim = NULL;
            free(atual);
        } else
        {
            while (atual->prox != NULL)
            {
                ant = atual;
                atual = atual->prox;

            }

            ant->prox = atual->prox;
            lista->fim = ant;
            free(atual);
        }

        lista->tam--;
    } else
    {
        printf("\nA lista esta vazia\n");
    }
}
//void removerElemento(Descritor *lista, int elemento);

void exibirLista(Descritor *lista)
{
    No* temp = lista->inicio;
        printf("\n---------------Lista------------------\n");
            if (lista->tam > 0)
            {
                while (temp != NULL)
                {
                   printf("\n%d\n\n", temp->n);
                   temp = temp->prox;
                }
            } else
            {
                printf("\nLista Vazia\n");
            }
        printf("\n---------------Fim--------------------\n");

}





