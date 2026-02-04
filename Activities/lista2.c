#include <stdio.h>
#include <stdlib.h>

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
de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na tela e em um arquivo .txt*/

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

}