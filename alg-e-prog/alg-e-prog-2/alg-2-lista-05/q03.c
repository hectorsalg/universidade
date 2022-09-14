#include<stdio.h>
#include<string.h>

//chama função.
void maiusculo(char *sPtr);

//main.
void main(){
    //variável.
	char frase[200];

    //repetidor e entrada.
    while(frase!='0'){
        gets(frase);
        if(frase[0]=='0'){
            break;
        }
        maiusculo(frase);
    }
}
//função.
void maiusculo(char *sPtr){
    //repetidor, condicional e saída.
    for(int i=0; sPtr[i]!='\0';i++){
        if(sPtr[i] >= 97 && sPtr[i] <= 122){
            printf("%c", sPtr[i]-32);
        }else{
            printf("%c", sPtr[i]);
        }
    }
    printf("\n");
}