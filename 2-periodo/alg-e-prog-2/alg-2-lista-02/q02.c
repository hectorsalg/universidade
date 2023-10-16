#include<stdio.h>
#include<string.h>

int main() {
	
    char nome[20];
	
    scanf("%s", nome);

    for(int i=0; nome[i]!='\0';i++){
        if(nome[i] >= 97 && nome[i] <= 122){
            printf("%c ", nome[i]-32);
        }else{
            printf("%c ", nome[i]);
        }
    }
    return 0;
}