#ifndef _FILA_H
#define _FILA_H

/*Implemente em linguagem C, uma fila para organizar o registro de software pelo INPI (Instituto Nacional da Propriedade Industrial). 
Ao pedir o registro de um software, deve-se indicar o título, autor, linguagem e ano da criação.

A fila deve ser definida tendo-se como estrutura de base uma lista circular encadeada. 
Como apontador para a lista, tem-se apenas um ponteiro fim, que indica o último nó da fila, e é suficiente para indicar também o primeiro elemento da fila.

Codifique:

a) a estrutura de dados para o registro do software, a estrutura de dados para a Fila

b) função para criar/iniciar a fila.

c) função para inserir um novo elemento na fila

d) função para retirar um elemento da fila

c) função main com a inserção de 5 elementos na fila e a retirada de um.*/

typedef struct descritor Descritor;

Descritor* criarLista();
int enfilera(Descritor* l);
int desenfileira(Descritor* l);
void mostra_fila(Descritor* l);



#endif