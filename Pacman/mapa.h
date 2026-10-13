#ifndef _MAPA_H_
#define _MAPA_H_

#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'

//struct = estrutura de variaveis que são dependentes entre si
struct mapa{
	char** matriz;
	int linhas;
	int colunas;
};

//a função typedef cria um apelido para uma struct, facilita escrita de varias estructs
typedef struct mapa MAPA;

struct posicao{
	int x;
	int y;
};

typedef struct posicao POSICAO;

void liberamapa(MAPA* m);
void alocamapa(MAPA* m);
void lemapa(MAPA* m);
int encontramapa(MAPA* m, POSICAO*	p, char c);
int validacao(MAPA* m, int x, int y);
int ehvazio(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);
int ehparede(MAPA* m, int x, int y);
int podeandar(MAPA* m, char personagem, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* origem, MAPA* destino);

#endif