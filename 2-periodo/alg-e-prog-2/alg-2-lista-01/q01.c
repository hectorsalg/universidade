#include <stdio.h>

int main(){

	//variável.
    float preco;

	//entrada.
    scanf("%f", &preco);
	
	//condição e saída.
    if(preco < 20){
        printf("\n%.2f\n", preco * 1.45);
    }else{
        printf("\n%.2f\n", preco * 1.30);
    }
    return 0;
}
