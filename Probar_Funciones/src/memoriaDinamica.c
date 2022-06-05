/*
 * memoriaDinamica.c
 *
 *  Created on: 2 jun. 2022
 *      Author: thiag
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int* memoria_NewInt()
{
	int* newInt;
	newInt = NULL;
	newInt= (int*) malloc(sizeof(int));

	return newInt;
}

float* memoria_NewFloat()
{
	float* newFloat;
	newFloat = NULL;

	newFloat= (float*) malloc(sizeof(float));

	return newFloat;
}

char* memoria_NewChar()
{
	char* newChar;
	newChar = NULL;

	newChar= (char*) malloc(sizeof(char));

	return newChar;
}

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

float* memoria_PrepararPunteroFloat(float longitudPunteroFloat)
{
	float* punteroFloat;

	punteroFloat=memoria_NewFloat();

	if(memoria_ReSizePunteroFloat(punteroFloat, longitudPunteroFloat))
	{
		punteroFloat = NULL;
	}

	return punteroFloat;
}

char* memoria_PrepararPunteroChar(char longitudPunteroChar)
{
	char* punteroChar;

	punteroChar=memoria_NewChar();

	if(memoria_ReSizePunteroChar(punteroChar, longitudPunteroChar))
	{
		punteroChar = NULL;
	}

	return punteroChar;
}