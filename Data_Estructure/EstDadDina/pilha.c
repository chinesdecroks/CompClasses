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
//função para a operação de push (empilhar)
No* empilhar(No *topo);
//função para a operação de pop (desempilhar)
//Nesse caso será utilizado ponteiro de ponteiro pois essa função
//deve tanto retornar o nó desempilhado quanto retornar o novo valor do topo
// como uma função só pode retornar um único valor o novo nó para o topo será "retornado"
//para a função main a partir de uma passagem por referencia, mas como o topo já é um ponteiro
//então será necessário utilizar ponteiro de ponteiro
No* desempilhar(No **topo)
{
    if (*topo != NULL)
    {
        No* remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else 
        printf("\nPilha vazia!\n");
    return NULL;

}



int main(void)
{
    //Sempre se realiza operções no topo da pilha 
    //esse ponteiro topo aponta para o nó que estiver no topo da pilha
    //no caso é inicializado com NULL já que a pilha não tem nenhum nó
    No *remover, *topo = NULL;
    int opcao;

    do 
    {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desmpilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao)
        {
            case 1:
                topo = empilhar(topo);
                break;
            case 2:
                remover = desempilhar(&topo); 
                if (remover)
                {
                    printf("\nElemento removido com sucesso\n");
                    imprime_pessoa(remover->p);
                }
                else
                    printf("\nSem no a remover\n");
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

// Essa função cria um novo nó que recebe as informações de uma pessoa
// e cria um ponteiro para o topo anterior, e novo criado é retornado como 
// o topo atual
No* empilhar(No *topo)
{
    No *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    }
    else
        printf("\nErro ao aloccar memoria\n");
    return NULL;
}