#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

int main(){

    Fila *fila;
    fila = criarFila();
    inserir(fila);
    inserir(fila);
    inserir(fila);
    if (remover(fila)) printf("\nRemovido\n");
    else printf("Lista Vazia");
    inserir(fila);
    mostrarInicio(fila);
    mostrarFim(fila);
    mostrarTodaFila(fila);
    liberar(fila);
    return 0;
}