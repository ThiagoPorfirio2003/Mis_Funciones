/*
 ============================================================================
 Name        : Ejercicio1-2.c
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
	int numeroMayor;
	int i;

	for(i=1;i<4;i++)
	{
		printf("Ingrese el N%d:",i);
		scanf("%d",&numero);

		if(numero > numeroMayor || i==1)
		{
			numeroMayor=numero;
		}
	}

	printf("\nEl numero mayor es: %d",numeroMayor);

	return 0;
}
