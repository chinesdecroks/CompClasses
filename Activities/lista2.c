#include <stdio.h>
#include <stdlib.h>

/*1) Escreva um programa C que:
a. Crie um arquivo texto de nome “arq.txt”.
b. Permita que o usuário entre com diversos caracteres nesse arquivo, até que seja digitado
ENTER.
c. Feche o arquivo
int main(void)
{
    char phrase[500000];

    printf("Digite um paragrafo:\n");
    fgets(phrase, sizeof(phrase), stdin);
    FILE *f;
    f = fopen("arq.txt", "w");
    if (f == NULL)
    {
        printf("Erro na abertura/criacao do programa\n");
        exit(1);
    }

    fputs(phrase, f);


    fclose(f);
}*/

/*2) Abra e leia o arquivo criado no exercício anterior, caractere por caractere, e escreva na tela todos os
caracteres.

int main(void)
{
    char phrase[500000];

    FILE *f;

    f = fopen("arq.txt", "r");

    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    if (fgets(phrase, sizeof(phrase), f) != NULL)
    {
        printf("%s", phrase);
    }

    fclose(f);
}*/