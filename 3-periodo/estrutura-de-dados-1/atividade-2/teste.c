#include <stdio.h>

#include "criador.h"
#include "fazenda.h"
#include "animal.h"

int main(){
    Criador *criadores;
    criadores = criarListaDuplaCriadores();
    Criador *criador = criadores;
    criador = buscar(criadores);
    criador = fazendaCriador(criador);
    typeof(criador);
    return 0;
}