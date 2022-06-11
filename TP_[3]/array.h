/*
 * array.h
 *
 *  Created on: 8 jun. 2022
 *      Author: thiag
 */

#ifndef ARRAY_H_
#define ARRAY_H_

int array_SwapCambiarPosicionInt(int* punteroPrimerInt, int* punteroSegundoInt);

int array_MoverAdelanteInt(int* punteroInt, int posicionesAMover);

int array_MoverAtrasInt(int* punteroInt, int posicionesAMover);

int array_existeDatoInt(int* arrayDatos, int cantidadDatos,int datoAEcontrar);

int array_CompararCaracteresEspanolIngles(char primerCaracter, char segundoCaracter);

int array_CompararCadenaCaracteresEspanolInles(char* primeraCadena, char* segundaCadena);

int array_MoverAtrasVariosInt(int posicionDelDatoInicio, int posicionDelDatoFinal,int posicionesAMover, int* arrayDatos);


#endif /* ARRAY_H_ */
