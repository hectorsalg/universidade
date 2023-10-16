#include <stdio.h>

int expo(int base, int potencia);

int expo(int base, int potencia){
    if (potencia == 1) return base;
    return base * expo(base, potencia - 1);
}

int main(){

    int b, p;
    scanf("%d", &b);
    scanf("%d", &p);

    printf("%d\n", expo(b, p));

    return 0;
}