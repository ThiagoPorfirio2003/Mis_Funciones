#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Controller.h"
#include "Passenger.h"
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

Passenger* Passenger_new()
{
	Passenger* nuevoPasajero;

	nuevoPasajero = NULL;
	nuevoPasajero = (Passenger*) malloc(sizeof(Passenger));
	if(nuevoPasajero != NULL)
	{
		Passenger_setId(nuevoPasajero, 0);
		Passenger_setNombre(nuevoPasajero,"");
		Passenger_setApellido(nuevoPasajero,"");
		Passenger_setCodigoVuelo(nuevoPasajero,"");
		Passenger_setTipoPasajero(nuevoPasajero,0);
		Passenger_setPrecio(nuevoPasajero,0);
		Passenger_setEstadoVuelo(nuevoPasajero,0);
	}
	return nuevoPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* statusFlight)
{
	Passenger* nuevoPasajero;
	int statusFlightNumero;
	int tipoPasajeroNumero;
	int idNumero;
	float precioNumero;
	int retorno;

	nuevoPasajero = Passenger_new();

	if(nuevoPasajero != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL &&
			tipoPasajeroStr != NULL && codigoVueloStr != NULL && statusFlight != NULL &&
			!utn_verificarSerInt(idStr) && (idNumero = atoi(idStr)) >0 &&
			!utn_verificarSerNombre(nombreStr) && !utn_verificarSerNombre(apellidoStr) &&
			!utn_verificarSerFloat(precioStr) && (precioNumero = atof(precioStr)) >= VUELO_PRECIO_MINIMO &&
			!Passenger_verificarSerCodigoDeVuelo(codigoVueloStr))
	{
		retorno=0;
		if(!strcmp(statusFlight, "Aterrizado"))
		{
			statusFlightNumero=1;
		}
		else
		{
			if(!strcmp(statusFlight, "En Horario"))
			{
				statusFlightNumero=2;
			}
			else
			{
				if(!strcmp(statusFlight, "Demorado"))
				{
					statusFlightNumero=3;
				}
				else
				{
					if(!strcmp(statusFlight, "En Vuelo"))
					{
						statusFlightNumero=4;
					}
					else
					{
						retorno=1;
					}

				}
			}
		}

		if(!strcmp(tipoPasajeroStr, "FirstClass"))
		{
			tipoPasajeroNumero=1;
		}
		else
		{
			if(!strcmp(tipoPasajeroStr, "ExecutiveClass"))
			{
				tipoPasajeroNumero=2;
			}
			else
			{
				if(!strcmp(tipoPasajeroStr, "EconomyClass"))
				{
					tipoPasajeroNumero=3;
				}
				else
				{
					retorno=1;
				}
			}
		}

	}
	if(!retorno)
	{
		Passenger_setId(nuevoPasajero, idNumero);
		Passenger_setNombre(nuevoPasajero, nombreStr);
		Passenger_setApellido(nuevoPasajero, apellidoStr);
		Passenger_setCodigoVuelo(nuevoPasajero, codigoVueloStr);
		Passenger_setTipoPasajero(nuevoPasajero, tipoPasajeroNumero);
		Passenger_setPrecio(nuevoPasajero, precioNumero);
		Passenger_setEstadoVuelo(nuevoPasajero, statusFlightNumero);
	}
	else
	{
		free(nuevoPasajero);
	}

	return nuevoPasajero;
}


int Passenger_setId(Passenger* this,int id)
{
	int retorno;

	retorno=1;

	if(this != NULL)
	{
		this->id = id;
		retorno=0;
	}

	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno;

	retorno=1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno=0;
	}

	return retorno;
}


int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno=1;

	if(this != NULL && nombre != NULL /*&& !utn_verificarSerNombre(nombre)*/)
	{
		strcpy(this->nombre, nombre);
//		printf("\nnomnre : %s\n", nombre);
	//	printf("nombre Flecha : %s\n\n", this->nombre);
		retorno=0;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno=1;

	if(this != NULL && nombre != NULL /*&& !utn_verificarSerNombre(nombre)*/)
	{
		strcpy(nombre, this->nombre);
	//	printf("\n\nomnre get: %s\n", nombre);
		//printf("nombre Flecha get: %s\n\n", this->nombre);
		retorno=0;
	}

	return retorno;
}


int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno=1;

	if(this != NULL && apellido != NULL /*&& !utn_verificarSerNombre(apellido)*/)
	{
		strcpy(this->apellido, apellido);
	//	printf("\n\nAPELLIDO: %s\n", apellido);
		//printf("APELLIDO Flecha: %s\n\n", this->apellido);
		retorno=0;
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno=1;

	if(this != NULL && apellido != NULL /* && !utn_verificarSerNombre(apellido)*/)
	{
		strcpy(apellido, this->apellido);
	//	printf("\n\nAPELLIDO GET: %s\n", apellido);
		//printf("APELLIDO Flecha GET: %s\n\n", this->apellido);
		retorno=0;
	}

	return retorno;
}


int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno=1;

	if(this != NULL && codigoVuelo != NULL /*&& !controller_verificarSerCodigoDeVuelo(codigoVuelo)*/)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno=0;
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno=1;

	if(this != NULL && codigoVuelo != NULL /*&& !controller_verificarSerCodigoDeVuelo(codigoVuelo)*/)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno=0;
	}

	return retorno;
}


int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno;

	retorno=1;

	if(this != NULL /* && (tipoPasajero>1 || tipoPasajero<3)*/)
	{
		this->tipoPasajero = tipoPasajero;
		retorno=0;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno;

	retorno=1;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno=0;
	}

	return retorno;
}


int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno;

	retorno=1;

	if(this != NULL /*&& precio>0*/)
	{
		this->precio = precio;
		retorno=0;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno;

	retorno=1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno=0;
	}

	return retorno;
}


int Passenger_setEstadoVuelo(Passenger* this,int estadoDeVuelo)
{
	int retorno;

	retorno=1;

	if(this != NULL /*&& (estadoDeVuelo>1 || estadoDeVuelo<3)*/)
	{
		this->statusFlight = estadoDeVuelo;
		retorno=0;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,int* estadoDeVuelo)
{
	int retorno;

	retorno=1;

	if(this != NULL && estadoDeVuelo != NULL /*&& (estadoDeVuelo>1 || estadoDeVuelo<3)*/)
	{
		*estadoDeVuelo = this->statusFlight;
		retorno=0;
	}

	return retorno;
}


int Passenger_loadOnePassengerData(int* id,char* nombre, char* apellido, float* precio, int* tipoPasajero, char* codigoVuelo, int* statusFlight)
{
	int retorno;

	retorno=1;

	if(id!=NULL && nombre != NULL && apellido != NULL && precio != NULL && tipoPasajero != NULL && codigoVuelo != NULL && statusFlight != NULL &&
			!utn_GetNombreRango(nombre, "\nIngrese el nombre del pasajero: ", "Dato invalido. Ingrese el NOMBRE del pasajero: ", "\nHubo un error debido a faltante de memoria", 2, CANTIDAD_MAXIMA_CARACTERES_NOMBRE, CANTIDAD_CARACTERES_NOMBRE) &&
			!utn_GetNombreRango(apellido, "\nIngrese el apellido del pasajero: ", "Dato invalido. Ingrese el APELLIDO del pasajero: ", "\nHubo un error debido a faltante de memoria", 2, CANTIDAD_MAXIMA_CARACTERES_APELLIDO, CANTIDAD_CARACTERES_APELLIDO) &&
			!utn_GetFloatRango(precio, "\nIngresa el precio del vuelo, debe estar entre $10000 y $100000000: ", "El dato ingresado es invalido. Ingresa el precio del vuelo, debe estar entre $10000 y $100000000:", VUELO_PRECIO_MINIMO, VUELO_PRECIO_MAXIMO, CANTIDAD_CIFRAS_PRECIO) &&
			!utn_GetIntRango(tipoPasajero, "\nTipo de pasajero:\n 1. FirstClass  \n 2. ExecutiveClass\n 3. EconomyClass\nIngrese el numero correspondiente al tipo: ", "Dato invalido. Ingrese el numero correspondiente al tipo: ", TIPO_PASAJERO_OPCION_MINIMA, TIPO_PASAJERO_OPCION_MAXIMA, 5) &&
			!utn_GetIntRango(statusFlight, "\nEstado de vuelo:\n 1. Aterrizado\n 2. En horario\n 3. Demorado\n 4. En vuelo \nIngrese el numero que corresponda: ", "Dato ingresado invalido. Ingrese el numero que corresponda: ", TIPO_VUELO_OPCION_MINIMA, TIPO_VUELO_OPCION_MAXIMA, 5) &&
			!utn_GetCadenaAlfanumericaRango(codigoVuelo, "Teniendo como modelo \"AA1234A\", ingrese el codigo de vuelo: ", "Dato invalido. Teniendo como modelo \"AA1234A\", ingrese el codigo de vuelo: ", "\nNo se puede realizar la operacion debido a que ya no hay memoria\n", CANTIDAD_MINIMA_CARACTERES_CODIGOVUELO, CANTIDAD_MAXIMA_CARACTERES_CODIGOVUELO, 9))
	{
		retorno=0;
	}
	return retorno;
}

int Passenger_verificarSerCodigoDeVuelo(char* cadenaAlfanumerica)
{
	int retorno;
	int contadorLetras;
	int contadorNumeros;

	retorno =1;
	contadorLetras=0;
	contadorNumeros=0;

	if(cadenaAlfanumerica != NULL)
	{
		retorno=0;
		for(int i=0; i<7;i++)
		{
			if(isalpha(*(cadenaAlfanumerica+i)))
			{
				if((contadorNumeros == 0 && contadorLetras <2) || (contadorNumeros ==4 && contadorLetras ==2))
				{
					contadorLetras++;
				}
				else
				{
					retorno=1;
					break;
				}
			}
			else
			{
				if(isdigit(*(cadenaAlfanumerica+i)))
				{
					if(contadorNumeros<4 && contadorLetras == 2)
					{
						contadorNumeros++;
					}
					else
					{
						retorno=1;
						break;
					}
				}
				else
				{
					retorno=1;
					break;
				}
			}
		}
	}
	return retorno;
}

int Passenger_MostrarUnPasajero(Passenger* pPasajeroAMostrar)
{
	int retorno;
	int id;
	char nombre[CANTIDAD_CARACTERES_NOMBRE];
	char apellido[CANTIDAD_CARACTERES_APELLIDO];
	float precio;
	char codigoVuelo[CARACTERES_CODIGOVUELO];
	int tipoPasajeroNumero;
	int estadoDeVueloNumero;
	char tipoPasajero[CARACTERES_TIPO_PASAJERO_PALABRA];
	char estadoDeVueloPalabra[CARACTERES_ESTADO_VUELO_PALABRA];

	retorno=1;

	if(pPasajeroAMostrar != NULL &&
			!Passenger_getId(pPasajeroAMostrar, &id) &&
			!Passenger_getNombre(pPasajeroAMostrar, nombre) &&
			!Passenger_getApellido(pPasajeroAMostrar, apellido) &&
			!Passenger_getCodigoVuelo(pPasajeroAMostrar, codigoVuelo) &&
			!Passenger_getTipoPasajero(pPasajeroAMostrar, &tipoPasajeroNumero)&&
			!Passenger_getPrecio(pPasajeroAMostrar, &precio)  &&
			!Passenger_getEstadoVuelo(pPasajeroAMostrar, &estadoDeVueloNumero))
	{
		switch(estadoDeVueloNumero)
		{
			case 1:
				strcpy(estadoDeVueloPalabra, "Aterrizado");
				break;

			case 2:
				strcpy(estadoDeVueloPalabra, "En horario");
				break;

			case 3:
				strcpy(estadoDeVueloPalabra, "Demorado");
				break;

			case 4:
				strcpy(estadoDeVueloPalabra, "En vuelo");
				break;
		}

		switch(tipoPasajeroNumero)
		{
			case 1:
				strcpy(tipoPasajero, "First Class");
				break;

			case 2:
				strcpy(tipoPasajero, "Executive Class");
				break;

			case 3:
				strcpy(tipoPasajero, "EconomyClass");
				break;
		}
		printf("|%*d|%*s|%*s|$%*.2f|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, id, -CANTIDAD_CARACTERES_NOMBRE, nombre, -CANTIDAD_CARACTERES_APELLIDO, apellido, -CANTIDAD_CIFRAS_PRECIO, precio, -CARACTERES_MARCO_CODIGOVUELO, codigoVuelo, -CARACTERES_TIPO_PASAJERO_PALABRA, tipoPasajero, -CARACTERES_ESTADO_VUELO_PALABRA, estadoDeVueloPalabra);
		retorno=0;
	}
    return retorno;
}
