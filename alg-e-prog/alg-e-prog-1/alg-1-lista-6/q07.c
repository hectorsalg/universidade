#include<stdio.h>
#define max 10
int main() {
	
	int i=0, num=0, v[max], maior=0, menor=0;
	
	for(i; i<max; i++){
		scanf("%i", &num);
		if(num>maior){
			maior=num;
		}
		if(maior>num && num>menor){
			menor=num;
		}else {
			menor=num;
		}
	}
	printf("Maior: %i\n", maior);
	printf("Menor: %i", menor);
	return 0;
}
