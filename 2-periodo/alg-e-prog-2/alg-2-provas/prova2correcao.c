#include<stdio.h>
#include<string.h>

typedef struct{
    int codigo;
    char descricao[30];
    int idade;
    float preco;
} Brinquedos;

void cadastrar(Brinquedos brin);
void visualizar(Brinquedos brin);
void buscar1(Brinquedos brin);
void buscarIdade(Brinquedos brin);

int main(){
    
    Brinquedos brin;
    int opcao;
    
    printf("1-cadastrar\n");
    printf("2-visualizar\n");
    printf("3-buscar um registro\n");
    printf("4-buscar registros\n");
    printf("5-finalizar\n");
    while(opcao != 5){
        printf("Informe o modulo desejado: ");
        scanf("%d", &opcao);
        printf("\n");
        switch(opcao){
        case 1:
            cadastrar(brin);
            printf("\n");
            break;
        case 2:
            visualizar(brin);
            printf("\n");
            break;
        case 3:
            buscar1(brin);
            printf("\n");
            break;
        case 4:
            buscarIdade(brin);
            printf("\n");
            break;
        }
    }
}
void cadastrar(Brinquedos brin){
    
    FILE *cadastro;

    cadastro = fopen("cadastro.txt","a");

    if(cadastro == NULL){
        printf("Arquivo nao encontrado!\n");
    }else{
        printf("Digite o codigo: ");
        scanf("%d", &brin.codigo);
        setbuf(stdin,NULL);
        printf("Digite a descricao: ");
        scanf("%s", brin.descricao);
        printf("Digite a idade: ");
        scanf("%i", &brin.idade);
        printf("Digite o preco: ");
        scanf("%f", &brin.preco);
        fprintf(cadastro,"%d %s %d %.2f\n", brin.codigo, brin.descricao, brin.idade, brin.preco);
    }
    fclose(cadastro);
}

void visualizar(Brinquedos brin){
    
    FILE *visu;

    visu = fopen("cadastro.txt","r");

    while(!feof(visu)){
        //adicinei quebra de linha no fscanf para que não repetisse o ultimo valor.
        fscanf(visu,"%d %s %d %f\n", &brin.codigo, brin.descricao, &brin.idade, &brin.preco);
        printf("Codigo: %d, Descricao: %s, Idade: %d, Preco: %.2f\n", brin.codigo, brin.descricao, brin.idade, brin.preco);
    }
    fclose(visu);
}
void buscar1(Brinquedos brin){
    
    FILE *busca;

    busca = fopen("cadastro.txt","r");
    int pesquisa;
    int cont = 0;
    
    printf("Digite o codigo de busca: ");
    scanf("%d", &pesquisa);
    printf("\n");

    while(!feof(busca)){
        //adicinei quebra de linha no fscanf para que não repetisse o ultimo valor.
        fscanf(busca,"%d %s %d %f\n",&brin.codigo, brin.descricao, &brin.idade, &brin.preco);
        if(pesquisa == brin.codigo){
            printf("%d , %s , %d, %.2f\n", brin.codigo, brin.descricao, brin.idade, brin.preco);
            cont++;
        }
    }
    if(cont == 0){
        printf("Sem cadastro\n");
    }

    fclose(busca);
}
void buscarIdade(Brinquedos brin){
    
    FILE *busca;

    busca = fopen("cadastro.txt","r");
    int idade;
    int cont = 0;
    
    printf("Digite a idade minima: ");
    scanf("%d", &idade);
    printf("\n");

    while(!feof(busca)){
        //adicinei quebra de linha no fscanf para que não repetisse o ultimo valor.
        fscanf(busca,"%d %s %d %f\n",&brin.codigo, brin.descricao, &brin.idade, &brin.preco);
        if(idade < brin.idade){
            printf("%d , %s , %d, %.2f\n", brin.codigo, brin.descricao, brin.idade, brin.preco);
            cont++;
        }
    }
    if(cont == 0){
        printf("Sem cadastro\n");
    }
    fclose(busca);
}