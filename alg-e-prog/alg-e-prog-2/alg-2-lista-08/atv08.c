#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    int chave;
    char nome[30];
    char endereco[50];
    char telefone[14];
} Alunos;
int NUM_COMP = 0, NUM_MOV = 0;

void gerarDados(Alunos v[], int n, int ordemChave);
void ordena(Alunos v[], int tipoOrdenacao, int n);
int sorteiaNum(int min, int max);

int main(){
    
    srand((unsigned)time(NULL));
    int n, ordemChave, tipoOrdenacao;
    
    scanf("%d", &n);
    Alunos v[n];

    do{
        scanf("%d", &ordemChave);
        if(ordemChave == 3){
            break;
        }
        scanf("%d", &tipoOrdenacao);
        if(tipoOrdenacao == 0){
            printf("\n");
            printf("bolha\n");
        }
        if(tipoOrdenacao == 1){
            printf("\n");
            printf("selecao\n");
        }
        if(tipoOrdenacao == 2){
            printf("\n");
            printf("insercao\n");
        }
        
        gerarDados(v, n, ordemChave);
        ordena(v, tipoOrdenacao, n);
        printf("NUM_COMP: %d\nNUM_MOV: %d\n", NUM_COMP, NUM_MOV);
        printf("\n");

    } while (ordemChave != 3);
    

    return 0;
}
void gerarDados(Alunos v[], int n, int ordemChave){
    int i, aux = 0;
    switch (ordemChave){
    case 0:
        
        for(i = 0; i < n; i++){
            v[i].chave=i;
        }  
        for (i = 0; i < n; i++){
           // printf("%d ", v[i].chave);
        }
        printf("\n");
        break;
    case 1:
        
        for(i = 0; i < n; i++){

        v[i].chave=sorteiaNum(0, 10000);
        //printf("%d ", v[i].chave);
        }
        printf("\n");
        break;

    case 2:
        for(i = n-1; i >= 0; i--){
            v[aux].chave=i;
            //printf("%d ", v[aux].chave);
            aux++;
        }
        printf("\n");
        break;
    default:
        printf("valor invalido\n");
        break;
    }
}
void ordena(Alunos v[], int tipoOrdenacao, int n){
    
    int i, j, min, aux;
    Alunos aux1;

    switch(tipoOrdenacao){
    case 0:
        NUM_COMP = 0;
        NUM_MOV = 0;
        for (i = 0; i < n-1; i++){
            for (j = 1; j < n-i; j++){
                NUM_COMP++;
                if(v[j].chave < v[j-1].chave){
                    NUM_MOV += 3;
                    aux = v[j-1].chave;
                    v[j-1].chave = v[j].chave;
                    v[j].chave = aux;
                }
            }
        }
        for (i = 0; i < n; i++){
            //printf("%d ", v[i].chave);
        }
        printf("\n");
        
        break;

    case 1:
        NUM_COMP = 0;
        NUM_MOV = 0;
        for (i = 0; i < n-1; i++){
            min=i;
            for (j = i + 1; j <= n; j++){
                NUM_COMP++;
                if (v[j].chave<v[min].chave){
                    min=j;
                NUM_MOV += 3;
                }
            }
                NUM_COMP--;
                aux=v[min].chave;
                v[min].chave=v[i].chave;
                v[i].chave=aux;
        }
        for(i = 0; i < n; i++){
            //printf("%d ", v[i].chave);
        }
        printf("\n");
        
        break;

    case 2:
        NUM_COMP = 0;
        NUM_MOV = 0;
        for(i = 1; i < n; i++){
            aux1.chave = v[i].chave;
            NUM_MOV++;
            j=i-1;
            if(v[i].chave > v[j].chave){
                NUM_COMP++;
                NUM_MOV++;
            }
            while ((j >= 0) && (aux1.chave < v[j].chave)){
                NUM_COMP++;
                v[j+1].chave = v[j].chave;
                NUM_MOV++;
                j--;
            }
        }
            v[j+1].chave = aux1.chave;

        for (i = 0; i < n; i++){
            //printf("%d ", v[i].chave);
        }
        printf("\n");
        break;

    default:
        printf("valor invalido");
        break;
    }
}
int sorteiaNum(int min, int max){
    return rand()% max + min;
}