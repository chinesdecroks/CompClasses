#ifndef _NOTAS_H
#define _NOTAS_H

typedef struct aluno Aluno;
typedef struct no No;

void lista_vazia(No** l);
Aluno scan_aluno ();
int inserir (No** l);
void mostra_aluno(Aluno l);
void imprime_lista(No* lista);



#endif