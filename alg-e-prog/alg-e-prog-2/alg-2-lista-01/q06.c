#include <stdio.h>

int main(){
	
	//variável.
	int valor=0, resul;
	
	//repetidor e entrada.
	do{
		scanf("%i", &valor);
		resul=resul+valor;
	} while(valor > 0);
	
	//correção do resultado.
	resul=resul-valor;
	
	//sa�da.
	printf("%i", resul);
	return 0;
}