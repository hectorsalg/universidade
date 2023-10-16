#include<stdio.h>

int main() {
	
    char palavra[20];
	int i=0;
	
    scanf("%s", palavra);

    for(i; palavra[i]!='\0';i++){
        if(palavra[i] >= 97 && palavra[i] <= 122){
            printf("%c ", palavra[i]-32);
        }else{
            printf("%c ", palavra[i]);
        }
    }
    return 0;
}
