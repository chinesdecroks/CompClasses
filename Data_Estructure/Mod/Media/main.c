#include <stdio.h>
#include "media.h"

int main() {

    // Declaração das variáveis
    float num1, num2, num3, media;

    // Entrada de dados
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);

    printf("Digite o segundo número: ");
    scanf("%f", &num2);

    printf("Digite o terceiro número: ");
    scanf("%f", &num3);

    // Cálculo da média
    media = med(num1, num2, num3);

    // Saída do resultado
    printf("A média dos três números é: %.2f\n", media);
    return 0;
}