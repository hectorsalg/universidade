#include <stdio.h>
#include <stdlib.h>

#include "listadinamicasimples.h"

int main()
{
	Conta *lista;

	lista = criarLista();
	lista = inserirFim(lista);
	lista = inserirFim(lista);
	lista = inserirFim(lista);
	// int removeNum;
	// printf("Informe um valor para remover: ");
	// scanf("%d", &removeNum);
	// lista = remover(lista, removeNum);
	// int alteraNum;
	// printf("Informe um valor para alterar: ");
	// scanf("%d", &alteraNum);
	// lista = alterar(lista, alteraNum, 800);
	printf("\nLista:\n");
	liberarLista(lista);
	return 0;
}