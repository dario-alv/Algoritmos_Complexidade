
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
 *** Ficheiro:  crono.c
 *** Autor:     Joaquim Madeira    
 *** Data:      14/03/2003
 *** Versao:    1.00
 ***
 *****************************************************************************
 ***
 *** Informacao: 
 ***
 ***   A implementação para as funcoes que permitem obter tempos...
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


#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>

#include "crono.h"


static struct tms antes, depois;

static int antesr,depoisr;


void ligar( void ){

	antesr = times(&antes);

}


void parar( void ){

	depoisr = times(&depois);

}


int itemporeal( void ){

	return (depoisr - antesr) / sysconf(_SC_CLK_TCK);

}


double tempocpu( void ){

	return (double) (depois.tms_utime - antes.tms_utime) / sysconf(_SC_CLK_TCK);

}


double temposys( void ){

	return (double) (depois.tms_stime - antes.tms_stime) / sysconf(_SC_CLK_TCK);

}

