#include <stdio.h>
#include <stdlib.h>
#include "notas.h"

int main(void)
{
    No* l;
    int opcao;
    lista_vazia(&l);

    do
    {
        printf("0 - Sair\n1 - Inserir aluno\n2 - Imprimir lista\n3 - Buscar Aluno\n4 - Excluir da Lista\n5 - Comprar produto\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            if (inserir(&l))
                printf("Insercao feita com sucesso\n");
            else
                printf("Falha na insercao\n");
            break;
        case 2:
            imprime_lista(l);
            break;
        case 3:

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