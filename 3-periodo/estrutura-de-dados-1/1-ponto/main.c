#include <stdio.h>
#include <stdlib.h>

#include "imagem.h"

int main() {
    Imagem *img;

    img = criarImagem(5,5);
    preencherImagem(img);
    imprimirImagem(img);
    printf("\n");
    // img->pixels[10].valor = 255;
    // printf("%d\n\n", img->pixels[10].valor);
    // imprimirImagem(img);
    setPixelValue(img, 3, 2, 255);
    printf("Valor da posicao 3,2 %d\n", getPixelValue(img, 3, 2));
    imprimirImagem(img);

    /*
    1- Comente o que acontece com as linhas 15 e 16
    img->pixel[10].valor = 255;
    printf("%d ", img->pixel[10].valor);
    */ 
    /*
    2- Comente o que acontece com as linhas 20 e 21
    setPixelValue(img, 3, 2, 255);
    printf("Valor da posicao 3,2 %d\n", getPixelValue(img, 3, 2))
    */    

    liberarImagem(img);

    return 0;
}