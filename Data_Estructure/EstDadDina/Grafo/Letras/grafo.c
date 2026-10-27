#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

typedef struct no
{
    int destino;
    struct n* prox;
} No;

typedef struct 
{
    char V;
    int qnt;
    No* relacinamentos;
} Vertice;

struct grafo
{
    int T;
    Vertice** lista;
};


Grafo* criarGrafo(int size)
{
    Grafo* novo = (Grafo*)malloc(sizeof(Grafo));

    if (novo == NULL)
        return novo;

    Vertice** listaVer = (Vertice**)(size*sizeof(Vertice*));

    if (listaVer == NULL)
        return NULL;

    novo->lista = listaVer;
    novo->T = size;
    
    for (int i = 0; i < novo->T; i++)
    {
        char v;
        printf("Digite a letra do vertice: ");
        scanf("%c", &v);
        Vertice u = criarVertice(v);

        novo->lista[i] = &u;
    }

    return novo;
}

Vertice criarVertice(char V)
{
    Vertice novo;

    novo.V = V;
    novo.qnt = 0;
    novo.relacinamentos = NULL;

    return novo;
}


//A função recebe os indices dos vertices que se relacionam entre si
void relacao(Grafo* g, int v1, int v2, int directed)
{
    if (v1 >= g->T || v2 >=  g->T || v1 < 0 || v2 < 0)
    {
        printf("Indices dos vertices invalido\n");
        return;
    }

    No* atual = g->lista[v1]->relacinamentos;
    //Valida se o indices v2 esta em v1 e, se n direcionado,
    //v1 esta em v2
    int val = 0;

    while (atual != NULL)
    {
        if (atual->destino == v2)
        {
            val = 1;
            break;
        }
        atual = atual->prox;
    }

    //v1 é adjacente a v2 e v2 é sucessor de v1
    //Se não for direcionado o contrario se aplica
    if (!val)
    {
        No* novo1  = (No*)malloc(sizeof(No));
        novo1->destino = v2;
        novo1->prox = g->lista[v1]->relacinamentos;
        g->lista[v1]->relacinamentos = novo1;
        g->lista[v1]->qnt++;
    }

    if (!directed)
    {
        val = 0;
        atual = g->lista[v2]->relacinamentos;

        while (atual != NULL)
        {
            if (atual->destino == v1)
            {
                val = 1;
                break;
            }
            atual = atual->prox;
        }

        if (!val)
        {
            No* novo2  = (No*)malloc(sizeof(No));
            novo2->destino = v1;
            novo2->prox = g->lista[v2]->relacinamentos;
            g->lista[v2]->relacinamentos = novo2;
            g->lista[v2]->qnt++;
        }
    }
}

void relacoes(Grafo* g, int v1)
{
    int q, v, d;
    printf("Digite o numero de relacoes que %c possui: ", g->lista[v1]->V);
    scanf("%d", &q);
    getchar();

    for (int i = 0; i < q; i++)
    {
        printf("Digite o indice do grafo de destino: ");
        scanf("%d", &v);
        printf("Direcionado(1/0): ");
        scanf("%d", &d);
        relacao(g, v1, v, d);
    }
}

void montaGrafo(Grafo* g)
{
    for (int i = 0; i < g->T; i++)
        relacoes(g, i);
    
}

void mostraGrafo(Grafo* g)
{
    No* atual;

    for (int i = 0; i < g->T; i++)
    {
        int cont = 0;
        printf("%c => ", g->lista[i]->V);

        atual = g->lista[i]->relacinamentos;

        while (atual != NULL)
        {
            printf("%c%s", g->lista[atual->destino]->V, (cont == g->lista[i]->qnt - 1) ? " -> " : "VAZIO\n");
            cont++;

            atual = atual->prox;
        }
    }

}

