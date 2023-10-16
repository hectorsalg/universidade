#include<stdio.h>


main(){
	
    float n1, n2, n3, ma, mt, sm=0, contma;
    int i, qtda=20;

    for (i = 1; i <= qtda; i++){
        
		printf("Digite as 3 notas do aluno %i.\n", i);
        scanf("%f %f %f", &n1, &n2, &n3);

        ma = (n1+n2+n3)/3;

        printf("media do aluno %i: %.1f\n", i, ma);

        if (ma >= 7.0){
            contma++;
}  
		sm = sm + ma;
}
    	mt = sm/qtda;

    	printf("Media da turma: %.2f\n", mt);
    	printf("Percentual de alunos com media acima de 7: %.1f%%\n", (contma/qtda)*100);
    	return 0;
}
