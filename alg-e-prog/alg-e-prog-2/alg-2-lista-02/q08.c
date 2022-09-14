#include<stdio.h>

int main(){
    
    //variável.
    int v[10], num[10];

    printf("Informe 10 numeros entre 1 e 20: \n");

    //repetidor e entrada.    
    for(int i=0;i<10;i++){
        scanf("%d", &num[i]);
        while(num[i]>20 || num[i]<1){
            printf("numero invalido.\ninforme outro\n");
            scanf("%d", &num[i]);
        }
    }
    //repetidor, condicional e saída.
    printf("Elemento       Valor     Histograma\n");
    for(int j=0;j<10;j++){
        v[j]=num[j];
        if(num[j]>=10){
            printf("%8i       %i        ", j, v[j]);
        } else if(num[j]<10){
            printf("%8i       %i         ", j, v[j]);
        }
            for(int i=1;i<=num[j];i++){
            printf("*");
            }
            printf("\n");
        }
    return 0;
}