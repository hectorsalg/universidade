#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//variável.
char artigo[][20] ={"o", "um", "algum", "todo", "qualquer"};
char substantivo[][20]={"menino", "homem", "cachorro", "carro", "gato"};
char verbo[][20]= {"passou", "pulou", "correu", "saltou", "andou"};
char preposicao[][20]={"sobre", "sob", "ante", "ate", "com"};

//função.
int sortear();
void criaFrase(char frase[]);
int contatenar(char frase[], char palavra[], int pos);

//main.
void main(){
    srand((unsigned)time(NULL));
    //variável.
    char frase[200];
    //repetidor e saída.
    for(int i=0; i<20;i++){
        criaFrase(frase);
        printf("frase: %s\n", frase);
    }
}
//função.
void criaFrase(char frase[]){
    //variável.
    int s, pos=0;

    s=sortear();
    pos=concatenar(frase, artigo[s], pos);

    s=sortear();
    pos=concatenar(frase, substantivo[s], pos);

    s=sortear();
    pos=concatenar(frase, verbo[s], pos);

    s=sortear();
    pos=concatenar(frase, preposicao[s], pos);

    s=sortear();
    pos=concatenar(frase, artigo[s], pos);

    s=sortear();
    pos=concatenar(frase, substantivo[s], pos);
    
    frase[0]-=32;
    frase[pos-1]='.';
    frase[pos]='\0';
}
//função.
int sortear(){
    int s=rand()%5;
    return s;
}
//função.
int concatenar(char frase[], char palavra[], int pos){
    //variável.
    int i=0;
    //repetidor.
    while(palavra[i]!='\0'){
        frase[pos]=palavra[i];
        i++;
        pos++;
    }
    frase[pos]=' ';
    pos++;
    return pos;
}