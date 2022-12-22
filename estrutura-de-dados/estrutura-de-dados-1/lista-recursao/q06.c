#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int procura(int valor, int tam, int vet[], int count);

int procura(int valor, int tam,int vet[], int count){
    if (count == tam) return -1;
    else if (vet[count] == valor) return count;
    return procura(valor, tam, vet, count + 1);
}

int main(){

    srand(time(NULL));

    int valor, vetor[10], tam = sizeof(vetor) / sizeof(int);

    for (int i = 0; i < 10; i++) {
        vetor[i] = rand() % 100;
    }

    printf("Insira um valor: ");
    scanf("%d", &valor);

    if (procura(valor, tam, vetor, 0) == -1) {
        printf("Valor não encontrado!\n");
        return 0;
    }
    printf("Valor encontrado na posição %d\n", procura(valor, tam, vetor, 0));

    return 0;
}