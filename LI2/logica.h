#ifndef LI2_LOGICA_H
#define LI2_LOGICA_H
#include "dados.h"

int jogar(ESTADO *estado, COORDENADA c);
int jogada_possivel (ESTADO *e, COORDENADA c);
int jogo_terminado (ESTADO *e);
#endif
