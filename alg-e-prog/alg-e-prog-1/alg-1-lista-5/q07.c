#include<stdio.h>

main(){
	
	int n1=1, n2=1, n3, n4;
	
	printf("%i \n", n1);
	printf("%i \n", n2);
	
	for(n4=3; n4<=20; n4++){
		n3=n1+n2;
		printf("%i \n", n3);
		n1=n2;
		n2=n3;
	}
}
