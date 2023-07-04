#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

double calcularTempoQuickSort(int arr[], int n) {
    clock_t inicio, fim;
    double tempoExecucao;

    inicio = clock(); // Tempo de início do algoritmo

    quickSort(arr, 0, n - 1); // Chama a função Quick Sort

    fim = clock(); // Tempo de fim do algoritmo

    tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Cálculo do tempo de execução em segundos

    return tempoExecucao;
}

double calcularMediaTempo(int arr[], int n, int num_execucoes) {
    double tempo_total = 0.0;

    for (int i = 0; i < num_execucoes; i++) {
        tempo_total += calcularTempoQuickSort(arr, n);
    }

    return tempo_total / num_execucoes;
}

int main() {
    FILE* arquivo;
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

    printf("Media do tempo de execucao do Quick Sort em %d execucoes: %.6f segundos", num_execucoes, media_tempo);

    return 0;
}
