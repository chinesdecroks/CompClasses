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

int main(void)
{

}


Pessoa ler_pessoa()
{
    Pessoa p;

    printf("\nDigite nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n]%d%d%d", p.nome, p.data.dia, p.data.mes, p.data.ano);
}
