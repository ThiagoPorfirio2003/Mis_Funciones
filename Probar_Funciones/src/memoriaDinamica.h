/*
 * memoriaDinamica.h
 *
 *  Created on: 2 jun. 2022
 *      Author: thiag
 */

#ifndef MEMORIADINAMICA_H_
#define MEMORIADINAMICA_H_

int memoria_NewInt(int** punteroAPunteroFloatEstatico);

int memoria_NewFloat(float** punteroAPunteroFloatEstatico);

int memoria_NewChar(char** punteroAPunteroCharEstatico);

int memoria_NewIntConTamanio(int** punteroAPunteroIntEstatico ,int longitud);

int memoria_NewFloatConTamanio(float** punteroAPunteroFloatEstatico ,int longitud);

int memoria_NewCharConTamanio(char** punteroAPunteroCharEstatico ,int longitud);

int memoria_ReSizeInt(int** punteroAPunteroIntEstatico ,int nuevaLongitud);

int memoria_ReSizeFloat(float** punteroAPunteroFloatDinamico ,int nuevaLongitud);

int memoria_ReSizeChar(char** punteroAPunteroCharDinamico ,int nuevaLongitud);


#endif /* MEMORIADINAMICA_H_ */
