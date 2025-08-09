#include <stdio.h>
#include <stdbool.h>

#define TABULEIRO 8

bool posicao_valida(int linha, int coluna) {
    return linha >= 0 && linha < TABULEIRO && coluna >= 0 && coluna < TABULEIRO;
}

void movimento_bispo(int linha, int coluna, int d_linha, int d_coluna) {
    int nova_linha = linha + d_linha;
    int nova_coluna = coluna + d_coluna;

    if (!posicao_valida(nova_linha, nova_coluna)) return;

    printf("Bispo pode ir para (%d,%d)\n", nova_linha, nova_coluna);

    movimento_bispo(nova_linha, nova_coluna, d_linha, d_coluna);
}

void movimento_torre(int linha, int coluna) {
    for (int c = coluna + 1; c < TABULEIRO; c++) {
        printf("Torre pode ir para (%d,%d)\n", linha, c);
    }
    for (int c = coluna - 1; c >= 0; c--) {
        printf("Torre pode ir para (%d,%d)\n", linha, c);
    }
    for (int l = linha - 1; l >= 0; l--) {
        printf("Torre pode ir para (%d,%d)\n", l, coluna);
    }
    for (int l = linha + 1; l < TABULEIRO; l++) {
        printf("Torre pode ir para (%d,%d)\n", l, coluna);
    }
}

void movimento_rainha(int linha, int coluna) {
    movimento_torre(linha, coluna);

    movimento_bispo(linha, coluna, 1, 1);
    movimento_bispo(linha, coluna, 1, -1);
    movimento_bispo(linha, coluna, -1, 1);
    movimento_bispo(linha, coluna, -1, -1);
}

void movimento_cavalo(int linha, int coluna) {
    int movimentos[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < 8; i++) {
        int nova_linha = linha + movimentos[i][0];
        int nova_coluna = coluna + movimentos[i][1];

        if (!posicao_valida(nova_linha, nova_coluna)) {
            continue;
        }

        if (i == 5) {
            printf("Limite de movimentos do cavalo atingido\n");
            break;
        }

        printf("Cavalo pode ir para (%d,%d)\n", nova_linha, nova_coluna);
    }
}

int main() {
    int linha = 3, coluna = 3;

    printf("Movimentos do Bispo a partir de (%d,%d):\n", linha, coluna);
    movimento_bispo(linha, coluna, 1, 1);
    movimento_bispo(linha, coluna, 1, -1);
    movimento_bispo(linha, coluna, -1, 1);
    movimento_bispo(linha, coluna, -1, -1);

    printf("\nMovimentos da Torre a partir de (%d,%d):\n", linha, coluna);
    movimento_torre(linha, coluna);

    printf("\nMovimentos da Rainha a partir de (%d,%d):\n", linha, coluna);
    movimento_rainha(linha, coluna);

    printf("\nMovimentos do Cavalo a partir de (%d,%d):\n", linha, coluna);
    movimento_cavalo(linha, coluna);

    return 0;
}