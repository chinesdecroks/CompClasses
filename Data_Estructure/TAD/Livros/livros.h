#ifndef _LIVROS_H_
#define _LIVROS_H_

typedef struct
{
    char titulo[30], autor[30];
    int ano;
    float preco;
} Livros;

typedef struct lista
{
  Livros* dados;
  int tam;
  int cap;
} Lista;

void init_list(Lista* l);
void cria_list(Lista *l, int tam);
void liberar_list(Lista* l);
Livros scan_livro();
void inserir(Lista* l);
void mostra_livro(Livros l);
void imprimir_lista(Lista* l);
void excluir(Lista* l);


#endif