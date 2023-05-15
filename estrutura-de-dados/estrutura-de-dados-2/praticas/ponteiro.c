#include <stdio.h>


void pont(int **p, int *num) {
    **p = *num;
    *num = 50;
}

int main() {

    int *p, num;

    num = 9;
    p = &num;

    pont(&p, &num);

    printf("%d\n", *p);

    return 0;
}