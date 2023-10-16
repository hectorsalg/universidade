#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

double calcularTempoSelectionSort(int arr[], int n) {
    clock_t inicio, fim;
    double tempoExecucao;

    inicio = clock(); // Tempo de início do algoritmo

    selectionSort(arr, n); // Chama a função Selection Sort

    fim = clock(); // Tempo de fim do algoritmo

    tempoExecucao = ((double) (fim - inicio)) / CLOCKS_PER_SEC; // Cálculo do tempo de execução em segundos

    return tempoExecucao;
}

double calcularMediaTempo(int arr[], int n, int num_execucoes) {
    double tempo_total = 0.0;

    for (int i = 0; i < num_execucoes; i++) {
        tempo_total += calcularTempoSelectionSort(arr, n);
    }

    return tempo_total / num_execucoes;
}

int main() {
    FILE *arquivo;
    arquivo = fopen("dados3.txt", "r"); // Abre o arquivo em modo de leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    int n = 100000; // Tamanho do vetor
    int arr[n];
    int i;

    for (i = 0; i < n; i++) {
        fscanf(arquivo, "%d", &arr[i]); // Lê os dados do arquivo e armazena no vetor
    }

    fclose(arquivo); // Fecha o arquivo

    int num_execucoes = 30;
    double media_tempo = calcularMediaTempo(arr, n, num_execucoes);

    printf("Media do tempo de execucao do Selection Sort em %d execucoes: %.6f segundos", num_execucoes, media_tempo);

    return 0;
}