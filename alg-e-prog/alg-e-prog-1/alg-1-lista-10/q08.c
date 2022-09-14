#include<stdio.h>
#include<math.h>

struct coordenadas{
	float x, y;
};
typedef struct coordenadas Ponto;

float distancia(Ponto p1, Ponto p2){
	float d;
	
	d=pow((pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)), (1.0/2.0));
}
int main(void){
	Ponto ponto1, ponto2;
	float d;
	
	printf("Informe as coordenadas do ponto 1.\n");
	scanf("%f %f", &ponto1.x, &ponto1.y);
	printf("Informe as coordenadas do ponto 2.\n");
	scanf("%f %f", &ponto2.x, &ponto2.y);
	
	d=distancia(ponto1, ponto2);
	
	printf("Distancia entre A(%.lf, %.lf) e B(%.lf, %.lf): %.2lf\n", ponto1.x, ponto1.y, ponto2.x, ponto2.y, d);
}
