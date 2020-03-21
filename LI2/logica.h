/**
 * @file logica.h
 * Definição da camada logica.
 */
#ifndef LI2_LOGICA_H
#define LI2_LOGICA_H
#include <stdio.h>
#include "dados.h"
/**
 * \brief Função que usa os dados do estado e do input do jogador para fazer a jogada.
 * @param e Estado do jogo.
 * @param c Coordenada introduzida pelo utilizador.
 * @return Um novo estado atualizado conforme a jogada.
 */
int jogar(ESTADO *e, COORDENADA c);

/**
 * \brief Função que verifica se a jogada é possivel.
 * @param e Estado do jogo.
 * @param c Coordenada introduzida pelo utilizador.
 * @return 0 Caso nao seja possivel, 1 caso seja possivel.
 */
int jogada_possivel (ESTADO *e, COORDENADA c);

/**
 * \brief Verifica se o jogo terminou.
 * @param e Estado do jogo.
 * @return 1 caso o jogador 1 ganhe, 2 caso o jogador ganhe, 0 caso ainda ninguem tenha ganho, ou 3 caso as jogadas acabem.
 */
int jogo_terminado (ESTADO *e);

/**
 * \brief Coloca o tabuleiro e o estado do jogo num ficheiro
 * @param e Estado do jogo.
 * @param linha Nome do ficheiro onde vai ser guardado o estado.
 */
void tabuleiro_ficheiro(ESTADO *e, char linha[]);

/**
 * \brief Função (auxiliar) que atualiza os dados de forma a que a jogada fique realizada.
 * @param e Estado atual do jogo.
 * @param col posição da coluna.
 * @param lin posição da linha.
 */
void atualiza_jogada (ESTADO *e, int col, int lin);

/**
 * \brief Função que imprime o tabuleiro no ficheiro criado pelo utilizador com o comando "gr".
 * @param e Estado atual do jogo.
 * @param fp apontador do ficheiro, usado para escrever no documento de texto.
 */
void imprime_fileTab (ESTADO *e, FILE *fp);

/**
 * \brief Função que imprime as jogadas anteriores no ficheiro criado pelo utilizador com o comando "gr".
 * @param e Estado atual do jogo.
 * @param fp apontador do ficheiro, usado para escrever no documento de texto.
 */
void file_posAnt (ESTADO *e, FILE *fp);
#endif
