#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word.h"

struct no 
{
	char* w;
	struct no* prox;
};


void criaListaVazia(No **l){
   *l = NULL;
}


char* scan_word()
{
	char* word = (char*)malloc(50*sizeof(char));
	scanf("%[^\n]", word);

	return word;
}


int insere (No** l)
{
	No* novo = (No*)malloc(sizeof(No));
	
	if (novo)
	{
		novo->w = scan_word();
		novo->prox = *l;
		*l = novo;
		return 1;
	}
	else 
		return 0;
}


int remover(No** l)
{
	No* ant = NULL, *atual = *l;
	char nome[50];


	printf("Digite a palavra que sera excluida: ");
	scanf("%[^\n]", nome);


	if (*l)
	{


		while (strcmp(nome, atual->w))
		{
			ant = atual;
			atual = atual->prox;
		}


		if (ant == NULL)
			*l = atual->prox;
		else
			ant->prox = atual->prox;


		free(atual);


		return 1;
	} 
	else
		return 0;


}


void imprime_lista(No* l)
{
	printf("\n------------Lista-------------\n");
	if(l)
	{
		while (l)
		{
			printf("%s\n", l->w);
			l = l->prox;
		}
	} else
		printf("\nLista vazia\n");
	printf("\n-----------Fim----------------\n\n");
}

