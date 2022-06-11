#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"

#define CANTIDAD_MAXIMA_CARACTERES_NOMBRE 50
#define CANTIDAD_MAXIMA_CARACTERES_APELLIDO 50
#define CANTIDAD_CARACTERES_NOMBRE 50
#define CANTIDAD_CARACTERES_APELLIDO 50
#define VUELO_PRECIO_MINIMO 10000
#define VUELO_PRECIO_MAXIMO 100000000
#define CANTIDAD_CIFRAS_PRECIO 20
#define TIPO_PASAJERO_OPCION_MINIMA 1
#define TIPO_PASAJERO_OPCION_MAXIMA 4
#define TIPO_VUELO_OPCION_MINIMA 1
#define TIPO_VUELO_OPCION_MAXIMA 4
#define CANTIDAD_MAXIMA_CIFRAS_ID 10
#define CANTIDAD_MINIMA_CARACTERES_CODIGOVUELO 7
#define CANTIDAD_MAXIMA_CARACTERES_CODIGOVUELO 7
#define CARACTERES_TOTALES_CODIGOVUELO 9
#define CARACTERES_MARCO_CODIGOVUELO 10
#define CARACTERES_CODIGOVUELO 8
#define CARACTERES_TIPO_PASAJERO_PALABRA 20
#define CARACTERES_ESTADO_VUELO_PALABRA 20
#define MINIMA_OPCION_MODIFICAR_PASAJERO 1
#define MAXIMA_OPCION_MODIFICAR_PASAJERO 5




/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pArchivo;

	retorno =1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo=fopen(path,"r");
		if(!parser_PassengerFromText(pArchivo, pArrayListPassenger))
		{
			retorno=0;
		}
		else
		{
			retorno=1;
		}
		while(!fclose(pArchivo))
		{

		}
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{

	if(path != NULL )
	{

	}
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int *contadorId)
{
	Passenger* nuevoPasajero;

	int retorno;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	int statusFlight;

	retorno=1;

	if(pArrayListPassenger != NULL && contadorId != NULL)
	{

		if(!Passenger_loadOnePassengerData(contadorId, nombre, apellido, &precio, &tipoPasajero, codigoVuelo, &statusFlight))
		{
			(*contadorId)++;
			utn_trasnformarCadenaAMayuscula(codigoVuelo);
			nuevoPasajero = Passenger_newParametros(contadorId, nombre, apellido, &precio, &tipoPasajero, codigoVuelo, &statusFlight);
			if(!ll_add(pArrayListPassenger, nuevoPasajero))
			{
				retorno=0;
			}
		}

	}

    return retorno;
}

int controller_findPassengerById(int idAEncontrar, int cantidadPasajeros, LinkedList* pArrayListPassenger)
{
	int retorno;
	int idAuxiliar;

	Passenger* pasajeroBusqueda;

	retorno=-1;

	for(int i=0;i<cantidadPasajeros;i++)
	{
		if((pasajeroBusqueda = (Passenger*) ll_get(pArrayListPassenger, i)) != NULL && !Passenger_getId(pasajeroBusqueda ,&idAuxiliar) &&
				idAuxiliar == idAEncontrar)
		{
			retorno=i;
			break;
		}
	}

	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pasajeroAMoidificar;

	int retorno;
	int id;
	int cantidadPasajeros;
	int posicionPasajero;

	int opcionModificacion;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];

	retorno=1;

	if(pArrayListPassenger != NULL && !utn_GetIntRango(&id, "\nIngrese el id del pasajero cuyos datos desea modificar: ", "Dato invalido. Ingrese el id del pasajero cuyos datos desea modificar: ", 0, 2000, 30) &&
			(cantidadPasajeros= ll_len(pArrayListPassenger)) != -1 && (posicionPasajero=controller_findPassengerById(id, cantidadPasajeros, pArrayListPassenger)) != -1)
	{

		if((pasajeroAMoidificar = (Passenger*) ll_get(pArrayListPassenger, posicionPasajero)) != NULL)
		{
			printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
			printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			Passenger_MostrarUnPasajero(pasajeroAMoidificar);
			printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			if(!utn_GetIntRango(&opcionModificacion, "\nCaracteristicas a modificar:\n 1- Nombre\n 2- Apellido\n 3- Precio\n 4- Tipo de Pasajero \n 5- Codigo de vuelo\nIngrese el numero del aspecto a modificar:  ", "Ingrese el numero del aspecto a modificar: ", MINIMA_OPCION_MODIFICAR_PASAJERO, MAXIMA_OPCION_MODIFICAR_PASAJERO, 3))
			{
				switch(opcionModificacion)
				{
					case 1:
						utn_GetNombreRango(nombre, "\nIngrese el nuevo nombre del pasajero: ", "Dato invalido. Ingrese el nuevo NOMBRE del pasajero: ", "\nHubo un error debido a faltante de memoria", 2, CANTIDAD_MAXIMA_CARACTERES_NOMBRE, CANTIDAD_CARACTERES_NOMBRE);
						Passenger_setNombre(pasajeroAMoidificar, nombre);
						break;

					case 2:
						utn_GetNombreRango(apellido, "\nIngrese el nuevo apellido del pasajero: ", "Dato invalido. Ingrese el nuevo APELLIDO del pasajero: ", "\nHubo un error debido a faltante de memoria", 2, CANTIDAD_MAXIMA_CARACTERES_NOMBRE, CANTIDAD_CARACTERES_NOMBRE);
						Passenger_setApellido(pasajeroAMoidificar, apellido);
						break;

					case 3:
						utn_GetFloatRango(&precio, "\nIngresa el nuevo precio del vuelo, debe estar entre $10000 y $100000000: ", "El dato ingresado es invalido. Ingresa el nuevo precio del vuelo, debe estar entre $10000 y $100000000:", VUELO_PRECIO_MINIMO, VUELO_PRECIO_MAXIMO, CANTIDAD_CIFRAS_PRECIO);
						Passenger_setPrecio(pasajeroAMoidificar, precio);
						break;

					case 4:
						utn_GetIntRango(&tipoPasajero, "\nTipo de pasajero:\n 1. FirstClass  \n 2. ExecutiveClass\n 3. EconomyClass\nIngrese el numero correspondiente al tipo: ", "Dato invalido. Ingrese el numero correspondiente al tipo: ", TIPO_PASAJERO_OPCION_MINIMA, TIPO_PASAJERO_OPCION_MAXIMA, 5);
						Passenger_setTipoPasajero(pasajeroAMoidificar, tipoPasajero);
						break;

					case 5:
						while(utn_GetCadenaAlfanumericaRango(codigoVuelo, "Teniendo como modelo \"AA1234A\", ingrese el codigo de vuelo: ", "Dato invalido. Teniendo como modelo \"AA1234A\", ingrese el codigo de vuelo: ", "\nNo se puede realizar la operacion debido a que ya no hay memoria\n", CANTIDAD_MINIMA_CARACTERES_CODIGOVUELO, CANTIDAD_MAXIMA_CARACTERES_CODIGOVUELO, 9) ||
						Passenger_verificarSerCodigoDeVuelo(codigoVuelo))
						{
							printf("\nCodigo de vuelo incorrecto\n");
						}
						utn_trasnformarCadenaAMayuscula(codigoVuelo);
						Passenger_setCodigoVuelo(pasajeroAMoidificar, codigoVuelo);
						break;
				}
				retorno=0;
			}
		}
	}

    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger, char* mensajeDeError)
{
	int retorno;
	int cantidadPasajeros;
	Passenger* pPasajeroAMostrar;

	retorno=1;

	if(pArrayListPassenger != NULL && mensajeDeError != NULL)
	{
		retorno=0;
		cantidadPasajeros = ll_len(pArrayListPassenger);
		if(cantidadPasajeros != -1)
		{
			printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
			printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			for(int i=0;i<cantidadPasajeros;i++)
			{
				pPasajeroAMostrar = (Passenger*) ll_get(pArrayListPassenger, i);
				if(pPasajeroAMostrar == NULL || Passenger_MostrarUnPasajero(pPasajeroAMostrar))
				{
					retorno=1;
					printf(mensajeDeError);
					break;
				}
			}
			printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		}
	}

    return retorno;
}


/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}
/*
int Passenger_saveAsText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	int cantidadPasajerosAGuardar;
	int idAGuardar;
	char* nombreAGuardar;
	char* apellidoAGuardar;


	Passenger* pPasajeroAGuardar;

	retorno=1;

	if(pFile != NULL && pArrayListPassengerNULL)
	{
		if((cantidadPasajerosAGuardar = ll_len(pArrayListPassenger)) != NULL)
		{
			for(int i=0; i<cantidadPasajerosAGuardar;i++)
			{
				if((pPasajeroAGuardar= Passenger_new()) != NULL && (pPasajeroAGuardar=(Passenger*) ll_get(pArrayListPassenger, i)) != NULL)
				{

				}
			}
		}

	}

	return retorno;
}
*/

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pArchivo;

	retorno =1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo=fopen(path,"w");
		if(!parser_PassengerFromText(pArchivo, pArrayListPassenger))
		{
			retorno=0;
		}
		else
		{
			retorno=1;
		}
		while(!fclose(pArchivo))
		{

		}
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

