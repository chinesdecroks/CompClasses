#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notas.h"

struct aluno 
{
    char nome[50];
    double prt, trc, med;

};

struct no 
{
    Aluno n;
    struct no* prox;
};

void lista_vazia(No** l)
{
    *l = NULL;
}

Aluno scan_aluno ()
{
    Aluno aln;

    printf("Digite o nome do aluno: ");
    scanf("%[^\n]", aln.nome);
    getchar();
    
    printf("Digite a nota pratica do aluno: ");
    scanf("%lf", &aln.prt);
    getchar();
    
    printf("Digite a nota teorica do aluno: ");
    scanf("%lf", &aln.trc);
    getchar();

    aln.med = (aln.prt + aln.trc);

    return aln;

}

int inserir (No** l)
{
    No* novo = (No*) malloc (sizeof(No));

    if (novo == NULL)
        return 0;

    novo->n = scan_aluno();
    novo->prox = *l;
    *l = novo;

    return 1;
}

void mostra_aluno(Aluno l)
{
    printf("Nome: %s\nNota pratica: %.2lf\nNota teorica: %.2lf\nMedia final: %.2lf\n\n", l.nome, l.prt, l.trc, l.med);
}

void imprime_lista(No* lista)
{
    printf("\n------------- Inicio ---------------\n");
    if (lista)
        while (lista != NULL)
        {
            mostra_aluno(lista->n);
            lista = lista->prox;
        }
    else
        printf("\nLista Vazia\n");
    printf("\n-------------- Fim ----------------\n\n");

}

void busca_aluno(No* l)
{
    char nom[50];

    printf("Digite o nome do aluno: ");
    scanf("%[^\n]", nom);

    if (l)
        while (l != NULL)
        {
            if (!strcmp(l->n.nome, nom))
            {
                mostra_aluno(l->n);
                break;
            }
            l = l->prox;
        }
    else
        printf("\nLista Vazia\n");
}

void imprime_aprovados(No* lista)
{
    printf("\n------------- Aprovados ---------------\n");
    if (lista)
        while (lista != NULL)
        {
            if (lista->n.med >= 70)
                mostra_aluno(lista->n);
            lista = lista->prox;
        }
    else
        printf("\nLista Vazia\n");
    printf("\n-------------- Fim ----------------\n\n");

}

int excluir(No** l)
{
    No* ant = NULL, *atual = *l;
    char nom[50];

    printf("Digite o nome do aluno que deseja excluir: ");
    scanf("%[^\n]", nom);

    if (l)
        while (l != NULL)
        {
            if (!strcmp(atual->n.nome, nom))
            {
                if (atual == *l)
                    *l = (*l)->prox;
                else
                    ant->prox = atual->prox;
                
                free(atual);
                return 1;
            }

            ant = atual;
            atual = atual->prox;
        }
    else
        return 0;
}