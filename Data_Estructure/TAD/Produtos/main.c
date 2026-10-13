#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

int main(void)
{
    Lista l;
    int opcao;

    inicializa_lista(&l);

    do
    {
        printf("0 - Sair\n1 - Criar lista\n2 - Adicionar produto\n3 - Imprimir lista\n4 - Buscar produto mais barato\n5 - Comprar produto\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Insira quantos produtos deseja na sua lista: ");
            scanf("%d", &l.indice);
            l.dados = cria_lista(l.indice);
            insere_lista(l.dados, l.indice);
            break;
        case 2:
            l.dados = criar_produto(l.dados, &l.indice);
            break;
        case 3:
            listar_produtos(l.dados, l.indice);
            break;
        case 4:
            printf("O produto mais barato da lista eh:\n");
            imprime_produto(l.dados[busca_barato(l.dados, l.indice)]);
            break;
        case 5:
            venda(&l);
            break;
        default:
            if (opcao != 0)
                printf("\nOpcao invalida!\nTente novamente\n\n");
            break;
        }
    } while (opcao != 0);
    
    libera_lista(l.dados);
}