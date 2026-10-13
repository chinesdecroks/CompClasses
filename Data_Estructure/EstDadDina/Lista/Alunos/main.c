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
        printf("0 - Sair\n1 - Inserir aluno\n2 - Imprimir lista de alunos\n3 - Buscar Aluno\n4 - Excluir da Lista\n5 - Imprimir aprovados\nEscolha: ");
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
            busca_aluno(l);
            break;
        case 4:
            if(excluir(&l))
                printf("Remocao feita com sucesso!!\n");
            else
                printf("Remocao nao concluida!!\n");
            break;
        case 5:
            imprime_aprovados(l);
            break;
        default:
            if (opcao != 0)
                printf("\nOpcao invalida!\nTente novamente\n\n");
            break;
        }
    } while (opcao != 0);
}