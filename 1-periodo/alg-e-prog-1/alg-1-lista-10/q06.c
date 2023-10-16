#include<stdio.h>

int primo(int n);

int main(void){
	int i, n;
	
	scanf("%d", &n);
	
	printf("Numeros primos:\n");
	
	for(i=1; i<=n; i++){
		if(primo(i)==1){
			printf("%d eh primo.\n", i);
		}
	}	
}
int primo(int n){
	int qtdDiv=0, result, i;
	
	for(i=1; i<=n; i++){
		if(n%i==0){
			qtdDiv++;
		}
	} if(qtdDiv==2){
		result=1;
	} else{
		result=0;
	}
	return result;
}
