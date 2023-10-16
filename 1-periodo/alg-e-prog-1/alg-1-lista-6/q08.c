#include<stdio.h>

int main(){

	char nome[30];
	int i=0;
	
    scanf("%s", &nome);

    for(i; nome[i]!='\0';i++){
            printf("%c ", nome[i]);
        }

    return 0;

}
