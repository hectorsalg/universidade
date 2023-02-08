#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

int main(){
    Conta *conta;
    conta = criarPilha();
    conta = inserir(conta);
    conta = inserir(conta);
    conta = inserir(conta);
    conta = remover(conta);
    printf("\nTopo\n");
    mostrarTopo(conta);
    printf("\n\nToda a lista\n");
    mostrarTodaPilha(conta);
    liberar(conta);
    printf("\n\nToda a lista depois de liberar\n");
    mostrarTodaPilha(conta);
    return 0;
}