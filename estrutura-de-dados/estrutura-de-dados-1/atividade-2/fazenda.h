typedef struct fazenda Fazenda;
typedef struct endereco Endereco;

#include "animal.h"
#include "criador.h"

Fazenda *cadastrarFazenda(Fazenda *fazendas, Criador *criadores);
Fazenda *removerFazenda(Criador *criador);//nao permitir remover fazenda se houver animais cadastrados
Fazenda *alterarFazenda(Fazenda *fazendas);//alterar dados cadastrais da fazenda. exemplo: nome e endereco; 
Fazenda *buscarFazenda(Fazenda *fazendas);
Fazenda *criarAnimalFazenda(Fazenda *fazenda);
void qtdSexo(Fazenda *fazenda); // Quantidade de animais por sexo;
float fazendaPesoTotal(Fazenda *fazenda); // Peso total em arroba (isto é, a cada 15 KG)
float valorFazenda(Fazenda *fazenda); // Valor total da fazenda considerando o preço da arroba de R$ 267,50
void qtdStatus(Fazenda *fazenda); // lista de animais por tipo de status
Fazenda *animalFazenda(Fazenda *fazenda);
/*
Desenvolva funcoes que, dado uma FAZENDA, informar:
- Funcao para liberar a memoria
*/