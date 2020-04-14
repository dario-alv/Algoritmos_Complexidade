#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "crono.h"

int main (void)
{
	int Value, Element, NElem, Index, Test, *Array;

	/* leitura da dimensão do array */
	/* reading the array dimension */
	do
	{
		printf ("Tamanho do array - Array size N? "); Test = scanf ("%d", &NElem);
		scanf ("%*[^\n]"); scanf ("%*c");
	} while (Test == 0);

	/* criar o array na memória dinâmica - creating the array in the dynamic memory */
	if ((Array = (int *) calloc (NElem, sizeof (int))) == NULL) return EXIT_FAILURE;

	/* inicializar a semente de geração de números aleatórios */
	/* initiate the seed of the random numbers */
	srand (getpid());

	/* preencher o array com números aleatórios inteiros até 10000 */
	/* fill the array with random integer positive numbers until 10000 */
	for (Index = 0; Index < NElem; Index++)
	{
        	Array[Index] = (int) (10000 * (rand()/(RAND_MAX+1.0)));
	}

	/* Elementos a aceder - Elements to acess */
	/* Elemento Inicial - First Element - Element = 0; */
	/* Elemento Central - Middle Element - Element = NElem/2; */
	/* Elemento Final - Last Element - Element = NElem-1; */

	/* iniciar a contagem de tempo - start the crono */
	ligar ();

	/* inserir o código the acesso ao elemento do array - usar um ciclo for para obter um tempo */
	/* insert the code for acessing the array element - use a for cycle to obtain time */

	/* terminar a contagem de tempo - stop the crono */
	parar ();
	
	/* obter e imprimir o tempo de execução - get and print the execution time */
	printf ("Tempo de execução - Execution time = %f\n", tempocpu ());

	exit (EXIT_SUCCESS);
}

