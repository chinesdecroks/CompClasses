#include <stdio.h>
#include "fila.h"

int main(void)
{
    Descritor* fila = criarLista();

    for(int i = 0; i < 5; i++)
    {
        if (enfilera(fila))
        {
            printf("Elemento enfileirado\n");
        } else 
        {
            printf("Falha no enfileiramento\n");
        }
    }

    mostra_fila(fila);

    if (desenfileira(fila))
    {
            printf("Elemento desenfileirado\n");
    } else 
    {
            printf("Falha no desenfileiramento\n");
    }

    mostra_fila(fila);

    
}