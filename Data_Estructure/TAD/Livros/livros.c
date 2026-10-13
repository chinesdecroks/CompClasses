#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livros.h"

void init_list(Lista* l)
{
    l->dados = NULL;
    l->tam = 0;
    l->cap = 0;
}

void cria_list(Lista *l, int tam)
{
    if(l->dados == NULL)
    {
        l->dados = (Livros*)malloc(tam*sizeof(Livros));
        if (l->dados == NULL)
        {
            printf("Falha na alocação de memoria\n");
            exit(1);
        }

        printf("\nLista criada com sucesso!!!\n\n");
    }
    else
    {
        printf("A lista já foi criada insira elementos nela\n");
    }
}

void liberar_list(Lista* l)
{
    free(l->dados);
}

Livros scan_livro()
{
    Livros l;

    printf("Digite o título do livro: ");
    scanf("%[^\n]", l.titulo);
    getchar();

    printf("Digite o nome do autor(a) do livro: ");
    scanf("%[^\n]", l.autor);
    getchar();

    printf("Digite o ano de publicação do livro: ");
    scanf("%d", &l.ano);
    getchar();

    printf("Digite o preco do livro: ");
    scanf("%f", &l.preco);

    return l;

}

void inserir(Lista* l)
{
    int a = 1;

    if (l->dados != NULL)
    {
        do
        {
            if (l->tam < l->cap)
            {
                    l->dados[l->tam] = scan_livro();
                    l->tam++;
                    a = 0;
            } else
            {
                l->cap += 1;
                l->dados = (Livros*)realloc(l->dados, (l->cap)*sizeof(Livros));
            }
        } while (a);
    }
    else
    {
        printf("\nA lista não foi criada\nCrie a lista primeiro\n\n");
    }
}

void mostra_livro(Livros l)
{
    printf("\nNome: %s\nAutor: %s\nAno: %d\nPreco: R$ %.2f\n\n", l.titulo, l.autor, l.ano, l.preco);
}

void imprimir_lista(Lista* l)
{
    printf("\n------------ Inicio ------------");
    
    if (l->dados == NULL)
    {
        printf("\n\nLista esta vazia\n\n");
    } else
    {
        for (int i = 0; i < l->tam; i++)
            mostra_livro(l->dados[i]);
    }
    printf("------------- Fim -------------\n\n");

}

int busca_livro(Lista* l, char* nome)
{
    for (int i = 0; i < l->tam; i++)
    {
        if (!strcmp(l->dados[i].titulo, nome))
            return i;
    }

    return -1; 
}


void excluir(Lista* l)
{
    char nome[30];
    
    printf("Qual o nome do livro deseja excluir: ");
    scanf("%[^\n]", nome);
    getchar();

    int index = busca_livro(l, nome);

    if (index < 0 || l->dados == NULL)
        printf("\nItem não existe na lista\n\n");
    else
    {
        if (l->cap == 1 && index == 0)
        {
            init_list(l);
        } else
        {
            for (int i = index; i < l->tam; i++)
            {
                if (i+1 < l->tam)
                    l->dados[i] = l->dados[i+1]; 
            }

            l->cap -= 1;
            l->tam -= 1;

            l->dados = (Livros*)realloc(l->dados, l->cap*sizeof(Livros));

        }

        printf("\nExclusao feita com sucesso!!!\n\n");
    }
}