#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct 
{
    int cod;
    char nomeCarro[20];
    float valor;
}locacao;

void formatacao();
void escrita();
void leitura();
void busca();

int main(){

    int opcao;

    do{
        printf("Sistema de locacao baseado em arquivo\n");
        printf("Informe a opcao desejada (1-formatar, 2-escrever, 3-ler, 4-buscar, 0-finalizar): ");
        scanf("%d", &opcao);
        printf("\n");
        switch(opcao){
    
        case 0:
            break;
        case 1:
            formatacao();
            break;
        case 2:
            escrita();
            break;
        case 3:
            leitura();
            break;
        case 4:
            busca();
            break;
        }
    } while(opcao != 0);

    return 0;
}
void formatacao(){
    
    FILE *formatacao;
    locacao loc = {0, " ", 0.00};
    int i;

    if((formatacao = fopen("dados.bin", "wb")) == NULL){
        printf("Arquivo nao encontrado\n");
    } else{
        for(i = 0; i < 1000; i++){
        fwrite(&loc, sizeof (loc), 1, formatacao);
        }
        printf("Operacao de formatacao finalizada!\n");
        fclose(formatacao);
    }
}
void escrita(){
    
    FILE *escrita;
    locacao loc;
    int i;

    if((escrita = fopen("dados.bin", "rb+")) == NULL){
        printf("Arquivo nao encontrado\n");
    } else{
        printf("Digite o codigo da locacao (0-Finalizar): ");
        scanf("%d", &loc.cod);
        while(loc.cod != 0){
            printf("Digite o nome do veiculo: ");
            scanf("%s", loc.nomeCarro);
            setbuf(stdin, NULL);
            printf("Digite o valor da locacao: ");
            scanf("%f", &loc.valor);
            fseek(escrita, (loc.cod - 1) * sizeof(loc), SEEK_SET);
            fwrite(&loc, sizeof(loc), 1, escrita);
            printf("Digite o codigo da locacao (0-Finalizar): ");
            scanf("%d", &loc.cod);
        }
        printf("Operacao de escrita finalizada!\n");

        fclose(escrita);
    }
}
void leitura(){
    
    FILE *leitura;

    if((leitura = fopen("dados.bin", "rb+")) == NULL){
        printf("Arquivo não encontrado\n");
    } else {
    while(!feof(leitura)){
        locacao loc = {0, "", 0.0};
        fread(&loc, sizeof(locacao), 1, leitura);
        if(loc.cod != 0){
            printf("Codigo de Locacao | Nome de Veiculo | Valor de Locacao\n");
            printf("%-19d %-17s %.2f\n", loc.cod, loc.nomeCarro, loc.valor);
        }
    }
    printf("Operacao de leitura finalizada!\n");

    fclose(leitura);
    }
}
void busca(){
    
    FILE *busca;
    locacao loc;
    int i;

    if((busca = fopen("dados.bin", "rb+")) == NULL){
        printf("Arquivo não encontrado\n");
    } else{
        printf("Digite o codigo da locacao: ");
        scanf("%i", &loc.cod);
        
        fseek(busca,((loc.cod - 1) * sizeof(loc)), SEEK_SET);
        fread(&loc, sizeof(loc), 1, busca);

        if(loc.cod == 0){
            printf("Nenhum registro de locacao com a chave informada foi encontrado!\n");
        } else{
            printf("Codigo de Locacao | Nome de Veiculo | Valor de Locacao\n");
            printf("%-19d %-17s %.2f\n", loc.cod, loc.nomeCarro, loc.valor);
        }

        printf("Operacao de busca finalizada\n");

        fclose(busca);
    }
}
