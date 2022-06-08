/*
 * memoriaDinamica.c
 *
 *  Created on: 2 jun. 2022
 *      Author: thiag
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int memoria_NewChar(char** punteroAPunteroCharEstatico)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroCharEstatico!=NULL)
	{
		*punteroAPunteroCharEstatico=NULL;
		*punteroAPunteroCharEstatico= (char*) malloc(sizeof(char));
		if(*punteroAPunteroCharEstatico!=NULL)
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_NewCharConTamanio(char** punteroAPunteroCharEstatico ,int longitud)
{
	int retorno;

	retorno=1;

	if(punteroAPunteroCharEstatico!=NULL && longitud>0)
	{
		*punteroAPunteroCharEstatico=NULL;
		*punteroAPunteroCharEstatico= (char*) malloc(sizeof(char) * longitud);
		if(*punteroAPunteroCharEstatico!=NULL)
		{
			retorno=0;
		}
	}
	return retorno;
}

int memoria_EliminarPosicionArrayInt(int* punteroInt, int longitudPunteroInt, int posicionAEliminar)
{
	int retorno;

	retorno=1;

	if(punteroInt != NULL && longitudPunteroInt > 0 && posicionAEliminar > -1)
	{

	}

	return retorno;
}

