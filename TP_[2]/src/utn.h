/*
 * utn.h
 *
 *  Created on: 23 may. 2022
 *      Author: thiag
 */

#ifndef UTN_H_
#define UTN_H_

int utn_verificarSerInt(char* cadenaDeCaracteres);

int utn_verificarSerFloat(char* cadenaDeCaracteres);

int utn_VerificarSerMinuscula(char* caracter);

int utn_VerificarSerMayuscula(char* caracter);

int utn_VerificarSerLetra(char* caracter);

int utn_VerificarSerLetra_ASCII_EXTEND(char* caracter);

int utn_VerificarSerLetraEspanol(char* caracter);

int utn_verificarSerNombre(char* cadenaDeCaracteres);

int utn_verificarSerCadenaAlfanumerica(char* cadenaCaracteres);

int utn_trasnformarCadenaAMayuscula(char* direccionCadena);

int utn_CorregirNombre(char* direccionPalabra);

int utn_GetIntRango(int* direccionInt, char* mensaje, char* mensajeError, int minimo, int maximo, int cantidadDeCifras);

int utn_GetFloatRango(float* direccionFloat, char* mensaje, char* mensajeError, float minimo, float maximo, int cantidadDeCifras);

int utn_GetNombreRango(char* direccionPalabra, char* mensaje, char* mensajeError, char* mensajeErrorNull, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres);

int utn_GetCadenaAlfanumericaRango(char* direccionCadenaAlfanumerica, char* mensaje, char* mensajeError, char* mensajeErrorNull, int cantidadMinimaCaracteres, int cantidadMaximaCaracteres, int cantidadDeCaracteres);


#endif /* UTN_H_ */
