#include <stdio.h>
#include "media.h"

double med(double nota1, double nota2, double pontoext)
{
    double media = ((nota1 + nota2) / 2) + pontoext;

    if(media > 10)
        return 10;
    else 
        return media;
}

void imprimir_aluno(Aluno a)
{
    printf("Nome: %s\n", a.nome);
    printf("Media: %.2lf\n", a.media);
}

Aluno ler_aluno()
{
    Aluno a;
    double p1, p2, pntex;

    printf("Nome do aluno: ");
    scanf("%49[^\n]", a.nome);
    getchar();
    
    do
    {
        printf("Nota da P1, da P2 e pontos extras: ");
        scanf("%lf %lf %lf", &p1, &p2, &pntex);
        getchar();

        if (p1 > 10 || p1 < 0 || p2 > 10 || p2 < 0 || pntex > 5 || pntex < 0)
            printf("\nNotas inválidas!!! Por favor tente novamente.\n\n");
            
    } while (p1 > 10 || p1 < 0 || p2 > 10 || p2 < 0 || pntex > 5 || pntex < 0);

    a.media = med(p1, p2, pntex);

    return a;
}

void ler_sala(Aluno* v, int len)
{
    for (int i = 0; i < len; i++)
    {
        v[i] = ler_aluno();
    }

}

void imprimir_sala(Aluno* v, int len)
{
    for (int i = 0; i < len; i++)
    {
        imprimir_aluno(v[i]);
    }
}
