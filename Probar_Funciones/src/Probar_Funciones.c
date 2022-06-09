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
#include "utn.h"
#include "findDato.h"
#include "memoriaDinamica.h"
#include "array.h"




int main(void) {
	setbuf(stdout,NULL);

	FILE* pArchivo;

	char textoPrueba[]="Tercera Prueba";
	char txt[]="Que onda";
	int cantidadLetras;
	int cantTxt;

	cantidadLetras= strlen(textoPrueba);
	cantTxt= strlen(txt);

	pArchivo= fopen("pruebaBinaria.dat","wb");

	if(pArchivo !=NULL)
	{
		printf("\nSe pudo abrir\n");
		if(fwrite(textoPrueba, sizeof(char), cantidadLetras,pArchivo) == cantidadLetras)
		{
			printf("\nSe pudo escribir\n");
		}
		if(fwrite(txt, sizeof(char), cantTxt,pArchivo) == cantTxt)
		{
			printf("\nSe pudo sobreescribir\n");
		}
		else
		{
			printf("Hubo un error en la escritura");
		}
		if(!fclose(pArchivo))
		{
			printf("Se pudo cerrar");
		}
	}


	return 0;
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
}

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

*/
