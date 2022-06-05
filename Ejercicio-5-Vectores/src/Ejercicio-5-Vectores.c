/*
 ============================================================================
 Name        : Ejercicio-5-Vectores.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAMANIO 5

int main(void) {
	setbuf(stdout,NULL);

	int numeros[TAMANIO];
	int chequeoError;
	int acumuladorNumeros;
	float promedioNumeros;
	int i;

	acumuladorNumeros=0;

	chequeoError = inicializarIntFuncion(numeros, -1, TAMANIO);
	if(chequeoError == 0)
	{
		for(i=0;i<TAMANIO;i++)
		{
			printf("Introdusca el valor de la posicion %d: ",i);
			scanf("%d", &numeros[i]);
			acumuladorNumeros+=numeros[i];
		}
	}
	else
	{
		printf("\nHa ocurrido un error");
	}

	promedioNumeros = (float)acumuladorNumeros /5;

	printf("\nEl promedio de los numeros es: %.2f", promedioNumeros);
}
