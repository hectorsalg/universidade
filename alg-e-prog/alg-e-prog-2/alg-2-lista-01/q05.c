#include<stdio.h>

int main (){
	
	//variável.
	int h1, h2, m1, m2, s1, s2;
	
	//entrada.
	scanf("%i %i %i %i", &h1, &h2, &m1, &m2);
	
	//condição 1.
	if (h1 > h2 && m1 > m2) {
		s1 = h1 + m2;
		s2 = m1 * h2;
	}
	//condição 2.
	if (h1 > h2 && m1 < m2) {
		s1 = h1 + m1;
		s2 = m2 * h2;
	}
	//condição 3.
	if (h1 < h2 && m1 > m2) {
		s1 = h2 + m2;
		s2 = m1 * h1;
	}
	//condição 4.
	if (h1 < h2 && m1 < m2) {
		s1 = h2 + m1;
		s2 = m2 * h1;
	}

	//saída.
	printf("\n%i %i\n", s1, s2);
	return 0;
}