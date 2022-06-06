/*
 ============================================================================
 Name        : Probar_Funciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//strcat(Reemplaza a partir del barra0);
//sprintf(No reemplaza, guarda aca);
//Si no hay un '\0' se escribe 2 veces y en la segunda se agrega al final el \0
//Todas las variables que intervengan en estas funciones deben poseer el \0 sino hay errores


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//#include "utn.h"
#include "findDato.h"
#include "memoriaDinamica.h"
#include "array.h"


int utn_GetNombre(char* direccionPalabra, char* mensaje, char* mensajeError, char* mensajeErrorNull, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres);


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

	char* cadenaPrueba;// = (char*) malloc(sizeof(char)*50);;


	cadenaPrueba = NULL;
	cadenaPrueba = memoria_NewCharConTamanio(50);




	//numeroOtraPrueba=memoria_PrepararPunteroChar(50);

	/*
	for(int i=0;i<15;i++)
	{
		myGets(cadenaPrueba, 50);
		printf("\n%s\n", cadenaPrueba);
	}
	*/


	if(!utn_GetNombre(cadenaPrueba, "Ingrese: ", "Error, ingrese: ", "\nError es nulo\n", 2, 50,50))
	{
		printf("\nCadena igual a :%s", cadenaPrueba);
	}
	else
	{
		printf("Error");
	}



	/*
	char numeroPrueba[256];

		char otraPrueba[1234];
		char sinCero[]="hola";
	sinCero[4]='x';
	sprintf(otraPrueba,"%s, %s, %s", "Porfirio", sinCero, "Thiago Lisandro");

	//otraPrueba[3]= 'x';
	if(*(otraPrueba+31)== '\0')
	{
		printf("\n\nBarra 0\n\n");
	}
	if(isspace(*(otraPrueba+5)))
	{
		printf("Espacio");
	}

	printf("%c", *(otraPrueba+30));


	printf("\n\n%s\n\n", otraPrueba);

	for(int i=0;i<100;i++)
	{
		if(*(otraPrueba+i) == '\0')
		{
			printf("\nRompio");
			break;
		}
		else
		{
			printf("%c", *(otraPrueba+i));
		}
	}


	//array_MoverAdelanteUnInt(numeroPrueba);
	/*
	for(int i=0; i<2;i++)
	{
		printf("Numero: %d\n", *(numeroPrueba+i));
	}

	//printf("%d\n%d\n", *numeroPrueba, *(numeroPrueba+1));
	*/
	free(cadenaPrueba);

	return 0;
}




int getNombre(char* direccionPalabra, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferPalabra;

	retorno=1;

	if(direccionPalabra!=NULL && cantidadDeCaracteres>1)
	{
		bufferPalabra=NULL;
		bufferPalabra = memoria_NewCharConTamanio(cantidadDeCaracteres);

		if(bufferPalabra!=NULL)
		{
			if(!(myGets(bufferPalabra, cantidadDeCaracteres)) && !(utn_verificarSerNombre(bufferPalabra)))
			{
				retorno=0;
				strncpy(direccionPalabra, bufferPalabra, cantidadDeCaracteres);
			}
			free(bufferPalabra);
		}
	}

	return retorno;
}


int utn_CorregirNombre(char* direccionPalabra)
{
	int retorno;
	int banderaEspacio;

	retorno=1;
	banderaEspacio=0;

	if(direccionPalabra !=NULL)
	{
		retorno =0;
		*direccionPalabra = toupper(*direccionPalabra);
		direccionPalabra++;

		while(*direccionPalabra !='\0')
		{
			if(isalpha(*direccionPalabra))
			{
				if(banderaEspacio)
				{
					*direccionPalabra = toupper(*direccionPalabra);
					banderaEspacio=0;
				}
				else
				{
					*direccionPalabra = tolower(*direccionPalabra);
				}
			}
			else
			{
				banderaEspacio=1;
			}
			direccionPalabra++;
		}
	}
	return retorno;
}

int utn_GetNombre(char* direccionPalabra, char* mensaje, char* mensajeError, char* mensajeErrorNull, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferAuxiliar;

	retorno =1;
	bufferAuxiliar=NULL;

	if(direccionPalabra != NULL &&
			mensaje != NULL &&
			mensajeError !=NULL &&
			cantidadMinimaCaracteres > 0 &&
			cantidadMaximaCaracteres >= cantidadMinimaCaracteres &&
			cantidadDeCaracteres >1 &&
			cantidadMaximaCaracteres <= cantidadDeCaracteres &&
			mensajeErrorNull!=NULL)
	{
		bufferAuxiliar=memoria_NewCharConTamanio(cantidadDeCaracteres);
		if(bufferAuxiliar!=NULL)
		{
			printf("%s", mensaje);
			while(getNombre(bufferAuxiliar, cantidadDeCaracteres) ||
					strlen(bufferAuxiliar) < cantidadMinimaCaracteres ||
					strlen(bufferAuxiliar) > cantidadMaximaCaracteres)
			{
				printf("%s", mensajeError);
				//free(bufferAuxiliar);
			}

			utn_CorregirNombre(bufferAuxiliar);
			strcpy(direccionPalabra, bufferAuxiliar);
			retorno =0;
			free(bufferAuxiliar);
		}
		else
		{
			printf("%s", mensajeErrorNull);
		}
	}
	return retorno;
}
/*
char* utn_UnirNombreYApellido(char* nombre, char* apellido, int cantidadDeCaracteresNombreYApellido)
{
	int retorno;
	char* bufferCadena;
	retorno=1;

	if(nombre!=NULL && apellido!=NULL && depositoDeNombreYApellido!=NULL)
	{


		depositoDeNombreYApellido=memoria_NewCharConTamanio(cantidadCaracteres);
		if(depositoDeNombreYApellido!=NULL)
		{
			sprintf(depositoDeNombreYApellido,"%s, %s", apellido,nombre);
		}
		if(*(depositoDeNombreYApellido+cantidadCaracteres)== '\0')
		{
			printf("\n\nHay BARRA0\n\n");
		}
		//*(depositoDeNombreYApellido+1+strnlen(depositoDeNombreYApellido, cantidadCaracteres))='\0';
		retorno=0;
	}
	return retorno;
}*/

int myGets(char* direccionCadenaCaracteres, int longitud)
{
	int retorno;
	char* bufferString;

	retorno = 1;
	if(longitud>1 && direccionCadenaCaracteres != NULL)
	{
		bufferString=NULL;
		bufferString= memoria_NewCharConTamanio(longitud);

		if(bufferString!=NULL)
		{
			fflush(stdin);
			if(fgets(bufferString, sizeof(char)* longitud, stdin) != NULL)
			{
				if(*(bufferString +strnlen(bufferString, sizeof(char)* longitud)-1) == '\n')
				{
					*(bufferString +strnlen(bufferString, sizeof(char)* longitud)-1) = '\0';
				}
				if(strnlen(bufferString, sizeof(char)* longitud) < longitud)
				{
					strncpy(direccionCadenaCaracteres, bufferString, longitud);
					retorno = 0;
				}
			}
			free(bufferString);
		}
	}
	return retorno;
}

int utn_verificarSerNombre(char* cadenaDeCaracteres)
{
	int retorno;

	retorno=1;

	if(cadenaDeCaracteres != NULL && *cadenaDeCaracteres !=' ')
	{
		retorno =0;

		do{
			if(utn_VerificarSerLetra(cadenaDeCaracteres))
			{
				if(isspace(*cadenaDeCaracteres))
				{
					if(*(cadenaDeCaracteres+1)=='\0')
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
			cadenaDeCaracteres++;
		}while(*cadenaDeCaracteres != '\0');
	}
	return retorno;
}
int getNombre(char* direccionPalabra, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferPalabra;

	retorno=1;

	if(direccionPalabra!=NULL && cantidadDeCaracteres>1)
	{
		bufferPalabra=NULL;
		bufferPalabra = memoria_NewCharConTamanio(cantidadDeCaracteres);

		if(bufferPalabra!=NULL)
		{
			if(!(myGets(bufferPalabra, cantidadDeCaracteres)) && !(utn_verificarSerNombre(bufferPalabra)))
			{
				retorno=0;
				strncpy(direccionPalabra, bufferPalabra, cantidadDeCaracteres);
			}
			free(bufferPalabra);
		}
	}

	return retorno;
}
