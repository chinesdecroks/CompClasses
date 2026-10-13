#include <stdio.h>
#include <math.h>

double f(double x) { return x*log10(x) - 1; }

//epsilon é a minha tolerância
double bisseccao(double (*f)(double), double a, double b, double epsilon)
{
    double x;
    int itr = 0;

    if (f(a)*f(b) > 0)
        printf("Nada se pode concluir, pois o intervalo é monótono\n");
    else
    {

        while ((b-a)/2 > epsilon || itr > 100)
        {
            x = (a+b)/2;
            
            printf("k = %d | a = %lf | x = %lf | b = %lf | Erro = %lf\n", itr, a, x, b, (b-a)/2);

            if (f(a)*f(x) < 0)
                b = x;
            else if (f(a)*f(x) > 0)
                a = x;
            else
                return x;

            itr++;
        }

        return (a+b)/2;

    }
}

int main(void)
{
    double x, a, b, epsilon;
    char resposta;

    do
    {
        printf("Deseja testar valores(Y/N)? ");
        scanf("%c", &resposta);
        getchar();

        if (resposta == 'Y' || resposta == 'y')
        {
            printf("x = ");
            scanf("%lf", &x);
            getchar();
            printf("f(x) = xlog(x) - 1\nf(%.0lf) = %.3lf\n", x, f(x));
        }
        else if (resposta == 'N' || resposta == 'n')
            break;
        else 
            printf("Resposta inválida");
    } while (1);

    printf("Digite o intervalo [a, b]: ");
    scanf("%lf", &a);
    scanf("%lf", &b);
    printf("Digite a tolerancia desejada: ");
    scanf("%lf", &epsilon);

    x = bisseccao(f, a, b, epsilon);

    printf("A raiz da minha equacao é: %lf\n", x);
}