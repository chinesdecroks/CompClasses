#ifndef _PACMAN_H_
#define _PACMAN_H_

#define ESQUERDA 'a'
#define CIMA 'w'
#define DIREITA 'd'
#define BAIXO 's'
#define BOMBA 'b'

void move(char direcao);
int acabou();
int ehdirecao(char direcao);
void fantasmas();
int praondefantasmavai(int xatual, int yatual,
 int* xdestino, int* ydestino);
void explodepilula();
void explodepilula2(int x, int y, int somax, int somay, int qtd);

#endif