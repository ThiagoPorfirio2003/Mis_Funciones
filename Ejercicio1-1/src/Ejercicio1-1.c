/*
 ============================================================================
 Name        : Ejercicio1-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numero;
	int acumulador;
	int i;

	acumulador=0;

	for(i=1; i<3; i++)
	{
		printf("Ingrese el N%d de la suma:",i);
		scanf("%d",&numero);
		acumulador+=numero;
	}

	printf("\nEl resultado de la suma es: %d", acumulador);
}
