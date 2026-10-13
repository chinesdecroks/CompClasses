#ifndef LISTA_H_
#define LISTA_H_

typedef struct no No;

No* initList();
void inserirIni(No* lista, int valor);
void inserirFim(No* lista, int valor);
int consulta(No* lista, int tam);
double inserirIni_t(No* lista, int tam);
double inserirFim_t(No* lista, int tam);
double consulta_t(No* lista, int tam);

#endif