#include <stdio.h>

int main (){
   	
	//variável.
   	char dest;
    int viagem, preco;
    
    //entrada.
    scanf("%c", &dest);
    scanf("%i", &viagem);
    
    //condição norte e saída.
    if(dest=='a' && viagem==0){
    	printf("R$ 500.00");
    }else if(dest=='a' && viagem==1){
    	printf("R$ 900.00");
    }
    
	//condição nordeste e saída.
	if(dest=='b' && viagem==0){
    	printf("R$ 350.00");
    }else if(dest=='b' && viagem==1){
    	printf("R$ 650.00");
    }
    
	//condição centro-oeste e saída.
    if(dest=='c' && viagem==0){
    	printf("R$ 350.00");
    }else if(dest=='c' && viagem==1){
    	printf("R$ 600.00");
    }
    
	//condição sul e saída.
    if(dest=='d' && viagem==0){
    	printf("R$ 300.00");
    }else if(dest=='d' && viagem==1){
    	printf("R$ 550.00");
    }
    return 0;
}