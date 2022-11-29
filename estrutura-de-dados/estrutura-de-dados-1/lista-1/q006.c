#include <stdio.h>
#include <string.h>

int subtrai(char s1[], char s2[]){
    int size_s1 = strlen(s1);
    int size_s2 = strlen(s2);
    for (int i = 0; i < size_s1; i++) {
        for (int j = 0; j < size_s2; j++) {
            if (s1[i] == s2[j]) {
                for (int k = i; k < size_s1; k++) {
                    s1[k] = s1[k + 1];
                }
            }
        }
    }
    char *s3 = s1;
    printf("%s", s3);
    return 0;
}
 
int main() {
    char s1[15], s2[15];
    printf("Digite uma palavra: ");
    scanf("%s",&s1);
    printf("Digite outra palavra: ");
    scanf("%s",&s2);

    subtrai(s1, s2);
    
    return 0;
}