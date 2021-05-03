/*
 * utn.h
 *
 *  Created on: 30 abr. 2021
 *      Author: Flor y Gonza
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInteger(int* num, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

int utn_getFloat(float* num, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int utn_getName(char* vec, int size, char* mensaje, char* mensajeError, int reintentos);

#endif /* UTN_H_ */
