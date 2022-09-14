#include<stdio.h>
#include<math.h>

//chama função.
void cubo(int *nPtr);

//main.
void main(){
    //variável.
    int n;
    //repetidor, entrada e função.
    do{
        scanf("%d", &n);
        cubo(&n);
    }while(n!=0);
}
//função.
void cubo(int *nPrt){
    //variável.
    int cubo=0;
    //formula.
    cubo=pow((*nPrt), 3);
    //condição e saída.
    if(cubo!=0){
    printf("%d\n", cubo);
    } else{
        printf("\n");
    }
}