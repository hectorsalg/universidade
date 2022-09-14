#include<stdio.h>
#include<string.h>

int main(){

    char digito, num_neg[200];
    int k;

    while(digito != '0'){
        scanf("%c", &digito);
        scanf("%s", num_neg);
        if(digito != '0'){
            k = strlen(num_neg);
            for(int i = 0; i < k; i++){
                if(num_neg[ i ] == digito){
                    for(int j = i; j < k; j++)
                        num_neg[ j ] = num_neg[ j + 1 ];
                        num_neg[ k - 1 ] = 0;
                        k--;
                        i--;
                }
            }
            for(int i = 0; i < k; i++){
                if(num_neg[ i ] == '0'){
                    for(int j = 1; j < k; j++)
                        num_neg[ j ] = num_neg[ j + 1 ];
                        num_neg[ k - 1 ];
                        k--;
                        i--;
                } else
                    break;
            }
            if(k == 0){
                num_neg[0]='0';
                num_neg[1]='\0';
            }
            printf("%s\n", num_neg);
        }
    }
    return 0;
}