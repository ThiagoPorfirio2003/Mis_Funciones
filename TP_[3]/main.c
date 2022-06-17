#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

#define MENU_OPCION_MINIMA 1
#define MENU_OPCION_MAXIMA 10

//Falta todo lo binario, guardar los pasajeros si no se cargo previamente y el que el contador empieze en el ultimo id

int main()
{
	setbuf(stdout, NULL);

	int option;
	int banderaOpcionUno;
	int banderaOpcionDos;
	int banderaOpcionTres;
	int banderaOpcionSiete;
//	int banderaOpcionOcho;
	int banderaOpcionNueve;
	int banderaOpcionDiez;

	LinkedList* listaPasajeros;
	banderaOpcionUno = 0;
	banderaOpcionDos = 0;
	banderaOpcionTres = 0;
	banderaOpcionSiete = 0;
//	banderaOpcionOcho = 0;
	banderaOpcionNueve = 0;
	banderaOpcionDiez = 0;

    listaPasajeros = ll_newLinkedList();
    int contadorId = 0;

    do{
		printf("---------------------Menu-----------------------\n"
				"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
				"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n"
				"3. Ingresar datos de un pasajero\n"
				"4. Modificar datos de un pasajero, se requiere su ID\n"
				"5. Eliminar un pasajero, se requiere su ID\n"
				"6. Informe sobre pasajeros:\n"
				"7. Ordenar pasajeros\n"
				"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
				"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
				"10. Salir\n\n");

		if(!utn_GetIntRango(&option, "Ingrese la opcion: ", "Dato invalido. Ingrese la opcion: ", MENU_OPCION_MINIMA, MENU_OPCION_MAXIMA, 1))
		{
			switch(option)
			{
				case 1:
					if(!banderaOpcionUno)
					{
						if(!controller_loadFromText("data.csv",listaPasajeros))
						{
							banderaOpcionUno=1;
						}
						else
						{
							printf("\n\nHa habido un error en la lectura del archivo\n\n");
						}
					}
					else
					{
						printf("\n\nNo se puede cargar el archivo si ya lo hiciste antes\n\n");
					}
					break;

				case 2:
					break;

				case 3:
					if(controller_addPassenger(listaPasajeros, &contadorId))
					{
						printf("\n\nHa habido un error en la carga del pasajero\n\n");
					}
					else
					{
						banderaOpcionTres=1;
					}

					break;

				case 4:
					if(banderaOpcionUno || banderaOpcionDos || banderaOpcionTres)
					{
						if(controller_editPassenger(listaPasajeros))
						{
							printf("\n\nHa ocurrido un error en la modificacion del pasajero\n\n");
						}
					}
					else
					{
						printf("\n\nNo se puede editar ningun pasajero, debido a que no hay ninguno cargado\n\n");
					}

					break;

				case 5:
					if(banderaOpcionUno || banderaOpcionDos || banderaOpcionTres)
					{
						switch(controller_removePassenger(listaPasajeros))
						{
							case -1:
								printf("\n\nHa ocurrido un error en la eliminacion del pasajero\n\n");
							break;

							case 0:
								printf("\n\nSe ha eliminado con exito al pasajero\n\n");
								break;

							case 1:
								printf("\n\nSe ha eliminado pasajero, pero no se han podidio eliminar sus rastros de la lista\n\n");
								break;

							case 2:
								printf("\n\nCancelaste la eliminacion del pasajero, o hubo un error de ultimo momento\n\n");
								break;
						}
					}
					else
					{
						printf("\n\nNo se puede eliminar ningun pasajero, debido a que no hay ninguno cargado\n\n");
					}
					break;

				case 6:
					if(banderaOpcionUno || banderaOpcionDos || banderaOpcionTres)
					{
						if(controller_ListPassenger(listaPasajeros))
						{
							printf("\n\nHa ocurrido un error en la lectura del pasajero siguiente al ultimo mostrado\n\n");
						}
					}
					else
					{
						printf("\n\nNo se pueden listar los pasajeros, debido a que no hay ninguno cargado\n\n");
					}

					break;

				case 7:
					banderaOpcionSiete=1;
					Passenger_OrdenarPorApellidoYNombreAscendente(listaPasajeros);
					break;

				case 8:
					if(banderaOpcionUno || banderaOpcionDos || banderaOpcionSiete)
					{
						if(controller_saveAsText("data.csv",listaPasajeros))
						{
							printf("\n\nHubo problemas en el guardado\n\n");
						}
						banderaOpcionDiez=1;
					}
					else
					{
						if(banderaOpcionTres)
						{
							if(controller_addAsText("data.csv", listaPasajeros))
							{
								printf("\n\nHubo problemas en el guardado\n\n");
							}
							banderaOpcionDiez=1;
						}
						else
						{
							printf("\n\nNo se pueden guardar los pasajeros, debido a que no hay ninguno cargado\n\n");
						}

					}


					break;

				case 9:
					break;

				case 10:
					if(banderaOpcionNueve || banderaOpcionDiez)
					{
						printf("\n\nSaliendo...\n\n");
					}
					else
					{
						printf("\n\nNO PUEDE salir del programa sin antes haber guardado algun archivo\n\n");
					}
					break;
			}
			printf("\n");
		}
    }while(option != 10);
    return 0;
}

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
