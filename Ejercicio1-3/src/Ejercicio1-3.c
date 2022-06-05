/*
 ============================================================================
 Name        : Ejercicio1-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 1-3: ingresar 3 números y mostrar el número del medio, sólo si existe. En caso de que no
exista también informarlo.
Ejemplo:
1 5 3 el 3 es del medio
5 1 5 no hay numero del medio
3 5 1 el 3 es del medio
3 1 5 el 3 es del medio
5 3 1 el 3 es del medio

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int i;
	int numero[2];
	int numeroMedio;

	for(i=0;i<3;i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d",&numero[i]);
	}

	if(numero[0] == numero[1] || numero[0] == numero[2] || numero[2] == numero [1])
	{
		printf("\nNo hay un numerio del medio");
	}
	else
	{
		if(numero[0] > numero [1] && numero[0] < numero[2])
		{
			numeroMedio= numero[0];
		}
		else
		{
			if(numero[0] > numero [2] && numero[0] < numero[1])
			{
				numeroMedio= numero[0];
			}
		}

		if(numero[1] > numero [0] && numero[1] < numero[2])
		{
			numeroMedio= numero[1];
		}
		else
		{

			if(numero[1] > numero [2] && numero[1] < numero[0])
			{
				numeroMedio= numero[1];
			}
		}

		if(numero[2] > numero [0] && numero[2] < numero[1])
		{
			numeroMedio= numero[2];
		}
		else
		{

			if(numero[2] > numero [1] && numero[2] < numero[0])
			{
				numeroMedio= numero[2];
			}
		}

		printf("El numero del medio es: %d", numeroMedio);
	}



	return EXIT_SUCCESS;
}




