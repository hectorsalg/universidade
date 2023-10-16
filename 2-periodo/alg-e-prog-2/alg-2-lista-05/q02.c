#include<stdio.h>
#include<math.h>

//chame função.
void raizes(float a, float b, float c, float *x1, float *x2);

//main.
void main(){
    //variável.
    float a, b, c, x1, x2;
    //repetidor, condição, entrada e função.
    while(a!=0){
        scanf("%f", &a);
        if(a==0){
            break;
        }
        scanf("%f %f", &b, &c);
        raizes(a, b, c, &x1, &x2);
    }
}
//função.
void raizes(float a, float b, float c, float *x1, float *x2){
    //função.
    float delta=0;
    //fórmula.
    delta=(b*b)-(4*a*c);

    //condição e saída.
    if(delta>=0 && a!=0){
        *x1=((b*-1) + sqrt(delta))/(2*a);
        *x2=((b*-1) - sqrt(delta))/(2*a);
        printf("%.1f %.1f\n", *x1, *x2);
    }else{
        printf("complexo\n");
    }
}
