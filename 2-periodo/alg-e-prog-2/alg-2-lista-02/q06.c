#include <stdio.h>
#define m 4
#define n 6
#define p 8

int main(){

    //variáveç.
    int a[m][n],b[n][p],c[m][p];

    //repetidor e entrada.
    for (int i=1; i<=m;i++){
        for (int j=1;j<=n;j++){
            scanf("%d", &a[i][j]);
        }
        for (int i=1; i<=n;i++){
            for (int j=1;j<=p;j++){
            scanf("%d", &b[i][j]);
            }
        }
    //repetidor e saída.
        for (int i=1;i<=m;i++){
            for(int j=1;j<=p;j++){
                c[i][j]=a[i][j]*b[i][j];
                printf("%d", c[i][j]);
            } 
        }
    }
}