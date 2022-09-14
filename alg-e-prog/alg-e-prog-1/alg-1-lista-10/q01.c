#include <stdio.h>
#include <math.h>

void calculaRaizes(float a, float b, float c);

int main(){
    
	float a,b,c;

    scanf("%f %f %f", &a, &b, &c);
    calculaRaizes(a, b, c);

    return 0;
}

void calculaRaizes(float a, float b, float c){
    
	float delta, x1, x2;

    delta = (b*b)-4*a*c;
    printf("Delta %.1f\n", delta);
    
	if(delta>=0 && a!=0){
    	x1=((-b)+sqrt(delta))/(2*a);
    	x2=((-b)-sqrt(delta))/(2*a);
    	printf("x1: %.1f\n", x1);
    	printf("x2: %.1f\n", x2);
    } else {
        printf("Impossivel calcular raizes! ");
    }
	if(delta<0){
        printf("Raizes nao sao numeros reais.\n");
    } else if(delta==0){
    	printf("Possui uma raiz real.\n");
	} else if(delta>0){
		printf("Possui duas raizes reais.\n");
	}
}
