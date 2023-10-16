#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaestatica.h"

struct conta
{
	float saldo;
	int num_conta;
	char nome[100];
	
};

Conta *criarListaContasEstatica(int tam){
	Conta *listaContas = (Conta*) calloc(sizeof(Conta), tam);
	return listaContas;
}
void inserirElemento(Conta *lista, int p, int t){
	srand(time(NULL));
	if (p < t)
	{	
		printf("insira o saldo: ");
		scanf("%f", &lista[p].saldo);
		printf("insira o nome: ");
		scanf("%s", lista[p].nome);
		lista[p].num_conta = rand() % 100 + 10;
		// saber o numero da conta
		printf("%d\n", lista[p].num_conta);
	} else {
		for (int i = 0; i < t; i++){
			if (lista[i].nome[0] == '0') {
				printf("insira o saldo: ");
				scanf("%f", &lista[i].saldo);
				printf("insira o nome: ");
				scanf("%s", lista[i].nome);
				lista[i].num_conta = rand() % 100 + 10;
				break;
			}
		}
		printf("lista cheia.\n");
	}
	
}

void mostrarElemento(Conta *elemento, int p){
	if (elemento[p].nome[0] == '0'){
		printf("");
	} else printf("\nSaldo: %.2f\nNome: %s\nNumero da Conta: %d\n", elemento[p].saldo, elemento[p].nome, elemento[p].num_conta);
}
void mostrarTodosElementos(Conta *lista, int t){
	for (int i = 0; i < t; i++)
	{
		mostrarElemento(lista, i);
	}
}
//remover pelo numero da conta
void removerElemento(Conta *lista, int cnum,int t){
	int pos;

	pos = buscarElemento(lista, t, cnum);

    if(pos != -1){ 
        lista[pos].nome[0] = '0'; 
        lista[pos].num_conta = -1;
        lista[pos].saldo = 0.0;
    }else printf("Conta inexistente.\n");
}

int buscarElemento(Conta *lista, int tam, int num_conta){
	for (int i = 0; i < tam; i++)
	{	
		if (lista[i].num_conta == num_conta) {
			return i;
		}
	}
	return -1;
}

void liberarMemoria(Conta *listaContas){
	free(listaContas);
}

void mostrarSaldo(Conta *lista, int num_conta, int tamanho){
	int pos = buscarElemento(lista, tamanho, num_conta);
	printf("saldo: %.2f", lista[pos].saldo);
}