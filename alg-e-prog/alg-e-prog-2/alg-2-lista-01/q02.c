#include<stdio.h>

int main(){
	
	//variável.
	float sal, des, saldes, valor;
	
	//entrada.
	scanf("%f", &sal);
	
	//condição.
	if(sal <= 600){
		des=0;
	} else if(sal<=1200){
			des=0.20;
	} else if(sal<=2000){
			des=0.25;
	} else {
			des=0.30;
	}
	
	//fórmula.
	valor = sal-(sal*des);
	saldes = sal - valor;
	
	//saída
	printf("\n%.2f\n%.2f\n", saldes, valor);
	return 0;
}
