/*
 ============================================================================
 Name        : Probar_Funciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "findDato.h"
#include "memoriaDinamica.h"

int main(void) {
	setbuf(stdout,NULL);
	/*
	int numeroUno;
	int numeroMinimo;
	int numeroMaximo;
	int banderaNumeroMenor;
	int banderaNumeroMayor;

	banderaNumeroMenor=1;
	banderaNumeroMayor=1;


	for(int i=0;i<5;i++)
	{
		utn_getIntRango(&numeroUno, "Ingrese un numero entre -256 y 256: ", "El dato ingresado es invalido. Ingrese un numero entre -256 y 256: ", -256, 256);
		guardarMayorInt(&numeroMaximo, numeroUno, &banderaNumeroMayor);
		guardarMenorInt(&numeroMinimo, numeroUno, &banderaNumeroMenor);
	}

	float numeros[] = {1.1,1.6,1.3,1.05,1.2};
	float numeroMaximo;
	int banderaNumeroMaximo;

	if(!(find_BuscarMenorFloat(&numeroMaximo, &banderaNumeroMaximo, 5, numeros)))
	{
		printf("\nNumero Menor: %.2f", numeroMaximo);
	}

	char* minus= "Hola";
	char* segundoChar;
	segundoChar = newChar();
	dimensionarPunteroChar(segundoChar,10);
	*segundoChar = "Juan";
	printf("%s", *segundoChar);

	printf("%d", strlen(*minus));
	minus = memoria_NewChar();
	memoria_ReSizePunteroChar(minus,10);


	if(!(pruebaGets(minus, 10)))
	{
		printf("%s", minus);
	}
	else
	{
		printf("\nError");
	}

	*/


//	printf("\n\n%s\n\n", *(minus));

	char* numeroPrueba;

	numeroPrueba=memoria_PrepararPunteroChar(50);
	//char* c=memoria_NewChar();
	//c=memoria_PrepararPunteroChar(10);

	if(!utn_GetNombre(numeroPrueba, "Ingrese: ", "Error, ingrese: ", 2, 50, 50))
	{
		printf("%s", numeroPrueba);
	}
	else
	{
		printf("Error");
	}


	return 0;
}
