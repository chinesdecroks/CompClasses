typedef struct ponto Ponto;

//Cria um novo ponto
Ponto* pto_cria(float x, float y);
//Libera um ponto
void pto_libera(Ponto* p);
//Acessa os valores do ponto
void pto_acessa(Ponto* p, float* x, float* y);
//Atribui valor ao ponto
void pto_atribui(Ponto* p, float x, float y);
//Calcula distancia entre os pontos
float pto_distancia(Ponto* p1, Ponto* p2);
