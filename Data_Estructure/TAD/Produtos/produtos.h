#ifndef _PRODUTOS_H_
#define _PRODUTOS_H_

typedef struct produto
{
  int codProd;        //código do produto
  char nomeProd[10];  //nome do produto
  float valor;        //valor do produto
  int qtdeEstoque;    //quantidade disponível em estoque
} Produtos;

typedef struct lista
{
  Produtos* dados;
  int indice;
} Lista;

void inicializa_lista(Lista* l);
Produtos* cria_lista(int tam);
Produtos* criar_produto(Produtos* p, int* tam);
void libera_lista(Produtos* p);
Produtos insere_produto();
void imprime_produto(Produtos p);
void insere_lista(Produtos* p, int tam);
void listar_produtos(Produtos* p, int tam);
int busca_barato(Produtos* p, int tam);
void venda(Lista* l); 


#endif