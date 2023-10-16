#include <stdio.h>
#include "myString.h"


char *mystrcpy(char *s1, const char *s2){
	int i;
	for(i = 0; s2[i] != '\0'; i++){
		s1[i] = s2[i];
	}
	s1[i] = '\0';
	return s1;
}
char *mystrncpy(char *s1, const char *s2, size_t n){
	int i;
	for(i = 0; i < n; i++){
		s1[i] = s2[i];
	}
	return s1;
}
char *mystrcat(char *s1, const char *s2){
	int i = 0, count = 0;
	for(count; s1[count] != '\0';){
         count++;
    }
    for(i; s2[i] != '\0';){
         s1[count] = s2[i];
         i++;
         count++;
     }
     s1[count] = '\0';
     return s1;
}
char *mystrncat(char *s1, const char *s2, size_t n){
	int i = 0, j = 0, count = 0;
	
    for(count; s1[count] != '\0';){
    	count++;
    }
    for(i; s2[i] != '\0'; i++){
        for(j; j < n; j++){
            s1[count] = s2[j];
            count++;
        }
    }
    s1[count] = '\0';
    return s1;
}
int *mystrcmp(const char *s1, const char *s2){
	
	int i = 0, j = 0, counti = 0, countj = 0;
	char r1='0', r2='1';
	
	for(i; s1[i] != '\0'; i++){
		counti+=s1[i];
	}
	for(j; s2[j] != '\0'; j++){
		countj+=s2[j];
	}
	if(counti == countj){
		printf("%c", r1);
	} else if(counti > countj){
		printf("%c", r2);
	} else if(counti < countj){
		printf("-%c", r2);
	}
}
int *mystrncmp(const char *s1, const char *s2, size_t n){
	
	int i = 0, j = 0, k = 0, l = 0;
	int counti = 0, countj = 0;
	char r1='0', r2='1';
	
	for(i; s1[i] != '\0'; i++){
		for(j; j < n; j++){
		counti+=s1[j];
		}
	}
	for(k; s2[k] != '\0'; k++){
		for(l; l < n; l++){
		countj+=s2[l];
		}
	}
	if(counti == countj){
		printf("%c", r1);
	} else if(counti > countj){
		printf("%c", r2);
	} else if(counti < countj){
		printf("-%c", r2);
	}
}