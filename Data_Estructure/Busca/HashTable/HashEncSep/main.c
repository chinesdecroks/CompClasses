#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(void)
{
    Hash* ha = criaHash(3);
    Aluno al[12];
    char c[] = {'D','Q','B','I','M','H','G','U','A','C','R','S'};

    for (int i = 0; i < 12; i++)
    {
        al[i].nome = c[i];
    }

    for (int i = 0; i < 12; i++)
        insereHash_EncSep(ha, al[i]);

    mostraHashMatricula(ha);

    liberaHash(ha);
    


}