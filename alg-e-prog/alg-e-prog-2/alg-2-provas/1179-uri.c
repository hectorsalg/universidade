#include <stdio.h>

void imprimeVetor( int *v, int n, int sinal);

int main(){
    int par[5], impar[5];
    int n=0, v=0;
    int x, i, j;
    for (i=0;i<15;i++){
        scanf("%d", &x);
        if(x%2==0){
            par[n]=x;
            n++;
            if(n==5){
                for(j=0;j<5;j++){
                    imprimeVetor(par, n, 0);
                    n=0;
                }
            }
        }else{
            impar[v]=x;
            v++;
            if(v==5){
                for(j=0;j<5;j++){
                    imprimeVetor(impar, v, 1);
                    v=0;
                }
            }
        }
    }
    for(j=0;j<v;j++){
            printf("impar[%d] = %d\n", j, impar[j]);
        }
        for(j=0;j<n;j++){
            printf("par[%d] = %d\n", j, par[j]);
        }
    return 0;
}
void imprimeVetor( int *v, int n, int sinal){
    int i;
    if(sinal==0){
        for(i=0;i<n;i++){
            printf("par[%d] = %d\n", i, v[i]);
        }
    }else{
    if(sinal==1){
        for(i = 0;i < n; i++){
            printf("par[%d] = %d\n", i, v[i]);
        }
    }
    }
}