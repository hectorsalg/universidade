typedef struct animal Animal;

Animal *criaListaEncadeadaSimplesAnimais();
Animal *cadastrarAnimal(Animal *rebanho, Fazenda *fazenda);
Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal);//obervar para atualizar o status do animal na fazenda de destino
Animal *removerAnimal(Fazenda *fazenda, int id_animal);
/*
Desenvolva funcoes que:
- PermutarAnimais
- Funcao para liberar a memoria
*/