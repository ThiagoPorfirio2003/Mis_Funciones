#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "memoriaDinamica.h"

int static myGets(char* direccionCadenaCaracteres, int longitud)
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
/*
int static myGets(char* direccionCadenaCaracteres, int longitud)
{
	int retorno;
	char* bufferString;

	bufferString = memoria_PrepararPunteroChar(longitud);
	retorno = 1;

	if(direccionCadenaCaracteres != NULL && bufferString !=NULL && longitud > 0)
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
	return retorno;
}
*/

int utn_verificarSerInt(char* cadenaDeCaracteres)
{
	int retorno;
	retorno = 1;

	if(cadenaDeCaracteres != NULL && *cadenaDeCaracteres != '0')
	{
		retorno=0;

		if(*cadenaDeCaracteres == '-' ||
				*cadenaDeCaracteres == '+')
		{
			cadenaDeCaracteres++;
		}

		do{
			if(isdigit(*cadenaDeCaracteres) == 0)
			{
				retorno =1;
				break;
			}
			cadenaDeCaracteres++;
		}while(*cadenaDeCaracteres!= '\0');
	}
	return retorno;
}

int utn_verificarSerFloat(char* cadenaDeCaracteres)
{
	int retorno;
	int contadorPuntos;

	retorno = 1;
	contadorPuntos =0;

	if(cadenaDeCaracteres != NULL)
	{
		retorno=0;
		if(*cadenaDeCaracteres == '-' || *cadenaDeCaracteres == '+')
		{
			cadenaDeCaracteres++;
		}
		do{
			if(isdigit(*cadenaDeCaracteres) == 0)
			{
				if(contadorPuntos <2 && *cadenaDeCaracteres== '.')
				{
					contadorPuntos++;
				}
				else
				{
					retorno =1;
					break;
				}
			}
			cadenaDeCaracteres++;
		}while(*cadenaDeCaracteres!= '\0');

	}
	return retorno;
}

int utn_VerificarSerMinuscula(char* caracter)
{
	int retorno;

	retorno=1;

	if(caracter !=NULL && (islower(*caracter)||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ))
	{
		retorno=0;
	}

	return retorno;
}

int utn_VerificarSerMayuscula(char* caracter)
{
	int retorno;

	retorno=1;

	if(caracter !=NULL && (isupper(*caracter)||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�'))
	{
		retorno=0;
	}

	return retorno;
}

int utn_VerificarSerLetra(char* caracter)
{
	int retorno;

	retorno =1;

	if(caracter!=NULL && (isalpha(*caracter) ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�' ||
			*caracter == '�'))
	{
		retorno=0;
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

int static getInt(int* direccionInt, int cantidadDeCifras)
{
	int retorno;
	char* bufferInt;

	cantidadDeCifras+=2;
	bufferInt = memoria_PrepararPunteroChar(cantidadDeCifras);
	retorno =1;

	if(direccionInt !=NULL && bufferInt!=NULL)
	{
		if(!(myGets(bufferInt, cantidadDeCifras)) && !(utn_verificarSerInt(bufferInt)))
		{
			*direccionInt = atoi(bufferInt);
			retorno =0;
		}
		free(bufferInt);
	}

	return retorno;
}

int static getFloat(float* direccionFloat, int cantidadDeCifras)
{
	int retorno;
	char* bufferFloat;

	cantidadDeCifras+=2;
	bufferFloat = memoria_PrepararPunteroChar(cantidadDeCifras);
	retorno =1;

	if(direccionFloat !=NULL && bufferFloat !=NULL)
	{
		if(!(myGets(bufferFloat, cantidadDeCifras)) && !(utn_verificarSerFloat(bufferFloat)))
		{
			*direccionFloat = atof(bufferFloat);
			retorno =0;
		}
		free(bufferFloat);
	}
	return retorno;
}

int static getNombre(char* direccionPalabra, int cantidadDeCaracteres)
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

int utn_trasnformarCadenaAMayuscula(char* direccionCadena)
{
	int retorno;

	retorno=1;

	if(direccionCadena!=NULL)
	{
		retorno= 0;
		do{
			if(!utn_VerificarSerLetra(direccionCadena))
			{
				*direccionCadena = toupper(*direccionCadena);
			}
			direccionCadena++;
		}while(*direccionCadena != '\0');
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

int utn_GetIntRango(int* direccionInt, char* mensaje, char* mensajeError, int minimo, int maximo, int cantidadDeCifras)
{
	int retorno;
	int bufferInt;

	retorno=1;

	if(direccionInt!=NULL &&
			mensaje!=NULL &&
			mensajeError!=NULL &&
			minimo<=maximo
			&& cantidadDeCifras > 0)
	{
		printf("%s", mensaje);
		while(getInt(&bufferInt,cantidadDeCifras) || bufferInt < minimo || bufferInt > maximo)
		{
			printf("%s", mensajeError);
		}
		*direccionInt = bufferInt;
		retorno=0;
	}
	return retorno;
}

int utn_GetFloatRango(float* direccionFloat, char* mensaje, char* mensajeError, float minimo, float maximo, int cantidadDeCifras)
{
	int retorno;
	float bufferFloat;

	retorno=1;

	if(direccionFloat!=NULL &&
			mensaje!=NULL &&
			mensajeError!=NULL &&
			minimo<=maximo &&
			cantidadDeCifras>0)
	{
		printf("%s", mensaje);
		while(getFloat(&bufferFloat, cantidadDeCifras) || bufferFloat < minimo || bufferFloat > maximo)
		{
			printf("%s", mensajeError);
		}
		*direccionFloat = bufferFloat;
		retorno=0;
	}
	return retorno;
}

int utn_GetNombre(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferAuxiliar;

	bufferAuxiliar=memoria_NewCharConTamanio(cantidadDeCaracteres);
	retorno =1;

	if(direccionPalabra != NULL &&
			mensaje != NULL &&
			mensajeError !=NULL &&
			cantidadMinimaCaracteres > 0 &&
			cantidadMaximaCaracteres >= cantidadMinimaCaracteres &&
			cantidadDeCaracteres >0 &&
			cantidadMaximaCaracteres <= cantidadDeCaracteres)
	{
		printf("%s", mensaje);
		while(getNombre(bufferAuxiliar, cantidadDeCaracteres) ||
				strlen(bufferAuxiliar) < cantidadMinimaCaracteres ||
				strlen(bufferAuxiliar) > cantidadMaximaCaracteres)
		{
			printf("\nERROR\n");
			printf("\n\n%d\n\n", strlen(bufferAuxiliar));
			printf("%s\n", bufferAuxiliar);
			printf("%s", mensajeError);
			//free(bufferAuxiliar);
		}
		utn_CorregirNombre(bufferAuxiliar);
		strcpy(direccionPalabra, bufferAuxiliar);
		retorno =0;
		free(bufferAuxiliar);
	}

	return retorno;
}

int utn_UnirNombreYApellido(char* nombre, char* apellido, char* depositoDeNombreYApellido)
{
	int retorno;
	int cantidadCaracteres;
	retorno=1;

	if(nombre!=NULL && apellido!=NULL && depositoDeNombreYApellido!=NULL)
	{
		cantidadCaracteres = strlen(nombre)+ strlen(apellido);
		cantidadCaracteres+=3;

		depositoDeNombreYApellido=memoria_PrepararPunteroChar(cantidadCaracteres);
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

/*
int static verificarSerCadenaAlfanumerica(char* cadenaAlfanumerica)
{
	int retorno;
	int banderaExistenciaNumero;
	int banderaExistenciaCaracter;

	banderaExistenciaNumero=0;
	banderaExistenciaCaracter=0;

	retorno=1;

	if(cadenaAlfanumerica != NULL && *cadenaAlfanumerica !=' ')
	{
		do{
			if(isdigit(*cadenaAlfanumerica) != 0)
			{
				banderaExistenciaNumero =1;
			}
			else
			{
				if(isalpha(*cadenaAlfanumerica) != 0)
				{
					banderaExistenciaCaracter=1;
				}
				else
				{
					if(*cadenaAlfanumerica != '�' &&
						*cadenaAlfanumerica != '�' &&
						*cadenaAlfanumerica != '�' &&
						*cadenaAlfanumerica != '�' &&
						*cadenaAlfanumerica != '�' &&
						*cadenaAlfanumerica != '�' &&
						*cadenaAlfanumerica != '�' &&
						*cadenaAlfanumerica != '�' &&
						*cadenaAlfanumerica != '�' &&
						*cadenaAlfanumerica != '�' &&
						*cadenaAlfanumerica != '�' &&
						*cadenaAlfanumerica != '�')
					{
						banderaExistenciaCaracter=1;
					}
					else
					{
						retorno = 1;
						break;
					}
				}
			}
			cadenaAlfanumerica++;
		}while(*cadenaAlfanumerica != '\0');
		if(banderaExistenciaCaracter && banderaExistenciaNumero && *cadenaAlfanumerica == '\0')
		{
			retorno =0;
		}
	}
	return retorno;
}


int static getCadenaAlfanumerica(char* cadenaAlfanumerica)
{
	int retorno;
	char bufferChar[1024];

	retorno =1;

	if(cadenaAlfanumerica != NULL)
	{
		if(!(myGets(bufferChar, sizeof(bufferChar))) && !(verificarSerCadenaAlfanumerica(bufferChar)))
		{
			retorno =0;
			strcpy(cadenaAlfanumerica, bufferChar);
		}
	}
	return retorno;
}

int utn_getCadenaAlfanuerica(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int longitudPalabra)
{
	int retorno;
	char bufferPalabra[1024];
	int tamanioBuffer;

	tamanioBuffer = sizeof(bufferPalabra);
	retorno =1;

	if(direccionPalabra != NULL &&
			mensaje != NULL &&
			mensajeError !=NULL &&
			cantidadMinimaCaracteres > 0 &&
			cantidadMaximaCaracteres > cantidadMinimaCaracteres &&
			longitudPalabra >0 &&
			cantidadMaximaCaracteres < longitudPalabra)
	{
		printf("%s", mensaje);
		while(getCadenaAlfanumerica(bufferPalabra) ||
				strnlen(bufferPalabra, tamanioBuffer) < cantidadMinimaCaracteres ||
				strnlen(bufferPalabra, tamanioBuffer) > cantidadMaximaCaracteres)
		{
			printf("%s", mensajeError);
		}
		retorno =0;
		strncpy(direccionPalabra, bufferPalabra, longitudPalabra);
	}
	return retorno;
}

int utn_getLetraRango(char* direccionLetra, char* mensaje, char* mensajeError, char letraMinima, char letraMaxima)
{
	int retorno;
	char bufferLetra[1024];

	retorno=1;

	if(direccionLetra!=NULL &&
			mensaje!=NULL &&
			mensajeError!=NULL &&

			letraMinima<=letraMaxima)
	{

		printf("%s", mensaje);
		while(utn_getNombre(bufferLetra) || *bufferLetra < letraMinima || *bufferLetra > letraMaxima || strnlen(bufferLetra, sizeof(bufferLetra)) != 1)
		{
			printf("%s", mensajeError);
		}
		*direccionLetra = *bufferLetra;
		retorno=0;
	}
	return retorno;
}
*/

///
/*
int utn_GetNombre(char* direccionPalabra, char* mensaje, char* mensajeError, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres)
{
	int retorno;
	char* bufferAuxiliar;

	bufferAuxiliar= memoria_PrepararPunteroChar(cantidadDeCaracteres);

	retorno =1;

	if(direccionPalabra != NULL &&
			mensaje != NULL &&
			mensajeError !=NULL &&
			cantidadMinimaCaracteres > 0 &&
			cantidadMaximaCaracteres >= cantidadMinimaCaracteres &&
			cantidadDeCaracteres >0 &&
			cantidadMaximaCaracteres <= cantidadDeCaracteres)
	{
		printf("%s", mensaje);
		while(getNombre(bufferAuxiliar, cantidadDeCaracteres) ||
				strlen(bufferAuxiliar) < cantidadMinimaCaracteres ||
				strlen(bufferAuxiliar) > cantidadMaximaCaracteres)
		{
			printf("\n\n%d\n\n", strlen(bufferAuxiliar));
			printf("%s", mensajeError);
		}
		printf("\n\nLLega aca\n\n");
		utn_CorregirNombre(bufferAuxiliar);
		strcpy(direccionPalabra, bufferAuxiliar);
		free(bufferAuxiliar);
		retorno =0;
	}
	return retorno;
}
*/
