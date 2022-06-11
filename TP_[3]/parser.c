#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"

#define PRECIO_MINIMO 10000

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	char idCaracter[15];
	char nombre[50];
	char apellido[50];
	char precioCaracter[50];
	char tipoPasajeroCaracter[30];
	char codigoVuelo[8];
	char statusFlightCaracter[30];

	Passenger* nuevoPasajero;

	retorno=1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idCaracter, nombre, apellido, precioCaracter, codigoVuelo, tipoPasajeroCaracter, statusFlightCaracter);
		while(7 == fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idCaracter, nombre, apellido, precioCaracter, codigoVuelo, tipoPasajeroCaracter, statusFlightCaracter))
		{
			if((nuevoPasajero = Passenger_newParametros(idCaracter, nombre, apellido, precioCaracter, tipoPasajeroCaracter, codigoVuelo, statusFlightCaracter)) != NULL &&
					!ll_add(pArrayListPassenger, nuevoPasajero))
			{
				Passenger_MostrarUnPasajero(nuevoPasajero);
			}
			else
			{
				break;
			}

			if(feof(pFile))
			{
				retorno=0;
				break;
			}
		}
	}
	printf("\n\nCANTIDAD LIKEND %d\n\n",ll_len(pArrayListPassenger));
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
