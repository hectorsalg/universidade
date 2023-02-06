#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fazenda.h"
#include "animal.h"

struct animal{
	int id_animal, id_fazenda;
	char sexo; // M ou F
	float peso; //em KG
	int status; // 1 - Nascimento na propria fazenda | 2 - venda | 3 - troca 
	struct animal *prox;
};

int id = 1;

Animal *criaListaEncadeadaSimplesAnimais(){
	return NULL;
}

Animal *cadastrarAnimal(Animal *rebanho, Fazenda *fazenda){
	srand(time(NULL));
	Animal *new = (Animal*) malloc(sizeof(Animal));
	// Fazenda *aux = fazenda;
	new->id_animal = id;
	id++;
	new->id_fazenda = //fazenda->id_fazenda;
	printf("Sexo - M ou F");
	scanf("%c", &new->sexo);
	while(new->sexo != 'M' || new->sexo != 'F') scanf("%c", &new->sexo);
	new->peso = 300 + (rand() % 1200);
	printf("Status - 1 - Nascimento na propria fazenda | 2 - venda | 3 - troca - ");
	scanf("%d", &new->status);
	while(new->status < 1 && new->status > 3) scanf("%d", &new->status);
	new->prox = NULL;
	if (listaVazia(rebanho)) return new;
	// aux = rebanho;
	// while(*aux->prox*) aux = aux->prox;
	// aux->prox = new;
	return rebanho;
}

Animal *removerAnimal(Fazenda *fazenda, int id_animal) {
	fazenda = animalFazenda(fazenda);
	Animal *aux = fazenda;
	Animal *ant;
	while (aux->prox && aux->id_animal == id_animal) {
		ant = aux;
		aux = aux->prox;
	}
	ant->prox = aux->prox;
	return fazenda;
}

int listaVazia(Animal *rebanho){
	if (!rebanho) return 1;
	return 0;
}