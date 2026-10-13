#include <stdio.h>
#include <stdlib.h>
#include "num.h"

int main(void)
{
    Descritor* l = criar_lista();
    int opcao, a;
    inicializarLista(l);

    do
    {
        printf("0 - Sair\n1 - Inserir no inicio\n2 - Inserir no fim\n3 - Excluir no inicio\n4 - Excluir do final\n5 - Excluir elemento\n6 - Imprimir lista\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Digite um numero: ");
            scanf("%d", &a);
            if (adicionarNoInicio(l, a))
                printf("Insercao feita com sucesso\n");
            else
                printf("Falha na insercao\n");
            break;
        case 2:
             printf("Digite um numero: ");
             scanf("%d", &a);
             if (adicionarNoFinal(l, a))
                printf("Insercao feita com sucesso\n");
             else
                printf("Falha na insercao\n");
            break;
        case 3:
            if (removerDoInicio(l))
                printf("\nExclusao feita com sucesso\n");
            else
                printf("\nFalha na exclusao\n");
            break;
        case 4:
            if (removerDoFinal(l))
                printf("\nExclusao feita com sucesso\n");
            else
                printf("\nFalha na exclusao\n");
            break;
        case 5:
            printf("Digite um numero que sera excluido da lista: ");
            scanf("%d", &a);
             if (removerElemento(l, a))
                printf("Exclusao feita com sucesso\n");
             else
                printf("Falha na exclusao\n");
            break;
        case 6:
            exibirLista(l);
            break;
        default:
            if (opcao != 0)
                printf("\nOpcao invalida!\nTente novamente\n\n");
            break;
        }
    } while (opcao != 0);

}