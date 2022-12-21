#include <stdio.h>

int soma(int K, int resul);

int soma(int K, int resul){
    if (K == 0) return resul;
    return resul += K, soma(K - 1, resul);
}

int main(){

    int K, resul = 0;

    printf("Informe um valor: ");
    scanf("%d", &K);

    printf("%d \n", soma(K, resul));

    return 0;
}