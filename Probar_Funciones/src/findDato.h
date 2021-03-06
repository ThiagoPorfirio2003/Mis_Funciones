/*
 * findDato.h
 *
 *  Created on: 1 jun. 2022
 *      Author: thiag
 */

#ifndef FINDDATO_H_
#define FINDDATO_H_

//INT

/// @brief
///
/// @pre
/// @post
/// @param direccionIntMayor
/// @param intRecibido
/// @param direccionBanderaIntMaximo
/// @return
int find_GuardarMayorInt(int* direccionIntMayor, int intRecibido, int* direccionBanderaIntMaximo);

/// @brief
///
/// @pre
/// @post
/// @param direccionIntMenor
/// @param intRecibido
/// @param direccionBanderaIntMenor
/// @return
int find_GuardarMenorInt(int* direccionIntMenor, int intRecibido, int* direccionBanderaIntMenor);

/// @brief
///
/// @pre
/// @post
/// @param direccionIntMayor
/// @param direccionBanderaIntMaximo
/// @param cantidadNumeros
/// @param direccionPrimerInt
/// @return
int find_BuscarMayorInt(int* direccionIntMayor, int* direccionBanderaIntMaximo, int cantidadNumeros, int* direccionPrimerInt);

/// @brief
///
/// @pre
/// @post
/// @param direccionIntMenor
/// @param direccionBanderaIntMenor
/// @param cantidadNumeros
/// @param direccionPrimerInt
/// @return
int find_BuscarMenorInt(int* direccionIntMenor, int* direccionBanderaIntMenor, int cantidadNumeros, int* direccionPrimerInt);

//FLOAT

/// @brief
///
/// @pre
/// @post
/// @param direccionFloatMayor
/// @param numeroRecibido
/// @param direccionBanderaFloatMaximo
/// @return
int find_GuardarMayorFloat(float* direccionFloatMayor, float numeroRecibido, int* direccionBanderaFloatMaximo);

/// @brief
///
/// @pre
/// @post
/// @param direccionFloatMenor
/// @param numeroRecibido
/// @param direccionBanderaFloatMenor
/// @return
int find_GuardarMenorFloat(float* direccionFloatMenor, float numeroRecibido, int* direccionBanderaFloatMenor);

/// @brief
///
/// @pre
/// @post
/// @param direccionFloatMayor
/// @param direccionFloatNumeroMaximo
/// @param cantidadNumeros
/// @param direccionPrimerNumero
/// @return
int find_BuscarMayorFloat(float* direccionFloatMayor, int* direccionFloatNumeroMaximo, int cantidadNumeros, float* direccionPrimerNumero);

/// @brief
///
/// @pre
/// @post
/// @param direccionFloatMenor
/// @param direccionBanderaFloatMenor
/// @param cantidadNumeros
/// @param direccionPrimerNumero
/// @return
int find_BuscarMenorFloat(float* direccionFloatMenor, int* direccionBanderaFloatMenor, int cantidadNumeros, float* direccionPrimerNumero);

int guardarMenorOMayorInt(int* numeroMayorMenor, int numeroRecibido, int* banderaMayorMenor, int (*funcionMayorMenor)(int*,int,int*), int eleccionMayorMenor);

#endif /* FINDDATO_H_ */
