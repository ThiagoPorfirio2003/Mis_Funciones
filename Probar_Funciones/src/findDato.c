/*
 * findDato.c
 *
 *  Created on: 1 jun. 2022
 *      Author: thiag
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

//INT
int find_GuardarMayorInt(int* direccionIntMayor, int intRecibido, int* direccionBanderaIntMaximo)
{
	int retorno;

	retorno=1;

	if(direccionIntMayor != NULL && direccionBanderaIntMaximo !=NULL)
	{
		retorno =0;
		if(*direccionBanderaIntMaximo || *direccionIntMayor<intRecibido)
		{
			*direccionIntMayor=intRecibido;
			*direccionBanderaIntMaximo=0;
		}
	}
	return retorno;
}

int find_GuardarMenorInt(int* direccionIntMenor, int intRecibido, int* direccionBanderaIntMenor)
{
	int retorno;
	retorno=1;

	if(direccionIntMenor != NULL && direccionBanderaIntMenor !=NULL)
	{
		retorno =0;
		if(*direccionBanderaIntMenor || *direccionIntMenor>intRecibido)
		{
			*direccionIntMenor=intRecibido;
			*direccionBanderaIntMenor=0;
		}
	}
	return retorno;
}

int find_BuscarMayorInt(int* direccionIntMayor, int* direccionBanderaIntMaximo, int cantidadNumeros, int* direccionPrimerInt)
{
	int retorno;
	int bufferIntMayor;
	retorno =1;

	if(direccionIntMayor != NULL && direccionBanderaIntMaximo != NULL && direccionPrimerInt !=NULL && cantidadNumeros > 0)
	{
		for(int i=0;i<cantidadNumeros;i++)
		{
			if(find_GuardarMayorInt(&bufferIntMayor, *(direccionPrimerInt+i), direccionBanderaIntMaximo))
			{
				break;
			}
		}
		retorno=0;
		*direccionIntMayor = bufferIntMayor;
	}
	return retorno;
}

int find_BuscarMenorInt(int* direccionIntMenor, int* direccionBanderaIntMenor, int cantidadNumeros, int* direccionPrimerInt)
{
	int retorno;
	int bufferIntMenor;
	retorno =1;

	if(direccionIntMenor != NULL && direccionBanderaIntMenor != NULL && direccionPrimerInt !=NULL && cantidadNumeros > 0)
	{
		for(int i=0;i<cantidadNumeros;i++)
		{
			if(find_GuardarMenorInt(&bufferIntMenor, *(direccionPrimerInt+i), direccionBanderaIntMenor))
			{
				break;
			}
		}
		retorno=0;
		*direccionIntMenor = bufferIntMenor;
	}
	return retorno;
}

//FLOAT
int find_GuardarMayorFloat(float* direccionFloatMayor, float numeroRecibido, int* direccionBanderaFloatMaximo)
{
	int retorno;

	retorno=1;

	if(direccionFloatMayor != NULL && direccionBanderaFloatMaximo !=NULL)
	{
		retorno =0;
		if(*direccionBanderaFloatMaximo || *direccionFloatMayor<numeroRecibido)
		{
			*direccionFloatMayor=numeroRecibido;
			*direccionBanderaFloatMaximo=0;
		}
	}
	return retorno;
}

int find_GuardarMenorFloat(float* direccionFloatMenor, float numeroRecibido, int* direccionBanderaFloatMenor)
{
	int retorno;

	retorno=1;

	if(direccionFloatMenor != NULL && direccionBanderaFloatMenor !=NULL)
	{
		retorno =0;
		if(*direccionBanderaFloatMenor || *direccionFloatMenor>numeroRecibido)
		{
			*direccionFloatMenor=numeroRecibido;
			*direccionBanderaFloatMenor=0;
		}
	}
	return retorno;
}

int find_BuscarMayorFloat(float* direccionFloatMayor, int* direccionFloatNumeroMaximo, int cantidadNumeros, float* direccionPrimerNumero)
{
	int retorno;
	float bufferFloatMayor;
	retorno =1;

	if(direccionFloatMayor != NULL && direccionFloatNumeroMaximo != NULL && direccionPrimerNumero !=NULL && cantidadNumeros > 0)
	{
		for(int i=0;i<cantidadNumeros;i++)
		{
			if(find_GuardarMayorFloat(&bufferFloatMayor, *(direccionPrimerNumero+i), direccionFloatNumeroMaximo))
			{
				break;
			}
		}
		retorno=0;
		*direccionFloatMayor = bufferFloatMayor;
	}
	return retorno;
}

int find_BuscarMenorFloat(float* direccionFloatMenor, int* direccionBanderaFloatMenor, int cantidadNumeros, float* direccionPrimerNumero)
{
	int retorno;
	float bufferFloatMenor;
	retorno =1;

	if(direccionFloatMenor != NULL && direccionBanderaFloatMenor != NULL && direccionPrimerNumero !=NULL && cantidadNumeros > 0)
	{
		for(int i=0;i<cantidadNumeros;i++)
		{
			if(find_GuardarMenorFloat(&bufferFloatMenor, *(direccionPrimerNumero+i), direccionBanderaFloatMenor))
			{
				break;
			}
		}
		retorno=0;
		*direccionFloatMenor = bufferFloatMenor;
	}
	return retorno;
}


int getMenorOMayorInt(int* numeroMayorMenor, int numeroRecibido, int* banderaMayorMenor, int (*funcionMayorMenor)(int*,int,int*))
{
	int retorno;

	retorno=1;

	if(numeroMayorMenor!=NULL && banderaMayorMenor!=NULL && *funcionMayorMenor != NULL)
	{
		if(!(funcionMayorMenor(numeroMayorMenor, numeroRecibido, banderaMayorMenor)))
		{
			retorno=0;
		}
	}
	return retorno;
}
/*
int findNumeroMedio(int* cadenaInt, int tamanioCadena,int opcionNumeroIgual)
{
	int retorno;

	retorno=1;

	if(cadenaInt !=NULL && tamanioCadena > 0)
	{
	//	= tamanioCadena/2;
	}

	return retorno;
}

int pedirYConseguirMayorNumero(int* numeroMayor, int cantidadDeNumeros, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno;
	int numeroAIngresar;
	int banderaNumeroMaximo;

	banderaNumeroMaximo=1;
	retorno=1;

	if(numeroMayor !=NULL && mensaje !=NULL && mensajeError !=NULL && cantidadDeNumeros >0)
	{
		for(int i;i<cantidadDeNumeros;i++)
		{
			if(!(utn_getIntRango(&numeroAIngresar, mensaje, mensajeError, minimo, maximo)))
			{
				if(recibirYConseguirMayorNumero(&numeroMayor, numeroAIngresar, &banderaNumeroMaximo))
				{
					break;
				} //
			}
		}
		retorno =0;
	}
	return retorno;
}
*/
