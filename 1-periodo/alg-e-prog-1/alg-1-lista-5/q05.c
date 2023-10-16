#include<stdio.h>

main(){
	
	float n1, n2, soma;
	char c;
	
	printf("-------------------------------------------------- ""\n");
	printf("MENU\n");
	printf("-------------------------------------------------- ""\n");
	printf("A - Maior Numero\n");
	printf("B - Menor Numero\n");
	printf("C - Media Aritmetica\n");
	printf("D - Finalizar\n");
	
	printf("Digite o primeiro numero.\n");
	scanf("%f", &n1);
	
	printf("Digite o segundo.\n");
	scanf("%f", &n2);
	while (c!='d'){
	printf("Escolha a opcao.\n");
	scanf(" %c", &c);
	
	switch (c){
		case 'A':
		if (n1>n2){
			printf("O maior numero eh %2.f\n", n1);
		} else if(n1<n2){
			printf("O maior numero eh %2.f\n", n2);
		} else {
			printf("O valor dos numeros eh o mesmo.\n");
		}
		break;
		case 'a':
		if (n1>n2){
			printf("O maior numero eh %2.f\n", n1);
		} else if(n1<n2){
			printf("O maior numero eh %2.f\n", n2);
		} else {
			printf("O valor dos numeros eh o mesmo.\n");
		}
		break;
		case 'B':
		if (n1>n2){
			printf("O menor numero eh %2.f\n", n2);
		} else if(n1<n2){
			printf("O menor numero eh %2.f\n", n1);
		} else {
			printf("O valor dos numeros eh o mesmo.\n");
		}
		break;
		case 'b':
		if (n1>n2){
			printf("O menor numero eh %2.f\n", n2);
		} else if(n1<n2){
			printf("O menor numero eh %2.f\n", n1);
		} else {
			printf("O valor dos numeros eh o mesmo.\n");
		}
		break;
		case 'C':
		soma = (n1+n2)/2;
		printf("A media foi de %.2f\n", soma);
		break;
		case 'c':
		soma = (n1+n2)/2;
		printf("A media foi de %.2f\n", soma);
		break;
		case 'D':
			printf("O Programa Finalizou.");
		case 'd':
			printf("O Programa Finalizou.");
		break;
		default:
			printf("Letra invalida.\n");
 		}
	}
}
