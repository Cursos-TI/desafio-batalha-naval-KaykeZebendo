#include <stdio.h>

// Constantes

const int TAMANHO_TABULEIRO = 10;       // Tabuleiro 10x10
const int TAMANHO_NAVIO_VERTICAL = 3;   // Navio vertical
const int TAMANHO_NAVIO_HORIZONTAL = 4; // Navio horizontal
const int TAMANHO_NAVIO_DIAGONAL = 3;   // Navio diagonal
const int VALOR_NAVIO = 3;              // Valor que representa um navio no tabuleiro
const int TAM_HABILIDADE = 5;           // Tamanho das matrizes de habilidade (cone, cruz, octaedro)


// Funções para posicionar navios (igual Aventureiro)

void posicionaNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial) {
    printf("=== Posicionando Navio Vertical ===\n");
    for (int i = 0; i < TAMANHO_NAVIO_VERTICAL; i++) {
        tabuleiro[linhaInicial + i][colunaInicial] = VALOR_NAVIO;
        printf("Parte %d -> Coordenada (%d, %d)\n", i + 1, linhaInicial + i, colunaInicial);
    }
    printf("\n");
}

void posicionaNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial) {
    printf("=== Posicionando Navio Horizontal ===\n");
    for (int j = 0; j < TAMANHO_NAVIO_HORIZONTAL; j++) {
        tabuleiro[linhaInicial][colunaInicial + j] = VALOR_NAVIO;
        printf("Parte %d -> Coordenada (%d, %d)\n", j + 1, linhaInicial, colunaInicial + j);
    }
    printf("\n");
}

void posicionaNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial) {
    printf("=== Posicionando Navio Diagonal ===\n");
    for (int i = 0; i < TAMANHO_NAVIO_DIAGONAL; i++) {
        tabuleiro[linhaInicial + i][colunaInicial + i] = VALOR_NAVIO;
        printf("Parte %d -> Coordenada (%d, %d)\n", i + 1, linhaInicial + i, colunaInicial + i);
    }
    printf("\n");
}


// Função: exibeTabuleiro

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


// Função: exibeHabilidade
// Descrição: Exibe a matriz de habilidade

void exibeHabilidade(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


// Função: habilidadeCone
// Preenche a matriz de habilidade em formato cone

void habilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // preenchendo cone: centro maior, borda menor
            if ((i == 2) || (i == 1 && j >= 1 && j <= 3) || (i == 0 && j == 2)) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}


// Função: habilidadeCruz
// Preenche a matriz de habilidade em formato cruz

void habilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 2 || j == 2) { // linha e coluna do meio
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}


// Função: habilidadeOctaedro
// Preenche a matriz de habilidade em formato octaedro

void habilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if ((i == 2 && j == 2) || (i == 1 && j == 2) || (i == 3 && j == 2) || 
                (i == 2 && j == 1) || (i == 2 && j == 3)) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}


// Função Principal

int main() {
    printf("--- Desafio Batalha Naval - Nível Mestre ---\n\n");

    // Inicializa o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; 
        }
    }


    // Posiciona os navios
    posicionaNavioVertical(tabuleiro, 1, 2);
    posicionaNavioHorizontal(tabuleiro, 3, 0);
    posicionaNavioDiagonal(tabuleiro, 5, 5);
    posicionaNavioDiagonal(tabuleiro, 0, 7);

    // Exibe o tabuleiro completo
    exibeTabuleiro(tabuleiro);

    // Cria e exibe as habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    habilidadeCone(cone);
    printf("=== Habilidade: Cone ===\n");
    exibeHabilidade(cone);

    habilidadeCruz(cruz);
    printf("=== Habilidade: Cruz ===\n");
    exibeHabilidade(cruz);

    habilidadeOctaedro(octaedro);
    printf("=== Habilidade: Octaedro ===\n");
    exibeHabilidade(octaedro);

    printf("--- Todas as habilidades exibidas com sucesso! ---\n");

    return 0;
}
