#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

//tipo.
typedef struct tipoNo{
	char time;
	struct tipoNo *proximo;
} tipoNo;
//tipo.
typedef struct tipoFila{

	tipoNo *primeiro;
	tipoNo *ultimo;

} tipoFila;
//função.
void queue(tipoFila *fila);
void push(tipoFila *fila, char time);
_Bool pop(tipoFila *fila, char *retorno);
void main (){
	//variavel.
	int a, b;
	tipoFila fila;
	char i, timeA, timeB, retorno;
	queue(&fila);
	//repetidor, função, condicional, e saída.
	for (i = 'A'; i <= 'P'; ++i)
		push(&fila, i);
	for (i = 0; i < 15; ++i){
		pop(&fila, &retorno);
		timeA = retorno;
		pop(&fila, &retorno);
		timeB = retorno;
		scanf("%d %d", &a, &b);
		if (a > b)
			push(&fila, timeA);
		else
			push(&fila, timeB);
	}
	pop(&fila, &retorno);
	printf("%c\n", retorno);
}
//função.
void queue(tipoFila *fila){
	fila->primeiro = NULL;
	fila->ultimo = NULL;
}
//função.
void push(tipoFila *fila, char time){
	//variável
	tipoNo *auxiliar;
	auxiliar = (tipoNo *) malloc(sizeof(tipoNo));
	//condicional.
	if (!auxiliar)
		exit(1);
	if (fila->primeiro)
	{
		fila->ultimo->proximo = auxiliar;
		auxiliar->proximo = NULL;
	}
	else
		fila->primeiro = auxiliar;
		fila->ultimo = auxiliar;
		auxiliar->time = time;
}
//função.
_Bool pop(tipoFila *fila, char *retorno){
	//variável.
	tipoNo *auxiliar;
	//condional.
	if (fila->primeiro){
		if (fila->primeiro->proximo){
			*retorno = fila->primeiro->time;
			auxiliar = fila->primeiro;
			fila->primeiro = fila->primeiro->proximo;
			free(auxiliar);
			return true;
		} else{
			*retorno = fila->primeiro->time;
			auxiliar = fila->primeiro;
			fila->primeiro = fila->ultimo = NULL;
			free(auxiliar);
			return true;
		}
	} else{
		retorno = NULL;
		return false;
	}
}