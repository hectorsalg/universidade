#include<stdio.h>

main(){
	
	char sexo;
	int contm, contf;
	
	contm=contf=0;
	
	do {
		printf("Informe o sexo.\n");
		scanf("%c", &sexo);
			if (sexo == 'm'){
			contm++;
		}
			if (sexo == 'f'){
			contf++;
		}

		setbuf (stdin, NULL);
	} while (sexo != '@'); {
	if(contf>=0){
	printf("Feminino: %i\n", contf);
}
	if(contm>=0){
	printf("Masculino: %i\n", contm);
	if(sexo=='@'){
	printf("Programa Finalizado.");
	}
}
}
}
