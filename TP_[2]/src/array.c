/*
 * array.c
 *
 *  Created on: 5 jun. 2022
 *      Author: thiag
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

int array_SwapCambiarPosicionInt(int* punteroPrimerInt, int* punteroSegundoInt)
{
	int retorno;
	int auxiliar;

	retorno=1;

	if(punteroPrimerInt != NULL && punteroSegundoInt !=NULL)
	{
		auxiliar = *(punteroPrimerInt);
		*(punteroPrimerInt)= *(punteroSegundoInt);
		*punteroSegundoInt=auxiliar;
		retorno=0;
	}

	return retorno;
}

int array_MoverAdelanteInt(int* punteroInt, int posicionesAMover)
{
	int retorno;

	retorno=1;

	if(punteroInt != NULL && posicionesAMover>-1)
	{
		*(punteroInt+posicionesAMover) = *punteroInt;
		retorno=0;
	}
	return retorno;
}

int array_MoverAtrasInt(int* punteroInt, int posicionesAMover)
{
	int retorno;

	retorno=1;

	if(punteroInt !=NULL && posicionesAMover >-1)
	{
		*(punteroInt-posicionesAMover) = *punteroInt;
		retorno=0;
	}
	return retorno;
}
//Se mover todos los datos que esten en frente de posicionDeInicio
//La posicion empieza a contar desde 0
int array_MoverAdelanteVariosInt(int posicionDeInicio, int posicionFinal,int posicionesAMover, int* arrayDatos, int longitudArray)
{
	int retorno;

	retorno=1;

	if(arrayDatos!=NULL && posicionDeInicio>-1 && posicionFinal>posicionDeInicio && posicionesAMover > -1 && longitudArray>0)
	{
		posicionDeInicio--;
		longitudArray--;
		for(int i=longitudArray; i>posicionDeInicio;i--)
		{
			for(int j=0; j<longitudArray;j++)
			{

			}
		}
	}

	return retorno;
}

int array_MoverAtrasVariosInt(int posicionDelDatoInicio, int posicionDelDatoFinal,int posicionesAMover, int* arrayDatos)
{
	int retorno;

	retorno=1;

	if(arrayDatos!=NULL && posicionDelDatoInicio>-1 && posicionDelDatoFinal>posicionDelDatoInicio && posicionesAMover > -1)
	{
		retorno=0;
		posicionDelDatoFinal++;
		for(int i=posicionDelDatoInicio; i<posicionDelDatoFinal;i++)
		{
			if(array_MoverAtrasInt(i+arrayDatos, posicionesAMover))
			{
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}

int array_CompararCaracteresEspanolIngles(char primerCaracter, char segundoCaracter)
{
	int retorno;
	int banderaSwitch;
	char* auxiliarCaracterEspanol;
	char* auxiliarCaracterIngles;

	retorno=2;
	banderaSwitch=0;

	if(primerCaracter != '\0' && segundoCaracter != '\0')
	{
		retorno=0;

		if(!utn_VerificarSerLetra_ASCII_EXTEND(&primerCaracter) && utn_VerificarSerLetra_ASCII_EXTEND(&segundoCaracter))
		{
			auxiliarCaracterEspanol=&primerCaracter;
			auxiliarCaracterIngles=&segundoCaracter;
			banderaSwitch=1;
		}
		else
		{
			if(utn_VerificarSerLetra_ASCII_EXTEND(&primerCaracter) && !utn_VerificarSerLetra_ASCII_EXTEND(&segundoCaracter))
			{
				auxiliarCaracterEspanol=&segundoCaracter;
				auxiliarCaracterIngles=&primerCaracter;
				banderaSwitch=1;
			}
		}

		if(banderaSwitch)
		{
			switch(*auxiliarCaracterEspanol)
			{
				case 'á':
					if(*auxiliarCaracterIngles> 'a')
					{
						*auxiliarCaracterEspanol='a';
					}
					else
					{
						if(*auxiliarCaracterIngles=='a')
						{
							*auxiliarCaracterEspanol='b';
						}
					}
					break;

				case 'é':
					if(*auxiliarCaracterIngles> 'e')
					{
						*auxiliarCaracterEspanol='e';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'e')
						{
							*auxiliarCaracterEspanol='f';
						}
					}

					break;

				case 'í':
					if(*auxiliarCaracterIngles> 'i')
					{
						*auxiliarCaracterEspanol='i';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'i')
						{
							*auxiliarCaracterEspanol='j';
						}
					}

					break;

				case 'ó':
					if(*auxiliarCaracterIngles> 'o')
					{
						*auxiliarCaracterEspanol='o';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'o')
						{
							*auxiliarCaracterEspanol='p';
						}
					}

					break;

				case 'ú':
					if(*auxiliarCaracterIngles> 'u')
					{
						*auxiliarCaracterEspanol='u';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'u')
						{
							*auxiliarCaracterEspanol='v';
						}
					}

					break;

				case 'Á':
					if(*auxiliarCaracterIngles> 'A')
					{
						*auxiliarCaracterEspanol='A';
					}
					else
					{
						if(*auxiliarCaracterIngles=='A')
						{
							*auxiliarCaracterEspanol='B';
						}
					}

					break;

				case 'É':
					if(*auxiliarCaracterIngles> 'E')
					{
						*auxiliarCaracterEspanol='E';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'E')
						{
							*auxiliarCaracterEspanol='F';
						}
					}
					break;

				case 'Í':
					if(*auxiliarCaracterIngles> 'I')
					{
						*auxiliarCaracterEspanol='I';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'I')
						{
							*auxiliarCaracterEspanol='J';
						}
					}
					break;

				case 'Ó':
					if(*auxiliarCaracterIngles> 'O')
					{
						*auxiliarCaracterEspanol='O';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'O')
						{
							*auxiliarCaracterEspanol='P';
						}
					}
					break;

				case 'Ú':
					if(*auxiliarCaracterIngles> 'U')
					{
						*auxiliarCaracterEspanol='U';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'U')
						{
							*auxiliarCaracterEspanol='V';
						}
					}
					break;

				case 'ñ':
					if(*auxiliarCaracterIngles> 'n')
					{
						*auxiliarCaracterEspanol='n';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'n')
						{
							*auxiliarCaracterEspanol='o';
						}
					}
					break;

				case 'Ñ':
					if(*auxiliarCaracterIngles> 'N')
					{
						*auxiliarCaracterEspanol='N';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'N')
						{
							*auxiliarCaracterEspanol='O';
						}
					}
					break;
			}
		}
		if(primerCaracter<segundoCaracter)
		{
			retorno=-1;
		}
		else
		{
			if(segundoCaracter<primerCaracter)
			{
				retorno=1;
			}
		}
	}

	return retorno;
}

int array_CompararCadenaCaracteresEspanolInles(char* primeraCadena, char* segundaCadena)
{
	int retorno;
	int longitudPrimeraCadena;
	int longitudSegundaCadena;

	retorno=2;

	if(primeraCadena!=NULL && segundaCadena!=NULL)
	{
		retorno=0;
		longitudPrimeraCadena = strlen(primeraCadena);
		longitudSegundaCadena = strlen(segundaCadena);

		for(int i=0;i<longitudPrimeraCadena && i<longitudSegundaCadena;i++)
		{
			retorno = array_CompararCaracteresEspanolIngles(*(primeraCadena+i), *(segundaCadena+i));
			if(retorno!=0)
			{
				break;
			}
		}
	}

	return retorno;
}


int array_existeDatoInt(int* arrayDatos, int cantidadDatos,int datoAEcontrar)
{
	int retorno;

	retorno=1;

	if(arrayDatos!=NULL && cantidadDatos>0)
	{
		for(int i=0; i<cantidadDatos;i++)
		{
			if(*(arrayDatos+i)== datoAEcontrar)
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

