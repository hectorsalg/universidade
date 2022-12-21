#include <stdio.h>

int positivos(int K);

int positivos(int K){
    if (K < 0) return K;
    return printf("%d ", K), positivos(K - 1);
}

int main(){

    int K;

    printf("Informe um valor: ");
    scanf("%d", &K);

    positivos(K);

    return 0;
}