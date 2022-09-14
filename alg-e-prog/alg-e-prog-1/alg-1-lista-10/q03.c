#include<stdio.h>
#include<math.h>

float IMC(float peso, float altura);

int main(){

    float peso, altura, imc;

    printf("Digite a altura: ");
        scanf("%f", &altura);

    printf("Digite o peso: ");
        scanf("%f", &peso);

    	imc = IMC(peso, altura);
		printf("Imc: %.f", imc);
		
    if(imc > 25){
        printf("Acima do Peso\n");
    }
	return 0;
}

float IMC(float peso, float altura){

    float imc;

    imc = pow(altura,2);
    imc = peso/imc;

    return imc;
}
