#ifndef _NUM_H
#define _NUM_H

typedef struct descritor Descritor;

void inicializarLista(Descritor *lista);
int adicionarNoInicio(Descritor *lista, int valor);
int adicionarNoFinal(Descritor *lista, int valor);
int removerDoInicio(Descritor *lista);
int removerDoFinal(Descritor *lista);
int removerElemento(Descritor *lista, int elemento);
void exibirLista(Descritor *lista);
Descritor* criar_lista();


#endif