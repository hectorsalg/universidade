#include<stdio.h>

int main() {
	
	float num;
	int i=0;
	
	scanf("%f", &num);
    for(i; i<100; i++){
        printf("N[%i] = %.4f\n", i, num);
        num=num/2;
    }
    return 0;
}
