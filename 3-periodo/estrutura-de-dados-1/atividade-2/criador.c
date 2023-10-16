#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "fazenda.h"
#include "animal.h"

int id = 1;

struct criador
{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;//Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio; //esse valor deve ser constantemente modificado para que o valor esteja atualizado	
	struct criador *prox, *ant; //lista dupla encadeada, nao é necessário ser circular
};

Criador *criarListaDuplaCriadores(){
	return NULL;
}

Criador *cadastrar(Criador *criadores){
	Criador *new = (Criador*) calloc(sizeof(Criador),1), *aux;
	Fazenda *aux = criarListaEncadeadaCircularFazendas();
	new->id_criador = id;
	id++;
	new->fazendas = aux;
	printf("Nome - ");
	scanf("%s", new->nome);
	new->patrimonio = 0.0;
	new->prox = NULL;
	new->ant = criadores;
	if (listaVazia(criadores)) return new;
	aux = criadores;
	while (aux->prox) aux = aux->prox;
	aux->prox = new;
	return criadores;
}

Criador *remover(Criador *criadores){
	Criador *aux = criadores;
	Criador *aux2 = buscar(criadores);
	if (aux2 == aux && aux->fazendas) {
			return aux->prox;
	}

	while(aux){
		if (aux->prox == aux2 && aux->fazendas) {
				aux->prox = aux2->prox;
				return criadores;
		} 
		aux = aux->prox;
	};
}

Criador *buscar(Criador *criadores){
	Criador *aux = criadores;

	if (!listaVazia(criadores)){
		while (aux){
			if (aux->id_criador == id) return aux;
			else aux = aux->prox;
		}
	}
	return 0;
}

void patrimonio(Criador *criadores){
	Criador *aux = buscar(criadores);
	printf("Patrimonio: %.2f\n", aux->patrimonio);
}

int listaVazia(Criador *criadores){
	if (!criadores) return 1;
	return 0;
}

Criador *criarFazendaCriador(Criador *criador){
	Fazenda *fazenda = (Fazenda*)malloc(sizeof(Fazenda*));
	Criador *aux = criador;
	while (aux->prox){
		aux = aux->prox;
	}
	fazenda = cadastrarFazenda(fazenda, aux);
	aux->fazendas = fazenda;
	return criador;
}

Criador *remover(Criador *criadores, int id_criador) {
	Criador *aux = criadores;
	Criador *ant;
	while (aux->prox && aux->id_criador != id_criador){
		ant = aux;
		aux = aux->prox;
	} 
	if (aux->fazendas) ant->prox = aux->prox;
	return criadores;
}

void mostrarCriadores(Criador *criadores){
	Criador *aux = criadores;
	while(aux){
		printf("ID: %d\nNome: %s\nPatrimonio: %.2f\n", aux->id_criador, aux->nome, aux->patrimonio);
		if(aux->fazendas) printf("Possui fazenda\n\n");
		aux = aux->prox;
	}
}

Criador *buscar(Criador *criadores) {
	Criador *criador = criadores;
	int id;
	printf("Qual o id do dono da fazenda?\n");
    scanf("%d", &id);
	while (criador->prox && criador->id_criador != id){
		criador = criador->prox;
	}
	return criador;
}

Criador *fazendaCriador(Criador *criador){
	Fazenda *fazenda = criador->fazendas;
	fazenda = buscarFazenda(fazenda);
	return fazenda;
}

Criador *animalCriador(Fazenda *fazenda){
	Animal *animal = fazenda = animalCriador(fazenda);
	return fazenda;
}