#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

//Exercício: Faça um vetor de 5 listas de números cada elemento que for adicionado na lista
//deve se vericar o resto em relação ao valor 5 e então deve adicionar o elemento a lista 
//em que o indice bate com o resto em relação ao 5 
int main()
{
   srand(time(NULL));

   Descritor **listas = (Descritor**)malloc(10 * sizeof(Descritor*));

   for (int i = 0; i < 10; i++)
     listas[i] = criar_lista();

   for (int i = 0; i < 20; i++)
   {
        int rng = rand() % 100;
        adicionarAsListas(listas, 10, rng);
   }

   for (int i = 0; i < 10; i++)
   {
        printf("lista %d: ", i);
        mostrarLista(listas[i]);
   }

   printf("\nMaior Numero do Vetor: %d\n", maiorDoVet(listas, 10));

   for (int i = 0; i < 10; i++)
        liberaLista(listas[i]);

     
   free(listas);


   
}