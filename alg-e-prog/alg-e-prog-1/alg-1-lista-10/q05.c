#include<stdio.h>

int menor3(int x, int y, int z);

int main(void){
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	printf("Menor valor: %d\n", menor3(a, b, c));
}
int menor3(int x, int y, int z){
	int menor;
	if(x <= y && x <=z){
        menor = x;
    } else if (y <= x && y <= z){
        menor = y;
    } else if (z <= x && z <= y){
        menor = z;
    }
	return menor;
}
