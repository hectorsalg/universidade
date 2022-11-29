#include <stdio.h>

int pot(int x, int y){
    if(y==1){
        return x;
    }else{
        return (x*pot(x,y-1));
    }
}

int main() {

    int x,y;
    float media = 0.0;
    printf("Insira um valor: ");
    scanf("%i", &x);
    printf("Insira um valor: ");
    scanf("%i", &y);
    printf("\n Result: %d ", pot(x,y));
    return 0; 

}