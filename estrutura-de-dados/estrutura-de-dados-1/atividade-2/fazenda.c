#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
#include "criador.h"
#include "fazenda.h"

struct endereco{
	char cidade[50], estado[2], logradouro[200];
};

int id = 1;

struct fazenda
{
	int id_criador, id_fazenda;
	char nome[100];
	Endereco localizacao;
	float valor_fazenda;//lembrar de atualizar o valor sempre que houver alterações no rebanho
	Animal *rebanho; // ponteiro para uma lista (verificar no .h do animal que lista é)
	//ponteiro para permitir o apontamento para o proximo elemento da lista (deve ser circular)
	struct fazenda *prox;
};

Criador *criarListaEncadeadaCircularFazendas(){
	return NULL;
}

Fazenda *cadastrarFazenda(Fazenda *fazendas, Criador *criadores) {
	Fazenda *new = (Fazenda*) malloc(sizeof(Fazenda)), *aux;
	Animal *auxAnimal = criaListaEncadeadaSimplesAnimais();
	Criador *aux = criadores;
	new->id_fazenda = id;
	id++;
	new->id_criador = aux->id_criador;
	printf("Nome - ");
	scanf(" %s", new->nome);
	new->valor_fazenda = 0.0;
	new->rebanho = auxAnimal;
	printf("Cidade - ");
	scanf(" %s", new->localizacao.cidade);
	printf("Estado - ");
	scanf(" %s", &new->localizacao.estado);
	printf("Logradouro - ");
	scanf(" %s", &new->localizacao.logradouro);
	if (listaVazia(fazendas)) {
        new->prox = new;
        return new;
    }
	aux = fazendas;
	while(aux->prox != fazendas) {
        aux = aux->prox;
    }
    new->prox = fazendas;
	aux->prox = new;
	return fazendas;
}

Fazenda *removerFazenda(Criador *criador) {
	Criador *aux = criador;
	aux = fazendaCriador(aux);
	
	return 0;
}

Fazenda *buscarFazenda(Fazenda *fazendas){
	Fazenda *aux = fazendas;
	int id;
	printf("Qual o id da fazenda?\n");
    scanf("%d", &id);
	if (!listaVazia(fazendas)){
		do {
			if (aux->id_fazenda == id) return aux;
			else aux = aux->prox;
		} while (aux != fazendas);
	}
	return 0;
}

int listaVazia(Fazenda *fazendas){
	if (!fazendas) return 1;
	return 0;
}

Fazenda *criarAnimalFazenda(Fazenda *fazenda){
	Animal *animal = (Animal*)malloc(sizeof(Animal*));
	Fazenda *aux = fazenda;
	while (aux->prox){
		aux = aux->prox;
	}
	animal = cadastrarAnimal(animal, aux);
	aux->rebanho = animal;
	return fazenda;
}

Fazenda *alterarFazenda(Fazenda *fazendas) {
	Fazenda *aux = fazendas;
	aux = buscarFazenda(aux);
	printf("Novo nome - ");
	scanf(" %s", aux->nome);
	printf("Nova Cidade - ");
	scanf(" %s", aux->localizacao.cidade);
	printf("Novo Estado - ");
	scanf(" %s", &aux->localizacao.estado);
	printf("Nova Logradouro - ");
	scanf(" %s", &aux->localizacao.logradouro);

	return fazendas;
}

void qtdSexo(Fazenda *fazenda) {
	Fazenda *aux = fazenda;
	int sexo[2];
	aux = buscarFazenda(aux);
	Animal *animal = animalFazenda(aux);
	while(animal) {
		if (animal->sexo == 'M') sexo[0]++;
		else sexo[1]++;
		animal = animal->prox;
	}
	printf("Quantidade de animais do sexo Masculino: %d\n", sexo[0]);
	printf("Quantidade de animais do sexo Feminino: %d\n", sexo[1]);
}

float fazendaPesoTotal(Fazenda *fazenda) {
	Fazenda *aux = fazenda;
	float pesoT;
	aux = buscarFazenda(aux);
	Animal *animal = animalFazenda(aux);
	while(animal) {
		pesoT += animal->peso;
		animal = animal->prox;
	}
	pesoT /= 15;
	return pesoT;
}

float valorFazenda(Fazenda *fazenda) {
	float valor = fazendaPesoTotal(fazenda);
	valor *= 267.5;
	return valor;
}

void qtdStatus(Fazenda *fazenda) {
	Fazenda *aux = fazenda;
	int status[3];
	aux = buscarFazenda(aux);
	Animal *animal = animalFazenda(aux);
	while(animal) {
		if (animal->status == 1) status[0]++;
		else if (animal->status == 2) status[1]++;
		else status[2]++;
		animal = animal->prox;
	}
	printf("Quantidade de animais do status 1 - Nascido na fazenda: %d\n", status[0]);
	printf("Quantidade de animais do status 2 - Compra/Venda: %d\n", status[1]);
	printf("Quantidade de animais do status 3 - Troca: %d\n", status[2]);
}

Fazenda *animalFazenda(Fazenda *fazenda){
	Animal *animal = fazenda->rebanho;
	return animal;
}