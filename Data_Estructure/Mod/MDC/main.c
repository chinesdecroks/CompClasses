#include <stdio.h>
#include "mdc.h"

int main(void)
{
    int a, b, mdc;

    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);

    //Função que define o mdc
    mdc = max_div_com(a, b);

    printf("O MDC de %d e %d eh %d\n", a, b, mdc);

}