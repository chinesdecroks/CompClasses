#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ponto.h"//Inclui protótipos de função

struct ponto
{
    float x;
    float y;
};

int main(void)
{
    Ponto* p, *p1;
    float x, y, x1, y1;

    p = pto_cria(2, 3);
    p1 = pto_cria(4, 5);
    pto_acessa(p, &x, &y);
    pto_acessa(p1, &x1, &y1);

    printf("%f %f\n%f %f\n", x, y, x1, y1);

    float d = pto_distancia(p, p1);

    printf("A distancia entre o ponto A e B eh %f\n", d);



    pto_libera(p);
    pto_libera(p1);



}

Ponto* pto_cria(float x, float y)
{
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if (p != NULL)
    {
        p->x = x;
        p->y = y;
    }

    return p;
}

void pto_libera(Ponto* p)
{
    free(p);
}

void pto_acessa(Ponto* p, float* x, float* y)
{
    *x = p->x;
    *y = p->y;
}

void pto_atribui(Ponto* p, float x, float y)
{
    p->x = x;
    p->y = y;
}

float pto_distancia(Ponto* p1, Ponto* p2)
{
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}
