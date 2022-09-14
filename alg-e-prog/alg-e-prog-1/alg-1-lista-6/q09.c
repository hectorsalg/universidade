#include<stdio.h>

int main(){
    
	int n, t, a=0, b=1, i=0;
    unsigned long int fib = 0;

    scanf("%i", &t);

    for (i; i < t; i++){
        scanf("%i", &n);

        for (i; i < n-1; i++){
            fib = a + b;
            a = b;
            b = fib;
        }
        printf("Fib(%i) = %li\n", n, fib);
        fib=0;
        a=0;
        b=1;
    }
    return 0;
}
