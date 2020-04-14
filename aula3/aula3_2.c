#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* alusão da função que implementa o algoritmo pretendido */
/* allusion to the function that implements the algorithm */
int BiggerThanPred (int [], int);

/* variável global para contar as operações aritméticas executadas pelo algoritmo */
/* global variable for counting the arithmetic operations executed by the algorithm */
int Comp = 0;

int main (void)
{
	/* declaração dos arrays de teste - usar o pretendido para cada execução */
	/* declaration of the test arrays - use each one for each execution */

	int Array[] = { 1, 9, 2, 8, 3, 4, 5, 3, 7, 2 }; 
	//int Array[] = { 1, 7, 4, 6, 5, 2, 3, 2, 1, 0 };
	//int Array[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };

	//int Array[] = { };
	int NElem = sizeof (Array) / sizeof (int); int Result;

	/* invocação do algoritmo pretendido - algorithm invocation */ 
	Result = BiggerThanPred (Array, NElem);

	/* apresentação do resultado e do número de operações de comparação executadas pelo algoritmo */
	/* presenting the result and the number of comparation operations executed by the algorithm */

	fprintf (stdout, "Resultado = %3d N. de operacoes = %3d\n", Result, Comp);

	exit (EXIT_SUCCESS);
}

/* implementação do algoritmo pretendido */
/* não se esqueça de contar as operações aritméticas executadas pelo algoritmo usando a variável global */

/* implementation of the pretended algorithm */
/* do not forget to count the arithmetic operations using the global variable */

int BiggerThanPred (int array[], int n)
{
	assert(n>1);
	int count = 0;
	int countMax = 1;
	int pos = -1;
	for(int i = n-1; i>=1; i--) {
		for(int j=i-1; j>=0; j--) {
			Comp++;
			if(array[i]>array[j]) count++;
		}
		Comp++;
		//Comp++;
		if(count>=countMax) {
			pos = i;
			countMax = count;
		}
		//if(i-1<countMax) break;
		count = 0;
	}
	//printf("n: %d\n", countMax);
	return pos;
}
