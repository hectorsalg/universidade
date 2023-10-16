#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//função.
int arremesso();

//main.
void main(){
	
    srand((unsigned)time(NULL));
	//variável.
	int dado1, dado2, soma, ponto;
	//entrada.
	dado1=arremesso();
	dado2=arremesso();
	soma=dado1+dado2;
    
	//condicional e saída.
    printf ("A soma dos dados %d + %d = %d\n", dado1, dado2, soma);
	if((soma==7)||(soma==11)){
		printf ("O jogador ganhou :)");
	}else if((soma==2)||(soma==3)||(soma==12)){
		printf ("O jogador perdeu :(");
	}else if((soma==4)||(soma==5)||(soma==6)||(soma==8)||(soma==9)||(soma==10)){
        printf ("O ponto eh %d\n", soma);
    do{
     	dado1=arremesso();
	    dado2=arremesso();
	    ponto=dado1 + dado2;

    	if(ponto==7){
    		printf ("A soma dos dados %d + %d = %d\nO jogador perdeu :(\n", dado1, dado2, ponto);
        break;
		} 
		else if(ponto!=soma){
			printf ("A soma dos dados %d + %d = %d\n", dado1, dado2, ponto);
        }
        else if(ponto==soma){
			printf ("A soma dos dados %d + %d = %d\nO jogador ganhou :)\n", dado1, dado2, ponto);
        break;	
		}
	} while(ponto!=soma);
	}	
}
//função.
int arremesso(){
 	return 1 + rand()%6;
}