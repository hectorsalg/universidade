#include<stdio.h>

int mdc(int num1, int num2);

int main(void){
	
	int x, y, div;
	
	scanf("%d %d", &x, &y);
	
	div = mdc(x, y);
	printf("MDC: %d", div);
}
int mdc(int num1, int num2){

    int resto;

    do {
        resto = num1 % num2;

        num1 = num2;
        num2 = resto;

    } while (resto != 0);

    return num1;
}
