#include<stdio.h>
#include<math.h>

int potencia(int x, int n);

int main (){
	int x, n, result;
	
	scanf("%d %d", &x, &n);
	
	result = potencia(x, n);
	
	printf("Resultado: %d\n", result);
}
int potencia(int x, int n){
	int i, result=0;
	
	result=pow(x, n);
	
	return result;
}
