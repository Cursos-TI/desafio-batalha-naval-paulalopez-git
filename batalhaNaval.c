#include <stdio.h>

#define TAMANHO_TABULEIRO 10  // Tamanho fixo do tabuleiro 10x10
#define TAMANHO_NAVIO 3       // Tamanho fixo de cada navio


// Parte 1 - Desafio Nível Novato
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

        // 7. Se não há sobreposição, posiciona o navio vertical
        if (pode_posicionar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = 3;
            }
        } else {
            printf("Erro: Sobreposição detectada no navio vertical!\n");
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro!\n");
    }

    //8. Exibir coordenadas dos navios
    printf("\nCoordenadas do Navio Horizontal:\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("(%d, %d)\n", linha_navio_horizontal, coluna_navio_horizontal + i);
    }

    printf("\nCoordenadas do Navio Vertical:\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("(%d, %d)\n", linha_navio_vertical + i, coluna_navio_vertical);
    }

    // 9. Exibe o tabuleiro completo
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;



    

// Parte 2 - Desafio Nível Aventureiro 

#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

   // 1. Função para verificar se pode posicionar o navio

int pode_posicionar(int tabuleiro[10][10], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;   
        if (diagonal == 1) {         // Diagonal ↘
            l += i;
            c += i;
        } else if (diagonal == 2) {  // Diagonal ↙
            l += i;
            c -= i;
        } else if (direcao == 0) {   // Horizontal →
            c += i;
        } else if (direcao == 1) {   // Vertical ↓
            l += i;
        }

        // Verifica limite do tabuleiro
        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO || c < 0)
            return 0;

        // Verifica sobreposição
        if (tabuleiro[l][c] == NAVIO)
            return 0;
    }

    return 1;
}

   // 2. Função para Posicionar o Navio 
void posicionar_navio(int tabuleiro[10][10], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (diagonal == 1) {
            l += i;
            c += i;
        } else if (diagonal == 2) {
            l += i;
            c -= i;
        } else if (direcao == 0) {
            c += i;
        } else if (direcao == 1) {
            l += i;
        }

        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
   //3. Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navio 1 - Horizontal
    int l1 = 2, c1 = 3;
    if (pode_posicionar(tabuleiro, l1, c1, 0, 0)) {
        posicionar_navio(tabuleiro, l1, c1, 0, 0);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    // Navio 2 - Vertical
    int l2 = 5, c2 = 7;
    if (pode_posicionar(tabuleiro, l2, c2, 1, 0)) {
        posicionar_navio(tabuleiro, l2, c2, 1, 0);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    // Navio 3 - Diagonal ↘ (principal)
    int l3 = 0, c3 = 0;
    if (pode_posicionar(tabuleiro, l3, c3, -1, 1)) {
        posicionar_navio(tabuleiro, l3, c3, -1, 1);
    } else {
        printf("Erro: Não foi possível posicionar o navio diagonal ↘.\n");
    }

    // Navio 4 - Diagonal ↙ (secundária)
    int l4 = 0, c4 = 9;
    if (pode_posicionar(tabuleiro, l4, c4, -1, 2)) {
        posicionar_navio(tabuleiro, l4, c4, -1, 2);
    } else {
        printf("Erro: Não foi possível posicionar o navio diagonal ↙.\n");
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}



    

// Parte 3 - Desafio Nível Mestre

#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5
#define TAMANHO_HABILIDADE 5

// Inicializa o tabuleiro com 0
void inicializar_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Posiciona um navio horizontal ou vertical
void posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (direcao == 0 && coluna + i < TAMANHO_TABULEIRO) { // horizontal
            tabuleiro[linha][coluna + i] = NAVIO;
        } else if (direcao == 1 && linha + i < TAMANHO_TABULEIRO) { // vertical
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

// Cria matriz de habilidade Cone (forma de pirâmide para baixo)
void criar_habilidade_cone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= (TAMANHO_HABILIDADE / 2) - i && j <= (TAMANHO_HABILIDADE / 2) + i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Cria matriz de habilidade Cruz
void criar_habilidade_cruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int meio = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == meio || j == meio) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Cria matriz de habilidade Octaedro (losango)
void criar_habilidade_octaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int meio = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Sobrepõe a habilidade no tabuleiro
void aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origem_linha, int origem_coluna) {
    int offset = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha = origem_linha - offset + i;
            int coluna = origem_coluna - offset + j;

            if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != NAVIO) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Exibe o tabuleiro completo com marcações
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro Final:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro
    inicializar_tabuleiro(tabuleiro);

    // Posiciona dois navios
    posicionar_navio(tabuleiro, 2, 3, 0); // horizontal
    posicionar_navio(tabuleiro, 5, 7, 1); // vertical

    // Matrizes de habilidades
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Cria as formas
    criar_habilidade_cone(cone);
    criar_habilidade_cruz(cruz);
    criar_habilidade_octaedro(octaedro);

    // Aplica as habilidades no tabuleiro
    aplicar_habilidade(tabuleiro, cone, 1, 4);       // Cone em (1,4)
    aplicar_habilidade(tabuleiro, cruz, 7, 2);       // Cruz em (7,2)
    aplicar_habilidade(tabuleiro, octaedro, 6, 6);   // Octaedro em (6,6)

    // Exibe o tabuleiro final
    exibir_tabuleiro(tabuleiro);

    return 0;
}
    
    








    

    
    

    return 0;
}
