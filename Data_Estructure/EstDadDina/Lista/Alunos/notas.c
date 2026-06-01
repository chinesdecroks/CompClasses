#include <stdio.h>
#include <stdlib.h>
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
    scanf("%[ˆ\n]", aln.nome);
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
    printf("Nome: %s\nNota pratica: %.2lf\nNota teorica: %.2lf\nMedia: %.2lf\n", l.nome, l.prt, l.trc, l.med);
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
    printf("\n------------- Inicio ---------------\n\n");

}