#include<stdio.h>

int main(){   

	int num, menor=0, maior=0, i, n1,soma=0;    
	
	printf("Informe quantos numeros quer digitar.\n");
	scanf("%i", &i);
	
	for (n1=0; n1< i; n1++) {
	printf("Digite um numero: ");
	scanf("%i", &num);
	soma= soma + num;
	
	if(num > maior){
	maior = num;
	} 
	if (menor==0){
	menor = num;
	} else if (num<menor){
	menor = num;
	}
	
}      
	
	printf("A soma foi de %i\n", soma);
	printf("Maior: %i\n", maior);   
	printf("Menor: %i", menor); 
	return 0;  
}                                 
