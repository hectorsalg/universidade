#include<stdio.h>
#include<string.h> 

int main(){
	
    //variável.
    char palavra[20];
	int i = 0, j = 0, k = 0, posicao[20];
	
    //repetidor.
	for(j = 1; j <= 20; j++)
	{
		posicao[j] = 20;
	}
	
    //entrada.
    printf("Informe uma palavra: ");
    scanf("%s", palavra);
	
    //repetidor e condicional.
	for(i = 1;i <= 20; i++){
		if(palavra[i] == 'r'){
			palavra[i] = 'l';
			posicao[i] = i;
		}
		if(palavra[i] == 'R'){
			palavra[i] = 'L';
			posicao[i] = i;
		}
	}
	
    //saída e repetidor.
	printf("Cebolinha falaria: %s\n", palavra);
	printf("Houve troca nos caracteres: ");
	for(k = 1; k < 20; k++){
		if(posicao[k] != 20){
			printf("%d ", posicao[k] + 1);
			}
	}
    return 0;
}