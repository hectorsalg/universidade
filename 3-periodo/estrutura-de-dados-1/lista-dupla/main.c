#include <stdio.h>
#include <stdlib.h>

#include "listaDinamicaDupla.h"

int main(){
	Conta *lista;

    lista = criarLista();
    int op, valor, antigo, novo;
    while(op != 0) {
        printf("Insira um opcao:\n0- Sair\n1- InserirInicio\t2- InserirFim\t3- inserirOrdenado\n4- remover\t5- alterar\t6- mostrar lista\n");
        scanf("%d", &op);
        printf("\n");
        switch (op) {
            case 0:
                liberarLista(lista);
                break;
            case 1:
                lista = inserirInicio(lista);
                printf("\n");
                break;
            case 2:
                lista = inserirFim(lista);
                printf("\n");
                break;
            case 3:
                lista = inserirOrdenado(lista);
                printf("\n");
                break;
            case 4:
                printf("Insira um numero de conta ou saldo para remover conta: ");
                scanf("%d", &valor);
                lista = remover(lista, valor);
                printf("\n");
                break;
            case 5:
                printf("Insira um numero de conta ou saldo para alterar na conta, em seguida o novo valor a adicionar: ");
                scanf("%d %d", &antigo, &novo);
                lista = alterar(lista, antigo, novo);
                printf("\n");
                break;
            case 6:
                mostrarLista(lista);
                break;
            default:
                break;
        }
    }
    return 0;
}