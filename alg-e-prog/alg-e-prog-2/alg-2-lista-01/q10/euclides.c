#include<stdio.h>

//função mdc.
long mdc_euclides(long m, long n);

//função principal.
int main(){
	
    //variável.
	int x, y, div;
	
    //entrada.
	scanf("%d %d", &x, &y);
	
	div = mdc_euclides(x, y);
    //saída.
	printf("%d", div);

    return 0;
}
//função mdc.
long mdc_euclides(long m, long n){

    //variável.
    long r;

    //repetidor.
    while (n!=0){
        r=m%n;
        m=n;
        n=r;
    }
    return m;   
}