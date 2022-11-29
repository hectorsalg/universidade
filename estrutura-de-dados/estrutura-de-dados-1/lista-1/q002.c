//  Crie uma solução que recebe uma matriz de M x N (m = 200, n = 100) informados pelo usuário. Essa matriz será preenchida aleatoriamente de 0 a X ( valor informado pelo usuário). Ao final o algoritmo deverá apresentar quantas vezes cada número contida na matriz ocorreu. Exemplo para uma matriz qualquer: [1, 0, 2, 3, 4, 1, 0, 9]:
// O número 0 ocorreu 2 vezes
// O número 1 ocorreu 2 vezes
// O número 2 ocorreu 1 vez
// O número 3 ocorreu 1 vez
// O número 4 ocorreu 1 vez
// O número 9 ocorreu 1 vez
// Como pode ser observado, a questão de plural nas frases deve ser tratado; os números que são ocorrerem na matriz não devem ser apresentados.


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    srand(time(NULL));

    int X, matriz[200][100], qtd0=0, qtd1=0,qtd2=0,qtd3=0,qtd4=0,qtd5=0,qtd6=0,qtd7=0,qtd8=0, qtd9=0;

    printf("Insira um valor limite: ");
    scanf("%i", &X);

    for (int i = 0; i < X; i++) {
        for (int m = 0; m < 200; m++) {
            for (int n= 0; n < 100; n++) {
                matriz[m][n] = rand() % 10;
                switch(matriz[m][n]) {
                    case 0:
                        qtd0++;
                        break;
                    case 1:
                        qtd1++;
                        break;
                    case 2:
                        qtd2++;
                        break;
                    case 3:
                        qtd3++;
                        break;
                    case 4:
                        qtd4++;
                        break;
                    case 5:
                        qtd5++;
                        break;
                    case 6:
                        qtd6++;
                        break;
                    case 7:
                        qtd7++;
                        break;
                    case 8:
                        qtd8++;
                        break;
                    case 9:
                        qtd9++;
                        break;
                }
                break;
            }
            break;
        }
    }
    if (qtd0 > 1) {
        printf("O número 0 correu %i vezes \n", qtd0);
    } else if (qtd0 == 1) {
        printf("O número 0 correu %i vez \n", qtd0);
    }
    if (qtd1 > 1) {
        printf("O número 1 correu %i vezes \n", qtd1);
    } else if (qtd1 == 1) {
        printf("O número 1 correu %i vez \n", qtd1);
    }
    if (qtd2 > 1) {
        printf("O número 2 correu %i vezes \n", qtd2);
    } else if (qtd2 == 1) {
        printf("O número 2 correu %i vez \n", qtd2);
    }
    if (qtd3 > 1) {
        printf("O número 3 correu %i vezes \n", qtd3);
    } else if (qtd3 == 1) {
        printf("O número 3 correu %i vez \n", qtd3);
    }
    if (qtd4 > 1) {
        printf("O número 4 correu %i vezes \n", qtd4);
    } else if (qtd4 == 1) {
        printf("O número 4 correu %i vez \n", qtd4);
    }
    if (qtd5 > 1) {
        printf("O número 5 correu %i vezes \n", qtd5);
    } else if (qtd5 == 1) {
        printf("O número 5 correu %i vez \n", qtd5);
    }
    if (qtd6 > 1) {
        printf("O número 6 correu %i vezes \n", qtd6);
    } else if (qtd6 == 1) {
        printf("O número 6 correu %i vez \n", qtd6);
    }
    if (qtd7 > 1) {
        printf("O número 7 correu %i vezes \n", qtd7);
    } else if (qtd7 == 1) {
        printf("O número 7 correu %i vez \n", qtd7);
    }
    if (qtd8 > 1) {
        printf("O número 8 correu %i vezes \n", qtd8);
    } else if (qtd8 == 1) {
        printf("O número 8 correu %i vez \n", qtd8);
    }
    if (qtd9 > 1) {
        printf("O número 9 correu %i vezes \n", qtd9);
    } else if (qtd9 == 1) {
        printf("O número 9 correu %i vez \n", qtd9);
    }

    return 0;

}