#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "listaDinamicaDupla.h"

struct conta{
	float saldo;
	char titular[100];
	int num_conta;
	struct conta *prox, *ant;
};

Conta *criarLista(){
	return NULL;
}

Conta *inserirInicio(Conta *lista){
	Conta *new = (Conta*) calloc(sizeof(Conta),1);
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	new->ant = NULL;
	new->prox = lista;
	if (!listaVazia(lista))
		lista->ant = new;
	return new;
}

Conta *inserirFim(Conta *lista){
	Conta *new = (Conta*) calloc(sizeof(Conta),1), *aux;
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	scanf("%f", &new->saldo);
	new->prox = NULL;
	new->ant = lista;
	if (listaVazia(lista)) return new;
	aux = lista;
	while (aux->prox) aux = aux->prox;
	aux->prox = new;
	return lista;
}

Conta *inserirOrdenado(Conta *lista){
	srand(time(NULL));
	Conta *new = (Conta*) malloc(sizeof(Conta)), *aux, *prox;
	new->num_conta = rand() % 100 + 10;
	printf("%d\n", new->num_conta);
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	new->prox = NULL;
	new->ant = lista;
	if (listaVazia(lista)) return new;
	aux = lista;
	while (aux->prox && aux->num_conta < new->num_conta) {
		aux = aux->prox;
		prox = aux;
	}
	if (new->num_conta < lista->num_conta) {
		lista->ant = new;
		new->prox = lista;
		new->ant = NULL;
		return new;
	}
	aux->prox = new;
	new->ant = aux;
	return lista;
}

Conta *remover(Conta *lista, int valor){
	Conta *aux = lista;
	Conta *aux2 = buscar(lista, valor);
	if (aux2 == aux) {
			return aux->prox;
	}

	while(aux){
		if (aux->prox == aux2) {
				aux->prox = aux2->prox;
				return lista;
		} 
		aux = aux->prox;
	};
}

Conta *buscar(Conta *lista, int valor){
	Conta *aux = lista;

	if (!listaVazia(lista)){
		while (aux){
			if (aux->num_conta == valor || aux->saldo == valor) return aux;
			else aux = aux->prox;
		}
	}
	return 0;
}

Conta *alterar(Conta *lista, int oldValue, int newValue){
	Conta *aux, *busca = (Conta*) malloc(sizeof(Conta));
	busca = buscar(lista, oldValue);
	
	if (busca) {
		while (aux){
			if (aux->num_conta == busca->num_conta) {
				aux->num_conta == newValue;
			} else if (aux->saldo == busca->saldo) {
				aux->saldo == newValue;
			}
			aux = aux->prox;
		}
	}
}

int listaVazia(Conta *lista){
	if (!lista) return 1;
	return 0;
}

void mostrarLista(Conta *lista){
	Conta *aux = lista;
	while(aux){
		printf("Nome: %s\nSaldo: %.2f\nNum conta %d\n\n", aux->titular, aux->saldo, aux->num_conta);
		aux = aux->prox;
	}
}

void liberarLista(Conta *lista) {
	free(lista);
}