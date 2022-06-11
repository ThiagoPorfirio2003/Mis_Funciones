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
#define MENU_OPCION_MAXIMA 7

int main()
{
	setbuf(stdout, NULL);

	LinkedList* listaPasajeros = ll_newLinkedList();
    int option;
    int contadorId = 0;

    do{
		printf("---------------------Menu-----------------------\n"
				"3. Ingresar datos de un pasajero\n"
				"4. Modificar datos de un pasajero, se requiere su ID\n"
				"5. Eliminar un pasajero, se requiere su ID\n"
				"6. Informe sobre pasajeros:\n"
				"7. Ordenar pasajeros\n\n");

		if(!utn_GetIntRango(&option, "Ingrese la opcion: ", "Dato invalido. Ingrese la opcion", MENU_OPCION_MINIMA, MENU_OPCION_MAXIMA, 1))
		{
			switch(option)
			{
				case 1:
					if(controller_loadFromText("data.csv",listaPasajeros))
					{
						printf("Ha habido un error en la lectura");
					}

					break;

				case 2:
					break;

				case 3:
					controller_addPassenger(listaPasajeros, &contadorId);
					break;

				case 4:
					controller_editPassenger(listaPasajeros);
					break;

				case 5:
					break;

				case 6:
					controller_ListPassenger(listaPasajeros, "\nHa ocurrido un error en la lectura de los pasajeros\n");
					break;

				case 7:
					break;

				case 8:
					break;

				case 9:
					break;

				case 10:
					break;
			}
		}

    }while(option != 10);
    return 0;
}

