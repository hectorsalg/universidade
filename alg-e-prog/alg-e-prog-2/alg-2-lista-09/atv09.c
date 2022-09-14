#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 1000

typedef struct{
    int chave;
    char nomeCarro[20];
} Registro;

typedef struct{
    Registro item[MAX];
    int tamanho;
} Tabela;

void questao02(Tabela *tabela);
void questao03(Tabela *tabela);
int questao04(int codigo, Tabela *tabela);
void questao05(Tabela *tabela);
int questao06(char nome[], Tabela *tabela);
void questao07(Tabela *tabela);
void ordenar(Tabela *tabela);
int sequencial(int chave, Tabela *tabela, int *contsequen);
int binaria(int chave, Tabela *tabela, int *contbin);

int main(){
    
    char nome[20];
    int i, qtd = 0, codigo = 0, comp;
    Tabela tabela;
    
    srand((unsigned) time(NULL));
    
    questao02(&tabela);
    ordenar(&tabela);
    questao03(&tabela);
    
    printf("\nDigite o codigo que deseja buscar: ");
    scanf("%d", &codigo);
    
    qtd = questao04(codigo, &tabela);
    
    printf("O codigo %i se repete %i vez(es)\n\n", codigo, qtd);
    
    questao05(&tabela);
    
    printf("Digite o nome que deseja verificar se existe: \n");
    scanf("%s", nome);
    
    comp = questao06(nome, &tabela);
    if(comp == 0) {
        printf("Ja existe carro com o nome digitado\n");
    } else {
        printf("Nao existe carro com o nome digitado\n");
    }
    questao07(&tabela);
    return 0;
}
void questao02(Tabela *tabela){
    
    int i = 0, max = 1000, min = 1;
    
    for(i = 1; i < MAX; i++){
        tabela->item[i].chave = rand() % max + min;
        strcpy(tabela->item[i].nomeCarro, "Gol");
    }
}
void ordenar(Tabela *tabela){
    
    int i, j, min, aux;
    
    for(i = 0; i < 1000 - 1; i++){
        min = i;
        for(j = i+1; j < 1000; j++){
            if (tabela->item[j].chave < tabela->item[min].chave){
                min = j;
            }
        }
        aux = tabela->item[min].chave;
        tabela->item[min].chave = tabela->item[i].chave;
        tabela->item[i].chave = aux;
    }
}
void questao03(Tabela *tabela){
    
    int chave, i, seq, bin, contbin = 0, contsequen = 0;
 
    for(int j = 0; j < 100; j++){
        chave = rand() % 1000 + 1;

        seq = sequencial(chave, tabela, &contsequen);
        bin = binaria(chave, tabela, &contbin);
    }
    printf("Pesquisa sequencial: a media de registros percorridos por pesquisa eh %i\n", contsequen/100);
    printf("Pesquisa binaria: a media de registros percorridos por pesquisa eh %i\n", contbin/100);
}
int sequencial(int chave, Tabela *tabela, int *contsequen){
    
    int j;
    
    tabela->item[0].chave = chave;
    
    for( j = MAX; tabela->item[j].chave != chave; j--){
        *contsequen += 1;
    }
    if(tabela->item[0].chave == chave){
        tabela->item[0].chave = 0;
    }
    return j;
}
int binaria(int chave, Tabela *tabela, int *contbin){
    
    int i, esq, dir;
    
    tabela->tamanho = 1000;
    
    if(tabela->tamanho == 0){
        return 0;
    }
    
    esq = 1;
    tabela->tamanho = 1000;
    dir = tabela->tamanho;
    
    do{
        *contbin += 1;
        i = (esq + dir) / 2;
        if (chave > tabela->item[i].chave){
            esq = i + 1;

        } else{
            dir = i - 1;
        }
    } while((chave != tabela->item[i].chave) && (esq <= dir));
    if(chave == tabela->item[i].chave){
        return i;
    }
    else{
        return 0;
    }
}
int questao04(int codigo, Tabela *tabela){
    
    int qtd = 0, i = 0;

    for(i = 0; i < tabela->tamanho; i++){
        if(tabela->item[i].chave == codigo){
            qtd += 1;
        }
    }
    return qtd;
}
void questao05(Tabela *tabela){
    
    int codigo, i, qtd, retirado = 0;
    
    printf("\nDigite o codigo a ser retirado: ");
    scanf("%d", &codigo);

    for(i = 0; i < tabela->tamanho; i++){
        if(tabela->item[i].chave == codigo){
            tabela->item[i].chave = tabela->item[tabela->tamanho].chave;
            tabela->tamanho = tabela->tamanho - 1;
            retirado += 1;
        }
    }
    printf("%i registros com o codigo %i foram removidos\n", retirado, codigo);
    
    qtd = questao04(codigo, tabela);
    
    printf("O codigo %i se repete %i vez(es)\n\n", codigo, qtd);
}
int questao06(char nome[], Tabela *tabela){
    
    int j, comp;

    for( j = MAX; j > 0; j--){
        comp = strcmp(tabela->item[j].nomeCarro, nome);
        if(comp == 0) {
            return comp;
        }
    }
    return comp;
}
void questao07(Tabela *tabela){
    
    int registro = 0, comp, confirma;
    char nome[20];
    
    printf("\nDigite o codigo e em seguida o nome do veiculo\n");
    scanf("%d %s", &registro, nome);

    comp = questao06(nome, tabela);
    if(comp == 0){
        printf("Existem registros desse veiculo. Digite 0 para cancelar e 1 para confirmar a insercao:\n");
        scanf("%d", &confirma);
    } else{
        printf("Nao existem registros desse veiculo. Digite 0 para cancelar e 1 para confirmar a insercao:\n");
        scanf("%d", &confirma);
    }
    switch(confirma){
    case 0:
        printf("\nNao foi registrado\n");
        break;
    case 1:
        if(tabela->tamanho == MAX){
            printf("Erro: tabela cheia, pois nao foi retirado nenhum registro\n");
        } else{
            tabela->tamanho += 1;
            tabela->item[tabela->tamanho].chave = registro;
            strcpy(tabela->item[tabela->tamanho].nomeCarro, nome);
            printf("\nCodigo do carro: %d, Nome do carro: %s\n", registro, tabela->item[tabela->tamanho].nomeCarro);
            break;
        }
    }
}
/*
Resposta da 3

Pesquisa sequencial:
No melhor caso o valor esperado é 1;
No médio caso o valor esperado é 500,5;
No pior caso o valor esperado é 1000.

O valor calculado da média dos 100 casos pesquisados fica entre o valor esperado
do pior caso e o caso médio, ou seja, o valor ficar entre 500,5 e 1000.

Pesquisa binaria:
O valor esperado é o log2(1000) = 9,9;
Valor calculado da média dos 100 casos pesquisados variam entre 8 e 9;
Sendo na maioria dos casos 9, ou seja, o valor da média é bem próximo do valor esperado.
*/