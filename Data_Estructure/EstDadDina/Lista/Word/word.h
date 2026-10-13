#ifndef _WORD_H
#define _WORd_H

typedef struct no No;

void criaListaVazia(No **l);
char* scan_word();
int insere(No** l);
int remover(No** l);
void imprime_lista(No* l);

#endif
