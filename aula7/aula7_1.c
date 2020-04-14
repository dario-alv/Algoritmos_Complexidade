#include <stdio.h>
#include <stdlib.h>

/* alusão da função que implementa o algoritmo pretendido */
float Metodo1 (float, unsigned int);
float Metodo2 (float, unsigned int);
/* variável global para contagem das multiplicações */
int NumMulti = 0;

int main (void) {
	/* obter N do utilizador */
	unsigned int N;
	float x;
	printf("N: ");
	scanf("%d", &N);
	printf("X: ");
	scanf("%f", &x);
	/* invocação do algoritmo pretendido */ 
	float Result = Metodo1 (x, N);
	
	/* apresentação do resultado e do número de operações aritméticas executadas pelo algoritmo */
	fprintf (stdout, "Método1:\n");
	fprintf (stdout, "Resultado = %.6f N.de multi = %3d\n", Result, NumMulti);
	
	/* voltar a iniciar as variaveis globais */ 
	NumMulti = 0;
	
	/* aplicar 2º metodo */
	Result = Metodo2 (x, N);
	fprintf (stdout, "Método2:\n");
	fprintf (stdout, "Resultado = %.6f N.de multi = %3d\n", Result, NumMulti);
	
	exit (EXIT_SUCCESS);
}

/* algoritmos pedidos */
float Metodo1 (float x, unsigned int N) {
	if(N>0) {NumMulti++; return (x * Metodo1(x, N-1));}
	return 1.0;
}

float Metodo2 (float x, unsigned int N) {
	if(N==0) return 1.0;
	float val;
	if((N%2)==0) {
		NumMulti++;
		val = Metodo2(x, N/2);
		return val * val;
	}
	NumMulti += 2;
	val = Metodo2(x, N/2);
	return x * val * val;
}