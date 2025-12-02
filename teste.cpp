#include <stdio.h>
#include <math.h>
#include <string.h>
/*1)Faça um programa que leia um número inteiro e o imprima, então leia um número real e também o
imprima.
int main(void)
{


    int i;
    double j;

    printf("Digite um numero natural e um numero real:");

    scanf("%d %lf", &i, &j);

    printf("%d %lf\n", i, j);


}
    */

    /*2) Peça ao usuário para digitar três valores inteiros e imprima a soma deles

    int main(void)
    {
        int v,v1,v2;

        printf("Digite tres numeros: ");
        scanf("%d %d %d", &v,&v1,&v2);

        printf("A soma desses numeros eh: %d\n", v+v1+v2);

    } */

    /*3) Efetue a leitura de um número inteiro e imprima o resultado do quadrado desse número

    int main(void)
    {
        int i;
        scanf("%d", &i);

        printf("i^2 = %d\n", (int)pow(i, 2));
    } */

    /* Exercício extra: Pegar v0 e t e calcular distancia de queda de algum objeto
    int main(void)
    {
        double v0,t;
        const double g = 9.81;
        
        printf("Digite a velocidade inicial e o tempo: ");
        scanf("%lf %lf", &v0, &t);

        printf("S = %lf m\n", (v0*t) + (-g * (int)pow(t, 2))/2);
    } */

    /*4) Leia um valor em reais e a cotação do dólar. Em seguida, imprima o valor correspondente em dólares.
    int main(void)
    {

        double r,cd;
        printf("Digite o valor em reais e a cotacao do dolar: ");
        scanf("%lf %lf", &r, &cd);

        printf("O valor correspondente em dolares é U$ %.2lf\n", r/cd);

    }*/

    /*Exercício extra: Leia o Valor em graus celsius ou em Farenheit 
    e converta para celsius ou farenheit dependendo da escolha do Usuaŕio

    int main(void)
    {
        double T;
        char scl;

        printf("Digite o sistema de temperatura desejado(C ou F) e a temperatura nesse sistema: ");
        scanf("%c %lf", &scl, &T);

        if (scl == 'C')
        {
            double F = 1.8*T + 32;

            printf("A temperatura em Farenheit é %.1lf F\n", F);
        } else if (scl == 'F')
        {
            double C = (T - 32)/1.8;
            printf("A temperatura em Celsius é %.1lf °C\n", C);
        }
    } */

    /*5) Leia uma velocidade em m/s (metros por segundo) e apresente-a convertida em km/h (quilômetros por
    hora). A fórmula de conversão é: K = M * 3.6, sendo K a velocidade em km/h e M em m/s.*/
    /*int main(void)
    {
        double v;

        printf("Digite a velocidade em m/s: ");
        scanf("%lf", &v);

        printf("%.2lf km/h\n", v*3.6);



    }*/

    /*6) Leia quatro notas, calcule a média aritmética e imprima o resultado

    int main(void)
    {
        double v[4];
        double soma = 0;

        printf("Digite 4 notas: ");

        for(int i = 0; i < 4; i++)
        {
            scanf("%lf", &v[i]);
        }

        for (int i = 0; i < 4; i++)
        {
            soma += v[i];
        }

        printf("A media eh %.1lf\n", soma/4);
    } */

    /*Exercicio extra: Leia tres notas e seus respectivos pesos
        Calcule a media ponderada

        int main(void)
        {
            double n[3], p[3], soma = 0, somap = 0;

            printf("Digite tres notas e seus pesos respectivos: ");

            for (int i = 0; i < 3; i++)
            {
                scanf("%lf %lf", &n[i], &p[i]);
            }

            for (int i = 0; i < 3; i++)
            {
                soma += n[i]*p[i];
                somap += p[i];
            }

            printf("A media ponderada sera %.1lf\n", soma/somap);
        }*/

        /*7) Efetue a leitura de três valores e apresente como resultado a soma dos quadrados dos três valores lidos


        int main(void)
        {
            int v[3], soma = 0;

            printf("Digite tres numeros: ");

            for (int i = 0; i < 3; i++)
            {
                scanf("%d", &v[i]);
            }

            for (int i = 0; i < 3; i++)
            {
                soma += (int)pow(v[i], 2);
            }

            printf("A soma dos quadrados é %d\n", soma);
        }*/

    
    /*11) Escreva um programa C que leia os catetos de um triângulo retângulo e calcule sua hipotenusa
    int main(void)
    {
        double a, b, c;

        printf("Digite os catetos: ");
        scanf("%lf %lf", &a, &b);

        c = sqrt(pow(a,2) + pow(b,2));

        printf("A hipotenusa é %.1lf\n", c);
    }*/

    /*8) Leia um número inteiro e imprima o seu antecessor e o seu sucessor

    int main(void)
    {
        int w;
        printf("Digite um numero inteiro: ");
        scanf("%d", &w);
        printf("Antecessor = %d\nSucessor = %d\n", w -1, w+1);
    }*/

    /*9) Leia um número inteiro e imprima a soma do sucessor de seu triplo com o antecessor de seu dobro.

    int main(void)
    {
        int i;
        printf("Digite um numero: ");
        scanf("%d", &i);

        int soma = (3*i+1) + (2*i-1);

        printf("SOMA = %d\n", soma);
    }*/

    /*10) Leia o tamanho do lado de um quadrado e imprima como resultado a área do quadrado.

    int main(void)
    {
        double l;
        printf("Digite o lado do quadrado: ");
        scanf("%lf", &l);

        printf("A = %.1lf m²\n", pow(l, 2));
    }*/

    /*12) Faça um programa que leia o valor de um produto e imprima esse valor com um desconto de 15%.

    int main(void)
    {
        double a;
        printf("Digite o valor do produto: ");
        scanf("%lf", &a);

        printf("Valor a pagar com desconto de 15 %% R$ %.2lf\n", a - (a*0.15));
    }*/

    /*13) Leia o salário de um funcionário, calcule e imprima o valor do novo salário sabendo que ele recebeu
um aumento de 25%.

    int main(void)
    {
        double s;
        printf("Digite o seu salario: ");
        scanf("%lf", &s);

        printf("Novo salario com acrescimo de 25 %% R$ %.2lf\n", s + (s*0.25));
    }*/

   /*14) Uma empresa contrata um encanador a R$ 30,00 por dia. Crie um programa que solicite o número de
dias trabalhados pelo encanador e imprima a quantia líquida que deverá ser paga, sabendo-se que são
descontados 7.5% para imposto de renda.

    int main(void)
    {
        int d;
        printf("Digite os dias trabalhados: ");
        scanf("%d", &d);

        double s = 30*d;

        printf("Valor liquido = R$ %.2lf\n", s - (0.075*s));
    }*/

    /*15) Receba a altura do degrau de uma escada e a altura que se deseja subir. Calcule e imprima quantos
degraus são necessários para subir a escada toda.

    int main(void)
    {
        double a, h;
        printf("Digite a altura dos degraus e a altura que pretende subir: ");
        scanf("%lf %lf", &a, &h);

        printf("Os degraus necessarios para subir sao %d\n", (int)(h/a));
    }*/

    /*16) Leia um valor inteiro em segundos e imprima-o em horas, minutos e segundos.

    int main(void)
    {
        int s;
        printf("Digite um valor em segundos: ");
        scanf("%d", &s);

        printf("%d : %d : %d\n", s/3600, (s%3600)/60, (s%3600)%60);
    }*/

    /*exercico extra: escrevav um programa que imprima "VocÊ ainda é jovem" se idade for menor que 30 anos

    int main(void)
    {
        int idade;
        printf("Digite a sua idade: ");
        scanf("%d", &idade);

        if (idade < 30)
        {
            printf("Voce ainda eh jovem!\n");
        }
    }*/
    /*
    int main(void)
    {
        int i;

        printf("Digite um numero: ");
        scanf("%d", &i);

        if (i >= 0)
        {
            printf("%lf\n", pow(i, 0.5));
        } else{
            printf("%lf*i\n", pow(abs(i), 0.5));
        }

    }*/

    /*

    int main(void)
    {
        char c;
        int h;


        printf("C - carro\nO - onibus\nM - Caminhao\n\nDigite o codigo do seu veiculo: ");
        scanf("%c", &c);

        printf("Quantas horas o veiculo ficou estacinado: ");
        scanf("%d", &h);

        switch(c)
        {
            case 'C':
                printf("R$ %.2lf\n", h*2.0);
                break;
            case 'O':
                printf("R$ %.2lf\n", h*3.0);
                break;
            case 'M':
                printf("R$ %.2lf\n", h*4.0);
                break;
            default:
                printf("Essa letra nao representa nenhum veiculo\n");
                break;
            

        }
    }*/

    /*

    int main(void)
    {
        double peso, altura;
        printf("Digite o valor peso e altura, respectivamente: ");
        scanf("%lf %lf", &peso, &altura);

        if (altura < 1.2)
        {
            if (peso <= 60)
            {
                printf("Grupo A\n");
            } else if (peso > 60 && peso <= 90)
            {
                printf("Grupo B\n");
            } else if (peso > 90)
            {
                printf("Grupo C\n");
            }
        } else if (altura >= 1.2 && altura <= 1.7)
        {
            if (peso <= 60)
            {
                printf("Grupo D\n");
            } else if (peso > 60 && peso <= 90)
            {
                printf("Grupo E\n");
            } else if (peso > 90)
            {
                printf("Grupo F\n");
            }
        } else if (altura > 1.7)
        {
            if (peso <= 60)
            {
                printf("Grupo G\n");
            } else if (peso > 60 && peso <= 90)
            {
                printf("Grupo H\n");
            } else if (peso > 90)
            {
                printf("Grupo I\n");
            }
        }
    }*/

    /*17) Três amigos jogaram na loteria. O valor da aposta foi de R$40,00, sendo que o primeiro amigo
contribuiu com R$20,00 reais, o segundo com R$15,00 e o terceiro com R$5,00. Caso eles ganhem o
prêmio de R$27.000.000,00, concordaram em repartí-lo proporcionalmente ao valor da aposta pago
por cada um. Faça uma programa que calcule e imprima a parte do prêmio a que cada amigo tem
direito.

    int main(void)
    {
        double premio = 27*pow(10,6);

        printf("Amigo 1 R$ %.2lf\namigo 2 R$ %.2lf\nAmigo 3 R$ %.2lf\n", (20/40.0)*premio, (15/40.0)*premio, (5/40.0)*premio);
    }*/

    /*18) Leia o valor de um ângulo em graus e apresente-o convertido em radianos. A fórmula de conversão é:
R = G * π/180, sendo G o ângulo em graus, R o valor em radianos e π = 3.14.

    int main(void)
    {
        const double pi = 3.14;
        double grau;
        printf("Digite o angulo em graus: ");
        scanf("%lf", &grau);

        printf("%lf rad\n", grau*pi/180);

        
    }*/

    /*19) Faça um programa para ler as dimensões de um terreno (comprimento C e largura L), bem como o
preço do metro do arame, P. Calcule e imprima o custo para cercar o terreno com uma cerca de 5 fios

    int main(void)
    {
        double l, c, p;

        printf("Digite a largura, o comprimento e o preco do arame: ");
        scanf("%lf %lf %lf", &l, &c, &p);

        p *= 5;

        printf("O preco do arame fica R$ %.2lf\n", (2*l+2*c)*p);
    }*/

    /*20) Implemente um programa em C que calcule o ano de nascimento de uma pessoa a partir de sua idade
e do ano atual.

    int main(void)
    {
        int idade, ano;

        printf("Digite sua idade e o ano atual: ");
        scanf("%d %d", &idade, &ano);

        printf("Voce nasceu em %d\n", ano - idade);
    }*/

    /*21) Leia um número real. Se o número lido for positivo, imprima a raiz quadrada; se for negativo, imprima o
número ao quadrado.

    int main(void)
    {
        double i;

        printf("Digite um numero: ");
        scanf("%lf", &i);

        if (i > 0)
        {
            i = pow(i,0.5);
        } else if (i < 0)
        {
            i = pow(i, 2);
        }

        printf("%lf\n", i);
    }*/

    /*22) Determine se um determinado ano lido é bissexto. Um ano é bissexto se for divisível por 400, ou se for
divisível por 4 e não for divisível por 100. Por exemplo: 1988, 1992, 1996.

    int main(void)
    {
        int ano;
        printf("Digite um ano: ");
        scanf("%d", &ano);

        if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
        {
            printf("Eh bissexto\n");
        } else 
        {
            printf("Nao eh bissexto\n");

        }
    }*/

    /*23) Receba o valor do salário de um trabalhador e o valor da prestação de um empréstimo. Se a prestação
for maior que 30% do salário, imprima “Emprestimo nao concedido”. Caso contrário, imprima
“Emprestimo concedido”.

    int main(void)
    {
        double sal, emp;
        printf("Digite o salario do trabalhador e o valor de um emprestimo: ");
        scanf("%lf %lf", &sal, &emp);

        if (emp > 0.3*sal)
        {
            printf("Emprestimo nao concedido\n");
        } else if (emp <= 0.3*sal)
        {
            printf("Emprestimo concedido\n");
        }
    }*/

    /*24) Faça um programa que receba um número inteiro e verifique se este número é par ou ímpar

    int main(void)
    {
        int a;

        printf("Digite um numero: ");
        scanf("%d", &a);

        if (a % 2 == 0)
        {
            printf("eh par\n");
        } else
        {
            printf("eh impar\n");
        }
    }*/

    /*25) Dados três valores, A, B e C, verificar se eles podem ser valores dos lados de um triângulo e, se forem,
qual é o tipo do triângulo (equilátero, isósceles ou escaleno), considerando os seguintes conceitos:
 O comprimento de cada lado de um triângulo é menor do que a soma dos outros dois lados.
 Chama-se equilátero o triângulo que tem três lados iguais.
 Denominam-se isósceles o triângulo que tem o comprimento de dois lados iguais.
 Recebe o nome de escaleno o triângulo que tem os três lados diferentes.

    int main(void)
    {
        double a, b, c;

        printf("Digite os lados de um triangulo: ");
        scanf("%lf %lf %lf", &a, &b, &c);

        if (a >= b + c || b >= a + c || c >= a + b)
        {
            printf("Os lados nao formam um triangulo\n");

        } else 
        {
            if (a == b && b == c)
            {
                printf("Triangulo Equilatero\n");
            } else if (a == b ^ b == c ^ c == a)
            {
                printf("Triangulo Isoceles\n");
            }else
            {
                printf("Triangulo escaleno\n");
            }
        }
    }*/

    /*26) Usando switch, escreva um programa que leia um inteiro entre 1 e 7 e imprima o dia da semana
correspondente a este numero. Isto é: domingo, se 1; segunda-feira, se 2; e assim por diante.

    int main(void)
    {
        int dia;

        printf("Digite um numero de 1 a 7: ");
        scanf("%d", &dia);

        switch (dia)
        {
        case 1:
            printf("Domingo\n");
            break;
        case 2:
            printf("Segunda-feira\n");
            break;
        case 3:
            printf("Terca-feira\n");
            break;
        case 4:
            printf("Quarta-feira\n");
            break;
        case 5:
            printf("Quinta-feira\n");
            break;
        case 6:
            printf("Sexta-feira\n");
            break;
        case 7:
            printf("Sabado\n");
            break;
        
        default:
            printf("O valor nao esta de 1 a 7\n");
            break;
        }
    }*/

    /*27) Faça um programa para verificar se um determinado número inteiro é divisível por 3 ou 5, mas não
simultaneamente pelos dois.

    int main(void)
    {
        int a;

        printf("Digite um numero: ");
        scanf("%d", &a);

        if (a % 3 == 0 ^ a % 5 == 0)
        {
            if (a % 3 == 0)
            {
                printf("O numero eh divisivel somente por 3\n");
            } else 
            {
                printf("O numero eh divisivel somente por 5\n");
            }

        } else 
        {
            if (a % 3 == 0 && a % 5 == 0)
            {
                printf("O numero eh divisivel por 3 e 5\n");
            } else 
            {
                printf("O numero nao eh divisivel nem por 5 nem por 3\n");
            }
        }
    }*/

    /*Escreva o menu de opções, como no exemplo abaixo. Leia a opção do usuário, em seguida leia 2
números reais e execute a operação escolhida sobre eles. (Escreva uma mensagem de erro se a
opção for inválida.)

    int main(void)
    {
        int a, b, c;
        double r;
        printf("Escolha a opcao:\n1- Soma de 2 numeros.\n2- Diferenca entre 2 numeros.\n3- Produto entre 2 numeros.\n4- Divisao entre 2 numeros (detalhe: o denominador não pode ser zero).\nOpcao: ");
        scanf("%d", &a);

        

        if (a > 0 && a <= 4)
        {
            printf("Digite o primeiro número: ");
            scanf("%d", &b);
            printf("Digite o segundo número: ");
            scanf("%d", &c);
            
            if (a == 1)
            {
                r = b + c;
            } else if (a == 2)
            {
                r = b - c;
            } else if (a == 3)
            {
                r = b*c;
            } else if (a == 4)
            {
                r = b/(double)c;
            }

            printf("Resultado = %lf\n", r);
        } else 
        {
            printf("O valor informado de operador aritimetico eh invalido\n");
        }
    }*/

    /*29) Uma empresa vende o mesmo produto para quatro diferentes estados. Cada estado possui uma taxa
diferente de imposto sobre o produto (MG 7%; SP 12%; RJ 15%; MS 8%). Faça um programa em que
o usuário entre com o valor e o estado destino do produto e o programa retorne o preço final do
produto acrescido do imposto do estado em que ele será vendido. Se o estado digitado não for válido,
mostrar uma mensagem de erro.

    int main(void)
    {
        char uf[3];
        double valor;

        printf("Digite a UF(MG,SP,RJ,MS) e o valor do produto: ");
        scanf("%s %lf", uf, &valor);

        if (!strcmp(uf, "MG") || !strcmp(uf, "SP") || !strcmp(uf, "RJ") || !strcmp(uf, "MS"))
        {
            if (!strcmp(uf, "MG"))
            {
                valor += (valor*0.07);
            } else if(!strcmp(uf, "SP"))
            {
                valor += (valor*0.12);
            } else if(!strcmp(uf, "RJ"))
            {
                valor += (valor*0.15);
            } else if (!strcmp(uf, "MS"))
            {
                valor += (valor*0.08);
            }

            printf("R$ %.2lf\n", valor);
        } else 
        {
            printf("Esse estado digitado não se encontra no sistema\n");
        }
    }*/

    /*30) Escreva um programa que leia o código do produto escolhido no cardápio de uma lanchonete e sua
quantidade. Assim, o programa deve calcular o valor a ser pago por aquele lanche. Considere que a
cada execução somente será calculado um pedido. O cardápio da lanchonete segue a tabela a seguir:

    int main(void)
    {
        int cod,qnt;
        double valor;

        printf("Digite o cod do produto e a quantidade desejada: ");
        scanf("%d %d", &cod, &qnt);

        switch (cod)
        {
        case 100:
            valor = 1.2;
            break;
        case 101:
            valor = 1.3;
            break;
        case 102:
            valor = 1.5;
            break;
        case 103:
            valor = 1.2;
            break;
        case 104:
            valor = 1.7;
            break;
        case 105:
            valor = 2.2;
            break;
        case 106:
            valor = 1;
            break;
        
        default:
            printf("Codigo invalido\n");
            break;
        }

        printf("Total = R$ %.2lf\n", valor*qnt);
    }*/

    /*31) Escreva um programa que leia um número inteiro positivo e imprima os 5 primeiros múltiplos de 3
desse número.

    int main(void)
    {
        int a, cont = 5 ;

        printf("Digite um numero: ");
        scanf("%d", &a);


        if (a % 3 == 1)
        {
            a += 2;
        } else if (a % 3 == 2)
        {
            a += 1;
        }

        while (cont > 0)
        {
            printf("%d\n", a);

            a+=3;
            cont--;
        }
    }*/

    /*32) Escreva um programa que faça a leitura de vários números inteiros, até que se digite um número
negativo. O programa tem que retornar o maior e o menor número lido.

    int main(void)
    {
        int a;

        printf("Digite um numero: ");
        scanf("%d", &a);

        int maior = a, menor = a;
        
        while (a >= 0)
        {
            printf("Digite um numero: ");
            scanf("%d", &a);
            if (menor > a && a >= 0)
            {
                menor = a;

            }
            if (maior < a)
            {
                maior = a;
            }
        }

        printf("O maior numero eh %d\nO menor numero eh %d\n", maior, menor);
    }*/

    /*33) Faça um programa que leia 10 inteiros e imprima sua média

    int main(void)
    {
        int a, soma;

        printf("Digite 10 notas: ");

        for(int i = 0; i < 10; i++)
        {
            scanf("%d", &a);

            soma += a;
        }

        printf("Media = %lf\n", soma/10.0);
    }*/

   /*34) Faça um programa que calcule e mostre a soma dos 50 primeiros números pares.

    int main(void)
    {
        int soma = 0;

        for(int i = 0; i <= 50; i += 2)
        {
            soma += i;
        }

        printf("%d\n", soma);
    }*/


    /*35) Faça um algoritmo que leia um número positivo e imprima seus divisores

    int main(void)
    {
        int a;

        printf("Digite um numero: ");
        scanf("%d", &a);

        printf("Sao divisores desse numero: ");
        for (int i = 1; i <= a; i++)
        {
            if (a % i == 0)
            {
                printf("%d%c", i, (i == a) ? '\n' : ' ');
            }
        }
    }*/

    /*36) Faça um programa que peça ao usuário para digitar 10 valores e some-os

    int main(void)
    {
        double a, soma;

        printf("Digite 10 notas: ");

        for(int i = 0; i < 10; i++)
        {
            scanf("%lf", &a);

            soma += a;
        }

        printf("Soma = %.0lf\n", soma);
    }*/

    /*37) Alan e Bob são colegas de trabalho. Alan recebe um salário de R$3.000,00, enquanto Bob recebe um
salário de R$2.000,00. Todo mês, Alan aplica metade de seu salário numa caderneta de poupança,
que rende 0,39% ao mês, enquanto Bob aplica metade de seu salário em um fundo de ações que lhe
rende 5% ao mês. Construa um programa que calcule a quantidade de meses necessários para que o
valor pertencente a Bob iguale ou ultrapasse o valor pertencente a Alan.

//Investmentos foncionam da seguinte forma a porcentagem de rendimento vezes o valor guardado
//ou seja, s*(1+rendimento)+valor adicinado emnsalmente

    int main(void)
    {
        double s1 = 1500, s2 = 1000;
        int cont = 0;

        while (s1 > s2)
        {
            s1 = s1*(1+0.0039) + 1500;
            s2 = s2*(1+0.05) + 1000;

            cont++;
        } 

        printf("Serao necessario %d meses para que o valor de Bob se iguale ou ultrapasse o de Alan\n", cont);
    }*/

    /*38) Faça um programa que leia 10 inteiros positivos, ignorando não positivos, e imprima sua média.

    int main(void)
    {
        int a, sum = 0;

        for (int i = 0; i < 10;)
        {
            scanf("%d", &a);

            if (a >= 0)
            {
                sum += a;
                i++;
            }
        }

        printf("A media eh %lf\n", sum/10.0);
    }*/