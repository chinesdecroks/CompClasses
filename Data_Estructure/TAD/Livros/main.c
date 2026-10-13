#include <stdio.h>
#include <stdlib.h>
#include "livros.h"

int main(void)
{
    Lista l;
    int opcao;

    init_list(&l);

    do
    {
        printf("0 - Sair\n1 - Criar lista\n2 - Inserir livro\n3 - Imprimir lista\n4 - Excluir livro\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Insira quantos livros deseja na sua lista: ");
            scanf("%d", &l.cap);
            cria_list(&l, l.cap);
            break;
        case 2:
            inserir(&l);
            break;
        case 3:
            imprimir_lista(&l);
            break;
        case 4:
            excluir(&l);
            break;
        default:
            if (opcao != 0)
                printf("\nOpcao invalida!\nTente novamente\n\n");
            break;
        }
    } while (opcao != 0);
    
    liberar_list(&l);
}