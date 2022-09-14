#include<stdio.h>
#define max 12

int main() {
    
	int i=0, v[max], x, y, soma;

    for (i; i<max; i++){
        scanf("%i", &v[i]);
    }
    scanf("%i %i", &x, &y);
    soma = v[x] + v[y];
    printf("%i\n", soma);
    return 0;
}
