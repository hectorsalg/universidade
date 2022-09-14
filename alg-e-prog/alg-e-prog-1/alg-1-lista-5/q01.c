#include<stdio.h>

main (){
	int num, alg;
	
	printf ("Escreva um numero inteiro de maior que 0(Zero).\n");
	scanf("%i", &num);
	
	while (num > 0){

	alg = num%10;
	
	if (alg%2 == 0){
	 	printf("%i eh par\n", alg);
		} else {
	 	printf("%i eh impar\n", alg);
	}
	num = num/10;
	alg = num%10;
	}
}
