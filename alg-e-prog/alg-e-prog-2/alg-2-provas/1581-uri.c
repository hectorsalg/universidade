#include <stdio.h>
#include <string.h>
#define MAX 20

int main(){

    int N, i, K, j;
    char S[MAX], axu1[MAX], axu2[MAX] = "ingles";

    scanf("%d", &N);

    for (i = 0; i < N; i++){
        scanf("%d", &K);
        setbuf(stdin, NULL);
        scanf("%s", axu1);
        for (j = 1; j < K; j++){
            setbuf(stdin, NULL);
            scanf("%s", S);
            if (strcmp(axu1, S) != 0) // Linguas diferente
            {
                strcpy(axu1, axu2);
            }
        }
        printf("%s\n", axu1);
        axu1[0] = '\0';
        S[0] = '\0';
    }
    return 0;
}