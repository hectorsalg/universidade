#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MAX 50
#define qtd_naipes 4
#define qtd_faces 13
#define qtd_cartas 52

typedef struct{
    char *naipe;
    char *face;
} Carta;

//chama função.
int sotear(int min, int max);

void preenche(Carta *deck, char *face[], char *naipe[]);
void imprime(Carta *deck);
void embaralha(Carta *deck);

//variável.
int num;

//main.
void main(){
    //variável.
    Carta deck[qtd_cartas];
    char *naipe[] = {(char *)"Paus", (char *)"Ouros", (char *)"Copas", (char *)"Espadas"};
    char *face[] = {(char *)"As", (char *)"Dois", (char *)"Tres", (char *)"Quatro", (char *)"Cinco", (char *)"Seis", (char *)"Sete", (char *)"Oito", (char *)"Nove", (char *)"Dez", (char *)"Valete", (char *)"Damas", (char *)"Rei"};
    srand((unsigned)time(NULL));

    preenche(deck, face, naipe);
    //entrada.
    scanf("%d", &num);

    imprime(deck);
    printf("\n");

}
//função.
int sotear(int min, int max){
    return rand()%max+min;
}
//função.
void preenche(Carta *deck, char *face[], char *naipe[]){
    //variável.
    int count=0;
    //repetidor.
    for(int i=0; i < qtd_naipes; i++){
        for(int j=0; j < qtd_faces; j++){
            deck[count].face = face[j];
            deck[count].naipe = naipe[i];
            count++;
        }
    }
}
//função.
void imprime(Carta *deck){
    //escolha.
    switch(num){
        case 0:
            embaralha(deck);
            //repetidor e saída.
            for(int i=0; i<qtd_cartas; i++){
                printf("%s de %s\n", deck[i].face, deck[i].naipe);
            }
            break;
        case 1:
            //repetidor e saída.
            for(int i=0; i<qtd_cartas; i++){
                printf("%s de %s\n", deck[i].face, deck[i].naipe);
            }
            break;
    }
}
//função.
void embaralha(Carta *deck){
    //variável.
    Carta cartaux;

    //repetidor.
    for(int i=0; i<qtd_cartas; i++){
        num=sotear(0, 51);
        cartaux.face=deck[num].face;
        cartaux.naipe=deck[num].naipe;

        deck[num].face=deck[i].face;
        deck[num].naipe=deck[i].naipe;

        deck[i].face=cartaux.face;
        deck[i].naipe=cartaux.naipe;
    }
}