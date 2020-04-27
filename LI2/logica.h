/**
 * @file logica.h
 * Definição da camada logica.
 */
#ifndef LI2_LOGICA_H
#define LI2_LOGICA_H
#include <stdio.h>
#include "dados.h"
#include "lista.h"
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
 * @return 1 caso o jogador 1 ganhe, 2 caso o jogador ganhe, 0 caso ainda ninguem tenha ganho, 3 caso as jogadas acabem, ou 4 caso a peça fique encurralada.
 */
int jogo_terminado (ESTADO *e);

/**
 *\brief Verifica se a peça está encurralada.
 * @param e Estado atual do jogo.
 * @return 1 caso esteja encurralada, 0 caso nao esteja.
 */
int encurralado(ESTADO *e);

/**
 * \brief Verifica se todas as casas a volta da peça branca estao preenchidas com peças pretas.
 * @param e Estado atual do jogo.
 * @return 1 caso a peca esteja encurralada, 0 caso nao esteja.
 */
int check_around (ESTADO *e);

/**
 * \brief Verifica todas as casas a volta da peca branca caso se encontre em col == 0 ou col == 7.
 * @param e Estado atual do jogo.
 * @return 1 caso a peca esteja encurralada.
 */
int check_lados (ESTADO *e);

/**
 * \brief Verifica todas as casas  a volta da peça branca caso se encontre em lin == 0 ou lin == 7;
 * @param e Estado atual do jogo.
 * @return 1 caso a peça esteja encurralada.
 */
int check_bottom(ESTADO *e);

/**
 * \brief Coloca o tabuleiro e o estado do jogo num ficheiro
 * @param e Estado do jogo.
 * @param linha Nome do ficheiro onde vai ser guardado o estado.
 */
void tabuleiro_ficheiro(ESTADO *e, char *linha);

/**
 * \brief Função (auxiliar) que atualiza os dados de forma a que a jogada fique realizada.
 * @param e Estado atual do jogo.
 * @param col posição da coluna.
 * @param lin posição da linha.
 */
void atualiza_jogada (ESTADO *e, int col, int lin);

/**
 * \brief Lê um ficheiro e atualiza o estado do jogo com o estado do jogo definido nesse ficheiro.
 * @param e Estado atual do jogo.
 * @param linha Linha obtida pela função "fgets()" no interpretador.
 * @return 1 caso consiga ler o ficheiro, 0  caso nao consiga.
 */
int ler_ficheiro (ESTADO *e, char linha []);

/**
 * \brief Converte a string no formato de dados do ficheiro criado pelo utilizador para um inteiro correspondente à linha.
 * @param str String de onde vao ser tirados os dados.
 * @return Uma posição para a linha do tabuleiro.
 */
int retira_linha (char str[]);

/**
 * \brief Converte a string no formato de dados do ficheiro criado pelo utilizador para um inteiro correspondente à coluna.
 * @param str String de onde vao ser tirados os dados.
 * @return Uma posição para a coluna do tabuleiro.
 */
int retira_coluna (char str[]);

/**
 * \brief Função para executar o comando "pos".
 * @param e Estado atual do jogo.
 * @param linha Linha obtida pelo interpretador na camada "Interface".
 * @return 1 caso a operação seja executada com sucesso, 0 caso não seja executada com sucesso.
 */
int pos (ESTADO *e, char *linha);

// ======= BOT ======= //

/**
 * \brief
 * @param str
 * @param cords
 */
COORDENADA get_cords(char *str);

/**
 * \brief Atribui uma pontuação a cada uma das casas do tabuleiro.
 * @param e Estado atual do jogo.
 * @return A pontuação final.
 */
int scores(ESTADO *e);

/**
 * \brief Copia um struct para um outro struct.
 * @param e Estado atual do jogo.
 * @param aux Struct auxiliar para onde vao ser copiadas as informações.
 */
void copyStruct (ESTADO *e, ESTADO *aux);

/**
 * \brief Função para o comando jog, joga em uma posição disponível aleatória.
 * @param e Estado atual do jogo.
 */
void jog (ESTADO *e);

/**
 * \brief Função que invoca o minimax para decidir qual é a melhor jogada a realizar.
 * @param e Estado atual do jogo.
 */
void bestMove (ESTADO *e);

/**
 * \brief Variação do algoritmo "minimax".
 * @param e Cópia do estado do jogo.
 * @param depth Profundidade.
 * @param player Varia entre -1 e 1, dependendo de quem e a vez de jogar.
 * @return Score da posição onde a peça se encontra.
 */
int negamax (ESTADO *e, int depth, int player);

/**
 * \brief Verifica se o jogador se encontra na possibilidade de fazer uma jogada vencedora.
 * @param e Estado atual do jogo.
 * @param L Lista com posições possiveis.
 * @return 1 caso exista uma jogada vencedora.
 */
int check_vencedora (ESTADO *e, LISTA L);

/**
 * \brief Caso exista uma jogada vencedora, obtem esta jogada.
 * @param L Lista de jogadas possiveis.
 * @return As coordenadas da jogada vencedora.
 */
COORDENADA get_vencedor(LISTA L);
#endif
