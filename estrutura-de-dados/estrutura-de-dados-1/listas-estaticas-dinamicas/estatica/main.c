#include <stdio.h>
#include <stdlib.h>
#include "listaestatica.h"

int main()
{
	int pos = 0, tam = 10, nremove, nsaldo;
	Conta *lista = criarListaContasEstatica(tam);
	printf("inserir\n");
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	printf("\n");
	printf("digite o num da conta para remover: ");
	scanf("%d", &nremove);
	removerElemento(lista, nremove, tam);
	printf("removido\n\n");
	printf("inserir\n");
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	printf("\n");
	printf("mostrar elemento\n");
	mostrarElemento(lista, 1);
	printf("\n");
	printf("mostrar todos\n");
	mostrarTodosElementos(lista, tam);
	printf("\n");
	printf("digite o num da conta para buscar saldo: ");
	scanf("%d", &nsaldo);
	mostrarSaldo(lista, nsaldo, tam);
	liberarMemoria(lista);
	return 0;
}