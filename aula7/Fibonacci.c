#include <stdio.h>
#include <stdlib.h>

/* alusão da função que implementa o algoritmo pretendido */
unsigned int Fib1 (unsigned int);
unsigned int Fib2 (unsigned int);
/* variável global para contar as chamadas recursivas do algoritmo */
int Mult = 0;

int main (void) {
	/* obter a e b */
	unsigned int N;
	printf("N: ");
	scanf("%d", &N);
	
	/* invocação do algoritmo pretendido */ 
	int Result = Fib1 (N);
	
	/* apresentação do resultado e do número de operações aritméticas executadas pelo algoritmo */
	fprintf (stdout, "F.Recursiva:\n");
	fprintf (stdout, "Result: %d\nMulti: %d\n", Result, Mult);
	
	/* aplicar 2º metodo */
	Mult = 0;
	Result = Fib2 (N);
	
	fprintf (stdout, "\nP.Dinâmica:\n");
	fprintf (stdout, "Result: %d\nMulti: %d\n", Result, Mult);
	
	exit (EXIT_SUCCESS);
}

/* algoritmos pedidos */
unsigned int Fib1 (unsigned int N) {
	if(N==0) return 0;
	if(N==1) return 1;
	Mult += 2;
	return 3 * Fib1(N-1) + 2 * Fib1(N-2); 
}

unsigned int Fib2 (unsigned int N) {
	int f[N+2];
	f[0] = 0;
	f[1] = 1;
	for(int i=2; i<=N; i++) {
		Mult += 2;
		f[i] = 3 * f[i-1] + 2 * f[i-2];
	}
	return f[N];
}