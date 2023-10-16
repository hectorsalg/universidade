#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "listadinamicasimples.h"

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
	Conta *new = (Conta*) malloc(sizeof(Conta));
	new->num_conta = rand() % 100 + 10;
	printf("%d\n", new->num_conta);
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	new->prox = lista;
	return new;
}

Conta *inserirFim(Conta *lista){
	srand(time(NULL));
	Conta *aux, *new = (Conta*) malloc(sizeof(Conta));
	new->num_conta = rand() % 100 + 10;
	printf("%d\n", new->num_conta);
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	new->prox = NULL;
	if (listaVazia(lista)) return new;
	aux = lista;
	while(aux->prox) aux = aux->prox;
	aux->prox = new;
	return lista;
}

Conta *inserirOrdenado(Conta *lista) {
	srand(time(NULL));
	Conta *new = (Conta*) malloc(sizeof(Conta));
	Conta *aux, *ant;
	aux = lista;
	ant = NULL;
	new->num_conta = rand() % 100 + 10;
	printf("%d\n", new->num_conta);
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	new->prox = NULL;
	if (listaVazia(lista)) return new;
	while(aux && aux->num_conta < new->num_conta){
		ant = aux;
		aux = aux->prox;
	}
	if(ant == NULL) {
		new->prox = lista;
		lista = new;
	} else {
		ant->prox = new;
		new->prox = aux;
	}
	return lista;
}

Conta *remover(Conta *lista, int valor){
	Conta *aux = lista;
	Conta *aux2 = buscar(lista, valor);
	if (aux2 == aux) {
			return aux->prox;
	}

	while (aux) {
		if (aux->prox == aux2) {
				aux->prox = aux2->prox;
				return lista;
		} 
		aux = aux->prox;
	}
}
Conta *buscar(Conta *lista, int valor){
	Conta *aux = lista;

	if (!listaVazia(lista)){
		while(aux){
			if (aux->num_conta == valor || aux->saldo == valor) return aux;
			else aux = aux->prox;
		}
	}
}

Conta *alterar(Conta *lista, int oldValue, int newValue) {
	Conta *aux, *aux2, *resul = (Conta*) malloc(sizeof(Conta));
	aux = buscar(lista, oldValue);
	aux2 = buscar(lista, oldValue);
	if (aux->saldo == oldValue) {
		aux->saldo = newValue;
	} else if (aux->num_conta == oldValue) {
		aux->num_conta = newValue;
	}
	resul = lista;

	while (resul->prox) {
		if (resul == aux2) {
			resul = aux;
			return resul;
		} else {
			if (resul->prox == aux2) {
				resul->prox = aux;
				return resul;
			} 
		}
		resul = resul->prox;
	}
}

int listaVazia(Conta *lista){
	if (!lista) return 1;
	return 0;
}

void mostrarLista(Conta *lista){
	Conta *aux = (Conta*) malloc(sizeof(Conta));
	aux = lista;
	while(aux){
		printf("Nome: %s\nSaldo: %.2f\nNum conta %d\n\n", aux->titular, aux->saldo, aux->num_conta);
		aux = aux->prox;
	}
}

void liberarLista(Conta *lista){
	free(lista);
}