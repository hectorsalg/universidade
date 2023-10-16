#include<stdio.h>

int main(){
    
    //variáevl;
    int v[10], num=0;
	
    //repetidor e saída.
    printf("Elemento     Valor\n");
    for(int i=0;i<10;i++){
        v[i] = num+2;
        printf("%8i     %i\n", i, v[i]);
        num+=2;
    }
    return 0;
}