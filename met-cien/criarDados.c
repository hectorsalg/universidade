#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *arquivo;
    arquivo = fopen("dados2.txt", "w"); // Abre o arquivo em modo de escrita

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    srand(time(NULL)); // Inicializa a semente para números aleatórios

    int i;
    for (i = 0; i <= 99999; i++) {
        int numero = rand() % 100000; // Gera um número aleatório entre 0 e 99.999
        fprintf(arquivo, "%d\n", numero); // Escreve o número no arquivo
    }

    fclose(arquivo); // Fecha o arquivo
    printf("Dados inseridos com sucesso no arquivo.");

    return 0;
}