#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ldec.h"

int main(void)
{
    Descritor* l = criarLista();
    int opcao, a;
    listaVazia(l);

    do
    {
        printf("0 - Sair\n1 - Inserir eletores\n2 - Mostrar candidatos\n3 - Eleger Lider\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            if (inserir(l))
                printf("Insercao feita com sucesso\n");
            else
                printf("Falha na insercao\n");
            break;
        case 2:
             mostrarEleitores(l);
            break;
        case 3:
           srand(time(NULL));
           int k = rand() % 10;
           printf("O Líder eh %s\n", escolhe_Lider(l, k));
            break;
        default:
            if (opcao != 0)
                printf("\nOpcao invalida!\nTente novamente\n\n");
            break;
        }
    } while (opcao != 0);

}