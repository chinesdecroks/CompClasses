#ifndef LISTA_H_
#define LISTA_H_

typedef struct descritor Descritor;

void inicializarLista (Descritor* l);
Descritor* criar_lista();
int inserirNoInicio (Descritor* l, int valor);
int inserirNoFim(Descritor* l, int valor);
int removerInicio(Descritor* l);
int removerFim(Descritor* l);
int removerElemento(Descritor* l, int elem);
void mostrarLista (Descritor* l);
void liberaLista(Descritor* l);
void adicionarAsListas(Descritor* v[], int tam, int valor);
int maiorDoVet(Descritor** v, int tam);



#endif