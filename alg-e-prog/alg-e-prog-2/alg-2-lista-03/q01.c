#include<stdio.h>

//função.
int inverter();

//main.
void main(){
    //variável.
    int resul, num;

    //entrada e saída.
    printf("Digite um numero inteiro entre 1000 e 9999: ");
    scanf("%d", &num);
    resul=inverter(num);
}
//main.
int inverter(int num){
    //variável.
    int invertido=0;

    //condicional.
    if((num>=1000)&&(num<=9999)){
        do{
            invertido=num%10;
            printf("%d", invertido);
            num=num/10;
        } while(num!=0);
    }else{
        printf("numero invalido.");
    }
}