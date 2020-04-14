#include <stdio.h>
#include <stdlib.h>

/* alusão da função que implementa o algoritmo pretendido */
int isPower (unsigned int, unsigned int);
/* variável global para contar as chamadas recursivas do algoritmo */
int NumDiv = 0;

int main (void) {
	/* obter a e b */
	unsigned int a, b;
	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);
	
	/* invocação do algoritmo pretendido */ 
	int Result = isPower (a, b);
	
	/* apresentação do resultado e do número de operações aritméticas executadas pelo algoritmo */
	if(Result) fprintf (stdout, "%d é potência de %d\n", a, b);
	else fprintf(stdout, "%d NÃO é potência de %d\n", a, b);
	fprintf(stdout, "Número divisões: %d\n", NumDiv);
	exit (EXIT_SUCCESS);
}

/* algoritmos pedidos */
int isPower (unsigned int a,unsigned int b) {
	if(a == b || a==1) return 1;
	if(a%b == 0) { NumDiv++; return isPower (a/b, b); }
	else return 0;
}
