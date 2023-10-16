#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MAX 50
#define qtd_naipe 4
#define qtd_valores 13
#define qtd_cartas 52

//chama função.
int Sotear(int min, int max);
void montarBaralho();
void imprimeCartas(int num);
void embaralhar();

//tipo e variável.
struct Carta{
    char naipe[MAX];
    char valor[MAX];
};
char naipe[qtd_naipe][MAX]= {"Paus", "Ouros", "Copas", "Espadas"};
char valor[qtd_valores][MAX]= {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis","Sete", "Oito", "Nove", "Dez", "Valete", "Damas", "Rei"};

struct Carta deck[qtd_cartas];

//main.
void main(){
    //variável
    int num;
    srand((unsigned)time(NULL));

    montarBaralho();

    //entrada.
    scanf("%d", &num);
    
    imprimeCartas(num);
    printf("\n");
}
//função.
int Sotear(int min, int max){
    return rand()%max+min;
}
//função.
void montarBaralho(){
    //variável.
    int count=0;

    //repetidor.
    for(int i=0;i<qtd_naipe; i++){
        for(int j=0; j<qtd_valores; j++){
            strcpy(deck[count].valor, valor[j]);
            strcpy(deck[count].naipe, naipe[i]);
            count++;
        }
    }
}
//função.
void imprimeCartas(int num){
    //escolha.
    switch(num){
        case 0:
            embaralhar();
            //repetidor e saída.
            for(int i=0; i<qtd_cartas; i++){
                printf("%s de %s\n", deck[i].valor, deck[i].naipe);
            }
            break;
        case 1:
            //repetidor e saída.
            for(int i=0; i<qtd_cartas; i++){
                printf("%s de %s\n", deck[i].valor, deck[i].naipe);
            }
            break;
    }
}
//função.
void embaralhar(){
    //variável.
    int num;
    struct Carta cartaAux;

    //repetidor.
    for(int i=0; i<qtd_cartas; i++){
        num=Sotear(0, 51);
        strcpy(cartaAux.valor, deck[num].valor);
        strcpy(cartaAux.naipe, deck[num].naipe);

        strcpy(deck[num].valor, deck[i].valor);
        strcpy(deck[num].naipe, deck[i].naipe);

        strcpy(deck[i].valor, cartaAux.valor);
        strcpy(deck[i].naipe, cartaAux.naipe);
    }
}