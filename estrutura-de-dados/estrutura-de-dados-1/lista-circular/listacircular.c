#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "listacircular.h"

struct conta{
	float saldo;
	char titular[100];
	int num_conta;
	struct conta *prox;
};

Conta *criarLista(){
	return NULL;
}

Conta *inserirInicio(Conta *lista){
	srand(time(NULL));
	Conta *new = (Conta*) malloc(sizeof(Conta)), *aux;
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf(" %s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	if (listaVazia(lista)) {
        new->prox = new;
    } else {
		aux = lista;
		while(aux->prox != lista) {
			aux = aux->prox;
		}
		new->prox = lista;
		aux->prox = new;
	}
	return new;
}

Conta *inserirFim(Conta *lista){
    srand(time(NULL));
	Conta *new = (Conta*) malloc(sizeof(Conta)), *aux;
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf(" %s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	if (listaVazia(lista)) {
        new->prox = new;
        return new;
    }
	aux = lista;
	while(aux->prox != lista) {
        aux = aux->prox;
    }
    new->prox = lista;
	aux->prox = new;
	return lista;
}

Conta *inserirOrdenado(Conta *lista){
	srand(time(NULL));
	Conta *new= (Conta*) malloc(sizeof(Conta)), *aux, *ant;
	new->num_conta = rand() % 100 + 10;
	printf("\n%d\n", new->num_conta);
	printf("Nome - ");
	scanf(" %s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	if (!lista) {
        new->prox = new;
        return new;
    }
	aux = lista;
	ant = lista;
	do {
		ant = aux;
		aux = aux->prox;
	} while (aux != lista && new->num_conta > aux->num_conta);
	if (new->num_conta < lista->num_conta) {
		new->prox = lista;
		while (aux->prox != lista) aux = aux->prox;
		aux->prox = new;
		return new;
	}
	ant->prox = new;
	new->prox = aux;
	while(aux->prox != lista) aux = aux->prox;
	aux->prox = lista;
	return lista;
}

Conta *remover(Conta *lista, int valor) {
	Conta *aux = lista;
	Conta *aux2 = buscar(lista, valor);
	if (aux2 == aux) {
			return aux->prox;
	}

	do {
		if (aux->prox == aux2) {
				aux->prox = aux2->prox;
				return lista;
		} 
		aux = aux->prox;
	} while (aux != lista);
}

Conta *buscar(Conta *lista, int valor){
	Conta *aux = lista;

	if (!listaVazia(lista)){
		do {
			if (aux->num_conta == valor || aux->saldo == valor) return aux;
			else aux = aux->prox;
		} while (aux != lista);
	}
	return 0;
}

Conta *alterar(Conta *lista, int oldValue, int newValue) {
	Conta *aux, *busca = (Conta*) malloc(sizeof(Conta));
	busca = buscar(lista, oldValue);
	
	if (busca) {
		do {
			if (aux->num_conta == busca->num_conta) {
				aux->num_conta == newValue;
			} else if (aux->saldo == busca->saldo) {
				aux->saldo == newValue;
			}
			aux = aux->prox;
		} while (aux != lista);
	}
}

int listaVazia(Conta *lista){
	if (!lista) return 1;
	return 0;
}

void mostrarLista(Conta *lista){
    Conta *aux = lista;
    if (!listaVazia(lista)){
        do{
            printf("Nome: %s\nSaldo: %.2f\nNum Conta: %d\n\n", aux->titular, aux->saldo, aux->num_conta);
            aux = aux->prox;
        } while (aux != lista);
    }
}

void liberarLista(Conta *lista) {
	free(lista);
}