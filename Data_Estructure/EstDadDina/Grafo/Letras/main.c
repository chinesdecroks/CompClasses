#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(void)
{
    Grafo* g = criarGrafo(5);
    //Grafo
    //0: A => B -> C -> VAZIO
    //1: B => A -> C -> E -> VAZIO
    //2: C => B -> E -> VAZIO
    //3: D => A -> E -> VAZIO
    //4: E => D -> B -> C -> VAZIO 

    montaGrafo(g);
    mostraGrafo(g);
    
}