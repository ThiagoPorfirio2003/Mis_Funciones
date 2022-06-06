/*
 * array.c
 *
 *  Created on: 5 jun. 2022
 *      Author: thiag
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int array_SwapCambiarPosicionInt(int* punteroPrimerInt, int* punteroSegundoInt)
{
	int retorno;
	int auxiliar;

	retorno=1;

	if(punteroPrimerInt != NULL && punteroSegundoInt !=NULL)
	{
		auxiliar = *(punteroPrimerInt);
		*(punteroPrimerInt)= *(punteroSegundoInt);
		*punteroSegundoInt=auxiliar;
		retorno=0;
	}

	return retorno;
}

int array_MoverAdelanteUnInt(int* punteroInt)
{
	int retorno;

	retorno=1;

	if(punteroInt != NULL)
	{
		*(punteroInt+1) = *punteroInt;
		retorno=0;
	}

	return retorno;
}

int array_MoverAtrasUnInt(int* punteroInt)
{
	int retorno;

	retorno=1;

	if(punteroInt !=NULL)
	{
		*(punteroInt-1) = *punteroInt;
		retorno=0;
	}

	return retorno;
}
