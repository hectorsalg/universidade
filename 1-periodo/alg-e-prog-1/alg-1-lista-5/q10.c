#include<stdio.h>

main(){
	
	int i, div=1, cont=0, contp=0;
	
	do{
	
	printf("DIgite um numero inteiro positivo.\n");
	scanf("%i", &i);
	
		for(div; div <= i; div++){
			if(i%div==0){
				cont++;
				}
		}	if(cont==2){
				contp++;
				}	div=1;
	if(i!=-1){
	printf("Sao %i numeros divisores de %i\n", cont, i);
	cont=0;
	}
	}
	while (i!=-1);{
	if(contp==0){
	printf("Nao houve numero primo.\n");
	printf("Programa Finalizado.");
	} else {
	printf("O total de numeros primos digitados foi %i\n", contp);
	printf("Programa Finalizado.");
	}
	}
}
