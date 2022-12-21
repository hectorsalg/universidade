#include <stdio.h>

int somaEntre(int A, int B, int resul);

int somaEntre(int A, int B, int resul){
    if (A == B) return resul;
    return resul += A, somaEntre(A + 1, B, resul);
}

int main(){

    int A, B, resul = 0;

    printf("Informe valor A: ");
    scanf("%d", &A);
    printf("Informe valor B: ");
    scanf("%d", &B);

    if (B < A) printf("%d \n", somaEntre(B, A, resul));
    else printf("%d \n", somaEntre(A, B, resul));

    return 0;
}