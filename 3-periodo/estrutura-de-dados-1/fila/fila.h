typedef struct conta Conta;
typedef struct fila Fila;

Fila *criarFila();
void inserir(Fila* fila);
int remover(Fila* fila);
int vazio(Fila* fila);
void liberar(Fila* fila);
void mostrarInicio(Fila *fila);
void mostrarFim(Fila *fila);
void mostrarTodaFila(Fila *fila);