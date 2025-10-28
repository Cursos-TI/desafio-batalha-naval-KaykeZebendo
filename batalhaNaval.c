#include <stdio.h>

// Constantes

const int TAMANHO_TABULEIRO = 10;       // Tabuleiro 10x10
const int TAMANHO_NAVIO_VERTICAL = 3;   // Navio vertical
const int TAMANHO_NAVIO_HORIZONTAL = 4; // Navio horizontal
const int TAMANHO_NAVIO_DIAGONAL = 3;   // Navio diagonal
const int VALOR_NAVIO = 3;              // Valor que representa um navio no tabuleiro


// Função: posicionaNavioVertical
// Descrição: Posiciona um navio vertical no tabuleiro.

void posicionaNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial) {
    printf("=== Posicionando Navio Vertical ===\n");
    for (int i = 0; i < TAMANHO_NAVIO_VERTICAL; i++) {
        tabuleiro[linhaInicial + i][colunaInicial] = VALOR_NAVIO;
        printf("Parte %d do navio vertical: Coordenada (%d, %d)\n", i + 1, linhaInicial + i, colunaInicial);
    }
    printf("\n");
}


// Função: posicionaNavioHorizontal
// Descrição: Posiciona um navio horizontal no tabuleiro.

void posicionaNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial) {
    printf("=== Posicionando Navio Horizontal ===\n");
    for (int j = 0; j < TAMANHO_NAVIO_HORIZONTAL; j++) {
        tabuleiro[linhaInicial][colunaInicial + j] = VALOR_NAVIO;
        printf("Parte %d do navio horizontal: Coordenada (%d, %d)\n", j + 1, linhaInicial, colunaInicial + j);
    }
    printf("\n");
}


// Função: posicionaNavioDiagonal
// Descrição: Posiciona um navio diagonal no tabuleiro.

void posicionaNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial) {
    printf("=== Posicionando Navio Diagonal ===\n");
    for (int i = 0; i < TAMANHO_NAVIO_DIAGONAL; i++) {
        tabuleiro[linhaInicial + i][colunaInicial + i] = VALOR_NAVIO;
        printf("Parte %d do navio diagonal: Coordenada (%d, %d)\n", i + 1, linhaInicial + i, colunaInicial + i);
    }
    printf("\n");
}


// Função: exibeTabuleiro
// Descrição: Exibe todo o tabuleiro no console.
// 0 = posição vazia, 3 = navio

void exibeTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("=== Tabuleiro Completo ===\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


// Função Principal

int main() {
    printf("--- Desafio Batalha Naval - Nível Aventureiro ---\n\n");

    // Inicializa o tabuleiro com zeros
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionando navios
    posicionaNavioVertical(tabuleiro, 1, 2);     // Navio vertical
    posicionaNavioHorizontal(tabuleiro, 3, 0);   // Navio horizontal
    posicionaNavioDiagonal(tabuleiro, 5, 5);     // Navio diagonal 1
    posicionaNavioDiagonal(tabuleiro, 0, 7);     // Navio diagonal 2

    // Exibe o tabuleiro completo
    exibeTabuleiro(tabuleiro);

    printf("--- Posicionamento concluído! ---\n");
    return 0;
}
