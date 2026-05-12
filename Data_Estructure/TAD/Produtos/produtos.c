#include <stdio.h>
#include "produtos.h"

Produtos* cria_lista(int tam)
{
    Produtos* p = (Produtos*) malloc(tam*sizeof(Produtos)); 

    return p;
}