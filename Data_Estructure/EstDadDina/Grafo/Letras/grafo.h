#ifndef _GRAFO_H_
#define _GRAFO_H_

typedef struct grafo Grafo; 

Grafo* criarGrafo(int size);
Vertice criarVertice(char V);
void relacao(Grafo* g, int v1, int v2, int directed);
void relacoes(Grafo* g, int v1);
void montaGrafo(Grafo* g);
void mostraGrafo(Grafo* g);


#endif