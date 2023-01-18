#include <stdio.h>
#include <stdlib.h>

#include "funcoes.h"

int main() {
    char *str1, *str2;
    str1 = ler();
    str2 = ler();

    printf("Tamanho str1: %d\n", tamanho(str1));
    printf("Tamanho str2: %d\n", tamanho(str2));
    printf("Igualdade: %d\n", iguais(str1, str2));
    printf("Concatenacao: %s\n", concatenar(str1, str2));

    return 0;
}
