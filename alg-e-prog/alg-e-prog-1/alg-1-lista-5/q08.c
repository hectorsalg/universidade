#include<stdio.h>

main(){
	
	float contop1, contop2, contop3, mi1, mi2, mi3;
	int i, op, id, id1, id2, id3, x;
	
	contop1=contop2=contop3=mi1=mi2=mi3=id1=id2=id3=0;
	
	printf("Informe quantas pessoas seram entrevistadas.\n");
	scanf("%i", &x);
	
	for (i = 1; i <= x; i++){
	printf("Qual a idade do entrevistado %i?\n", i);
	scanf("%i", &id);
	
	printf("Qual sua opiniao sobre o La la land?\nSendo, Excelente(3)\nBom(2)\nRegular(1)\n");
	scanf("%i", &op);
	
	if (op==3){
		contop3++;
		id3= id3+id;
	} else if (op==2){
		contop2++;
		id2= id2+id;
	} else if (op==1){
		contop1++;
		id1= id1+id;
	} else {
		printf("Numero invalido.\n");
	}
}	
	if(contop1==0){
	printf("Ninguem votou em regular.\n");
}	else {
	mi1=id1/contop1;
	printf("A media das idades na escolha regular foi de %.1f\n", mi1);
}
	if(contop2==0){
	printf("Ninguem votou em bom.\n");	
	} else {
	mi2=id2/contop2;
	printf("A media das idades na escolha bom foi de %.1f\n", mi2);
} 	
	if(contop3==0){
	printf("Ninguem votou em excelente.\n");
	} else {
	mi3=id3/contop3;
	printf("A media das idades na escolha excelente foi de %.1f\n", mi3);
}
	while (contop3!=0){
		if((contop2==0) && (contop1==0)){
			printf("Todas as opinioes foram em excelente.\n");
		} else {
			printf("A porcentagem de votos em excelente foi %.1f%%\n", (x-contop3)*100/x);
		}
		break;
	}
	while (contop2!=0){
		if((contop3==0) && (contop1==0)){
			printf("Todas as opinioes foram em bom.\n");
		} else {
			printf("A porcentagem de votos em bom foi %.1f%%\n", (x-contop2)*100/x);
		}
		break;
	}
	while (contop1!=0){
		if((contop3==0) && (contop2==0)){
			printf("Todas as opinioes foram em regular.\n");
		} else {
			printf("A porcentagem de votos em regular foi %.1f%%\n", (x-contop1)*100/x);
		}
		break;
	}
}
