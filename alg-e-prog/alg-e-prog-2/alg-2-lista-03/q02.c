#include<stdio.h>
#include<math.h>

//tipo.
struct coordenadas{
	float x, y;
};
typedef struct coordenadas Ponto;

Ponto p1, p2;
float d;
//função.
int distancia(Ponto p1, Ponto p2);

//main.
void main(){
	//variável.
	float resul;
	//entrada.	
	scanf("%f %f", &p1.x, &p2.x);
	scanf("%f %f", &p1.y, &p2.y);
	
	distancia(p1, p2);
	//saída.
	printf("Distancia : %.f\n", distancia(p1, p2));
}
int distancia(Ponto p1, Ponto p2){
	//fórmula.
	d=pow(((pow((p2.x-p1.x), 2))+(pow((p2.y-p1.y), 2))), (2));
	return d;
}