#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "forca2.h"

char password[MAX_PALAVRAS]; 
char tries[26];
int tries_done = 0;


int main(void)
{
    choose_password();
    try();

    printf("%s\n", password);

}

void choose_password()
{
    FILE* f;
    

    f = fopen("word.txt", "r");
    if (f == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    int words;

    //o arquivo .txt deve ter a quantidade de palavras
    fscanf(f, "%d", &words);

    //A função srand define a semente de numeros pseudorandomicos
    //inibindo a seed padrão da função rand que é padronizada
    srand(time(0));

    int randomic = rand() % words;

    for (int i = 0; i <= randomic; i++)
    {
        fscanf(f, "%s", password);
    }

    fclose(f);
}

void try()
{
    char try;
    int validation = 0;

    while (!validation)
    {
        printf("Digite uma letra: ");
        scanf(" %c", &try);
        if (try >= 'A' && try <= 'Z' || try >= 'a' && try <= 'z')
        {
            if (try >= 'A' && try <= 'Z')
                try += 32;

            tries[tries_done] = try;
            tries_done++;
            validation = 1;
        }
        else 
        {
            printf("Caracter inválido! Tente novamente.\n");
        }
    }
}

int already_try(char letter)
{
    int find = 0;

    for (int i = 0; i < tries_done; i++)
    {
        if (tries[i] == letter)
        {
            
        }
    }
}