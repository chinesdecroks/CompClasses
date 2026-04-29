#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int dia, mes, ano;
} Data;

typedef struct pessoa
{
    char nome[50];
    Data data;
} Pessoa;

typedef struct no
{
    Pessoa p;
    struct no *proximo;

} No;

Pessoa ler_pessoa();
void imprime_pessoa(Pessoa p);


int main(void)
{
    No *topo = NULL;
    int opcao;

    do 
    {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desmpilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao)
        {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            default:
                if(opcao != 0)
                    printf("\nOpcao invalida!!!\n");
        }
    } while (opcao != 0);

    return 0;

}


Pessoa ler_pessoa()
{
    Pessoa p;

    printf("\nDigite nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n]%d%d%d", p.nome, p.data.dia, p.data.mes, p.data.ano);
    return p;
}

void imprime_pessoa(Pessoa p)
{
    printf("Nome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}
