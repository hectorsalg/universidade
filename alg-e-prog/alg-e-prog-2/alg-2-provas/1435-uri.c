#include <stdio.h>

int i, j, k, l, p, matriz, N, digitador = 1, count1 = 0, count2 = 0, r, m[100][100];

void preencheMatriz(int tamanho, double M[][100]);
void imprimeMatriz(int tamanho, double M[][100]);

int main(){
    
    while(1){
        scanf("%d", &N);
        if(N==0){
        break;
         } else{
        preencheMatriz(N,m[N][N]);
        imprimeMatriz(N, m[N][N]);
        }
    }
        printf("\n");
    return 0;
}
void preencheMatriz(int N, double M[][100]){
    digitador=1;
    count1=0;
    count2=0;
    matriz=N;
    if(N%2==0){
    r=N/2;
    } else if(N%2==1)
        r=(N/2)+1;
        for(i=1; i<=r; i++){
            for(j=count1; j<matriz; j++){
                for(k=count2; k<matriz; k++){
                    m[j][k]=digitador;
                }
            }
        digitador++;
        count1++;
        count2++;
        matriz--;
        }
}
void imprimeMatriz(int N, double M[][100]){
    for(l=0; l<N; l++){
            for(p=0; p<N; p++){
                if(p==0){
                     printf("%3d",m[l][p]);
                }else {
                     printf("%3d",m[l][p]);
                }
            }
        printf("\n");
    }
}