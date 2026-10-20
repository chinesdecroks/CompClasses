#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(void)
{
    Hash* ha = criaHash(10);
    Aluno al[10];
    char v[] = {'I', 'C', 'W', 'Y', 'L', 'Z', 'E', 'O', 'K', 'P'};

    for (int i = 0; i < 10; i++)
        al[i].nome = v[i];

    for (int i = 0; i < 10; i++)
        insereHash_Sigma(ha, al[i]);

    mostraHashMatricula(ha);

    liberaHash(ha);
    


}