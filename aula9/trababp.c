#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "abp.h"

void PrintQueue (PtQueue);

int main (void)
{
	PtABPNode abp, node; int test; unsigned int count; PtQueue queue;

	abp = ABPCreate ();

	printf ("--------------------------------------------------------------------------------------------\n");
	if (ABPEmpty (abp)) printf ("Arvore vazia! - Empty tree!\n");
	printf ("-------------------------- Testar o DeleteMin ----------------------------------------------\n");
	ABPDeleteMin (&abp);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	printf ("-------------------------- Testar o DeleteMax ----------------------------------------------\n");	
	ABPDeleteMax(&abp);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	printf ("-------------------------- Testar o FloorValue ---------------------------------------------\n");
	node = ABPFloorValue (abp, 57);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	printf ("-------------------------- Testar o CeilValue ----------------------------------------------\n");
	node = ABPCeilValue (abp, 57);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	printf ("--------------------------- Testar o Elements ----------------------------------------------\n");
	if ((queue = QueueCreate (sizeof (int))) != NULL)
	{
		ABPElements (abp, queue, 25, 65);
		QueueDestroy(&queue); /*erro do adrego*/
		if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	}
	printf ("----------------------------- Testar o Rank ------------------------------------------------\n");
	test = ABPRank (abp, 70);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	printf ("--------------------------- Testar o EvenOdd -----------------------------------------------\n");
	test = ABPIsEvenOdd (abp);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());


    ABPInsertRec (&abp, 50); ABPInsertRec (&abp, 60); ABPInsertRec (&abp, 30);
    ABPInsertRec (&abp, 25); ABPInsertRec (&abp, 45); ABPInsertRec (&abp, 55); ABPInsertRec (&abp, 65);

	printf ("--------------------------------------------------------------------------------------------\n");
	if (ABPEmpty (abp)) printf ("Arvore vazia! - Empty tree!\n");
	else 
	{
		ABPDisplay (abp);
		printf ("--------------------------------------------------------------------------------------------\n");
		printf ("Numero de nos da arvore (number of nodes) = %d\n", ABPSize (abp));
		printf ("Altura da arvore (tree height) = %d\n", ABPHeight (abp));
	}
	printf ("--------------------------------------------------------------------------------------------\n");

	printf ("-------------------------- Testar o DeleteMin ----------------------------------------------\n");
	printf ("Arvore listada em ordem (inorder traversal) 0 -> ");
	ABPInOrderRec (abp); printf ("\n");
	count = 0;
	while (!ABPEmpty(abp))
	{
		count++;
		ABPDeleteMin (&abp);
		if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
		else
		{
			printf ("Arvore listada em ordem (inorder traversal) %d -> ", count);
			ABPInOrderRec (abp); printf ("\n");
		}
	}
	printf ("--------------------------------------------------------------------------------------------\n");
	if (ABPEmpty (abp)) printf ("Arvore vazia! - Empty tree!\n");
	else 
	{
		ABPDisplay (abp);
		printf ("--------------------------------------------------------------------------------------------\n");
		printf ("Numero de nos da arvore (number of nodes) = %d\n", ABPSize (abp));
		printf ("Altura da arvore (tree height) = %d\n", ABPHeight (abp));
	}
	printf ("--------------------------------------------------------------------------------------------\n");
	
    ABPInsertRec (&abp, 50); ABPInsertRec (&abp, 60); ABPInsertRec (&abp, 30);
    ABPInsertRec (&abp, 25); ABPInsertRec (&abp, 45); ABPInsertRec (&abp, 55); ABPInsertRec (&abp, 65);


	if (ABPEmpty (abp)) printf ("Arvore vazia! - Empty tree!\n");
	else 
	{
		ABPDisplay (abp);
		printf ("--------------------------------------------------------------------------------------------\n");
		printf ("Numero de nos da arvore (number of nodes) = %d\n", ABPSize (abp));
		printf ("Altura da arvore (tree height) = %d\n", ABPHeight (abp));
	}
	printf ("--------------------------------------------------------------------------------------------\n");

	printf ("-------------------------- Testar o DeleteMax ----------------------------------------------\n");
	printf ("Arvore listada em ordem (inorder traversal) 0 -> ");
	ABPInOrderRec (abp); printf ("\n");
	count = 0;
	while (!ABPEmpty(abp))
	{
		count++;
		ABPDeleteMax(&abp);
		if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
		else
		{
			printf ("Arvore listada em ordem (inorder traversal) %d -> ", count);
			ABPInOrderRec (abp); printf ("\n");
		}
	}
	printf ("--------------------------------------------------------------------------------------------\n");
	if (ABPEmpty (abp)) printf ("Arvore vazia! - Empty tree!\n");
	else 
	{
		ABPDisplay (abp);
		printf ("--------------------------------------------------------------------------------------------\n");
		printf ("Numero de nos da arvore (number of nodes) = %d\n", ABPSize (abp));
		printf ("Altura da arvore (tree height) = %d\n", ABPHeight (abp));
	}
	printf ("--------------------------------------------------------------------------------------------\n");

    ABPInsertRec (&abp, 50); ABPInsertRec (&abp, 60); ABPInsertRec (&abp, 30);
    ABPInsertRec (&abp, 25); ABPInsertRec (&abp, 45); ABPInsertRec (&abp, 55); ABPInsertRec (&abp, 65);
	if (ABPEmpty (abp)) printf ("Arvore vazia! - Empty tree!\n");
	else 
	{
		ABPDisplay (abp);
		printf ("--------------------------------------------------------------------------------------------\n");
		printf ("Numero de nos da arvore (number of nodes) = %d\n", ABPSize (abp));
		printf ("Altura da arvore (tree height) = %d\n", ABPHeight (abp));
	}
	printf ("--------------------------------------------------------------------------------------------\n");

	printf ("-------------------------- Testar o FloorValue ---------------------------------------------\n");
	node = ABPFloorValue (abp, 57);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	else printf ("floor do 57 = %d\n", ABPElement (node));
	node = ABPFloorValue (abp, 60);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	else printf ("floor do 60 = %d\n", ABPElement (node));
	node = ABPFloorValue (abp, 15);
	if (ABPErrorCode () == ABP_EMPTY) printf ("floor do 15 - arvore vazia ou elemento inexistente\n");
	else printf ("floor do 15 = %d\n", ABPElement (node));
	
	printf ("-------------------------- Testar o CeilValue ----------------------------------------------\n");
	node = ABPCeilValue (abp, 57);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	else printf ("ceil do 57 = %d\n", ABPElement (node));
	node = ABPCeilValue (abp, 30);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	else printf ("ceil do 30 = %d\n", ABPElement (node));
	node = ABPCeilValue (abp, 70);
	if (ABPErrorCode () == ABP_EMPTY) printf ("ceil do 70 - arvore vazia ou elemento inexistente\n");
	else printf ("ceil do 70 = %d\n", ABPElement (node));

	printf ("--------------------------- Testar o Elements ----------------------------------------------\n");

	if ((queue = QueueCreate (sizeof (int))) != NULL)
	{
		ABPElements (abp, queue, 25, 65);
		printf ("Elementos entre 25 e 65 -> ");
		PrintQueue (queue);
		
		ABPElements (abp, queue, 0, 25);
		printf ("Elementos entre 0 e 25 -> ");
		PrintQueue (queue);	

		ABPElements (abp, queue, 65, 90);
		printf ("Elementos entre 65 e 90 -> ");
		PrintQueue (queue);	

		ABPElements (abp, queue, 32, 57);
		printf ("Elementos entre 32 e 57 -> ");
		PrintQueue (queue);
		QueueDestroy (&queue);   	
		printf ("--------------------------------------------------------------------------------------------\n");
	}
	printf ("----------------------------- Testar o Rank ------------------------------------------------\n");
	test = ABPRank (abp, 70);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	else printf ("%d elementos menores do que 70\n", test);

	test = ABPRank (abp, 50);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	else printf ("%d elementos menores do que 50\n", test);

	test = ABPRank (abp, 20);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	else printf ("%d elementos menores do que 20\n", test);


	printf ("--------------------------- Testar o EvenOdd -----------------------------------------------\n");
	test = ABPIsEvenOdd (abp);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	else if (test) printf ("arvore composta por pares e impares alternadamente\n");
		 else printf ("arvore nao composta por pares e impares alternadamente\n");
	printf ("--------------------------------------------------------------------------------------------\n");

    ABPDeleteRec (&abp, 50);
	if (ABPEmpty (abp)) printf ("Arvore vazia! - Empty tree!\n");
	else 
	{
		ABPDisplay (abp);
		printf ("--------------------------------------------------------------------------------------------\n");
		printf ("Numero de nos da arvore (number of nodes) = %d\n", ABPSize (abp));
		printf ("Altura da arvore (tree height) = %d\n", ABPHeight (abp));
	}
	printf ("--------------------------------------------------------------------------------------------\n");

	printf ("--------------------------- Testar o EvenOdd -----------------------------------------------\n");
	test = ABPIsEvenOdd (abp);
	if (ABPErrorCode ()) printf ("Erro = %s\n", ABPErrorMessage ());
	else if (test) printf ("arvore composta por pares e impares alternadamente\n");
		 else printf ("arvore nao composta por pares e impares alternadamente\n");
	printf ("--------------------------------------------------------------------------------------------\n");
	printf ("\n");
	
	ABPDestroy (&abp);
	return 0;
}

void PrintQueue (PtQueue pqueue)
{
	if (pqueue == NULL) { printf ("Erro\n"); return ; }
	
	int number;
	while (!QueueIsEmpty (pqueue))
	{
		QueueDequeue (pqueue, &number);
		printf ("%d ", number);
	}
	 printf ("\n");
}

