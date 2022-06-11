/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	int statusFlight;

}Passenger;

int Passenger_verificarYTransfomarEstadoVueloStringAInt(char* estadoVueloString, int* estadoVueloNumero);
int Passenger_verificarTtransfomarTipoPasajeroStringAInt(char* tipoPasajeroString, int* tipoPasajeroNumero);

int Passenger_verificarYTransfomarEstadoVueloIntAString(char* estadoVueloString, int estadoVueloNumero);
int Passenger_verificarYTransfomarTipoPasajeroIntAString(char* tipoPasajeroString, int tipoPasajeroNumero);

int Passenger_transformarIDaString(char* idString, int idNumero);
int Passenger_transformarPrecioaString(char* precioString, float precioNumero);



Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* statusFlight);

void Passenger_delete(LinkedList* pArrayListPassenger, Passenger* pasajeroAEliminar);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,int estadoDeVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int* estadoDeVuelo);

int Passenger_setAll(Passenger* pasajeroASetear, int id, char* nombre,char* apellido, char* codigoVuelo, int tipoPasajero, float precio, int estadoVuelo);
int Passenger_getAll(Passenger* pPasajeroAGetear, int* id, char* nombre,char* apellido, char* codigoVuelo, int* tipoPasajero, float* precio, int* estadoVuelo);

int Passenger_modificarNombre(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria);
int Passenger_ModificarApellido(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria);
int Passenger_ModificarCodigoVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria, char* mensajeCodigoInvalido);
int Passenger_ModificarTipoPasajero(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError);
int Passenger_ModificarPrecioVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError);
int Passenger_ModificarEstadoVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError);


int Passenger_askOnePassengerData(char* nombre, char* apellido, float* precio, int* tipoPasajero, char* codigoVuelo, int* statusFlight);

int Passenger_verificarSerCodigoDeVuelo(char* cadenaAlfanumerica);

int Passenger_MostrarUnPasajero(Passenger* pPasajeroAMostrar);

int Passenger_saveAsText(FILE* pFile , LinkedList* pArrayListPassenger);

#endif /* PASSENGER_H_ */
