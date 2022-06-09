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

struct a{
	char nombre[10];
	int edad;
	};

int main(void) {
	setbuf(stdout, NULL);



	FILE *bin;
	struct a pers;
	bin=fopen("bin.dat","wb");
	printf("\nIngrese el nombre: ");
	gets(pers.nombre);
	printf("Ingrese la edad: ");
	scanf("%d",&pers.edad);
	fflush(stdin);
	fwrite(&pers,sizeof(pers),1,bin);
	fclose(bin);


	return EXIT_SUCCESS;
}




