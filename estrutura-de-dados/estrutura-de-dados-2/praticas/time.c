#include <stdio.h>
#include <time.h>

int main() {

    time_t tempoAtual = time(NULL);
    struct tm *dataAtual = localtime(&tempoAtual);
    int ano = dataAtual->tm_year + 1900;
    
    printf("%d\n", ano);

    return 0;
}