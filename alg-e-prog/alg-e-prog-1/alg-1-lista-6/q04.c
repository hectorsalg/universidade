#include<stdio.h>

int main(){
    int v[10], n=0, i=0;
	
    printf("Elemento     Valor\n");
    for(i; i < 10; i++){
        v[i] = n+2;
        printf("%8i     %i\n", i, v[i]);
        n+=2;
    }
    return 0;
}
