#include<stdio.h>

int main(){
	
	int v[10], n=0, i=0;
	
	scanf("%i", &n);
    for(i; i <= 10; i++){
        v[i] = n;
        printf("N[%i] = %i\n", i, v[i]);
        v[i] = n+n;
        n+=n;
    }
    return 0;
}
