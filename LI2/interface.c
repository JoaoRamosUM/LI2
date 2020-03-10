#include "interface.h"
#include <stdio.h>
#include <string.h>
#include "logica.h"
#define BUF_SIZE 1024

void mostrar_tabuleiro(ESTADO *e) {
    char item;
    //Imprime as letras no topo do tabuleiro.
    printf("   ");
    for (char c = 'a'; c < 'i'; c++)
        printf("%c  ", c);
    printf("\n");

    /*
    Imprime o conteudo do tabuleiro, imprimindo '*' no caso de a Peça ser "BRANCA",
    '#' no caso de a peça ser "PRETA", e '.' no caso de ser "VAZIO".
    */

    for (int i = 0; i < 8; i++) {
        printf("%d  ", i+1);
        for (int j = 0; j < 8; j++) {
            if (e -> tab[i][j] == VAZIO)
                item = '.';
            else if (e -> tab[i][j] == BRANCA)
                item = '*';
            else
                item = '#';

            printf("%c  ", item);
        }
        printf("\n");
    }
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];

    mostrar_tabuleiro(e);
    printf("Faz a tua jogada: ");

    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    return 1;
}
