#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* alusão da função que implementa o algoritmo pretendido */
/* allusion to the function that implements the algorithm */
int SequentialSequence (int [], int);

/* variável global para contar as operações aritméticas executadas pelo algoritmo */
/* global variable for counting the arithmetic operations executed by the algorithm */
int Sum = 0;

int main (void)
{
	/* declaração dos arrays de teste - usar o pretendido para cada execução */
	/* declaration of the test arrays - use each one for each execution */

	//int Array[] = { 1, 3, 4, 5, 5, 6, 7, 7, 8, 9 };
	//int Array[] = { 1, 2, 4, 5, 5, 6, 7, 8, 8, 9 };
	//int Array[] = { 1, 2, 3, 6, 8, 8, 8, 9, 9, 9 };
	//int Array[] = { 1, 2, 3, 4, 6, 7, 7, 8, 8, 9 };
	//int Array[] = { 1, 2, 3, 4, 5, 7, 7, 8, 8, 9 };
	//int Array[] = { 1, 2, 3, 4, 5, 6, 8, 8, 9, 9 };
	/* int Array[] = { 1, 2, 3, 4, 5, 6, 7, 9, 9, 9 }; */
	/* int Array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 8, 9 }; */
	int Array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 9 };
	//int Array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
 
	//int Array[] = { 1, 3, 2, 3, 5};
	//int Array[] = { 1, 2, 4, 3, 5};
	//int Array[] = { 1, 2, 3, 5, 6};
	//int Array[] = { 1, 2, 3, 4, 6};
	//int Array[] = { 1, 2, 3, 4, 5};
	int NElem = sizeof (Array) / sizeof (int); 
	int Result;

	/* invocação do algoritmo pretendido - algorithm invocation */ 
	Result = SequentialSequence (Array, NElem);

	/* apresentação do resultado e do número de operações aritméticas executadas pelo algoritmo */
	/* presenting the result and the number of arithmetic operations executed by the algorithm */
	if (Result) fprintf (stdout, "Verifica ");
	else fprintf (stdout, "Nao verifica ");

	fprintf (stdout, "Resultado = %3d N. de operacoes = %3d\n", Result, Sum);

	exit (EXIT_SUCCESS);
}

/* implementação do algoritmo pretendido */
/* não se esqueça de contar as operações aritméticas executadas pelo algoritmo usando a variável global */

/* implementation of the pretended algorithm */
/* do not forget to count the arithmetic operations using the global variable */

int SequentialSequence (int array[], int n)
{
	assert(n>1);
	for(int i=0; i<n-1; i++){
		Sum++;
		if(array[i]+1!=array[i+1]) return 0;
	}
	return 1;
}

