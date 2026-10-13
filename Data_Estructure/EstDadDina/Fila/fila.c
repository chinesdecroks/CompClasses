#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct software
{
    char titulo[50], autor[50], linguagem[70];
    int ano;

}Soft;

typedef struct no
{
    Soft s;
    struct no* prox;
}No;

struct descritor
{
    No* fim;
    int tam;
};

void inicializa(Descritor* l)
{
    l->fim = NULL;
    l->tam = 0;
}

Descritor* criarLista()
{
    Descritor* l = (Descritor*)malloc(sizeof(Descritor));

    if (l != NULL)
        inicializa(l);

    return l;
}

Soft scan_software()
{
    Soft s;
    printf("Digite o titulo do software: ");
    scanf("%[^\n]", s.titulo);
    getchar();

    printf("Digite o autor do software: ");
    scanf("%[^\n]", s.autor);
    getchar();

    printf("Digite a linguagem do software: ");
    scanf("%[^\n]", s.linguagem);
    getchar();

    printf("Digite o ano de criacao do software: ");
    scanf("%d", &s.ano);
    getchar();

    return s;

}

No* novo_software()
{
    No* novo = (No*)malloc(sizeof(No));

    if (novo == NULL)
        return novo;

    novo->s = scan_software();
    novo->prox = NULL;

    return novo;
}

int enfilera(Descritor* l)
{
    No* novo = novo_software(), *aux = l->fim;
    if (novo == NULL || l == NULL)
        return 0;

    if (l->tam == 0)
    {
        novo->prox = novo;
        l->fim = novo;
    } else 
    {
        novo->prox = aux->prox;
        aux->prox = novo;

        l->fim = novo;
    }

    l->tam++;

    return 1;
}

int desenfileira(Descritor* l)
{
    if(l == NULL || l->tam == 0)
        return 0;

    No *auxf = l->fim, *auxi = l->fim->prox;

    if (l->tam == 1)
    {
        free(auxf);
        l->fim = NULL;
    } else 
    {
        auxf->prox = auxi->prox;
        free(auxi);
    }

    l->tam--;

    return 1;
}


void mostra_fila(Descritor* l)
{
    printf("\n=======================================\n");
    if(l == NULL)
        printf("Lista nao inicializada\n");
    else if (l->tam == 0)
        printf("Lista Vazia\n");
    else
    {
        No* aux = l->fim->prox, *auxi = l->fim->prox;

        do
        {
            printf("Titulo: %s\nAutor: %s\nLinguagem: %s\nAno: %d\n\n", aux->s.titulo, aux->s.autor, aux->s.linguagem, aux->s.ano);

            aux = aux->prox;
        } while (aux != auxi);
        
    }
    printf("=======================================\n");
}
