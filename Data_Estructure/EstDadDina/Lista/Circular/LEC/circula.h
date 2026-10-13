#ifndef _CIRCULAR_H
#define _CIRCULAR_H

typedef struct descritor Descritor;
typedef struct nave Nave;

void listaVazia(Descritor* l);
Descritor* criarLista();
Nave scanNave();
int criarNave(Descritor* l);
int listaNaves(Descritor* l, int quant);
void mostrarNaves(Descritor* l);
void abastecer(Descritor* l, int qnt);
void reset(Descritor* l);

#endif

