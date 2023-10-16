#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MAX 1000

typedef struct{
    int chave;
    char nomeCarro[20];
} Registro;

typedef struct{
    Registro item[MAX+1];
    int tamanho;
} Tabela;

void preencheTabela(Tabela *tabela);
void salvarDados(Tabela *tabela, char filename[100]);
void restauraDados(Tabela *tabvoid, char filename[100]);

int main(){
    
    char filename[100];
    int opcao;
    Tabela tabela, tabvoid;
    
    srand(time(NULL));
    
    preencheTabela(&tabela);

    printf("Sistema de backup de dados\n");
    printf("Informe a operacao desejada (1-salvar, 2-restaurar):\n");
    scanf("%i", &opcao);

    switch(opcao){ 
    
    case 1:
        
        printf("Informe o nome do arquivo:\n");
        scanf("%s", filename[100]);
        salvarDados(&tabela, filename[100]);

    break;

    case 2:
        
        printf("Informe o nome do arquivo:\n");
        scanf("%s", filename[100]);
        restauraDados(&tabvoid, filename[100]);

    break;

    default:

        printf("Numero invalido!");

    break;
    }
        printf("Operacao concluida com sucesso!");
}
void preencheTabela(Tabela *tabela){
    
    int i, min = 1, max = 1000;

    for(i = 0; i < MAX; i++){
        tabela->item[i].chave = rand() % max + min;
        strcpy(tabela->item[i].nomeCarro, "Gol");
    }
}
void salvarDados(Tabela *tabela, char filename[100]){
    
    FILE *file;
    int i;
    
    file = fopen(filename,"w");

    if(file==NULL){
        printf("Erro ao abrir a tabela!\n");
    }else{
        printf("Arquivo aberto com sucesso!\n");
    }
    for(i = 0; i < MAX; i++){
        fprintf(file,"%d %s\n", tabela->item[i].chave, tabela->item[i].nomeCarro);
    }
    
    fclose(file);
}
void restauraDados(Tabela *tabvoid, char filename[100]){
    
    FILE *file;
	char veiculo[100];
	int i=0, chave;
    Registro reg;

	file = fopen(filename,"r");

    if(file==NULL){
        printf("Erro ao abrir a tabela!\n");
    }else{
        printf("Arquivo aberto com sucesso!\n");
    }
    do{
        fscanf(file,"%d %s\n", &tabvoid->item[i].chave, tabvoid->item[i].nomeCarro);
        i++;
    } while(!feof(file));

    fclose(file);
}