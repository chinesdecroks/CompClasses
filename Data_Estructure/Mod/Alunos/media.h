#ifndef _MEDIA_H
#define _MEDIA_H

typedef struct TipoAluno
{
    char nome[50];
    double media;
} Aluno; 

Aluno ler_aluno();
void imprimir_aluno(Aluno a);
double med(double nota1, double nota2, double pontoext);
void ler_sala(Aluno* v, int len);
void imprimir_sala(Aluno* v, int len);


#endif