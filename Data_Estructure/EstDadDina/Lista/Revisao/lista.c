#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no
{
    int num;
    struct no* prox;
} No;

struct descritor
{
    int tam;
    No* inicio;
    No* fim;
};

void inicializarLista (Descritor* l)
{
    l->tam = 0;
    l->inicio = NULL;
    l->fim = NULL;
}

Descritor* criar_lista()
{
    Descritor* l = (Descritor*)malloc(sizeof(Descritor));
    inicializarLista(l);

    return l;
}

int inserirNoInicio (Descritor* l, int valor)
{
    No* novo = (No*)malloc(sizeof(No));
    
    if (novo == NULL)
        return 0;
        
    novo->num = valor;
    novo->prox = l->inicio;

    if (l->inicio == NULL)
        l->fim = novo;

    l->inicio = novo;
    l->tam++;

    return 1;
}

int inserirNoFim(Descritor* l, int valor)
{
    No* novo = (No*)malloc(sizeof(No));
    
    if (novo == NULL)
        return 0;

    novo->num = valor;
    novo->prox = NULL;

    if (l->fim == NULL)
        l->inicio = novo;
    else
        l->fim->prox = novo;

    l->fim = novo;
    l->tam++;

    return 1;
}

int removerInicio(Descritor* l)
{
    if (l->tam == 0 || l == NULL)
        return 0;

    No* aux = l->inicio;

    if (l->tam == 1)
    {
        l->inicio = NULL;
        l->fim = NULL;
        free(aux);
    } else
    {
        l->inicio = aux->prox;
        free(aux);
    }

    l->tam--;

    return 1;
}

int removerFim(Descritor* l)
{
    if (l->tam == 0 || l == NULL)
        return 0;

    No* atual = l->inicio, *ant = NULL;

    while (atual->prox != NULL)
    {
        ant = atual;
        atual = atual->prox;
    }
    
    if (l->tam == 1)
    {
        l->inicio = NULL;
        l->fim = NULL;
        free(atual);
    } else
    {
        ant->prox = atual->prox;
        l->fim = ant;
        free(atual);
    }

    l->tam--;

    return 1;
}

int removerElemento(Descritor* l, int elem)
{
    if (l->tam == 0 || l == NULL)
        return 0;

    No* atual = l->inicio, *ant = NULL;
    int achou = 0;

    while (atual != NULL)
    {
        if (atual->num == elem)
        {
            achou = 1;
            break;
        }

        ant = atual;
        atual = atual->prox;
    }

    if (achou)
    {
        if (atual == l->inicio)
        {
            removerInicio(l);

        } else if (atual == l->fim)
        {
            removerFim(l);
        } else
        {
            ant->prox = atual->prox;
            l->tam--;

            free(atual);
        }

        return 1;
    } else
        return 0; 
}

void mostrarLista (Descritor* l)
{
    if (l == NULL)
        printf("Lista não inicializada\n");
    else if (l->tam == 0)
        printf("Lista vazia\n");
    else
    {
        No *atual = l->inicio; 

        while (atual != NULL)
        {
            printf("%d%s", atual->num, (atual->prox == NULL) ? "\n" : " -> ");

            atual = atual->prox;
        }
    }
}

void adicionarAsListas(Descritor* v[], int tam, int valor)
{
    int r = valor % tam;
    inserirNoFim(v[r], valor);
}

void liberaLista(Descritor* l)
{
    No* atual = l->inicio, *ant = NULL;

    while (atual != NULL)
    {
        ant = atual;
        atual = atual->prox;
        free(ant);
    }

    free(l);

}

int maiorDaList(Descritor* l)
{
    if (l == NULL || l->tam == 0)
        return -1;

    int maior = l->inicio->num;
    No* at = l->inicio;

    while (at != NULL)
    {
        if (maior < at->num)
            maior = at->num;

        at = at->prox;
    }

    return maior;
}

int maiorDoVet(Descritor** v, int tam)
{
    int maior = maiorDaList(v[0]);

    if (v == NULL)
        return -1;

    for (int i = 0; i < tam; i++)
        if (maior < maiorDaList(v[i]))
            maior = maiorDaList(v[i]);

    return maior;

}


