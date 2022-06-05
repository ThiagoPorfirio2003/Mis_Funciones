/*
 * memoriaDinamica.h
 *
 *  Created on: 2 jun. 2022
 *      Author: thiag
 */

#ifndef MEMORIADINAMICA_H_
#define MEMORIADINAMICA_H_

int* memoria_NewInt();

float* memoria_NewFloat();

char* memoria_NewChar();

int memoria_ReSizePunteroInt(int* punteroIntADimensionar, int nuevaLongitud);

int memoria_ReSizePunteroFloat(float* punteroFloatADimensionar, int nuevaLongitud);

int memoria_ReSizePunteroChar(char* punteroCharADimensionar, int nuevaLongitud);

int* memoria_PrepararPunteroInt(int longitudPunteroInt);

float* memoria_PrepararPunteroFloat(int longitudPunteroFloat);

char* memoria_PrepararPunteroChar(int longitudPunteroChar);

#endif /* MEMORIADINAMICA_H_ */