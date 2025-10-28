#include <stdio.h>

// -------------------- Constantes --------------------

// Tamanho do tabuleiro (5x5)
const int TAMANHO_TABULEIRO = 5;

// Número de partes do navio vertical
const int TAMANHO_NAVIO_VERTICAL = 3;

// Número de partes do navio horizontal
const int TAMANHO_NAVIO_HORIZONTAL = 4;


// -------------------- Funções --------------------

// Posiciona o navio verticalmente no tabuleiro
void posicionaNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                            int linhaInicial, int colunaInicial) {
    printf("=== Posicionando Navio Vertical ===\n");
    for (int i = 0; i < TAMANHO_NAVIO_VERTICAL; i++) {
        tabuleiro[linhaInicial + i][colunaInicial] = 1; // Marca o navio vertical
        printf("Parte %d -> Coordenada (%d, %d)\n", i + 1, linhaInicial + i, colunaInicial);
    }
    printf("\n");
}

// Posiciona o navio horizontalmente no tabuleiro
void posicionaNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                              int linhaInicial, int colunaInicial) {
    printf("=== Posicionando Navio Horizontal ===\n");
    for (int j = 0; j < TAMANHO_NAVIO_HORIZONTAL; j++) {
        tabuleiro[linhaInicial][colunaInicial + j] = 2; // Marca o navio horizontal
        printf("Parte %d -> Coordenada (%d, %d)\n", j + 1, linhaInicial, colunaInicial + j);
    }
    printf("\n");
}

// Exibe as coordenadas ocupadas no tabuleiro
// Mostra todas as posições onde há partes de navios
void exibeCoordenadasOcupadas(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("=== Coordenadas Ocupadas ===\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] != 0) {
                printf("(%d, %d) -> Valor: %d\n", i, j, tabuleiro[i][j]);
            }
        }
    }
    printf("\n");
}


// -------------------- Função Principal --------------------
int main(void) {
    printf("--- Desafio Batalha Naval ---\n\n");

    // Cria a matriz do tabuleiro e preenche com 0 (vazio)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Define as posições iniciais dos navios
    int linhaVertical = 1;
    int colunaVertical = 2;
    int linhaHorizontal = 3;
    int colunaHorizontal = 0;

    // Chama as funções de posicionamento dos navios
    posicionaNavioVertical(tabuleiro, linhaVertical, colunaVertical);
    posicionaNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);

    // Exibe todas as coordenadas ocupadas
    exibeCoordenadasOcupadas(tabuleiro);

    printf("--- Posicionamento concluído! ---\n");

    return 0;
}
