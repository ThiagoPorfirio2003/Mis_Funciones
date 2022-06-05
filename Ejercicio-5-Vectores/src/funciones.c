/*
 * funciones.c
 *
 *  Created on: 21 abr. 2022
 *      Author: thiag
 */

#include <stdio.h>
#include <stdlib.h>


int inicializarIntFuncion(int array[], int valorInicializador, int tamanio)
{
	int retorno;
	int i;

	retorno = 0;

	if(array != NULL && tamanio > 2)
	{
		for(i=0; i<tamanio; i++)
		{
			array[i] = valorInicializador;
		}
	}
	else
	{
		retorno = 1;
	}

	return retorno;
}

void cargaConsecutivaArray(int array[], int tamanio)
{
	int i;

	for(i=0;i<tamanio;i++)
	{
		printf("\nIntrodusca el valor de la posicion %d",i);
		scanf("%d", &array[i]);
	}
}

