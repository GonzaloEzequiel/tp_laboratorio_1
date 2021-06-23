/*
 * utn.h
 *
 *  Created on: 30 abr. 2021
 *      Author: Flor y Gonza
 */

#ifndef FUNCIONESUTN_H_
#define FUNCIONESUTN_H_


/** \brief FETCHS AN INTEGER INPUT FROM USER
 *
 * \param num int* POINTER TO INTEGER VALUE
 * \param mensaje[] char ARRAY PROMPT MESSAGE FOR USER
 * \param mensajeError[] char ARRAY ERROR MESSAGE IF INVALID INPUT
 * \param minimo int MIN VALUE TO FETCH
 * \param maximo int MAX VALUE TO FETCH
 * \param reintentos int ALLOWED RETRY ATTEMPTS
 *
 * \return int RETURN (-1) IF ERROR - (0) IF OK
 *
 */
int utn_getInteger(int* num, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);


/** \brief FETCHS A FLOAT INPUT FROM USER
 *
 * \param num float* POINTER TO FLOAT VALUE
 * \param mensaje[] char ARRAY PROMPT MESSAGE FOR USER
 * \param mensajeError[] char ARRAY ERROR MESSAGE IF INVALID INPUT
 * \param minimo int MIN VALUE TO FETCH
 * \param maximo int MAX VALUE TO FETCH
 * \param reintentos int ALLOWED RETRY ATTEMPTS
 *
 * \return int RETURN (-1) IF ERROR - (0) IF OK
 *
 */
int utn_getFloat(float* num, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);


/** \brief FETCHS A CHARACTER INPUT FROM USER
 *
 * \param num char* POINTER TO CHAR VALUE
 * \param mensaje[] char ARRAY PROMPT MESSAGE FOR USER
 * \param mensajeError[] char ARRAY ERROR MESSAGE IF INVALID INPUT
 * \param minimo int MIN VALUE TO FETCH
 * \param maximo int MAX VALUE TO FETCH
 * \param reintentos int ALLOWED RETRY ATTEMPTS
 *
 * \return int RETURN (-1) IF ERROR - (0) IF OK
 *
 */
int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);


/** \brief FETCHS AN NAME OR LASTNAME (ARRAY) INPUT FROM USER AND FORMATS IT WITH CAPITAL INITIALS
 *
 * \param num char* POINTER TO ARRAY VALUE
 * \param size int LENGTH OF THE ARRAY
 * \param mensaje[] char ARRAY PROMPT MESSAGE FOR USER
 * \param mensajeError[] char ARRAY ERROR MESSAGE IF INVALID INPUT
 * \param reintentos int ALLOWED RETRY ATTEMPTS
 *
 * \return int RETURN (-1) IF ERROR - (0) IF OK
 *
 */
int utn_getName(char* vec, int size, char* mensaje, char* mensajeError, int reintentos);


/** \brief FETCHS A DATE (ARRAY) INPUT FROM USER
 *
 * \param day int* POINTER TO DAY VALUE
 * \param month int* POINTER TO MONTH VALUE
 * \param year int* POINTER TO YEAR VALUE
 * \param mensaje[] char ARRAY PROMPT MESSAGE FOR USER
 * \param mensajeError[] char ARRAY ERROR MESSAGE IF INVALID INPUT
 * \param reintentos int ALLOWED RETRY ATTEMPTS
 *
 * \return int RETURN (-1) IF ERROR - (0) IF OK
 *
 */
int utn_getDate(int* day, int* month, int* year, char* mensaje, char* mensajeError, int reintentos);

#endif /* FUNCIONESUTN_H_ */
