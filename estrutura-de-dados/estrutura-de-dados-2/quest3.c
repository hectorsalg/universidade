#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5
#define TAMS 11


void maiorStr(char VS[TAM][TAMS], int i, int qtdS, char maiorS[TAMS]) {
    if(i < qtdS) {
        maiorStr(VS, i + 1, qtdS, maiorS);
        if (strlen(VS[i]) > strlen(maiorS))
            strcpy(maiorS, VS[i]);
    }
}

int isVogal(char c) {
    return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || 
        c == 'i' || c == 'I' || c == 'o' || c == 'O' ||
        c == 'u' || c == 'U');
}

void iniciaVogal(char VS[TAM][TAMS], int i, int qtdS, int *qtdVogal) {
    if (i < qtdS) {
        if(isVogal(VS[i][0]))
            (*qtdVogal)++;
        iniciaVogal(VS, i + 1, qtdS, qtdVogal);
    }
}

int iniciaMaiuscula(char c) {
    return (c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' ||
            c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' ||
            c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' ||
            c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' ||
            c == 'Y' || c == 'Z');
}

void str4plus(char VS[TAM][TAMS], int i, int qtdS, char maiores4[TAM][TAMS], int j) {
    if (i < qtdS) {
        if(strlen(VS[i]) > 4 && iniciaMaiuscula(VS[i][0])) {
            printf("\n STRLEN: %d\n", strlen(VS[i]));
            strcpy(maiores4[j], VS[i]);
            str4plus(VS, i + 1, qtdS, maiores4, j + 1);
        } else
            str4plus(VS, i + 1, qtdS, maiores4, j);
    }
}

int main() {

    char VS[TAM][TAMS], maiorS[TAMS], maiores4[TAM][TAMS];
    int count = 0, qtdS = TAM, qtdVogal = 0;

    for(int i = 0; i < TAM; i++) {
            fgets(VS[i], TAMS, stdin);
    }

    maiorStr(VS, count, qtdS, maiorS);
    iniciaVogal(VS, count, qtdS, &qtdVogal);
    str4plus(VS, count, qtdS, maiores4, count);
    
    printf("\n");
    printf("Letra A:\n");
    for(int i = 0; maiorS[i] != '\0'; i++) {
        printf("%c", maiorS[i]);
    }
    printf("\n");

    printf("Letra B:\n%d\n", qtdVogal);

    printf("\n");
    printf("Letra C:\n");
    for(int i = 0; i < TAM; i++) {
        for (int j = 0; maiores4[i][j] != '\0'; j++) {
            printf("%c", maiores4[i][j]);
        }
    } 

    printf("\n");

    return 0;
}