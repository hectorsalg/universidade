#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

double calcularTempoMergeSort(int arr[], int n) {
    clock_t inicio, fim;
    double tempoExecucao;

    inicio = clock(); // Tempo de início do algoritmo

    mergeSort(arr, 0, n - 1); // Chama a função Merge Sort

    fim = clock(); // Tempo de fim do algoritmo

    tempoExecucao = ((double) (fim - inicio)) / CLOCKS_PER_SEC; // Cálculo do tempo de execução em segundos

    return tempoExecucao;
}

double calcularMediaTempo(int arr[], int n, int num_execucoes) {
    double tempo_total = 0.0;

    for (int i = 0; i < num_execucoes; i++) {
        tempo_total += calcularTempoMergeSort(arr, n);
    }

    return tempo_total / num_execucoes;
}

int main() {
    FILE *arquivo;
    arquivo = fopen("dados.txt", "r"); // Abre o arquivo em modo de leitura

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

    printf("Media do tempo de execucao do Merge Sort em %d execucoes: %.6f segundos", num_execucoes, media_tempo);

    return 0;
}