#include <stdio.h>

void divisores(int num, int aux, int i, int vet[], int j) {
    if (aux > 0) {
        if (num % aux == 0) {
            vet[j] = aux;
            divisores(num, --aux, ++i, vet, ++j);
        } else 
            divisores(num, --aux, ++i, vet, j);
    }
}

int main() {

    int num, aux, count, vet[10] = {};

    num = aux = 10;
    count = 0;

    divisores(num, aux, count, vet, count);

    for(int i = 0; i < 10; i++) {
        if (vet[i] != 0)
            printf("%d\n", vet[i]);
    }

    return 0;
}