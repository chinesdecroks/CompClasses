//diretiva ifndef = se a contante não estiver definida chama o código
//evita repeticao, pois a constante se define depois da primeira chamada, e não é necessario chamar novamente o código
#ifndef _UI_H
#define _UI_H

#include "mapa.h"

void imprimeparte(char desenho[4][7], int parte);
void imprimemapa(MAPA* m);



#endif