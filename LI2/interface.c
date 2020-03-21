#include "interface.h"
#include <stdio.h>
#include <string.h>
#include "logica.h"
#define BUF_SIZE 1024

void mostrar_tabuleiro(ESTADO *e) {
    char item;
    int num = 8;

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
        printf("%d  ", num);
        num--;
        for (int j = 0; j < 8; j++) {
            char peca = obter_casa(e, i, j);
            printf("%c  ", peca);
        }
        printf("\n");
    }
    printf("#(%d) JOG: %d => ", obter_numero_de_jogadas(e) + 1, obter_jogador_atual(e));
}


int interpretador(ESTADO *e) {
    char linha[BUF_SIZE], comando [BUF_SIZE];
    char col[2], lin[2];

    ///> Usa a funcao "jogo_terminado" para verificar se tem de continuar a pedir comandos.
    while (jogo_terminado(e) == 0) {
        printf("\n");
        mostrar_tabuleiro(e);
        if (fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;
        else
            if (strlen(linha) == 2 && strncmp(linha, "Q", 1) == 0) {
                printf("Saiu do jogo. \n");
                break;
            }
            else if (strncmp(linha, "gr", 2) == 0) {
                tabuleiro_ficheiro(e, linha);
                printf("Gravado.\n");
            }
            else if (strncmp(linha, "ler", 3) == 0) {

               // if (ler_ficheiro(e,linha) == 1) {
               ler_ficheiro(e,linha);
                    printf("Estado do jogo atualizado!\n");
                //}
                //else printf("Nao foi possivel encontrar esse ficheiro.\n");
            }


        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};
            if(jogar(e,coord) == 0)
                printf("Jogada Invalida. \n");
        }
    }
    if (jogo_terminado(e) == 1)
        printf("Parabens!! O jogador 1 ganha!\n");
    else if (jogo_terminado(e) == 2)
        printf("Parabens!! O jogador 2 ganha! \n");
    else if (jogo_terminado(e) == 3)
        printf("Acabaram-se as jogadas! Ninguém ganhou. \n");
    return 1;
}
