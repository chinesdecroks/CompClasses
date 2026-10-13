#ifndef _CIRCULAR_H
#define _CIRCULAR_H

typedef struct no No;
typedef struct descritor Descritor;
typedef struct pessoa Pessoa;

void listaVazia(Descritor* l);
Descritor* criarLista();
Pessoa scanEleitor();
No* criarEleitor();
int inserir(Descritor* l);
int removerNo(Descritor *l, No* p);
No* andar_frente(No *atual, int n);
No* andar_tras(No *atual, int n);
No* sorteioInicial(Descritor* l);
char* escolhe_Lider(Descritor* l, int k);
void mostrarEleitores(Descritor* l);

#endif