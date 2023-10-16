#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//função.
int sortear();

//main.
void main(){
    //variável.
    int i=1, num, valor;
    
    srand((unsigned)time(NULL));
    //repetidor, condicional e saída.
    valor=sortear();
    do{
        scanf("%d", &num);
        if(num>valor){
            printf("Muito alto. Tente novamente.\n");
        } else if(num<valor){
            printf("Muito baixo. Tente novamente.\n");
        }else{
            printf("Excelente! voce adivinhou o numero!\nTentativa %d", i);
        }
        i++;
    }while(valor!=num);
}
//função.
int sortear(){
    return 1+rand()%1000;
}