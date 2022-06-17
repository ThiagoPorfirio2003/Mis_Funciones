/*
 * ArrayPassenger.h
 *
 *  Created on: 11 may. 2022
 *      Author: thiag
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int id;
	char name[50];
	char lastName[50];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} Passenger;

#endif /* ARRAYPASSENGER_H_ */

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initPassengers(Passenger* list, int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, int statusFlight, char flycode[]);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int findPassengerById(Passenger* list, int len,int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);

int Passenger_SwapPassenger(Passenger* this, Passenger* pasajeroDeCambio);

int Passenger_SwapPorApellidoAscendente(Passenger* primerPasajero, Passenger* segundoPasajero);

int Passenger_SwapPassengerPorApellidoYTipoPasajero(Passenger* primerPasajero, Passenger* segundoPasajero, int (*pFuncionSwapeoApellido)(Passenger*, Passenger*), int (*pFuncionSwapeoNombre)(Passenger*, Passenger*));

int Passenger_SwapPassengerPorCodigoVueloYEstadoVuelo(Passenger* primerPasajero, Passenger* segundoPasajero, int (*pFuncionSwapCodigoVuelo)(Passenger*, Passenger*), int (*pFuncionEstadoVuelo)(Passenger*, Passenger*));


/** \brief Sort the elements in the array of passengers, the argument order
*indicate UP or DOWN order
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);

int printOnePassenger(Passenger* pPasajeroAMostrar);


/** \brief print the content of passengers array
* \param list Passenger*
* \param length int
* \return int
*/
int printPassengers(Passenger* list, int length, int modoImpresion);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengerByCode(Passenger* list, int len, int order);

int Passenger_askOnePassengerData(char* nombre, char* apellido, char* codigoVuelo,float* precio, int* tipoPasajero, int* statusFlight);



int Passenger_modificarNombre(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria);

int Passenger_ModificarApellido(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria);

int Passenger_ModificarCodigoVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria, char* mensajeCodigoInvalido);

int Passenger_ModificarTipoPasajero(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError);

int Passenger_ModificarPrecioVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError);

int Passenger_ModificarEstadoVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError);



int modifyPassengerById(Passenger* list, int posicionPasajero, int opcion, int tamanioNombre, int intentos, float precioMinimo, float precioMaximo);

int Passenger_getTotalYPromedioPrecio(Passenger* list, int cantidadPasajeros, float* precioPromedio, float* precioTotal);

int Passenger_getCantidaEncimaPrecioPromedio(Passenger* list, int cantidadPasajeros, float precioPromedio);



