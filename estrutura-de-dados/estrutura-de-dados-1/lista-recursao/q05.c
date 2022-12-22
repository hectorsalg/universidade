#include <stdio.h>

float juros(float valor, int meses, float taxa);

float juros(float valor, int meses, float taxa){
    if (meses == 0) return valor;
    return (1 + (taxa/100)) * juros(valor, meses - 1, taxa);
}

int main(){
    int meses;
    float valor, taxa;

    printf("Informa o valor, quantidade de meses e taxa: ");
    scanf("%f %d %f", &valor, &meses, &taxa);

    printf("%.2f \n", juros(valor, meses, taxa));
    
    return 0;
}