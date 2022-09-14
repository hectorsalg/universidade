#include<stdio.h>
#define min(x, y)(((x)<(y)) ? (x) : (y))

//função mdc.
long mdc_trivial(long m, long n);

//função principal.
int main(){
	
    //variável.
	int x, y, div;
	
    //entrada.
	scanf("%d %d", &x, &y);
	
	div = mdc_trivial(x, y);
	//saída.
    printf("%d", div);

    return 0;
}
//função mdc.
long mdc_trivial(long m, long n){

    //variável.
    long d;

    d = min(m, n);
    
    //repetidor.
    while(m%d!=0 || n%d!=0){
    
        d--;
    }
    return d;
}