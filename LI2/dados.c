#include "dados.h"
#include <stdlib.h>

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    for (int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            e -> tab[i][j] = VAZIO;
        }
    }
    ///> Atribui uma peca "BRANCA" na posição "e5".
    e -> tab[3][4] = BRANCA;
    e-> tab[7][0] = UM;
    e->tab[0][7] = DOIS;
    ///> Define como ultima jogada a peça inicial, para ser utilizado futuramente na funçao "jogar".
    (e -> ultima_jogada).coluna = 4;
    (e -> ultima_jogada).linha = 3;
    ///> Inicializa o numero de jogadas, atribuindo-lhe o valor '0'.
    e -> num_jogadas = 0;
    ///> Coloca como jogador atual o jogador 1, visto que o jogo começa sempre por ele.
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
    int lin = abs(c.linha -8) - 1;
    r = e -> tab[lin][c.coluna];
    return r;
}

CASA obter_casa (ESTADO *e, int i, int j) {
    CASA r = e -> tab[i][j];
    return r;
}

char obtem_dados_jogadas_col (ESTADO *e, int n, int i) {
    if (n == 1) {
        return e->jogadas[i].jogador1.coluna + 'a';
    }
    else
        return e->jogadas[i].jogador2.coluna + 'a';
}

int obtem_dados_jogadas_lin (ESTADO *e, int n, int i) {
    int lin;
    if (n == 1) {
        lin = abs((e->jogadas[i].jogador1.linha + 1) - 8) + 1;
        return lin;
    }
    else
        lin = abs((e -> jogadas[i].jogador2.linha + 1) - 8) + 1;
        return lin;
}

void set_casa (ESTADO *e, char linha [], int k) {
    int i;
    for ( i = 0; i < 9; i++) {
        switch (linha[i]) {
            case ('.'):
                e->tab[k][i] = VAZIO;
                break;
                ///> Ao encontrar a posição onde coloca a peça BRANCA, define também essa posição como última jogada.
            case ('*'):
                e->tab[k][i] = BRANCA;
                e->ultima_jogada.coluna = i;
                e->ultima_jogada.linha = k ;
                break;
            case('#'):
                e->tab[k][i] = PRETA;
                break;
            case('2'):
                e->tab[k][i] = DOIS;
                break;
            case('1'):
                e->tab[k][i] = UM;
            default:
                break;
        }
    }
}
///> Função auxiliar para a função "ler_ficheiro".
void set_estado (ESTADO *e, char cord[]) {
    int i;
    int jog = atoi(cord);
    e->num_jogadas = jog-1;
    for (i = 0; cord[i] != '\n'; i++){;}

    if (i < 8) {
        e->jogador_atual = 2;
    }
    else
        e->jogador_atual = 1;
}