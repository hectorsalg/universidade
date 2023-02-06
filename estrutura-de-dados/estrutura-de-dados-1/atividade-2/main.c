#include <stdio.h>

#include "criador.h"
#include "fazenda.h"
#include "animal.h"

int main(){
    Criador *criadores;
    Fazenda *fazenda;
    criadores = criarListaDuplaCriadores();
    int op = 1,op2, possui, id, idf;
    while(op != 0){
        printf("0- sair\t1-Cadastrar\t2- Remover\n3- Informacao da fazenda\n4- Informacao do criador\n5- Troca");
        scanf("%d", &op);
        switch (op) {
        case 0:
            break;
        case 1:
            printf("1-Cadastro de criador\t2-Cadastro de fazenda\n3- Cadastro de animal");
            scanf("%d", &op2);
            switch (op2){
            case 1:
                criadores = cadastrar(criadores);
                break;
            case 2:
                Criador *criador = criadores;
                criador = buscar(criadores);
                criador = fazendaCriador(criador);
                criador = cadastrarFazenda(fazenda, criador);
                possui = 1;
                break;
            case 3:
                Criador *criador = criadores;
                criador = buscar(criadores);
                criador = buscarFazenda(criador);
                criador = criarAnimalFazenda(fazenda);
                break;
            default:
                break;
            }
            break;
        case 2:
            printf("1-Remover criador\t2-Remover fazenda\n3- Remover animal");
            scanf("%d", &op2);
            switch (op2){
            case 1:
                printf("Qual o id do criador?\n");
                scanf("%d", &id);
                criadores = remover(criadores, id);
                break;
            case 2:
                Criador *criador = criadores;
                criador = buscar(criadores);
                criador = removerFazenda(criador);
                break;
            case 3:
                Criador *criador = criadores;
                criador = buscar(criadores);
                criador = fazendaCriador(criador);
                printf("Qual o id do animal?\n");
                scanf("%d", &id);
                criador = removerAnimal(criador, id);
                break;
            }
            break;
        case 3:
            printf("1-Quantidade por sexo\t2-Peso em arroba\n3- Valor da fazenda\n Quantidade por status");
            scanf("%d", &op2);
            switch (op2){
            case 1:
                printf("Qual o id da fazenda?\n");
                scanf("%d", &id);
                qtdSexo(fazenda, id);
                break;
            case 2:
                printf("Qual o id da fazenda?\n");
                scanf("%d", &id);
                fazendaPesoTotal(fazenda, id);
                break;
            case 3:
                printf("Qual o id da fazenda?\n");
                scanf("%d", &id);
                valorFazenda(fazenda, id);
                break;
            case 4:
                printf("Qual o id da fazenda?\n");
                scanf("%d", &id);
                qtdStatus(fazenda, id);
                break;
            break;
            }
        case 4:
            printf("1-Mostrar todas as informcoes de todos\t2-Patrimonio de um criador");
            scanf("%d", &op2);
            switch (op2){
            case 1:
                mostrarCriadores(criadores);
                break;
            case 2:
                printf("Qual o id do criador?\n");
                scanf("%d", &id);
                //Patrimonio do criador
                break;
            }
            break;
        case 5:
            //Troca
        }
    }
    return 0;
}