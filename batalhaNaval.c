#include <stdio.h>

#define TAMANHO_TABULEIRO 10  // Tamanho fixo do tabuleiro 10x10
#define TAMANHO_NAVIO 3       // Tamanho fixo de cada navio


// Parte 1 - Nível Novato
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // 1. Inicializa o tabuleiro com 0 (água)
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }
    // 2. Define coordenadas iniciais dos navios (fixas no código)
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 4;

    int linha_navio_vertical = 5;
    int coluna_navio_vertical = 7;

    // 3. Verifica se o navio horizontal cabe no tabuleiro
    if (coluna_navio_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // 4. Posiciona o navio horizontal (linha fixa, coluna avança)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = 3;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro!\n");
    }

    // 5. Verifica se o navio vertical cabe no tabuleiro
    if (linha_navio_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // 6. Verifica se há sobreposição com o navio horizontal
        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] == 3) {
                pode_posicionar = 0;
                break;
            }
        }

















    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    

    return 0;
}
