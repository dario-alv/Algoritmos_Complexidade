#include <stdio.h>
#include <stdlib.h>

/* alusão da função que implementa o algoritmo pretendido */
unsigned int SRec (unsigned int);
unsigned int SDin (unsigned int);
/* variável global para contar as chamadas recursivas do algoritmo */
int Mult = 0;

int main (void) {
	/* obter a e b */
	unsigned int N;
	printf("N: ");
	scanf("%d", &N);
	
	/* invocação do algoritmo pretendido */ 
	int Result = SRec (N);
	
	/* apresentação do resultado e do número de operações aritméticas executadas pelo algoritmo */
	fprintf (stdout, "F.Recursiva:\n");
	fprintf (stdout, "Result: %d\nMulti: %d\n", Result, Mult);
	
	/* aplicar 2º metodo */
	Mult = 0;
	Result = SDin (N);
	
	fprintf (stdout, "\nP.Dinâmica:\n");
	fprintf (stdout, "Result: %d\nMulti: %d\n", Result, Mult);
	
	exit (EXIT_SUCCESS);
}

/* algoritmos pedidos */
unsigned int SRec (unsigned int N) {
	if(N==0) return 1;
	unsigned int SUM = 0;
	for(int i=0; i<=N-1; i++) {
		Mult += 1;
		SUM += SRec(i) * SRec(N-i-1);
	}
	return SRec(N-1) + SUM;  
}

unsigned int SDin (unsigned int N) {
	unsigned int f[N+1];
	unsigned int val;
	f[0] = 1;
	for(int i=1; i<=N; i++) {
		val = 0;
		for(int j=0; j<i; j++) {
			Mult += 1;
			val += f[j] * f[i-1-j];
		}
		f[i] = f[i-1] + val;
	}
	return f[N];
}