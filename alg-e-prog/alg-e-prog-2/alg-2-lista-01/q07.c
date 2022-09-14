#include <stdio.h>

int main(){
	
	//variavel.
	int x, y, i, pares=0, imp=1;
	
	//entrada.
	scanf("%i %i", &x, &y);
	
	//repeditor e condição.
	for(i=x;i<=y;i++){
		if(i%2==0){
			pares=pares+i;
		}else if(i%2!=0){
			imp=imp*i;
		}
	}
	
	//saída.
	printf("%i %i", pares, imp);
	return 0;
}