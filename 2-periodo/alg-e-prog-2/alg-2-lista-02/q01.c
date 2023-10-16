#include <stdio.h>
#define max 40
int main(){
	
    int alunos[max], i = 0, j = 0, k = 0, vezes[11], t = 0, v = 0;
	
	for(v = 0; v < 11; v++){
		vezes[v] = 0;
		}
	
	for(k = 0;k < max;k++){
		alunos[k] = 34;
		}
	
	while(alunos[i]){
		
		scanf("%d", &alunos[i]);
		
		if(alunos[i] == 0){
			vezes[0] += 1;
		}
		if(alunos[i] == 1){
			vezes[1] += 1;
		}if(alunos[i] == 2){
			vezes[2] += 1;
		}if(alunos[i] == 3){
			vezes[3] += 1;
		}if(alunos[i] == 4){
			vezes[4] += 1;
		}if(alunos[i] == 5){
			vezes[5] += 1;
		}if(alunos[i] == 6){
			vezes[6] += 1;
		}if(alunos[i] == 7){
			vezes[7] += 1;
		}if(alunos[i] == 8){
			vezes[8] += 1;
		}if(alunos[i] == 9){
			vezes[9] += 1;
		}if(alunos[i] == 10){
			vezes[10] += 1;
		} if(alunos[i] == -1){
			break;
			}
		i++;
	}for(t = 0;t < 11; t++){
		printf("%d     %d\n", t, vezes[t]);
	}
	return 0;
	}