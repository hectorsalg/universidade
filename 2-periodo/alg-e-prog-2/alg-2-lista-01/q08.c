#include<stdio.h>

int main(){
	
	//variável.
	int c, l, i, j;
	
	//entrada.
	scanf("%i %i", &l, &c);
	
	//repetidor e saída.
	for(i=1;i<=l;i++){
		for(j=1;j<=c;j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}