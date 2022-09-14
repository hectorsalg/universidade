#include<stdio.h>
#define MAX 10

int main(){

    //varíavel.
    int num[MAX], aux[MAX], count=0;

    //repetidor, entrada, condicional e saída.
    for(int i=0; i<MAX; i++){
        num[i]=0;
        aux[i]=0;
    }
    for(int i=0; i<MAX; i++){
        printf("Digite um numero: ");
        scanf("%d", &num[i]);
        if(num[i]>=10 && num[i]<=100){
            for(int j=0;j<=i;j++){
                if(num[i]==aux[j]){
                    count=1;
                }
            }
            if(!count){
                printf("O numumero %d ainda nao foi lido\n", num[i]);
            }
            aux[i]=num[i];
            count=0;
        }else {
            printf("Valor Invalido.\n");
        }
    }
    return 0;
}