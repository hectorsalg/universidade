#include<stdio.h>
#include<math.h>

//tipo.
struct coordenadas{
	float x1, x2, y1, y2;
};
typedef struct coordenadas Ponto;

//chama função.
float distancia(float x1, float y1, float x2, float y2);

//main.
void main(){
    //variável.
    Ponto local;
    float d;

    //entrada.
    scanf("%f %f", &local.x1, &local.y1);
    scanf("%f %f", &local.x2, &local.y2);

    d=distancia(local.x1, local.y1, local.x2, local.y2);

    //saída.
    printf("Distancia: %.4f\n", d);
}
//função.
float distancia(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}