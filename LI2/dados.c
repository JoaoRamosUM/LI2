#include "dados.h"
#include <stdlib.h>

/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
*/
ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    for (int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            e -> tab[i][j] = VAZIO;
        }
    }
    ///<Atribui uma peca "BRANCA" na posição "e5".
    e -> tab[4][4] = BRANCA;
    ///<Define como ultima jogada a peça inicial, para ser utilizado futuramente na funçao "jogar".
    (e -> ultima_jogada).coluna = 4;
    (e -> ultima_jogada).linha = 4;
    ///<Inicializa o numero de jogadas, atribuindo-lhe o valor '0'.
    e -> num_jogadas = 1;
    ///<O jogo começa sempre pelo jogador 1.
    e -> jogador_atual = 1;

    return e;
}

int obter_jogador_atual(ESTADO *estado) {
    return estado -> jogador_atual;
}

int obter_numero_de_jogadas(ESTADO *estado) {
    return estado -> num_jogadas;
}

CASA obter_estado_casa(ESTADO *e, COORDENADA c) {
    CASA r;
    r = e -> tab[c.linha][c.coluna];
    return r;
}

CASA obter_casa (ESTADO *e, int i, int j) {
    CASA r = e -> tab[i][j];
    return r;
}
