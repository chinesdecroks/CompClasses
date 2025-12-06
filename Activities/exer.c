#include <stdio.h>
#include <math.h>
#include <string.h>

    /*int main(void)
    {
        double a; 
        scanf("%lf", &a);

        printf("%.6lf\n", a*0.621371);
    }*/

    /*int main(void)
    {
        double x;
        scanf("%lf", &x);

        double y = 3*x -2;

        printf("%.0lf\n", y);
    }*/

    /*int main(void)
    {
        double x[3], soma = 0;

        for (int i = 0; i < 3; i++)
        {
            scanf("%lf", &x[i]);

            if (i == 0)
                soma += 2*x[i];
            if (i == 1)
                soma += 3*x[i];
            if (i == 2)
                soma += 3*x[i];
        }

        printf("%.2lf\n", soma/8);

        
    }*/

    /*int main(void)
    {
        float h, r;
        scanf("%f %f", &h, &r);

        printf("%f\n", h*r*r*3.141592);
    }*/

    /*int main(void)
    {
        int ano;
        //printf("Digite um ano: ");
        scanf("%d", &ano);

        if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
        {
            printf("SIM\n");
        } else 
        {
            printf("NAO\n");

        }
    }*/

    /*int main(void)
    {
        int a;

        //printf("Digite um numero: ");
        scanf("%d", &a);

        //printf("Sao divisores desse numero: ");
        for (int i = 1; i <= a; i++)
        {
            if (a % i == 0)
            {
                printf("%d%c", i, (i == a) ? '\n' : ' ');
            }
        }
    }*/

    int main(void)
    {
        int m[3][3], a = 0, det = 0;

        //printf("Digite uma matriz 3x3:\n");

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%d", &m[i][j]);
            }
        }

        while (a < 3)
        {
            int m1[2][2], l = 0, c = 0, temp = 1, temp1 = 1, det1;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (i != 0 && j != a)
                    {
                        m1[l][c] = m[i][j];

                        c++;
                        if (c == 2)
                        {
                            c = 0;
                            l++;

                        }
                    }
                }
            }

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (i == j)
                    {
                        temp *= m1[i][j];
                    } else
                    {
                        temp1 *= m1[i][j];

                    }
                }
            }

            det1 = temp - temp1;

            if (a == 1)
            {
                det1 = -det1;
            }

            det += m[0][a]*det1;

            

            a++;

        }

        printf("%d\n", det);
    }