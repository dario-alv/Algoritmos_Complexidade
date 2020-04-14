#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main (void)
{
	PtAVLNode avl; int st; char filename[21];

	system ("clear");
	printf ("\nLer arvore binaria de pesquisa do ficheiro - Read avl tree from a text file\n");
	do
	{
  		printf ("Nome do ficheiro (Filename) -> ");
		st = scanf ("%20[^\n]", filename);
		scanf ("%*[^\n]"); scanf ("%*c");
	} while (st == 0);

	avl = AVLCreateFile (filename);

	if (AVLEmpty (avl)) printf ("\nArvore vazia! Empty tree!\n");

	printf ("\nNumero de nos da arvore (node number) = %d\n", AVLSize (avl));

	printf ("\nAltura da arvore (tree height) = %d\n", AVLHeight (avl));

	printf ("\nArvore listada em pre-ordem (versao recursiva)\n");
	printf ("Tree listed using a pre-order traversal (recursive version)\n");
	AVLPreOrder (avl);
	printf ("\n");

	printf ("\nArvore listada em ordem (versao recursiva)\n");
	printf ("Tree listed using a in-order traversal (recursive version)\n");
	AVLInOrder (avl);
	printf ("\n");

	printf ("\nArvore listada em pos-ordem (versao recursiva)\n");
	printf ("Tree listed using a post-order traversal (recursive version)\n");
	AVLPosOrder (avl);
	printf ("\n");

	printf ("\nArvore listada hierarquicamente - Tree listed hierarchically\n");
	AVLDisplay (avl);
	printf ("\n");

	printf ("\nDestruir a arvore - Releasing the tree\n\n");
	AVLDestroy (&avl);

	return 0;
}

