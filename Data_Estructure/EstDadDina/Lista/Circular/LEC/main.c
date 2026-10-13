#include <stdio.h>
#include "circula.h"

int main(void)
{
    Descritor* l = criarLista();
    int opcao, a;
    listaVazia(l);

    do
    {
        printf("0 - Sair\n1 - Inserir naves\n2 - Imprimir naves\n3 - Abastecer\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Digite quantas naves: ");
            scanf("%d", &a);
            if (listaNaves(l, a))
                printf("Insercao feita com sucesso\n");
            else
                printf("Falha na insercao\n");
            break;
        case 2:
             mostrarNaves(l);
            break;
        case 3:
           printf("Digite quanto sera abastecido: ");
            scanf("%d", &a);
            abastecer(l, a);
            break;
        default:
            if (opcao != 0)
                printf("\nOpcao invalida!\nTente novamente\n\n");
            break;
        }
    } while (opcao != 0);

}