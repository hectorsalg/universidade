typedef struct conta Conta;

Conta *criarPilha();
Conta *inserir(Conta *conta);
Conta *remover(Conta *conta);
int vazio(Conta *conta);
void liberar(Conta *conta);
void mostrarTopo(Conta *conta);
void mostrarTodaPilha(Conta *conta);