#include<stdio.h>

int main(){
	
	//variável.
	int l, c, i, j;
	
	//entrada.
	scanf("%i %i", &l, &c);
	
	//repetidor, condição e saida.
	for(i=1;i<=l;i++){
		for(j=1;j<=c;j++){
			if(i==1){
				printf("*");
			}else if(i==l){
				printf("*");
			}else if(j>1 && j<c){
				printf(" ");
			}else if(j==1){
				printf("*");
			}else if(j==c){
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}