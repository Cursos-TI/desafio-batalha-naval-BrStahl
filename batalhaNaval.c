#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Função que valida se ja possui navio no local.
int verificaposicao(int linha,int coluna,int tamanho,int orientacao, int Tab[10][10]){
    if(orientacao == 0){
        for(int aux = coluna; aux < coluna+tamanho;aux++){
            if(Tab[linha][aux] != 0 ){
                return 0; 
            }
        }
    } else if(orientacao == 1){
        for (int aux = linha;aux < linha+tamanho;aux++){
            if(Tab[aux][coluna] != 0){
                return 0;
            }
        }
    } else if(orientacao == 2){ // Diagonal Principal
        for (int i = 0; i < tamanho; i++) {
            if (Tab[linha + i][coluna + i] != 0) {
                return 0;
            }
        }
    }  else if(orientacao == 3){ // Diagonal Secundaria
        for (int i = 0; i < tamanho; i++) {
            if (Tab[linha + i][coluna - i] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {

    // Variaveis de Agua,Navio,Tamanho Tabuleiroe e Tabuleiro 10x10
    int Tamanho_Tabu = 10;
    int Tabuleiro[Tamanho_Tabu][Tamanho_Tabu];
    int Agua = 0;
    int Navio = 3;

    // Variaveis do indice de Linha (1 - 10) e do Indice de Coluna (A - J)
    char Colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int Linha[10] ={1,2,3,4,5,6,7,8,9,10};

    // Inicializa o Tabuleiro do jogo 10x10
    for (int linha = 0; linha < 10; linha++){
        for(int coluna = 0; coluna <10; coluna++){
            Tabuleiro[linha][coluna] = Agua;
        }
    }

    printf("-------Legandas Tabuleiro-------\n");

    printf("\nLegenda\n");
    printf("\nÁgua = 0\n");
    printf("Navio = 3\n");
    
    printf("\n   ");

    printf("\n-------Tabuleiro Batalha Naval-------");
    printf("\n   ");

    //Variaveis do Navio 1 (Horizontal) no Tabuleiro.
    int Tamanho_Navio1 = 4;
    int Linha_navio1 = 1;
    int Coluna_navio1 = 2;
    int Orientacao_Navio1 = 0; // 0 - Horizontal, 1 - Vertical, 2 - Diagonal Secundaria, 3 - Diagonal Principal
    
    // Verificad se não excede o tamanho do Tabuleiro
    if(Tamanho_Navio1 + Coluna_navio1 > 10){
        printf("Navio 1 não foi posicionado!\n");
    } else { 
        if(!verificaposicao(Linha_navio1,Coluna_navio1,Tamanho_Navio1,Orientacao_Navio1,Tabuleiro)){ // Chama função de validação de posição
            printf("ERRO: Navio 1 não posicionado, pois ja possui um navio na posição desejada!\n");
            return 0;
        } else { // Inicializa o Navio 1 no tabuleiro
            for(int indice = Coluna_navio1 ;indice < Coluna_navio1+Tamanho_Navio1;indice++){
                Tabuleiro[Linha_navio1][indice] = Navio;
            }
        }
    }

    printf("\n   ");

    //Variaveis do Navio 2 (Vertical) no Tabuleiro.
    int Tamanho_Navio2 = 4;
    int Linha_navio2 = 2;
    int Coluna_navio2 = 8;
    int Orientacao_Navio2 = 1; // 0 - Horizontal, 1 - Vertical, 2 - Diagonal Secundaria, 3 - Diagonal Principal
    
    // Verificad se não excede o tamanho do Tabuleiro
    if(Tamanho_Navio2 + Linha_navio2 > 10){
        printf("Navio 2 não foi posicionado!\n");
    } else {
        if(!verificaposicao(Linha_navio2,Coluna_navio2,Tamanho_Navio2,Orientacao_Navio2,Tabuleiro)){ // Chama função de validação de posição
            printf("ERRO: Navio 2 não posicionado, pois ja possui um navio na posição desejada!\n");
            return 0;
        } else { // Inicializa o Navio 2 no tabuleiro
            for(int indice = Linha_navio2 ;indice < Linha_navio2+Tamanho_Navio2;indice++){
                Tabuleiro[indice][Coluna_navio2] = Navio;
            }
        }

    }

    printf("\n   ");

    //Variavel Navio 3 - Diagonal Principal
    int Tamanho_navio3 = 6;
    int linha_navio3 = 0;
    int coluna_navio3 = 8;
    int orientacao_navio3 = 2; // 0 - Horizontal, 1 - Vertical, 2 - Diagonal Secundaria, 3 - Diagonal Principal

    if (linha_navio3 + Tamanho_navio3 > 10 || coluna_navio3 - Tamanho_navio3 < -1){
        printf("ERRO: Navio excede o tamanho do tabuleiro!");
    } else {
        if (!verificaposicao(linha_navio3,coluna_navio3,Tamanho_navio3,orientacao_navio3,Tabuleiro)){
            printf("ERRO: Navio 3 não posicionado pois na posicão informada ja existe um navio!");
        } else {
            for (int i = 0 ; i < Tamanho_navio3;i++){
                Tabuleiro[linha_navio3+i][coluna_navio3-i] = Navio;
            }
        }
    }

    //Variavel Navio 4 - Diagonal Secundaria
    int Tamanho_navio4 = 5;
    int linha_navio4 = 5;
    int coluna_navio4 = 0;
    int orientacao_navio4 = 3; // 0 - Horizontal, 1 - Vertical, 2 - Diagonal Secundaria, 3 - Diagonal Principal

    if (linha_navio4 + Tamanho_navio4 > 10 || coluna_navio4 + Tamanho_navio4 > 10){
        printf("ERRO: Navio 4 excede o tamanho do tabuleiro!");
    } else {
        if(!verificaposicao(linha_navio4,coluna_navio4,Tamanho_navio4,orientacao_navio4,Tabuleiro)){
            printf("ERRO: Navio 4 não posicionado pois na posicão informada ja existe um navio!");
        } else {
            for (int i = 0 ; i < Tamanho_navio4;i++){
                Tabuleiro[linha_navio4+i][coluna_navio4+i] = Navio;
            }
        }
    }

    //Exibição dos Indices da Coluna
    for (int aux = 0; aux < 10; aux++){
        printf(" %c  ",Colunas[aux]);
    }

    printf("\n");

    //Exibe Tabuleiro 
    for (int linha = 0; linha < 10;linha++){
    
        //Exibição dos Indices da Coluna
        if(linha < 9){
            printf("%d   ",Linha[linha]);
            //Exibição dos Indices da Coluna
            for(int coluna = 0; coluna < 10;coluna++){
                printf("%d | ",Tabuleiro[linha][coluna]);
            }
                printf("\n");
        } else{
            printf("%d  ",Linha[linha]);
            for(int coluna = 0; coluna < 10;coluna++){
                printf("%d | ",Tabuleiro[linha][coluna]);
            }
            printf("\n");
        }
    }
        printf("------------------------------------------\n");
    return 0;
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

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
}
