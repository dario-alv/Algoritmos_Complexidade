/*******************************************************************************

 Ficheiro de interface do Tipo de Dados Abstrato Árvore Adelson-Velskii Landis
 (AVL) (avl.h). A implementação tem capacidade de múltipla instanciação, sendo
 providenciado um construtor para criar uma árvore vazia. É da responsabilidade
 da aplicação, invocar o destructor, para libertar a memória atribuída ao objecto.
 O módulo providencia um controlo centralizado de erro, disponibilizando uma
 função para obter o último erro ocorrido e uma função para obter uma mensagem
 de erro elucidativa.

 Autor : António Manuel Adrego da Rocha    Data : Abril de 2015

 Interface file of the abstract data type Adelson-Velskii Landis Tree ABP (avl.h).
 The implementation provides a constructor for creating an empty tree. The 
 application has the responsibility of calling the destructor to release the 
 dynamic memory allocated to the tree. The data-type has a central control error
 mechanism, providing operations for obtaining the last error occurred and for 
 obtaining the correspondent message. The data-type has also operations to store
 and retrieve trees from text files. The tree is simply represented by a pointer
 to its root.

*******************************************************************************/

#ifndef _AVL
#define _AVL

/****************** Definição do Tipo Ponteiro para uma AVL *******************/

typedef struct avlnode *PtAVLNode;

/************************ Definição de Códigos de Erro ************************/

#define	OK		    0	/* operação realizada com sucesso - operation with success */
#define	NO_AVL		1	/* a AVL não existe - tree does not exist */
#define	NO_MEM		2	/* memória esgotada - out of memory */
#define	NULL_PTR	3	/* ponteiro nulo - null pointer */
#define	AVL_EMPTY	4	/* AVL vazia - empty tree */
#define	REP_ELEM	5	/* já existe o elemento - element already exists in the tree */
#define	NO_ELEM		6	/* o elemento não existe - element does not exist in the tree */
#define	NO_FILE		7	/* o ficheiro não existe - file does not exist */

/*************************** Protótipos das Funções ***************************/

int AVLErrorCode (void);
/*******************************************************************************
 Função que devolve o código do último erro ocorrido. Returns the error code.
*******************************************************************************/

char *AVLErrorMessage (void);
/*******************************************************************************
 Função que devolve uma mensagem esclarecedora da causa do último erro ocorrido.
 Returns an error message.
*******************************************************************************/

PtAVLNode AVLCreate (void);
/*******************************************************************************
 Cria uma arvore vazia. Devolve um ponteiro a NULL.
 
 Creates the empty tree returning a NULL reference.
*******************************************************************************/

void AVLDestroy (PtAVLNode *proot);
/*******************************************************************************
 Destrói a arvore e coloca a referência a NULL. Valores de erro: OK ou AVL_EMPTY.
 
 Destroys the tree and releases the memory. Error codes: OK or ABP_EMPTY.
*******************************************************************************/

void AVLInsertRec (PtAVLNode *proot, int pelem);  /* versão recursiva */
/*******************************************************************************
 Coloca pelem na arvore. Não insere elementos repetidos.
 Valores de erro: OK, NO_MEM ou REP_ELE.
 
 Inserts pelem in the tree pointed by proot. Error codes: OK, NO_MEM or REP_ELE.
*******************************************************************************/

void AVLDeleteRec (PtAVLNode *proot, int pelem);  /* versão recursiva */
/*******************************************************************************
 Remove pelem da arvore. Valores de erro: OK ou NO_ELEM.
 
 Deletes pelem from the tree pointed by proot. Error codes: OK or NO_ELEM.
*******************************************************************************/

int AVLSearch (PtAVLNode proot, int pelem);
/*******************************************************************************
 Pesquisa se pelem existe na arvore. Devolve 1 em caso afirmativo e 0 em caso 
 contrário. Valores de erro: OK, AVL_EMPTY ou NO_ELEM.
 
 Searchs pelem in the tree pointed by proot. Returns 1 if it exists and 0 otherwise.
 Error codes: OK, ABP_EMPTY or NO_ELEM.
*******************************************************************************/

PtAVLNode AVLMinRec (PtAVLNode proot);  /* pesquisa de mínimo recursiva */
/*******************************************************************************
 Pesquisa o menor elemento da arvore. Valores de erro: OK ou AVL_EMPTY.
 
 Returns a pointer to the minimum element of the tree pointed by proot.
 Error codes: OK or ABP_EMPTY.
*******************************************************************************/

PtAVLNode AVLMaxRec (PtAVLNode proot);  /* pesquisa de máximo recursiva */
/*******************************************************************************
 Pesquisa o maior elemento da arvore. Valores de erro: OK ou AVL_EMPTY.
 
 Returns a pointer to the maximum element of the tree pointed by proot.
 Error codes: OK or ABP_EMPTY.
*******************************************************************************/

int AVLEmpty (PtAVLNode proot);
/*******************************************************************************
 Verifica se a arvore esta ou nao vazia. Valores de erro: OK.
 
 Verifies if the tree pointed by proot is empty or not. Returns 1 in affirmative
 case and 0 otherwise. Error code: OK.
*******************************************************************************/

int AVLElement (PtAVLNode pnode);
/*******************************************************************************
 Devolve o elemento armazenado em pnode. Valores de erro: OK ou NULL_PTR.
 
 Returns the element pointed by pnode. Error codes: OK or NULL_PTR.
*******************************************************************************/

unsigned int AVLSize (PtAVLNode proot);
/*******************************************************************************
 Calcula o numero de nos da arvore. Valores de erro: OK.
 
 Calculates the number of elements stores in the tree pointed by proot. Error code: OK.
*******************************************************************************/

unsigned int AVLHeight (PtAVLNode proot);
/*******************************************************************************
 Calcula a altura da arvore. Valores de erro: OK.
 
 Calculates the height of the tree pointed by proot. Error code: OK.
*******************************************************************************/

PtAVLNode AVLCreateFile (char *pnomef);
/*******************************************************************************
 Cria uma arvore a partir do ficheiro pnomef. Devolve a referência da arvore criada
 ou NULL, caso não consiga criar a arvore por falta de memória.
 
 Creates a tree from a text file. Returns a reference to the new tree or NULL if
 there isn't enough memory. Error codes: OK, NO_MEM or NO_FILE.
*******************************************************************************/

void AVLStoreFile (PtAVLNode proot, char *nomef);
/*******************************************************************************
 Armazena a arvore, caso ela exista, no ficheiro pnomef. O ficheiro tem na
 primeira linha o número de elementos da arvore, seguido dos elementos, um por
 linha. Valores de erro: OK, AVL_EMPTY ou NO_FILE.
 
 Stores the tree pointed by proot in text file pfname. The first line of the file
 constains the number of elements of the tree, followed by the emenets one per line.
 Error codes: OK, ABP_EMPTY or NO_FILE. 
*******************************************************************************/

void AVLPreOrder (PtAVLNode proot);
/*******************************************************************************
 Lista a arvore em pre-ordem. Valores de erro: OK.
 
 Lists the tree using a pre-order traversal. Error codes: OK or ABP_EMPTY.
*******************************************************************************/

void AVLInOrder (PtAVLNode proot);
/*******************************************************************************
 Lista a arvore em ordem (versão recursiva). Valores de erro: OK.
 
 Lists the tree using a in-order traversal. Error codes: OK or ABP_EMPTY.
*******************************************************************************/

void AVLPosOrder (PtAVLNode proot);
/*******************************************************************************
 Lista a arvore em pos-ordem. Valores de erro: OK.
 
 Lists the tree using a post-order traversal. Error codes: OK or ABP_EMPTY.
*******************************************************************************/

void AVLDisplay (PtAVLNode proot);
/*******************************************************************************
 Imprime no monitor os elementos da arvore de forma hierárquica.
 Valores de erro: OK ou AVL_EMPTY.
 
 Display hierarchically the tree pointed by proot. Error codes: OK or ABP_EMPTY.
*******************************************************************************/

#endif
