#include <stdio.h>
#include <stdlib.h>
#include "circular.h"

typedef struct nave
{
	int cap_max, comb;
} Nave;

typedef struct no
{
	Nave naves;
	struct no* prox;
} No;

struct descritor 
{
	No* cauda;
	int tam;
};

void listaVazia(Descritor* l)
{
	l->cauda = NULL;
	l->tam = 0;
}

Descritor* criarLista()
{
	Descritor* l = (Descritor*)malloc(sizeof(Descritor));
	return l;
} 

Nave scanNave()
{
	Nave n;
	printf("Capacidade de combustível das naves: ");
	scanf("%d", &n.cap_max);
	printf("Digite quanto de combustivel tem a nave: ");
	scanf("%d", &n.comb);
	
	return n;
}

void criarNave(Descritor* l)
{
	
	No* novo = (No*)malloc(sizeof(No)), *aux = l->cauda;
	novo->naves = scanNave();
	if (*l == NULL)
	{
		novo->prox = novo;
		l->cauda = novo;
	} else 
	{
		novo->prox = aux->prox;
		aux->prox = novo;
		l->cauda = novo;
	}
	
	l->tam++;
}

void listaNaves(Descritor* l, int quant)
{
	for (int i = 0; i < quant; i++)
		criarNave(l);
}

void abastecer(No** l, int qnt)
{
	while ()
}

void mostrarNaves(No* l)
{
	printf("---------------Lista-----------------\n");
	if(l)
	{
		No* aux = l;
		int cont = 1;
		while (l-> prox != aux)
		{
			printf("Nave: %d\nCap. Max:%d\nCap. Atual: %d\n", cont++, l->naves->cap_max, l->naves->comb);
			printf("\n\n");
		} else
			printf("\nLista vazia\n");
	}
	printf("---------------Fim-------------------\n");
}