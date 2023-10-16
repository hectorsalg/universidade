#include<stdio.h>

int main(){
	
	int i=1;
	float p, a, imc;
	for(i; i<=30;i++){
		printf("Informe o peso e altura da pessoa %i, respectivamente.\n", i);
		scanf("%f %f", &p, &a);
		imc=p/(a*a);
		printf("IMC da pessoa %i foi de %.2f\n", i, imc);
	} p=0; a=0;
}
