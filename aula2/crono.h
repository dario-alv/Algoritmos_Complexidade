
/*****************************************************************************
 ***
 *** Algoritmos
 ***
 *** Ano lectivo 2002/2003 --- 2o. Semestre
 ***
 *** Departamento de Electronica e Telecomunicacoes - Universidade de Aveiro
 ***
 *****************************************************************************
 ***
 *** Ficheiro:  crono.h
 *** Autor:     Joaquim Madeira    
 *** Data:      14/03/2003
 *** Versao:    1.00
 ***
 *****************************************************************************
 ***
 *** Informacao: 
 ***
 ***   O ficheiro para as funcoes que permitem obter tempos...
 ***
 ***   Versão algo ingénua e baseada num exemplo antigo.
 ***
 *****************************************************************************
 ***
 *** Alteracoes:   0.00   14/03/2003   Autor
 ***
 ***   Sem alteracoes.
 ***
 *****************************************************************************/


#ifndef _CRONO_H
#define _CRONO_H


/* Para iniciar a contagem de tempo */

void ligar( void );


/* Para terminar a contagem de tempo */

void parar( void );


int itemporeal( void );


/* Para obter o tempo de execução */

double tempocpu( void );


double temposys( void );


#endif 




