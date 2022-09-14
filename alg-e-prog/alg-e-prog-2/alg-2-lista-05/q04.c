#include<stdio.h>

//chama função.
void somaComplexo(float rz1, float iz1, float rz2, float iz2, float *rz3, float *iz3);

//main.
void main(){
    //variável.
    float rz1, iz1, rz2, iz2, rz3, iz3;
    //condicional, entrada e condicional.
    while(rz1!=0){
    scanf("%f", &rz1);
    if(rz1==0){
        break;
    }
    //entrada, função e saída.
    scanf("%f", &iz1);
    scanf("%f %f", &rz2, &iz2);
    somaComplexo(rz1, iz1, rz2, iz2, &rz3, &iz3);
    printf("%.1f + %.1fi\n", rz3, iz3);
    }
}
void somaComplexo(float rz1, float iz1, float rz2, float iz2, float *rz3, float *iz3){
    //fórmula.
    *rz3=(rz1+rz2);
    *iz3=(iz1+iz2);
}