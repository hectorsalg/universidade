#include<stdio.h>

main() {
	
	int numA, numB, resul=1;
	
	printf("Digite o primeiro numero.\n");
	scanf("%i", &numA);
	printf("Digite o segundo numero.\n");
	scanf("%i", &numB);
	
	while(numB>0){
	resul = resul * numA;
	numB--;
	printf("Resultado: %i\n", resul);
}
}
