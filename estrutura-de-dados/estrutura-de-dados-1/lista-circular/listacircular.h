typedef struct conta Conta;

Conta *criarLista();
Conta *inserirInicio(Conta *lista);
Conta *inserirFim(Conta *lista);
Conta *inserirOrdenado(Conta *lista);
Conta *remover(Conta *lista, int valor);
Conta *buscar(Conta *lista, int valor);
Conta *alterar(Conta *lista, int oldValue, int newValue);
int listaVazia(Conta *lista);
void mostrarLista(Conta *lista);
void liberarLista(Conta *lista);
