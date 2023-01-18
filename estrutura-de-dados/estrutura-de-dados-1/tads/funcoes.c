#include <stdio.h>
#include <stdlib.h>

#include "funcoes.h"

char *ler() {
    char *string;
    string = (char*)malloc(50 * sizeof(char));
    scanf("%s", string);
    return string;
}

char *concatenar(char *str1, char *str2) {
    int i = 0, count = 0;
	for(count; str1[count] != '\0';){
         count++;
    }
    for(i; str2[i] != '\0';){
         str1[count] = str2[i];
         i++;
         count++;
     }
     str1[count] = '\0';
     return str1;
}

int tamanho(char *str) {
    int count = 0;
    for (count; str[count] != '\0';) {
        count++;
    }
    return count;
}

int iguais(char *str1, char *str2) {
    int i = 0, j = 0, count = 0;

    for (i; str1[i] != '\0'; i++){
        if (str1[i] == str2[i]){
            count += 0; 
        } else {
            count += 1;
        }
    }
	if(count == 0){
		return 0;
	} else {
        return 1;
    }
}