#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pilha.h"

struct conta{
    float saldo;
    char titular[100];
    int num;
    struct conta *prox;
};

Conta *criarPilha(){
    return NULL;
}

Conta *inserir(Conta *conta){
    srand(time(NULL));
    Conta *new = (Conta*) malloc(sizeof(Conta));
    new->num = rand() % 100;
    printf("%d\n", new->num);
    printf("Nome - ");
    scanf(" %s", new->titular);
    printf("Saldo - ");
    scanf("%f", &new->saldo);
    new->prox = conta;
    return new;
}

Conta *remover(Conta *conta){
    Conta *aux = conta;
    if (vazio(conta)) return NULL;
    aux = conta->prox;
    free(conta);
    return aux;
}

int vazio(Conta *conta){
    if (!conta) return 1;
    return 0;
}
void liberar(Conta *conta) {
    while(conta){
        conta = remover(conta);
    }
}
void mostrarTopo(Conta *conta) {
    printf("Nome: %s\nSaldo: %.2f\nNum Conta: %d\n", conta->titular, conta->saldo, conta->num);
}
void mostrarTodaPilha(Conta *conta){
    Conta *aux = conta;
    if (!vazio(conta)) {
        while(aux) {
            printf("Nome: %s\nSaldo: %.2f\nNum Conta: %d\n", aux->titular, aux->saldo, aux->num);
        aux = aux->prox;
        }
    }
}