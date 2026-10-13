#include <stdio.h>
#include <stdlib.h>
#include "circula.h"

struct nave
{
	int cap_max, comb, val;
} ;

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

int criarNave(Descritor* l)
{
	
	No* novo = (No*)malloc(sizeof(No)), *aux = l->cauda;

	if (novo == NULL)
		return 0;

	novo->naves = scanNave();
	novo->naves.val = 0;

	if (l->tam == 0)
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

	return 1;
}

int listaNaves(Descritor* l, int quant)
{
	int cont = 0, i;
	for (i = 0; i < quant; i++)
	{
		if (criarNave(l))
			cont++;
		else
			return 0;
	}

	if (cont == i)
		return 1;
	else
		return 0;
		
		
}

void abastecer(Descritor* l, int qnt)
{
	int cont = 0;
	No* aux = l->cauda->prox;

	if (l->cauda)
	{
		while (cont != l->tam)
		{
			if ((aux->naves.cap_max < aux->naves.comb + qnt || aux->naves.cap_max == aux->naves.comb) && !aux->naves.val)
			{
				cont++;
				aux->naves.val = 1;
			} else if ((aux->naves.cap_max > aux->naves.comb) && !aux->naves.val)
			{
				aux->naves.comb += qnt;

				if (aux->naves.cap_max == aux->naves.comb)
				{
					cont++;
					aux->naves.val = 1;
				}
				
			} 

			aux = aux->prox;

		}

		reset(l); //Faz a validação voltar para 0
	} else
		printf("Sem naves para abastecer\n");
}

void reset(Descritor* l)
{
	No* aux = l->cauda;

	do
	{
		aux->naves.val = 0;
		aux = aux->prox;

	} while (l->cauda != aux);
}

void mostrarNaves(Descritor* l)
{
	printf("---------------Lista-----------------\n");
	if(l->cauda)
	{
		No* aux = l->cauda;
		int cont = 1;
		do
		{
			printf("Nave: %d\nCap. Max: %d\nCap. Atual: %d\n", cont++, aux->naves.cap_max, aux->naves.comb);
			printf("\n\n");
			aux = aux->prox;

		} while (l->cauda != aux);

	} else
		printf("\nLista vazia\n\n");
	printf("---------------Fim-------------------\n");
}