#include <stdio.h>
#include <stdlib.h>
#include "word.h"

int main(void)
{

    int opcao;
    No* l;

    criaListaVazia(&l);

    do
    {
        printf("0 - Sair\n1 - Inserir palavra\n2 - Imprimir lista\n3 - Remover palavra\n4 - Excluir da Lista\n5 - Comprar produto\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            if (insere(&l))
                printf("Insercao feita com sucesso\n");
            else
                printf("Falha na insercao\n");
            break;
        case 2:
            imprime_lista(l);
            break;
        case 3:
            if (remover(&l))
                printf("\nPalavra removida com sucesso\n");
            else
                printf("\nFalha na remocao da palavra\nOu lista vazia\n");
            break;
        case 4:

            break;
        case 5:
            
            break;
        default:
            if (opcao != 0)
                printf("\nOpcao invalida!\nTente novamente\n\n");
            break;
        }
    } while (opcao != 0);
}