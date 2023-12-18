#include <stdio.h>
#include <stdlib.h>

int main() {
    int l, c, linha, coluna, jogador, ganhou, jogadas, opcao;
    char jogo[3][3];

    do {
        jogador = 1;
        ganhou = 0;
        jogadas = 0;

        // Inicializar estruturas de dados
        for (l = 0; l < 3; l++) {
            for (c = 0; c < 3; c++) {
                jogo[l][c] = ' ';
            }
        }

        // Imprimir tabuleiro inicial
        for (l = 0; l < 3; l++) {
            for (c = 0; c < 3; c++) {
                if (c == 0) printf("\t");
                printf(" %c ", jogo[l][c]);
                if (c < 2) printf("|");
                if (c == 2) printf("  %d", l);
            }
            if (l < 2) printf("\n\t------------");
            printf("\n");
        }

        do {
            printf("\n\n\t 0   1   2\n\n");
            for (l = 0; l < 3; l++) {
                for (c = 0; c < 3; c++) {
                    if (c == 0) printf("\t");
                    printf(" %c ", jogo[l][c]);
                    if (c < 2) printf("|");
                    if (c == 2) printf("  %d", l);
                }
                if (l < 2) printf("\n\t------------");
                printf("\n");
            }

            do {
                printf("\nJOGADOR 1 = 0\nJOGADOR 2 = X\n");
                printf("\nJOGADOR %d: Digite a linha e a coluna que deseja jogar", jogador);
                scanf("%d%d", &linha, &coluna);

            } while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');

            if (jogador == 1) {
                jogo[linha][coluna] = '0';
                jogador++;
            } else {
                jogo[linha][coluna] = 'X';
                jogador = 1;
            }
            jogadas++;

            // Verificar vitória por linhas
            if ((jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0') ||
                (jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0') ||
                (jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0')) {
                printf("\nParabéns! o JOGADOR 1 ganhou por linha");
                ganhou = 1;
            }
            if ((jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X') ||
                (jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X') ||
                (jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X')) {
                printf("\nParabéns! o JOGADOR 2 ganhou por linha");
                ganhou = 1;
            }

            // Verificar vitória por colunas
            if ((jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0') ||
                (jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0') ||
                (jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0')) {
                printf("\nParabéns! o JOGADOR 1 ganhou por coluna");
                ganhou = 1;
            }
            if ((jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X') ||
                (jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X') ||
                (jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X')) {
                printf("\nParabéns! o JOGADOR 2 ganhou por coluna");
                ganhou = 1;
            }

            // Verificar vitória por diagonais
            if ((jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0') ||
                (jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0')) {
                printf("\nParabéns! JOGADOR 1 ganhou por diagonal");
                ganhou = 1;
            }
            if ((jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') ||
                (jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X')) {
                printf("\nParabéns! JOGADOR 2 ganhou por diagonal");
                ganhou = 1;
            }

        } while (ganhou == 0 && jogadas < 9);

        // Imprimir tabuleiro final
        printf("\n\n\t 0    1   2\n\n");
        for (l = 0; l < 3; l++) {
            for (c = 0; c < 3; c++) {
                if (c == 0) printf("\t");
                printf(" %c ", jogo[l][c]);
                if (c < 2) printf(" | ");
                if (c == 2) printf("   %d", l);
            }
            if (l < 2) printf("\n\t-------------");
            printf("\n");
        }

        if (ganhou == 0) printf("\n O jogo finalizou sem nenhum ganhador");
        printf("\nDigite 1 para jogar novamente: \n");
        scanf("%d", &opcao);
    } while (opcao == 1);

    return 0;
}
