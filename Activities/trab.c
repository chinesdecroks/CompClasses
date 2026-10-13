#include <stdio.h>

void imprimirExclamacoes(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("!");
        }
        printf("\n");
    }
}

int main() {
    int n;

    scanf("%d", &n);

    if(n <= 0) {
        printf("Erro");
    } else {
        imprimirExclamacoes(n);
    }

    return 0;
}