// Crie um algoritmo que recebe entradas inteiras do usuário até um momento que ele digitar um valor X que servirá como parada. X = -1, lembrando que o valor X não pode ser contavilizado para nada(somatório, média, menor valor, maior valor...). Ao final, o algoritmo deverá informar:
// a. O valor somatório de todos os números;
// b. O valor da média de todos os números;
// c. O menor e o maior números informados;

#include <stdio.h>

int main() {

    int num=0, soma=0, maior=0, menor=100000, qtd_num = 0;
    float media = 0.0;

    while(num != -1) {
        
        printf("Insira um valor: ");
        scanf("%i", &num);
        if (num == -1) {
            break;
        } else {
            soma += num;
            qtd_num++;
            if (num > maior) {
                maior = num;
            }
            if (num < menor) {
                menor = num;
            }
        }
    }
    media = soma/qtd_num;

    printf("somatório: %i, média: %f, menor: %i, maior: %i", soma, media, menor, maior );
    return 0; 

}