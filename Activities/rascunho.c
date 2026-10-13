#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500
/*void maior_menor (int *v, int tam, int *maior, int *menor)
{
    *maior = v[0];
    *menor = v[0];

    for (int i = 1; i < tam; i++)
    {
        if (*menor > v[i])
            *menor = v[i];

         if (*maior < v[i])
            *maior = v[i];
           
    }
}

struct Produto {
    char nome[20], descricao[20], categoria[20];
    float preco; 
};

void X (struct Produto p[], int *n, struct Produto p1) {
    p[*n] = p1;
    (*n)++;
}

int main(void)
{
    int v[5] = {144,21,3789,4,-8}, maior, menor;

    maior_menor(v, 5, &maior, &menor);

    printf("%d %d\n", maior, menor);
    

    struct Produto p[5], p1;
    int n = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Digite nome: ");
        scanf("%[^\n]", p1.nome);
        getchar();

        printf("Digite categoria: ");
        scanf("%[^\n]", p1.categoria);
        getchar();

        printf("Digite Descricao: ");
        scanf("%[^\n]", p1.descricao);
        getchar();

        printf("Digite preco: ");
        scanf("%f", &p1.preco);
        getchar();

        X(p, &n, p1);

        if (i == 4)
        {
            for (int j = 0; j < 5; j++)
                printf("Nome: %s\nCategoria: %s\nDescricao: %s\nPreco: R$ %.2f\n", p[j].nome, p[j].categoria, p[j].descricao, p[j].preco);
        }
    }
    

}*/


/*struct no {
   int vidas;
   char nome[10];
   float distancia;
   struct no* prox;
};

typedef struct no No;

void insere_lista_de(No **li, int v, char *n, float a){
  struct no* novo;
  novo = (No*) malloc (sizeof(No));
  novo->vidas = v;
  novo->distancia = a;
  strcpy(novo->nome,n); 
  novo->prox = *li;
  *li = novo;    
}
void imprime(No *li){
   if (li == NULL)
      printf("\nLista Vazia");
   else{
      No *aux;
      aux = li;
      while(aux != NULL){
          printf("\n%3d \t%s \t%f",aux->vidas, aux->nome, aux->distancia);
          aux = aux->prox;
      }
   }
}

void menorDistanciaExclui(No **l)
{
    No* atual = *l, *ant = NULL ,*aux = atual, *aux2 = NULL;

    while (atual)
    {
        if (aux->distancia > atual->distancia)
        {
            aux = atual;
            aux2 = ant;
        }
        
        ant = atual;
        atual = atual->prox;
    }

    if (aux == *l)
        *l = aux->prox;
    else
        aux2->prox = aux->prox;

    free(aux);
}

int main(void) {
  No* lista;
  lista = NULL;
  insere_lista_de(&lista,100,"hackr",6.33);
  insere_lista_de(&lista,60,"gamr",7.2);
  insere_lista_de(&lista,70,"strkid",10.7);
  insere_lista_de(&lista,110, "jog1",9.65);
  printf("\nLista de ataques: \nVidas \tJogador \tDistancia");
  imprime(lista);
  printf("\n\n");
  menorDistanciaExclui(&lista);
  printf("\n\n");
  imprime(lista);
}*/

typedef struct Tecnos
{
    int valvula;
    double cilindrada, cv;
}tecnos;

typedef struct Veiculo 
{
    char marca[30], modelo[40];
    int ano;
    tecnos dados;
} veiculo;

typedef struct Lista 
{
    int cpcdd, tam;
    veiculo* n;
} lista;

void cria_lista(lista* l)
{
    l->tam = 0;
    l->cpcdd = MAX;
    l->n = (veiculo*)malloc(MAX*sizeof(veiculo));
}

veiculo scan_veiculo()
{
    veiculo v;

    printf("Digite a marca: ");
    scanf("%[^\n]", v.marca);
    getchar();

    printf("Digite o modelo: ");
    scanf("%[^\n]", v.modelo);
    getchar();

    printf("Digite o ano: ");
    scanf("%d", &v.ano);
    getchar();

    printf("\nDADOS TECNOS\n");

    printf("Digite as cilindradas: ");
    scanf("%lf", &v.dados.cilindrada);
    getchar();

    printf("Digite a potencia em CV: ");
    scanf("%lf", &v.dados.cv);
    getchar();

    printf("Digite o número de valvulas : ");
    scanf("%d", &v.dados.valvula);
    getchar();
    
    return v;
}

void insere_lista(lista* l)
{
    if (l->n && l->tam < l->cpcdd)
    {
        l->n[l->tam] = scan_veiculo();
        l->tam++;
    }  else if (l->cpcdd >= l->tam)
    {
        printf("\nLista atingiu numero maximo de veiculos\n");
    } else 
    {
        printf("\nA lista nao foi criada\n");
    }
}

double performance(veiculo l)
{
    double res;

    if (l.dados.valvula >= 16)
        l.dados.cv *= 3;

    l.dados.cv *= 2;

    res = (l.dados.cv + l.dados.cilindrada) / l.dados.valvula;

    return res;

}

void imprime_veiculo(veiculo v)
{
    printf("Marca: %s\nModelo: %s\nAno: %d\n", v.marca, v.modelo, v.ano);
    printf("\nINFO TECNICAS\n");
    printf("Potencia em CV: %.3lf\nCilindradas: %lf cm^3\nNum valvulas: %d\nPerformance: %.2lf\n", v.dados.cv, v.dados.cilindrada, v.dados.valvula, performance(v));
}

void imprime_lista(lista l)
{
    printf("\n--------------Lista---------------\n\n");

    if (l.n)
    {
        for (int i = 0; i < l.tam; i++)
        {
            imprime_veiculo(l.n[i]);

            if (i != l.tam - 1)
                printf("\n");
        }

    } else 
        printf("Lista vazia");

    printf("\n\n---------------Fim-----------------\n");

}

void imprime_inferiores(lista l)
{
    printf("\n--------------Lista---------------\n\n");

    if (l.n)
    {
        for (int i = 0; i < l.tam; i++)
        {
            if (performance(l.n[i]) < 150)
            {
                imprime_veiculo(l.n[i]);

                if (i != l.tam - 1)
                    printf("\n");
            }
        }

    } else 
        printf("Lista vazia");

    printf("\n\n---------------Fim-----------------\n");
}