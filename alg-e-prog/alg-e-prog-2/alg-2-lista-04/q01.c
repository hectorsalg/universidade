#include <stdio.h>
#define MAX 5

//tipo.
typedef struct{
	char nome[20];
	float altura;
	float peso;
	float ira;
}Alunos;

//chama função.
void media(Alunos al[]);
void maior(Alunos alu[]);

//main.
void main(){
	//variável.
    Alunos aluno[MAX];

    //repetidor e entrada.
	for(int i=0; i<MAX; i++){
		scanf("%s", aluno[i].nome);
		scanf("%f %f %f", &aluno[i].altura, &aluno[i].peso, &aluno[i].ira);
	}
	media(aluno);
}
//função.
void media(Alunos al[]){
	//variável.
    float media_altura=0, media_peso=0, media_ira=0;

    //repetidor.
	for(int i=0; i<MAX; i++){                                                          
        media_altura+=al[i].altura;
		media_peso+=al[i].peso;                                                   
        media_ira+=al[i].ira;
	}
    //saída 1.
	printf("Media de Peso: %.3f\n", media_peso/5);
	printf("Media de Altura: %.3f\n", media_altura/5);
	printf("Media de IRA: %.3f\n", media_ira/5);

	maior(al);
}
//função.
void maior(Alunos alu[]){
	//variável.
    int nope=0, noal=0, noira;
	float posipeso=0,posial=0, posira=0;

    //repetidor.
	for(int i=0; i<MAX; i++){
		if(posipeso<alu[i].peso){
			posipeso=alu[i].peso;
			nope=i;
		}if(posial<alu[i].altura){                                                     
            posial=alu[i].altura;                                                     
            noal=i;
        }if(posira<alu[i].ira){
            posira=alu[i].ira;                                                        
            noira=i;                                                          
        }
	}
    //saída 2.
	printf("\nMaior Peso: %s (%.3f)\n", alu[nope].nome, posipeso);
	printf("Maior Altura: %s (%.3f)\n", alu[noal].nome, posial);
	printf("Maior IRA: %s (%.3f)\n", alu[noira].nome, posira);
	printf("\n");
}