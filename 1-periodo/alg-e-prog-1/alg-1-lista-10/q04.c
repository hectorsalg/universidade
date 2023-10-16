#include<stdio.h>

int menor2(int x, int y);

int main(void){
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	printf("Menor valor: %d\n", menor2(a, b));
}
int menor2(int x, int y){
	int menor;
	if(x>y){
		menor=y;
	}else {
		menor=x;
	}
	return menor;
}
