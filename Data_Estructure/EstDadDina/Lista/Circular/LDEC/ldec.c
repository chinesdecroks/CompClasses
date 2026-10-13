#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ldec.h"

struct pessoa
{
	char nome[50];
} ;

 struct no
{
	Pessoa p;
	struct no* prox;
    struct no* ant;
};

struct descritor 
{
	No* inicio;
    No* fim;
	int tam;
};

void listaVazia(Descritor* l)
{
	l->inicio = NULL;
    l->fim = NULL;
	l->tam = 0;
}

Descritor* criarLista()
{
	Descritor* l = (Descritor*)malloc(sizeof(Descritor));
	return l;
} 

Pessoa scanEleitor()
{
	Pessoa n;
	printf("Digite o nome do participante: ");
	scanf("%[^\n]", n.nome);
	
	return n;
}

No* criarEleitor()
{
	
	No* novo = (No*)malloc(sizeof(No));

	if (novo == NULL)
		return 0;

	novo->p = scanEleitor();
	novo->prox = NULL;
    novo->ant = NULL;
    
    return novo;
}

int inserir(Descritor* l)
{
    No* novo = criarEleitor(), *auxi = l->inicio, *auxf = l->fim;


    if (l->tam == 0)
	{
		novo->prox = novo;
        novo->ant = novo;
		l->inicio = novo;
        l->fim = novo;
	} else 
	{
		novo->prox = auxi;
        auxi->ant = novo;

        auxf->prox = novo;
        novo->ant = auxf;

        l->inicio = novo;
	}
	
	l->tam++;

	return 1;
}

int removerNo(Descritor *l, No* p)
{
    if (l == NULL || p == NULL || l->tam == 0)
        return 0;

    if (l->tam == 1)
    {   
        free(p);
        l->inicio = NULL;
        l->fim = NULL;
        l->tam = 0;
    } else
    {
        if (p == l->inicio)
            l->inicio = p->prox;
        if (p == l->fim)
            l->fim = p->ant;

        p->prox->ant = p->ant;
        p->ant->prox = p->prox;

        free(p);
        l->tam--;

        return 1;

    }
}

No* andar_frente(No *atual, int n)
{
    while (n--)
        atual = atual->prox;

    return atual;

}

No* andar_tras(No *atual, int n)
{
    while (n--)
        atual = atual->ant;

    return atual;

}

No* sorteioInicial(Descritor* l)
{

    srand(time(NULL));

    No* caixa = l->inicio;
    int pos = rand() % l->tam;
    while (pos--)
        caixa = caixa->prox;
    
    return caixa;
}

char *escolhe_Lider(Descritor* l, int k)
{
    No* caixa = sorteioInicial(l);
    int direita = 1;
    if (l->tam > 1)
    {
        No* eliminado;

        while (l->tam != 1)
        {
            if (direita)
            {
                eliminado = andar_frente(caixa, k-1);
                caixa = eliminado->ant;
                removerNo(l, eliminado);
            } else 
            {
                eliminado = andar_tras(caixa, k-1);
                caixa = eliminado->prox;
                removerNo(l, eliminado);
            }

            direita = !direita;
        }

        return l->inicio->p.nome;

    } else
    {
        return NULL;
    }
}

void mostrarEleitores(Descritor* l)
{
	printf("---------------Lista-----------------\n");
	if(l->inicio)
	{
		No* aux = l->inicio;
		int cont = 1;
		do
		{
			printf("%s\n", aux->p.nome);
			printf("\n\n");
			aux = aux->prox;

		} while (l->inicio != aux);

	} else
		printf("\nLista vazia\n\n");
	printf("---------------Fim-------------------\n");
}