typedef struct Vetor vet;

vet* cria_vet();
void inserir(vet* v, int valor);
int obter(vet* v, int index);
void liberar(vet* v);