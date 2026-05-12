#ifndef _PRODUTOS_H_
#define _PRODUTOS_H_

typedef struct produto{
  int codProd;        //código do produto
  char nomeProd[10];  //nome do produto
  float valor;        //valor do produto
  int qtdeEstoque;    //quantidade disponível em estoque
} Produtos;



#endif