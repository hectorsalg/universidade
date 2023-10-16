#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "imagem.h"


// A imagem é composta de pixel, cada pixel tem suas coordenadas (x, y) e seu valor (fiquem a vontade para preencher da forma que quiserem) além dos valores a imagem tem altura e largura.

// /* 
struct pixel{
    int valor, x, y;
};
struct imagem{
    Pixel *pixels;
    int largura, altura;
};
// */

Imagem *criarImagem(int largura, int altura) {
    Imagem *img;
    img = (Imagem*)malloc(sizeof(Imagem));
    img->altura = altura;
    img->largura = largura;
    img->pixels = (Pixel*)malloc(altura * largura * sizeof(Pixel));
    return img;
}

void preencherImagem(Imagem *img) {

    srand(time(NULL));
    int valor = 0, k;

    for(int i = 0; i < img->altura; i++) {
        for (int j = 0; j < img->largura; j++) {
            k = i * img->largura + j;
            valor = rand() % 255;
            // scanf("%d", &valor);
            // while (valor < 0 && valor > 255) {
            //     printf("Digite um valor positivo: ");
            //     scanf("%d", &valor);
            // } 
            setPixelValue(img, i, j, valor);
        }
    }
}

void imprimirImagem(Imagem *img) {
    int k;
    for(int i = 0; i < img->altura; i++) {
        for (int j = 0; j < img->largura; j++) {
            k = i * img->largura + j;
            printf("%d ", img->pixels[k].valor);
        }
        printf("\n");
    }
}

void liberarImagem(Imagem *img) {
    for (int i = 0; i < img->altura; i++){
        for (int j = 0; j < img->largura; j++){
            free(img);
        }
    }
}

void setPixelValue(Imagem *img, int y, int x, int valor) {
    int k;
    for(int i = y; i < img->altura; i++) {
        for (int j = x; j < img->largura; j++) {
            k = i * img->largura + j;
            if (i == y && j == x) {
                k = i * img->largura + j;
                img->pixels[k].valor = valor;
            }
        }
    }
}
    
int getPixelValue(Imagem *img, int y, int x) {
    int k;
    for(int i = 0; i < img->altura; i++) {
        for (int j = 0; j < img->largura; j++) {
            if (i == y && j == x) {
                k = i * img->largura + j;
                return img->pixels[k].valor;
            }
        }
    }
}