#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Fun��o para exibir o tabuleiro do jogo
void mostrarTabuleiro(char (*tabuleiro)[3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        printf("\n");
        for (j = 0; j < 3; j++) {
            printf("\t");
            printf("%c", tabuleiro[i][j]);
        }
        printf("\n");
        printf("\n");
    }
}


// Fun��o para verificar o Vencedor
int verificarVencedor(char (*tabuleiro)[3]) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        char *linha = tabuleiro[i];
        if (linha[0] == linha[1] && linha[0] == linha[2] && linha[0] != '_') {
            return 1; // Um jogador ganhou
        }
    }

    // Verificar colunas
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == tabuleiro[1][j] &&
            tabuleiro[0][j] == tabuleiro[2][j] &&
            tabuleiro[0][j] != '_') {
            return 1; // Um jogador ganhou
        }
    }

    // Verificar diagonais
    if ((tabuleiro[0][0] == tabuleiro[1][1] &&
         tabuleiro[0][0] == tabuleiro[2][2] &&
         tabuleiro[0][0] != '_') ||
        (tabuleiro[0][2] == tabuleiro[1][1] &&
         tabuleiro[0][2] == tabuleiro[2][0] &&
         tabuleiro[0][2] != '_')) {
        return 1; // Um jogador ganhou
    }

    return 0; // Nenhum vencedor encontrado
}

// Fun��o principal do jogo da velha
void jogoDaVelha(int *pontosJogador1, int *pontosJogador2) {
    int i, linha, coluna, cont;
    char matriz[3][3];

    // Inicializa��o da matriz do jogo com espa�os vazios
    for (i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = '_';
        }
    }

    // Loop principal do jogo
    for (cont = 0; cont < 9; cont++) {
        printf("\nDigite a linha que voc� quer jogar: ");
        scanf("%d", &linha);
        fflush(stdout);
        linha--;

        printf("\nDigite a coluna que voc� quer jogar: ");
        scanf("%d", &coluna);
        fflush(stdout);
        coluna--;

        printf("\n");
        // Verifica se a posi��o escolhida est� vazia
        if (matriz[linha][coluna] == '_') {
            // Preenche a posi��o com 'X' ou 'O' dependendo do turno
            if (cont % 2) {
                matriz[linha][coluna] = 'O';
            } else {
                matriz[linha][coluna] = 'X';
            }

            // Mostra o tabuleiro ap�s cada jogada
            mostrarTabuleiro(matriz);

            // Verifica se h� um vencedor ap�s a jogada atual
            if (verificarVencedor(matriz)) {
                printf("\nO Jogador %d ganhou a partida!\n", (cont % 2) + 1);
                
                // Ir� registrar e armazenar na vari�vel quantas vezes o jogador ganhou.
                if ((cont % 2) + 1 == 1) {
                (*pontosJogador1)++;
            } else {
                (*pontosJogador2)++;
            }
            break;
        	}
        } else {
            printf("\nO espa�o escolhido j� est� ocupado, repita a opera��o para um espa�o v�lido\n");
            cont--;
        }
    }
    // Se nenhum jogador venceu ap�s todas as jogadas, � um empate
    if (cont == 9) {
        printf("\nNingu�m ganhou :(\n");
    }
}

// Fun��o para exibir os cr�ditos dos criadores do jogo
void exibirCreditos() {
    printf("Integrantes: \n Jefferson Coutinho \n Marcio Cartaxo \n Antonio Neto \n Pedro Ernesto\n");
}

int main() {
    setlocale(0, "Portuguese");

    int escolha;
    int pontosJogador1 = 0;
    int pontosJogador2 = 0;

    // Loop principal do menu do jogo
    do {
        printf("<----JOGO DA VELHA---->\n");
        printf("\nPara jogar, digite (1)\n");
        printf("Para acessar os cr�ditos, digite (2)\n");
        printf("Para acessar o score, digite (3)\n");
        printf("Para finalizar, digite (4)\n");
        scanf("%d", &escolha);

        // Verifica a escolha do usu�rio e executa a a��o correspondente
        if (escolha == 1) {
            jogoDaVelha(&pontosJogador1, &pontosJogador2); // Inicia o jogo da velha
        } else if (escolha == 2) {
            exibirCreditos(); // Exibe os cr�ditos
        } else if(escolha == 3){	// Exibe quantas vezes o jogador ganhou 
			printf("O jogador 1 venceu %d partidas\n", pontosJogador1);
			printf("O jogador 2 venceu %d partidas\n", pontosJogador2);
			
		}else if (escolha == 4) {
            printf("             OOOOOOOOOOO               \n");
            printf("         OOOOOOOOOOOOOOOOOOO           \n");
            printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
            printf("    OOOOOO      OOOOO      OOOOOO      \n");
            printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
            printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
            printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
            printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
            printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
            printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
            printf("         OOOOOO         OOOOOO         \n");
            printf("             OOOOOOOOOOOO              \n");
            printf("\n	Obrigado por jogar!\n");
            // ... Mensagem de sa�da ...
        }
    } while (escolha != 4);

    return 0;
   
}
    
