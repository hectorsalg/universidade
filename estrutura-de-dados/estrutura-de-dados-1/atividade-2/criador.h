typedef struct criador Criador;

Criador *criarListaDuplaCriadores();
Criador *cadastrar(Criador *criadores);
Criador *buscar(Criador *criadores);
Criador *remover(Criador *criadores, int id_criador);//nao é permitido remover criador com fazendas cadastradas
Criador *criarFazendaCriador(Criador *criador);
void mostrarCriadores(Criador *criadores); // Funcao para mostrar cada criador e todos os seus respectivos atributos
Criador *fazendaCriador(Criador *criador);

/*
Desenvolva funçoes para:
- Retornar o patrimonio do criador (esse valor deve sempre estar atualizado)
- Funcao para liberar a memoria
*/