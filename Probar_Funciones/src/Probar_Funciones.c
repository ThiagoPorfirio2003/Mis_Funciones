/*
 ============================================================================
 Name        : Probar_Funciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//strcat(Reemplaza a partir del barra0);
//sprintf(No reemplaza, guarda aca);
//Si no hay un '\0' se escribe 2 veces y en la segunda se agrega al final el \0
//Todas las variables que intervengan en estas funciones deben poseer el \0 sino hay errores


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "findDato.h"
#include "memoriaDinamica.h"
#include "array.h"




int main(void) {
	setbuf(stdout,NULL);

	FILE* pArchivo;

	char textoPrueba[]="Tercera Prueba";
	char txt[]="Que onda";
	int cantidadLetras;
	int cantTxt;

	cantidadLetras= strlen(textoPrueba);
	cantTxt= strlen(txt);

	pArchivo= fopen("pruebaBinaria.dat","wb");

	if(pArchivo !=NULL)
	{
		printf("\nSe pudo abrir\n");
		if(fwrite(textoPrueba, sizeof(char), cantidadLetras,pArchivo) == cantidadLetras)
		{
			printf("\nSe pudo escribir\n");
		}
		if(fwrite(txt, sizeof(char), cantTxt,pArchivo) == cantTxt)
		{
			printf("\nSe pudo sobreescribir\n");
		}
		else
		{
			printf("Hubo un error en la escritura");
		}
		if(!fclose(pArchivo))
		{
			printf("Se pudo cerrar");
		}
	}


	return 0;
}



/*
/*
 * int Passenger_SwapPorApellidoDescendente(Passenger* primerPasajero, Passenger* segundoPasajero)
{
	int estadoComparacion;

	estadoComparacion=2;

	if(primerPasajero != NULL && segundoPasajero !=NULL)
	{
		estadoComparacion = strcmp(primerPasajero->lastName, segundoPasajero->lastName);
		if(estadoComparacion ==-1)
		{
			if(Passenger_SwapPassenger(primerPasajero, segundoPasajero))
			{
				estadoComparacion =2;
			}
		}
	}
	return estadoComparacion;
}

int Passenger_SwapPorNombreDescendente(Passenger* primerPasajero, Passenger* segundoPasajero)
{
	int estadoComparacion;

	estadoComparacion=2;

	if(primerPasajero != NULL && segundoPasajero !=NULL)
	{
		estadoComparacion = strcmp(primerPasajero->name, segundoPasajero->name);
		if(estadoComparacion ==-1)
		{
			if(Passenger_SwapPassenger(primerPasajero, segundoPasajero))
			{
				estadoComparacion =2;
			}
		}
	}
	return estadoComparacion;
}

int Passenger_SwapPassengerPorApellidoYNombre(Passenger* primerPasajero, Passenger* segundoPasajero, int (*pFuncionSwapeoApellido)(Passenger*, Passenger*), int (*pFuncionSwapeoNombre)(Passenger*, Passenger*))
{
	int retorno;
	int estadoSwapApellido;
	int estadoSwapNombre;

	retorno =2;

	if(primerPasajero != NULL && segundoPasajero != NULL && pFuncionSwapeoApellido != NULL && pFuncionSwapeoNombre != NULL)
	{
		estadoSwapApellido = pFuncionSwapeoApellido(primerPasajero, segundoPasajero);
		retorno=estadoSwapApellido;

		if(estadoSwapApellido !=2)
		{
			if(estadoSwapApellido == 0)
			{
				estadoSwapNombre = pFuncionSwapeoNombre(primerPasajero, segundoPasajero);
				retorno=estadoSwapNombre;
			}
		}
	}

	return retorno;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int retorno;
	int flagSwap;
	int estadoSwapAscendente;
	int limiteDecremental;
	int (*pFuncionSwapeoApellido) (Passenger*, Passenger*);
	int (*pFuncionSwapeoNombre) (Passenger*, Passenger*);


	retorno=1;

	if(list != NULL && len >0 && (order == 0 || order ==1))
	{
		limiteDecremental= len-1;
		retorno=0;

		if(order)
		{
			pFuncionSwapeoApellido = Passenger_SwapPorApellidoAscendente;
		    pFuncionSwapeoNombre = Passenger_SwapPorNombreAscendente;
		}
		else
		{
			pFuncionSwapeoApellido = Passenger_SwapPorApellidoDescendente;
		    pFuncionSwapeoNombre = Passenger_SwapPorNombreDescendente;
		}

		do{
			flagSwap=0;
			for(int i=0;i<limiteDecremental;i++)
			{
				estadoSwapAscendente = Passenger_SwapPassengerPorApellidoYNombre(&list[i], &list[i+1], pFuncionSwapeoApellido, pFuncionSwapeoNombre);
				if(estadoSwapAscendente != 2)
					{
						if(estadoSwapAscendente == 1)
						{
							flagSwap =1;
						}
					}
					else
					{
						retorno=1;
						break;
					}
			}
			if(retorno)
			{
				break;
			}

			limiteDecremental--;
		}while(flagSwap);
	}
	return retorno;
}

 *
 */

*/
