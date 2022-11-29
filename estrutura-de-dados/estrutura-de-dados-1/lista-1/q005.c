#include <stdio.h>
#include <string.h>

int main(){
    char frase[] = "O EXERCICIO E FACIL";
    int count = 0;

    for(int i = 0; i < 19; i++){
        count = 0;
        for(int j = i; j < 19; j++){
            if(frase[i] == frase[j]){
                count++;
            }
        }
        printf("%c = %d\n",frase[i], count);
    }
    return 0;
}