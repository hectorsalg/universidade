#include<stdio.h>

int main(){
	
	//variável.
	float p, total;
	int q;
	
	//entrada.
	scanf("%i", &q);
	
	//condição.
	if(q < 12){
		p= 1.30;
	} else {
		p= 1.00;
	}
	
	//fórmula.
	total = p*q;
	
	//saída.
	printf("\nR$ %.2f\n", total);
	return 0;
}