/*
 * memoriaDinamica.c
 *
 *  Created on: 2 jun. 2022
 *      Author: thiag
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int* memoria_NewInt(int* punteroEstaticoInt)
{
	int retorno;

	retorno=1;
	punteroEstaticoInt= (int*) malloc(sizeof(int));

	if(punteroEstaticoInt != NULL)
	{
		retorno=0;
	}

	return retorno;
}

float* memoria_NewFloat(float* punteroEstaticoFloat)
{
	int retorno;

	retorno=1;
	punteroEstaticoFloat= (float*) malloc(sizeof(float));

	if(punteroEstaticoFloat != NULL)
	{
		retorno=0;
	}

	return retorno;
}

char* memoria_NewChar()
{
	char* punteroChar;

	punteroChar= (char*) malloc(sizeof(char));

	return punteroChar;
}

char* memoria_NewCharConTamanio(int longitud)
{
	char* punteroDinamicoChar;

	punteroDinamicoChar= (char*) malloc(sizeof(char)* longitud);

	return punteroDinamicoChar;
}

/*
int memoria_ReSizePunteroInt(int* punteroIntADimensionar, int nuevaLongitud)
{
	int retorno;
	int* bufferInt;

	bufferInt = NULL;
	retorno =1;

	if(punteroIntADimensionar !=NULL && nuevaLongitud > 0)
	{
		bufferInt= (int*) realloc(punteroIntADimensionar, sizeof(int)* nuevaLongitud);
		if(bufferInt != NULL)
		{
			punteroIntADimensionar = bufferInt;
			retorno =0;
		}
	}
	return retorno;
}

int memoria_ReSizePunteroFloat(float* punteroFloatADimensionar, int nuevaLongitud)
{
	int retorno;
	float* bufferFloat;

	bufferFloat = NULL;
	retorno =1;

	if(punteroFloatADimensionar !=NULL && nuevaLongitud > 0)
	{
		bufferFloat= (float*) realloc(punteroFloatADimensionar, sizeof(float)* nuevaLongitud);
		if(bufferFloat != NULL)
		{
			punteroFloatADimensionar = bufferFloat;
			retorno =0;
		}
	}
	return retorno;
}

int memoria_ReSizePunteroChar(char* punteroCharADimensionar, int nuevaLongitud)
{
	int retorno;
	char* bufferChar;

	bufferChar = NULL;
	bufferChar = memoria_NewChar();

	retorno =1;

	if(punteroCharADimensionar !=NULL && nuevaLongitud > 0)
	{
		bufferChar= (char*) realloc(punteroCharADimensionar, sizeof(char)* nuevaLongitud);
		if(bufferChar != NULL)
		{
			punteroCharADimensionar = bufferChar;
			retorno =0;
		}
	}
	return retorno;
}

int memoria_nose(char* punteroDinamico, int longitud)
{
	int retorno;

	retorno=1;

	if(longitud>0)
	{
		punteroDinamico=(char*) malloc(sizeof(char)*longitud);
		if(punteroDinamico!=NULL)
		{
			retorno=0;
		}
	}
	printf("Antes de crear DINAMICO\n");
	punteroDinamico=(char*) malloc(sizeof(char)*longitud);
	printf("DESPUES de crear DINAMICO\n");

	if(punteroDinamico !=NULL && longitud>0 && !memoria_ReSizePunteroChar(punteroDinamico, longitud))
	{
		retorno=0;
	}


	return retorno;
}


/*
int* memoria_PrepararPunteroInt(int longitudPunteroInt)
{
	int* punteroInt;

	punteroInt=memoria_NewInt();

	if(memoria_ReSizePunteroInt(punteroInt, longitudPunteroInt))
	{
		punteroInt = NULL;
	}

	return punteroInt;
}

float* memoria_PrepararPunteroFloat(int longitudPunteroFloat)
{
	float* punteroFloat;

	punteroFloat=memoria_NewFloat();

	if(memoria_ReSizePunteroFloat(punteroFloat, longitudPunteroFloat))
	{
		punteroFloat = NULL;
	}

	return punteroFloat;
}

char* memoria_PrepararPunteroChar(int* punteroADimensionar, int longitudPunteroChar)
{
	/*
	char* punteroChar;

	printf("Antes de crear DINAMICO\n");
	punteroChar=memoria_NewChar();
	printf("DESPUES de crear DINAMICO\n");

	if(memoria_ReSizePunteroChar(punteroADimensionar, longitudPunteroChar))
	{
		punteroADimensionar = NULL;
	}

	return punteroADimensionar;
}
*/



int memoria_EliminarPosicionArrayInt(int* punteroInt, int longitudPunteroInt, int posicionAEliminar)
{
	int retorno;

	retorno=1;

	if(punteroInt != NULL && longitudPunteroInt > 0 && posicionAEliminar > -1)
	{

	}

	return retorno;
}
