#include<stdio.h>

int main() {
    
	char nome[20];
	int i=0;
	
    scanf("%s", &nome);

    for(i; nome[i]!='\0';i++){
        if (nome[i]==82 || nome[i]==114){
            printf("%c", nome[i]-6);
        }else{
            printf("%c", nome[i]);
        }
    }
    return 0;
}
