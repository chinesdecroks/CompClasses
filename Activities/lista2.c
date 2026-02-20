#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*1) Escreva um programa C que:
a. Crie um arquivo texto de nome “arq.txt”.
b. Permita que o usuário entre com diversos caracteres nesse arquivo, até que seja digitado
ENTER.
c. Feche o arquivo
int main(void)
{
    char phrase[500000];

    printf("Digite um paragrafo:\n");
    fgets(phrase, sizeof(phrase), stdin);
    FILE *f;
    f = fopen("arq.txt", "a+");
    if (f == NULL)
    {
        printf("Erro na abertura/criacao do programa\n");
        exit(1);
    }

    fputs(phrase, f);


    fclose(f);
}*/

/*2) Abra e leia o arquivo criado no exercício anterior, caractere por caractere, e escreva na tela todos os
caracteres.

int main(void)
{
    char phrase[500000];

    FILE *f;

    f = fopen("arq.txt", "r");

    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    if (fgets(phrase, sizeof(phrase), f) != NULL)
    {
        printf("%s", phrase);
    }

    fclose(f);
}*/

    /*3) Faça um programa C que leia um arquivo texto e mostre na tela quantas letras são vogais e quantas
são consoantes

int main(void)
{
    int v = 0, c = 0;
    FILE *f;
    char texto[1000];
    char arquivo[1000];

    printf("Digite o nome do arquivo:\n");
    scanf("%s", arquivo);
    

    f = fopen(arquivo, "r");
    if (f == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    fgets(texto, sizeof(texto), f);

    fclose(f);

    for (int i = 0; texto[i] != '\0'; i++)
    {
        if ((texto[i] >= 'A' && texto[i] <= 'Z') || (texto[i] >= 'a' && texto[i] <= 'z'))
        {
            if (texto[i] == 'A' || texto[i] == 'a' ||
                texto[i] == 'E' || texto[i] == 'e' || 
                texto[i] == 'I' || texto[i] == 'i' || 
                texto[i] == 'O' || texto[i] == 'o' || 
                texto[i] == 'U' || texto[i] == 'u')
            {
                v++;
            } else
            {
                c++;
            }
        }
    }

    printf("O numero de vogais desse arquivo eh %d, enquanto o numero de consoantes eh %d\n", v, c);
}*/

/*4) Escreva um programa C para gerar em um arquivo as tabuadas de 1 a 10.

int main(void)
{
    FILE *f;
    f = fopen("arq.txt", "w");
    if (f == NULL)
    {
        printf("Erro na abertura/criacao do arquivo\n");
        exit(1);

    }

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            fprintf(f, "%d X %d = %d\n", i,j,i*j);
        }
    }

    fclose(f);
}*/

/*5) Faça um programa que crie e imprima uma matriz identidade 4x4 em um arquivo.

int main(void)
{
    FILE *f;
    f = fopen("arq.txt", "w");
    if (f == NULL)
    {
        printf("Erro na abertura/criacao do arquivo\n");
        exit(1);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
            {
                fprintf(f, "1%c", (j == 3) ? '\n' : ' ');
            } else
            {
                fprintf(f, "0%c", (j == 3) ? '\n' : ' ');
            }
        }
    }

    fclose(f);
}*/

/*6) Implemente um programa que leia o nome, a idade e o endereço de uma pessoa e armazene os dados
em uma estrutura.

typedef struct Pessoa
{
    char nome[100];
    int idade;
    char endereco[1000];
} pessoa;

int main(void)
{
    pessoa p[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Digite o nome, idade e endereco:\n");
        fgets(p[i].nome, sizeof(p[i].nome), stdin);
        scanf("%d", &p[i].idade);
        getchar();
        fgets(p[i].endereco, sizeof(p[i].endereco), stdin);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Cadastro %d:\nNome: %sIdade: %d\nEndereco: %s", i+1, p[i].nome, p[i].idade, p[i].endereco);
    }
}*/

/*7) Utilizando uma estrutura, fazer um programa que permita a entrada de nome, idade e endereço de 5
pessoas e os imprima.

typedef struct Pessoa
{
    char nome[100];
    int idade;
    char endereco[1000];
} pessoa;

int main(void)
{
    pessoa p[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o nome, idade e endereco:\n");
        fgets(p[i].nome, sizeof(p[i].nome), stdin);
        scanf("%d", &p[i].idade);
        getchar();
        fgets(p[i].endereco, sizeof(p[i].endereco), stdin);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Cadastro %d:\nNome: %sIdade: %d\nEndereco: %s", i+1, p[i].nome, p[i].idade, p[i].endereco);
    }
}*/

/*8) Escreva um programa que armazene em um registro de dados (estrutura composta) os dados de um
funcionário de uma empresa, compostos de: Nome, Idade, Sexo (M/F), CPF, Data de Nascimento,
Código do Setor onde trabalha (0-99), Cargo que ocupa (string de até 30 caracteres) e Salário. Os
dados devem ser digitados pelo usuário, armazenados na estrutura e exibidos na tela.

typedef struct Funcionarios
{
    char nome[50];
    int idade;
    char sexo;
    char cpf[14];
    char nasc[10];
    int setor;
    char cargo[30];
    double salario;

}funcio;

int main(void)
{
    funcio p;

    printf("Faca o seu cadastro:\n");
    printf("Nome: ");
    scanf("%[^\n]", p.nome);
    printf("Idade: ");
    scanf("%d", &p.idade);
    getchar();
    printf("Sexo(M/F): ");
    scanf("%c", &p.sexo);
    getchar();
    printf("CPF(***.***.***-**): ");
    scanf("%[^\n]", p.cpf);
    printf("Nascimento(--/--/----): ");
    scanf("%s", p.nasc);
    printf("setor(0-99): ");
    scanf("%d", &p.setor);
    getchar();
    printf("Cargo(Max. 30 caracter): ");
    scanf("%[^\n]", p.cargo);
    printf("Salario: ");
    scanf("%lf", &p.salario);

    if (p.setor > 99 || p.setor < 0)
    {
        printf("Cadrasto falhou. Setor informado não existe\n");
        return 1;
    } else if (p.sexo != 'M' && p.sexo != 'F')
    {
        printf("Campo preenchido incorretamente\n");
        return 1;
    } else {

        printf("\n\nCadastro\n\nNome: %s\nIdade: %d\nSexo: %c\nCPF: %s\nNasc.: %s\nSetor: %d\nCargo: %s\nSalario: R$ %.2lf\n", p.nome, p.idade, p.sexo, p.cpf, p.nasc, p.setor, p.cargo, p.salario);
    
    }
    
}*/

/*9) Construa uma estrutura aluno com nome, número de matrícula e curso. Leia do usuário a informação
de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na tela e em um arquivo .txt

typedef struct Aluno
{
    char nome[50];
    char matricula[12];
    char curso[100];

} aluno;

int main(void)
{
    FILE *f;
    aluno p[5];

    printf("Cadastro dos alunos\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Nome: ");
        scanf("%[^\n]", p[i].nome);
        getchar();
        printf("Numero de Matricula: ");
        scanf("%[^\n]", p[i].matricula);
        getchar();
        printf("Curso: ");
        scanf("%[^\n]", p[i].curso);
        getchar();

    }

    printf("\n\nAlunos cadastrados\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Nome: %s\nMatricula: %s\nCurso: %s\n\n", p[i].nome, p[i].matricula, p[i].curso);
    }

    f = fopen("matricula.txt", "w");
    if (f == NULL)
    {
        printf("Falha no salvamento das informacoes\n");
        exit(1);
    } else 
    {
        printf("Cadastro salvo com sucesso\n");
        
    }

    for (int i = 0; i < 5; i++)
    {
        fprintf(f, "Nome: %s\nMatricula: %s\nCurso: %s\n", p[i].nome, p[i].matricula, p[i].curso);
    }

    fclose(f);

}*/

/*10) Escreva um programa que converta coordenadas polares para cartesianas:
 Crie e leia um ponto em coordenada polar, composto por raio (r) e argumento (a) em radianos.
 Crie outro ponto, agora em coordenada cartesiana, composto por x e y, sabendo que x = r * cos(a)
e y = r * sin(a).
Implemente os pontos em cada tipo de coordenada como duas estruturas. No programa principal, leia
um ponto em coordenada polar e mostre as coordenadas do ponto gerado no plano cartesiano.

typedef struct Polares
{
    double r;
    double rad;
    
} polares;

typedef struct Cartesiana
{
    double x;
    double y;
    
} cart;

int main(void)
{
    
    const double pi = 3.14159265;
    polares p1;
    cart c1;
    
    
    double graus;
    
    
    printf("Informe as cordenadas polares de um ponto(Raio/Angulo em graus):\n");
    scanf("%lf %lf", &p1.r, &graus);
    
    p1.rad = graus * pi/180;
    c1.x = p1.r * cos(p1.rad);
    c1.y = p1.r * sin(p1.rad);
    
    printf("O ponto em coordenadas cartesianas eh X = %.3lf e Y = %.3lf\n", c1.x, c1.y);

    return 0;
}*/

/*11) Escreva um programa com novos tipos de dados abaixo. Em seguida, crie uma instância (i.e., uma
variável) de um compromisso.
 Horário: composto de hora e minuto.
 Data: composto de dia, mês e ano.
 Compromisso: composto de uma data, horário e texto que descreva o compromisso.

typedef struct Horario
{
    int hora;
    int min;
} hor ;

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} dat;

typedef struct Compromisso
{
    hor hours;
    dat date;
    char ocasiao[10000];
    
} comp;

int main(void)
{
    
    comp c;
    
    printf("Digite o horario(hora e min), a data(dia, mes e ano) e um texto que desceve o compromisso:\n");
    scanf("%d %d %d %d %d", &c.hours.hora, &c.hours.min, &c.date.dia, &c.date.mes, &c.date.ano);
    getchar();
    scanf("%[^\n]", c.ocasiao);

    printf("Horario = %d:%d\nDia = %d/%d/%d\nCompromisso:\n%s\n", c.hours.hora, c.hours.min, c.date.dia, c.date.mes, c.date.ano, c.ocasiao);
    return 0;
}*/

/*12) Crie uma estrutura para representar um vetor no R3
, implemente um programa que calcule a soma de
dois vetores.

typedef struct Vetores
{
    double x;
    double y;
    double z;
} vet;

int main(void)
{
    vet v[2], vR = {0,0,0};
    

    printf("Digite dois vetores no R³:\n");

    for(int i = 0; i < 2; i++)
    {
        scanf("%lf %lf %lf", &v[i].x, &v[i].y, &v[i].z);
        vR.x += v[i].x;
        vR.y += v[i].y;
        vR.z += v[i].z;

    }

    printf("O vetor resultante da soma eh (%.1lf %.1lf %.1lf)\n", vR.x, vR.y, vR.z);
}*/

/*13) Crie um programa que leia um vetor com os dados de 5 carros: marca (máximo 15 letras), ano e preço.
Leia um valor p e mostre as informações de todos os carros com preço menor que p. Repita este
processo até que seja lido um valor p = 0.

typedef struct Carro
{
    char marca[15];
    int ano;
    double preco;
} car;


int main(void)
{
    car c[5];
    double p = 1;

    printf("De entrada de 5 carros.\nDeve-se informar a marca, o ano e o preco.\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Carro %d:\n", i+1);
        scanf("%[^\n] %d %lf", c[i].marca, &c[i].ano, &c[i].preco);
        setbuf(stdin, NULL);
    }

    while (p != 0)
    {
        printf("\nBusca por preco:");
        scanf("%lf", &p);

        for (int i = 0; i < 5; i++)
        {
            if (c[i].preco < p)
            {
                printf("\nMarca: %s\nAno: %d\nPreco: R$ %.2lf\n", c[i].marca, c[i].ano, c[i].preco);
            }

        }
    }
}*/

/*14) Crie um programa que leia um vetor com dados de 5 livros: título (máximo de 30 letras), autor (máximo
de 15 letras) e ano. Procure um livro por título, perguntando ao usuário qual título deseja buscar.
Mostre os dados de todos os livros encontrados.

typedef struct Livro
{
    char title[30];
    char author[15];
    int year;
} liv;



int main(void)
{
    liv l[5];
    char p[30];

    printf("De entrada em 5 livros.\nDeve-se informar a o titulo, o/a autor(a) e o ano.\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Livro %d:\n", i+1);
        scanf("%[^\n] %[^\n] %d", l[i].title, l[i].author, &l[i].year);
        setbuf(stdin, NULL);
    }

    
    
        printf("\nBusca por livro escreva o titulo: ");
        scanf("%[^\n]", p);

        for (int i = 0; i < 5; i++)
        {
            if (!strcmp(l[i].title, p))
            {
                printf("\nTitulo: %s\nAutor(a): %s\nAno: %d\n", l[i].title, l[i].author, l[i].year);
                break;
            } else if (i == 4)
            {
                printf("Livro não encontrado\n");
            }

        }
}*/

/*15) Crie um programa que controla o consumo de energia dos eletrodomésticos de uma casa:
 Cadastre 5 eletrodomésticos com nome (máximo 15 letras), potência (real, em kW) e tempo ativo
por dia (real, em horas).
 Leia um tempo t (em dias), calcule e mostre o consumo total na casa e o consumo relativo de cada
eletrodoméstico (consumo/consumo total) nesse período de tempo. Apresente este último dado em
porcentagem.

typedef struct Eletrodomestico
{
    char nome[15];
    double potencia;
    double tempo;
    double c;
    double cr;
} eledom;

int main(void)
{
    eledom e[5];
    int d;
    double ct = 0;

    printf("Indique os 5 eletrodomesticos que mais gastam energia.\nIndique nome, potencia(kW) e tempo em horas ao dia:\n");

    for(int i = 0; i < 5; i++)
    {
        printf("Eletrodom. %d:\n", i+1);
        scanf("%[^\n] %lf %lf", e[i].nome, &e[i].potencia, &e[i].tempo);
        setbuf(stdin, NULL);
    }

    printf("Indique os dias para calcular o gasto de enegia(kWh): ");
    scanf("%d", &d);

    for (int i = 0; i < 5; i++)
    {
        e[i].c = e[i].tempo*e[i].potencia*d;
        ct += e[i].c;
        
            if (i == 4)
            {
                printf("O consumo total eh %.2lf kWh\nConsumo relativo:\n", ct);
                for (int j = 0; j < 5; j++)
                {
                    e[j].cr = e[j].c/ct*100;
                    printf("%s: %.2lf %%\n",e[j].nome, e[j].cr);
                }
            }
    }

    
}*/

/*16) Escreva uma função que receba 2 parâmetros reais, a e b, e retorne (a*(b+3))/(a-b).

double expression(double a, double b);

int main(void)
{
    
    double a, b;
    scanf("%lf %lf", &a, &b);

    printf("%.2lf\n", expression(a, b));
}

double expression(double a, double b)
{
    double r = (a*(b+3))/(a-b);

    return r;
}*/

/*17) Escreva uma função que receba o raio de um círculo como parâmetro de entrada e calcule, como
parâmetros de saída, a área, o perímetro e o diâmetro do círculo

void circulo(double r);

int main(void)
{
    double r;
    scanf("%lf", &r);

    circulo(r);
}

void circulo(double r)
{
    const double pi = 3.14159;
    double d = 2*r;
    double p = d*pi;
    double a = r*r*pi;

    printf("Diametro: %.2lf\nPerimetro: %.2lf\nArea: %.2lf\n", d, p, a);
}*/

/*18) Escreva uma função que receba um número inteiro positivo, n, e calcule o somatório de 1 até n.

void f(int a);

int main(void)
{

    int a;
    scanf("%d", &a);

    f(a);

}

void f(int a)
{
    int s = 0;

    for (int i = 0; i <= a; i++)
    {
        s += i;
    }

    printf("O somatorio de 1 ate o numero %d eh %d\n", a, s);
}*/

/*19) Escreva uma função que receba, como parâmetro, três valores, X, Y e Z, e verifique se seguimentos
de reta com essas medidas podem formar um triângulo (o comprimento de cada lado de um triângulo é
menor do que a soma dos outros dois lados) e, em caso afirmativo, qual o tipo de triângulo. A função
deve retornar:
 0: se não for triângulo.
 1: se for triângulo escaleno (3 lados diferentes).
 2: se for triângulo isósceles (2 lados iguais).
 3: se for triângulo equilátero (3 lados iguais).

void ehtriangulo(int a, int b, int c);

int main(void)
{
    int x,y,z;
    scanf("%d %d %d", &x, &y, &z);

    ehtriangulo(x,y,z);

}

void ehtriangulo(int a, int b, int c)
{
    if (a > b+c || c > a+b || b > a+c)
    {
        printf("Nao forma triangulo\n");
    } else
    {
        if (a == b && b == c)
        {
            printf("Triangulo Equilatero\n");
        } else if (a == b ^ a == c ^ b == c)
        {
            printf("Triangulo Isoceles\n");
        } else 
        {
            printf("Triangulo escaleno\n");
        }
    }
}*/

/*20) Escreva um programa C que crie um vetor de 5 inteiros, uma função que calcule a soma de seus
elementos e outra função que imprima o vetor.

int somaVetor(int v[]);
int mostraVetor (int v[]);

int main(void)
{
    int v[5] = {1,2,3,4,5};
    int s = somaVetor(v);
    
    mostraVetor(v);

    printf("A soma dos elementos do vetor eh %d\n", s);
    
}

int somaVetor(int v[])
{
    int s = 0;

    for(int i = 0; i < 5; i++)
    {
        s += v[i];
    }

    return s;
}

int mostraVetor (int v[])
{
    for (int i = 0; i < 5; i++)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }
}
*/

/*21) Escreva uma função que receba 2 argumentos e troque seus valores

void troca(int *a, int *b);

int main(void)
{
    int a = 3, b = 2;

    troca(&a, &b);

    printf("%d %d\n", a, b);
}

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}*/

/*22) Escreva uma função recursiva que receba um número inteiro positivo, n, e calcule o somatório de 1 até n.

int f(int a);

int main(void)
{
	int a = 5;
	printf("A soma dos valores de 1 ate %d eh %d\n", a, f(a));
}

int f(int a)
{
	if (a == 1 || a == 0)
	{
		return 1;
	}

	return a + f(a - 1);
	
	
}*/

/*23) Reescreva o exercício 20 para trabalhar com vetores de qualquer tamanho.

int somaVetor(int v[], int a);
int mostraVetor (int v[], int a);

int main(void)
{
    int n;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);
    int v[n];
    printf("Digite os valores do vetor:\n");

    for (int i = 0; i < n; i++)
    {
	scanf("%d", &v[i]);
    }

    int s = somaVetor(v, n);
    
    mostraVetor(v, n);

    printf("A soma dos elementos do vetor eh %d\n", s);
    
}

int somaVetor(int v[], int a)
{
    int s = 0;

    for(int i = 0; i < a; i++)
    {
        s += v[i];
    }

    return s;
}

int mostraVetor (int v[], int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }
}*/

/*24) Escreva uma função que calcule a Sequência de Fibonacci, F, para um parâmetro n fornecido pelo 
usuário

int fib(int a);

int main(void)
{
	int a;
	scanf("%d", &a);
	printf("A sequencia de fibonnaci ate %d termo\n", a);

	for (int i = 0; i <= a; i++)
	{
		printf("%d%c", fib(i), (i == a) ? '\n' : ' ');
	} 	
}

int fib(int a)
{
	if (a == 0)
	{
		return 0;
	}
	if (a == 1)
	{
		return 1;
	}

	return (fib(a - 1) + fib(a - 2));
}*/

/*25) O número de controle de um CPF (seus 2 últimos dígitos verificadores, DV1 e DV2), são calculados da 
seguinte forma (considerando os primeiros 9 dígitos do CPF): 
a. Etapa 1: cálculo de DV1 
	i. Soma1: soma dos produtos de cada dígito por um peso de 2 a 10, na ordem inversa 
	   (do nono para o primeiro dígito). 
	ii. Multiplique a Soma1 por 10 e calcule o resto da divisão do resultado por 11. Se der 
	    10, DV1 é zero; caso contrário, o DV1 é o próprio resto. 
b. Etapa 2: cálculo de DV2 
	i. Soma2: soma dos produtos de cada dígito por um peso de 3 a 11, também na ordem 
	inversa. 
	ii. Adicione a Soma2 ao dobro do DV1, multiplique por 10 e calcule o resto da divisão 
	do resultado por 11. Se der 10, DV2, é zero; caso contrário o DV2 é o próprio resto. 
c. Etapa 3: Multiplique DV1 por 10, some com DV2 e você terá o número de controle do CPF. 

int dv1(int v[]);
int dv2(int v[]);

int main(void)
{
    int v[9];
    printf("Digite 9 primeiros digitos do CPF:\n");
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &v[i]);
    }

    int dv = dv1(v)*10 + dv2(v);

    printf("O digito verificador desses 9 digitos eh %d\n", dv);
	
}

int dv1(int v[])
{
    int a = 2, soma = 0;

    for (int i = 8; i >= 0; i--)
    {
        soma += a*v[i];
        a++;
    }

    soma *= 10;

    if (soma % 11 == 10)
    {
        return 0;
    } else 
    {
        return soma % 11;
    }
	
}

int dv2 (int v[])
{
   int a = 3, soma = 0, v1 = dv1(v);

    for (int i = 8; i >= 0; i--)
    {
        soma += a*v[i];
        a++;
    } 

    soma += 2*v1;
    soma *= 10;

    if (soma % 11 == 10)
    {
        return 0;
    } else 
    {
        return soma % 11;
    }
}*/

/*26) Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char.
Associe variáveis aos ponteiros (use &). Modifique os valores de cada variável usando os ponteiros.
Imprima os valores das variáveis antes e após a modificação.

int main(void)
{
    int a = 7, *p1 = &a;
    double b = 8.989888, *p2 = &b;
    char c = 'a', *p3 = &c;

    printf("%d, %lf, %c\n", a, b, c);

    *p1 += 10*9;
    *p2 += 0.010112;
    *p3 += 2;

    printf("%d, %lf, %c\n", a, b, c);
}*/

/*27) Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do teclado. Em
seguida, compare seus endereços e exiba o conteúdo do maior endereço.

int main(void)
{
    int a, *p1 = &a, b, *p2 = &b;

    scanf("%d %d", &a, &b);

    printf("a = %d e b = %d\n", &a, &b);

    if (*p1 > *p2)
    {
        printf("O endereco %d cujo conteudo eh %d eh maior\n", p1, *p1);
    } else if (*p1 < *p2)
    {
        printf("O endereco %d cujo conteudo eh %d eh maior\n", p2, *p2);
    } else 
    {
        printf("O endereco %d e %d possuem o mesmo conteudo que eh %d\n", p1, p2, *p1);
        
    }

*/

/*28) Faça um programa que leia três valores inteiros e chame uma função que receba estes 3 valores de
entrada e os retorne ordenados, ou seja, o menor valor na primeira variável, o segundo menor valor na
variável do meio, e o maior valor na última variável. A função deve retornar o valor 1 se os três valores
forem iguais e 0 se existirem valores diferentes. Exibir os valores ordenados na tela
OBS: A função ord segue o principio Bubble sort de ordenacao


void troca(int *a, int *b);
void ord(int v[], int n);

int main(void)
{
    int v[3];

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &v[i]);
    }

    ord(v, 3);

    for (int i = 0; i < 3; i++)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }

}

void troca (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}

void ord(int v[], int n)
{
    int trocado;
    int a = 0;
    do
    {
        trocado = 0;
        a++;

        for (int i = 0; i < n-a; i++)
        {
            if (v[i] > v[i+1])
            {
                troca(&v[i], &v[i+1]);
                trocado = 1;
            }
        }
    } while (trocado);
    
}*/

/*29) Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereço de
cada posição desse array.

int main(void)
{

    float v[10], *p = v;

    printf("Endereco de memoria das posicoes da array:\n");

    for (int i = 0; i < 10; i++)
    {
        printf("v[%d] = %d\n",i, p+i);
    }


}*/

/*30) Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando apenas
aritmética de ponteiros, leia esse array do teclado e imprima o dobro de cada valor lido.

int main(void)
{
    int v[5], *p = v;

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", p+i);

        if (i == 4)
        {
            for(int j = 0; j < 5; j++)
            {
                printf("v[%d] = %d\n", j, (*(p+j))*2);
            }
        }
    }

}*/

/*31) O que o programa abaixo imprime? O ++ incrementa o ptr, ou seja, ele vai para enderecos de memoria vizinhos sendo semelhante a fazer ptr += 1,
Alem disso o ++ esta apos o ptr, assim ocorre um pos incremento, sendo dessa forma possivel expressar o vetor vet

void main(void) 
{
    int vet[] = {4, 9, 12};
    int i,*ptr;
    ptr = vet;
    for (i = 0; i < 3; i++) 
    {
        printf("%d ",*ptr++);
    }
}*/

/*Faca uma funcao quer receba n inteiro e calcule o somatorio de 1 ate n

int soma(int n);

int main(void)
{
    int n = 5,  a = soma(n);
    printf("A soma de 1 ate %d eh %d\n", n, a);
}

int soma(int n)
{
    int a = 0;
    for (int i = 0; i <= n; i++)
    {
        a += i;
    }

    return a;
}*/

/*Função que verifica se o numero eh par

int ehPar(int n);

int main(void)
{
    if (ehPar(8))
        printf("Eh Par\n");
    else 
        printf("Eh impar\n");
    
}

int ehPar(int n)
{
    if (n % 2 == 0)
     return 1;
    else 
     return 0;
}*/

/*Crie uma funcao que inverte os numeros

double inv(long a);

int main(void)
{
    long a = 123456677;
    double b = inv(a);
    printf("%.0lf\n", b);
}

double inv(long a)
{
    long b = a, cont = -1;
    double soma = 0;
    while (a != 0)
    {
        a /= 10;
        cont++;

    }

    for (int i = cont; i >= 0; i--)
    {
        soma += (b%10)*pow(10.0, i);
        b /= 10;
    }

    return soma;

}*/

/*Criar uma funcao media de um vetor

float media(int v[], int tamanho);

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    float b = media(a, 5);

    printf("A media dos valores do vetor = %.2f\n", b);

}

float media(int *v, int tamanho)
{
    float sum = 0;

    for (int i = 0; i < tamanho; i++)
    {
        sum += *(v+i);
    }

    return sum/tamanho;
}*/

/*Função para verificar número primo
int ehPrimo(int n);

int main(void)
{
    int a;
    scanf("%d", &a);
    if (ehPrimo(a))
    {
        printf("Eh primo\n");
    } else 
    {
        printf("Nao eh primo");
    }
}

int ehPrimo(int n)
{
    int cont = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cont++;
        }

        if (cont > 3)
        {
            break;
        }
    }

    if (cont == 2)
        return 1;
    else 
        return 0;
}*/

/*Faça uma funcao que calcula o MDC(Maximo Divisor Comum)

int mdc(int a, int b);

int main(void)
{

    int b, a;
    scanf("%d %d", &a, &b);
    printf("O MDC de %d e %d = %d\n", a, b, mdc(a, b));

}

int mdc(int a, int b)
{
    int m, d;
    if (a >= b)
        m = a;
    else 
        m = b;

    for (int i = 1; i <= m; i++)
    {
        if (a % i == 0 && b % i == 0)
            d = i;
        
    }

    return d;
}*/

/*Crie uma função que ordene dois numeros

void ordenar(int *a, int *b);

int main(void)
{
    int a = 1, b = 7;

    printf("Desordenado: %d, %d\n", a, b);
    ordenar(&a, &b);
    printf("Ordenado: %d, %d\n", a, b);

}

void troca (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenar(int *a, int *b)
{  
    if (*a >= *b)
        troca(a, b);

}*/


