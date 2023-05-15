#include <stdio.h>
#include <stdlib.h>

typedef struct Dados {
    int num;
} Dados;

typedef struct ABB {
    Dados info;
    struct ABB *esq, *dir;
} ABB;

void criarABB(ABB *raiz);
void inserirABB(ABB **raiz, int valor);
int buscarABB(ABB *raiz, int busca);
void preOrdem(ABB *raiz);
void inOrdem(ABB *raiz);
void posOrdem(ABB *raiz);

int main() {

    ABB *arv;

    criarABB(arv);
    inserirABB(&arv, 5);
    inserirABB(&arv, 3);
    inserirABB(&arv, 7);
    inserirABB(&arv, 1);
    // printf("achou: %d\n", buscarABB(arv, 9)); teste da função buscar
    inOrdem(arv);
    printf("\n");

    return 0;
}

void criarABB(ABB *raiz) {
    raiz = NULL;
}

void inserirABB(ABB **raiz, int valor) {
    if(*raiz == NULL) {
        *raiz = (ABB*)malloc(sizeof(ABB));
        (*raiz)->info.num = valor;
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;
    } else if (valor < (*raiz)->info.num) {
        inserirABB(&((*raiz)->esq), valor);
    } else if (valor > (*raiz)->info.num) {
        inserirABB(&((*raiz)->dir), valor);
    }
}

int buscarABB(ABB *raiz, int busca) {
    int achou = 0;
    if (raiz != NULL) {
        if(raiz->info.num == busca) {
            achou = 1;
        } else if(busca < raiz->info.num)
            achou = buscarABB(raiz->esq, busca);
            else if(busca > raiz->info.num)
                achou = buscarABB(raiz->dir, busca);
    }
    return achou;
}

void preOrdem(ABB *raiz) {
    if (raiz != NULL) {
        printf("%d\t", raiz->info.num);
        inOrdem(raiz->esq);
        inOrdem(raiz->dir);
    }
}

void inOrdem(ABB *raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esq);
        printf("%d\t", raiz->info.num);
        inOrdem(raiz->dir);
    }
}

void posOrdem(ABB *raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esq);
        inOrdem(raiz->dir);
        printf("%d\t", raiz->info.num);
    }
}