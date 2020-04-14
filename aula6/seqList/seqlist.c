/*******************************************************************************
 Ficheiro de implementação do Tipo de Dados Abstracto SEQ_LIST (seqlist.c).
 A estrutura de dados de suporte da sequência é uma estrutura, constituída pelos
 campos de tipo inteiro Size para indicar o número de elementos armazenados na
 sequência e os campos de tipo ponteiro para nós de lista biligada Head e Tail,
 para representar, respectivamente, a cabeça e a cauda da lista biligada onde
 são armazenados os números inteiros.

 Autor : Dário César Loureiro Alves                   NMEC :67591
*******************************************************************************/

#include <stdio.h> 
#include <stdlib.h>

#include "seqlist.h"  /* Ficheiro de interface do TDA - ADT Interface file */

/************ Definição da Estrutura de Dados Interna da Sequência ************/

typedef struct binode *PtBiNode;
struct binode /* definição do nó da lista biligada */
{
	int Elem; /* o elemento da lista */
	PtBiNode PtPrev, PtNext; /* ponteiros para o nós anterior e seguinte */
};

struct seqlist
{
  int Size; /* número de elementos - sequence's size */
  PtBiNode Head; /* ponteiro para o início da lista (cabeça da lista) - list head */
  PtBiNode Tail; /* ponteiro para o fim da lista (cauda da lista) - list tail */
};

/*********************** Controlo Centralizado de Error ************************/

static unsigned int Error = OK;  /* inicialização do erro */

static char *ErrorMessages[] = {
                                 "sem erro - Without Error",
                                 "sequencia(s) inexistente(s) - Sequence(s) do not exist",
                                 "memoria esgotada - Out of memory",
                                 "indice errado - Wrong index",
                                 "elemento inexistente - Element does not exist",
                                 "sequencia vazia - Empty sequence",
                                 "sequencia cheia - Full sequence",
                                 "dimensao da sequencia errada - Wrong size",
                                 "ficheiro inexistente - File does not exist",
                                 "ponteiro nulo - Null pointer"
                               };

static char *AbnormalErrorMessage = "erro desconhecido - Unknown error";

/************** Número de mensagens de erro previstas no módulo ***************/

#define N (sizeof (ErrorMessages) / sizeof (char *))

/******************** Protótipos dos Subprogramas Internos ********************/

PtBiNode BiNodeCreate (int);
void BiNodeDestroy (PtBiNode *);
void DoubleListDestroy (PtBiNode *);

/*************************** Definição das Funções ****************************/

void SeqListClearError (void)
{ Error = OK; }

int SeqListError (void)
{ return Error; }

char *SeqListErrorMessage (void)
{
  if (Error < N) return ErrorMessages[Error];
  else return AbnormalErrorMessage;  /* sem mensagem de erro - no error message */
}

PtSeqList SeqListCreate ()
{
	PtSeqList List;
	if ((List = malloc (sizeof (struct seqlist))) == NULL)
	{ Error = NO_MEM; return NULL; }
	
	Error = OK;
	List->Size = 0;
	List->Head = NULL;
	List->Tail = NULL;
	return List;
}

void SeqListDestroy (PtSeqList *pseq)
{
	PtSeqList List = *pseq;
	if(List == NULL) { Error = NO_SEQ; return; }
	DoubleListDestroy (&List->Head);
	Error = OK;
	free(List);
	*pseq = NULL;
}

PtSeqList SeqListCopy (PtSeqList pseq)
{
  PtSeqList Copy;

  /* verifica se a sequência existe - verifies if sequence exists */
  if (pseq == NULL) { Error = NO_SEQ; return NULL; }

  /* criação da sequência copia nulo - creating an empty sequence */
  if ((Copy = SeqListCreate ()) == NULL) return NULL;

  /* fazer a copia da sequência - copying the components */
  for (PtBiNode Node = pseq->Head; Node != NULL; Node = Node->PtNext)
  {
    SeqListInsert (Copy, Node->Elem);
    if (Error == NO_MEM) break;
  }
  
  if (Error == NO_MEM) { SeqListDestroy (&Copy); return NULL; }
  
  Copy->Size = pseq->Size;
  Error = OK;
  return Copy;  /* devolve a sequência copia - returning the new sequence */
}

PtSeqList SeqListFileCreate (char *pfname)
{
  PtSeqList Seq; FILE *PtF; unsigned int Size, I; int Elem;

  /* abertura com validacao do ficheiro para leitura - opening the text file for reading */
  if ( (PtF = fopen (pfname, "r")) == NULL) { Error = NO_FILE; return NULL; }

  /* leitura da dimensão da sequência e do número de elementos */
  /* reading the sequence's dimension and the number of elements */
  fscanf (PtF, "%u", &Size);
  if (Size < 1) { Error = BAD_SIZE; fclose (PtF); return NULL; }

  /* criação da sequência vazia - creating an empty sequence */
  if ((Seq = SeqListCreate ()) == NULL) { fclose (PtF); return NULL; }

  Error = OK;
  /* leitura da sequência do ficheiro - reading the sequence's components from the text file */
  for (I = 0; I < Size; I++)
  {
    fscanf (PtF, "%d", &Elem);
    SeqListInsert (Seq, Elem);
    if (Error == NO_MEM) break;
  }

  if (Error == NO_MEM) { SeqListDestroy (&Seq); return NULL; }

  fclose (PtF);  /* fecho do ficheiro - closing the text file */
  return Seq;  /* devolve a sequência criada - returning the new sequence */
}

void SeqListStoreFile (PtSeqList pseq, char *pfname)
{
  FILE *PtF;

  /* verifica se a sequência existe - verifies if sequence exists */
  if (pseq == NULL) { Error = NO_SEQ; return ; }

  /* verifica se a sequência tem elementos - verifies if sequence has elements */
  if (pseq->Size == 0) { Error = SEQ_EMPTY; return ; }

  /* abertura com validacao do ficheiro para escrita - opening the text file for writing */
  if ((PtF = fopen (pfname, "w")) == NULL) { Error = NO_FILE; return ; }

  /* escrita do número de elementos armazenados na sequência */
  /* writing the number of elements */
  fprintf (PtF, "%u\n", pseq->Size);

  /* escrita da sequência - writing the sequence's components in the text file */
  for (PtBiNode Node = pseq->Head; Node != NULL; Node = Node->PtNext)
	fprintf (PtF, "%d\n", Node->Elem);

  Error = OK;
  fclose (PtF);  /* fecho do ficheiro - closing the text file */
}

int SeqListGetSize (PtSeqList pseq)
{
	if (pseq == NULL) { Error = NO_SEQ; return 0; }
	Error = OK;
	return pseq->Size;
}

int SeqListGetElement (PtSeqList pseq, int pindex)
{
	if(pindex>=pseq->Size || pindex<-pseq->Size)
	{ Error = BAD_INDEX; return 0; }

	Error = OK;
	PtBiNode Node;
	if(pindex>-1) {
		Node = pseq->Head;
		for(int I=1; I<=pindex; I++) Node = Node->PtNext;
		return Node->Elem;
	}
	Node = pseq->Tail;
	for(int I=-2; I>=pindex; I--) Node = Node->PtPrev; 
	return Node->Elem;
}

void SeqListSetElement (PtSeqList pseq, int pindex, int pvalue)
{
	if(pindex>=pseq->Size || pindex<-pseq->Size)
	{ Error = BAD_INDEX; return; }

	Error = OK;
	PtBiNode Node;
	if(pindex>-1) {
		Node = pseq->Head;
		for(int I=1; I<=pindex; I++) Node = Node->PtNext;
		Node->Elem = pvalue;
	}
	else {
		Node = pseq->Tail;
		for(int I=-2; I>=pindex; I--) Node = Node->PtPrev; 
		Node->Elem = pvalue;
	}
}

int SeqListEquals (PtSeqList pseq1, PtSeqList pseq2)
{
	if (pseq1 == NULL || pseq2 == NULL) { Error = NO_SEQ; return -1; }
	Error = OK;
	
	if(pseq1->Size != pseq2->Size) return 0;
	PtBiNode Node1 = pseq1->Head, Node2 = pseq2->Head;
	for (;Node1 != NULL; Node1 = Node1->PtNext, Node2 = Node2->PtNext) {
		if(Node1->Elem != Node2->Elem) return 0;
	}
	return 1;
}

void SeqListInsert (PtSeqList pseq, int pvalue)
{
	if(pseq == NULL) { Error = NO_SEQ; return; }
	PtBiNode Node;
	if((Node = BiNodeCreate(pvalue)) == NULL) return;
	if(pseq->Size==0) { pseq->Head = Node; pseq->Tail = Node; }
	else {
		Node->PtPrev = pseq->Tail;
		pseq->Tail->PtNext = Node;
		pseq->Tail = Node;
	}
	pseq->Size++;
	//printf("Size: %d\n", pseq->Size);sleep(2);
}

void SeqListDelete (PtSeqList pseq, int pvalue)
{
	if(pseq == NULL) { Error = NO_SEQ; return; }
	if(pseq->Size==0) { Error = SEQ_EMPTY; return; }
	
	Error = NO_NUMBER;
	PtBiNode Node = pseq->Head;
	for(int I=0; I<pseq->Size; I++) {
		if(Node->Elem==pvalue) {
			Error = OK;
			if(pseq->Size==1) {
				pseq->Head = NULL;
				pseq->Tail = NULL;
				BiNodeDestroy(&Node);
			} else if(Node == pseq->Head) {
				pseq->Head = pseq->Head->PtNext;
				pseq->Head->PtPrev = NULL;
				BiNodeDestroy(&Node);
				Node = pseq->Head;
			} else if(Node == pseq->Tail) {
				pseq->Tail = pseq->Tail->PtPrev;
				pseq->Tail->PtNext = NULL;
				BiNodeDestroy(&Node);
			} else {
				PtBiNode Temp = Node;
				Node->PtPrev->PtNext = Node->PtNext;
				Node->PtNext->PtPrev = Node->PtPrev;
				Node = Node->PtNext;
				BiNodeDestroy(&Temp);
				Temp = NULL;
			}
			pseq->Size--;
			I--;
		} else {
			Node = Node->PtNext;
		}
	}
}

int SeqListIsOrdered (PtSeqList pseq)
{
	if(pseq == NULL) { Error = NO_SEQ; return -1; }
	if(pseq->Size==0) { Error = SEQ_EMPTY; return -1; }
	Error = OK;
	PtBiNode Node = pseq->Head;
	for(int I=1; I<pseq->Size; I++){
		if(Node->Elem > Node->PtNext->Elem) return 0;
		Node = Node->PtNext;
	}
	return 1;
}

int SeqListIsEvenOdd (PtSeqList pseq)
{
	if(pseq == NULL) { Error = NO_SEQ; return -1; }
	if(pseq->Size==0) { Error = SEQ_EMPTY; return -1; }
	Error = OK;
	
	PtBiNode Node = pseq->Head;
	if(Node->Elem % 2 == 0) {
		for(int I = 1; I<pseq->Size; I++) {
			Node = Node->PtNext;
			if(I % 2 == 0) {
				if(Node->Elem % 2 != 0) return 0;
			} else {
				if(Node->Elem % 2 == 0) return 0;
			}
		}
	} else {
		for(int I = 1; I<pseq->Size; I++) {
			Node = Node->PtNext;
			if(I % 2 == 0) {
				if(Node->Elem % 2 == 0) return 0;
			} else {
				if(Node->Elem % 2 != 0) return 0;
			}
		}
	}
	return 1;
}

int SeqListNumberOfMultiples (PtSeqList pseq, int pvalue)
{
	if(pseq == NULL) { Error = NO_SEQ; return -1; }
	if(pseq->Size==0) { Error = SEQ_EMPTY; return -1; }
	Error = OK;
	int num = 0;
	for(PtBiNode Node = pseq->Head; Node!=NULL; Node = Node->PtNext) {
		if(Node->Elem % pvalue == 0) num++;
	}
	return num;
}

void SeqListSmallerBigger (PtSeqList pseq, int * psmall, int * pbig)
{
	if(pseq == NULL) { Error = NO_SEQ; return; }
	if(pseq->Size==0) { Error = SEQ_EMPTY; return; }
	Error = OK;
	PtBiNode Node = pseq->Head;
	(*psmall) = Node->Elem; (*pbig) = Node->Elem;
	Node = Node->PtNext;
	for(; Node!=NULL; Node = Node->PtNext) {
		if(Node->Elem<(*psmall)) (*psmall) = Node->Elem;
		if(Node->Elem>(*pbig)) (*pbig) = Node->Elem;
	}
}

int SeqListIsPalindromic (PtSeqList pseq)
{
	if(pseq == NULL) { Error = NO_SEQ; return -1; }
	if(pseq->Size==0) { Error = SEQ_EMPTY; return -1; }
	Error = OK;
	PtBiNode Left = pseq->Head;
	PtBiNode Right = pseq->Tail;
	for(int I=0; I<pseq->Size/2; I++) {
		if(Left->Elem != Right->Elem) return 0;
		Left = Left->PtNext;
		Right = Right->PtPrev;
	}
	return 1;
}

double SeqListAverage (PtSeqList pseq)
{
	if(pseq == NULL) { Error = NO_SEQ; return -1; }
	if(pseq->Size==0) { Error = SEQ_EMPTY; return -1; }
	Error = OK;
	double val = 0;
	for(PtBiNode Node=pseq->Head; Node!=NULL; Node=Node->PtNext) {
		val += Node->Elem;
	}
	return val / pseq->Size;
}

/*******************************************************************************
 Função auxiliar para criar um nó da lista biligada. Valores de erro: OK ou NO_MEM.
 
 Auxiliary function to create a binode. Error codes: OK or NO_MEM.
*******************************************************************************/

PtBiNode BiNodeCreate (int pelem)	/* alocação do nó */
{
	PtBiNode Node;

	if ((Node = (PtBiNode) malloc (sizeof (struct binode))) == NULL)
	{ Error = NO_MEM; return NULL; }

	Node->Elem = pelem;	/* copiar a informação */
	Node->PtPrev = NULL;	/* apontar para detrás para NULL */
	Node->PtNext = NULL;	/* apontar para a frente para NULL */

	Error = OK;
	return Node;
}

/*******************************************************************************
 Função auxiliar para libertar um nó da lista biligada. Valores de erro: OK ou NULL_PTR.
 
 Auxiliary function to free a binode. Error codes: OK or NULL_PTR.
*******************************************************************************/
void BiNodeDestroy (PtBiNode *pnode)	/* libertação do nó */
{
	if (*pnode == NULL) { Error = NULL_PTR; return; }
	free (*pnode);	/* libertação do nó */
	*pnode = NULL;	/* colocar o ponteiro a nulo */
	Error = OK;
}

/*******************************************************************************
 Função auxiliar para destruir uma lista biligada. Valores de erro: OK ou NULL_PTR.
 
 Auxiliary function to destroy a double link list. Error codes: OK or NULL_PTR.
*******************************************************************************/
void DoubleListDestroy (PtBiNode *phead)
{
	PtBiNode TmpHead = *phead; PtBiNode Node;

	if (TmpHead == NULL) { Error = NULL_PTR; return; }
	while (TmpHead != NULL)
	{
		Node = TmpHead; TmpHead = TmpHead->PtNext;
		BiNodeDestroy (&Node);
	}
	Error = OK; 
}
