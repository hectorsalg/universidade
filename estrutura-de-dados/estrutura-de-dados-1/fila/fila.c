#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fila.h"

struct conta{
	float saldo;
	char titular[100];
	int num;
	struct conta *prox;
};

struct fila{
    struct conta *inicio, *fim;
};

Fila *criarFila(){
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
	return fila;
}

void inserir(Fila* fila){
    Conta *new = (Conta*) malloc(sizeof(Conta));

	new->num = rand() % 100 + 10;
    printf("%d\n", new->num);
	printf("Nome - ");
	scanf(" %s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
    new->prox = NULL;

    if(vazio(fila)){
        fila->inicio = new;
        fila->fim = new;
    }

    fila->fim->prox = new;
    fila->fim = new;

}

int vazio(Fila *filas){
    if(!filas->inicio) return 1;
    return 0;
}

int remover(Fila* fila){
    Conta *aux; 
    if(vazio(fila)) return 0;
    else if(fila->inicio == fila->fim){
        fila->inicio = fila->fim = NULL;
        return 1;
    }else{ 
        aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        return 1;
    }
}

void mostrarInicio(Fila *fila){
    if(vazio(fila)) printf("Lista vazia\n\n");
    else printf("Titular: %s\nSaldo: %.2f\nNum Conta: %d\n\n", fila->inicio->titular, fila->inicio->saldo, fila->inicio->num);
}

void mostrarFim(Fila *fila){
    if(!vazio(fila)) printf("Lista vazia\n\n");
    else printf("Titular: %s\nSaldo: %.2f\nNum Conta: %d\n\n", fila->fim->titular, fila->fim->saldo, fila->fim->num);
}

void mostrarTodaFila(Fila *fila){
    Conta *aux = fila->inicio;
    if(vazio(fila)) printf("Lista vazia\n\n");
    else if(aux->prox == fila->fim && fila->fim->prox != NULL) printf("Titular: %s\nSaldo: %.2f\nNumeros: %d\n", aux->titular, aux->saldo, aux->num);
    else {
        while(aux){
            printf("Titular: %s\nSaldo: %.2f\nNum Conta: %d\n", aux->titular, aux->saldo, aux->num);
            aux = aux->prox;
        }
    }
}

void liberar(Fila* fila){
    Conta *temp, *head = fila->inicio;

    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp);
    }
    free(fila->inicio);
    free(fila->fim);
}
