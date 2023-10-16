#include<stdio.h>
#include<stdlib.h>

//função.
int arremesso();
//main.
void main(){

    srand((unsigned)time(NULL));
    //variável.
    int moeda, countco=0, countca=0;

    //repetidor e entrada.
    for(int i=0;i<100;i++){
        moeda=arremesso();
        if(moeda==1){
            countca++;
            printf("cara\n");
        }else if(moeda==0){
            countco++;
            printf("coroa\n");
        }
    }
    //saída.
    printf("%d ocorrencias de cara\n", countca);
}
//função.
int arremesso(){
    return rand()%2;
}