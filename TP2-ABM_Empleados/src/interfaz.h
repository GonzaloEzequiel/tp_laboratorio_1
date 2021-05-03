/*
 * interfaz.h
 *
 *  Created on: 21 abr. 2021
 *      Author: Flor y Gonza
 */

#ifndef INTERFAZ_H_
#define INTERFAZ_H_

/** \brief ES LA INTERFAZ GRAFICA, MUESTRA EL MENU ITERADO, MUESTRA LOS SUB-MENUS DE LAS OPCIONES SELECCIONADAS, INDICA LOS MENSAJES DE ERROR
 *
 * \return void
 */
void interfaz();


/** \brief PANTALLA PRINCIPAL DEL PROGRAMA, MENU DE OPCIONES DEL ABM A SELECCIONAR QUE SE PASARA POR REFERENCIA
 *
 * \param x int* DIRECCION DE MEMORIA DE LA OPCION SELECCIONADA
 *
 * \return void
 */
int mainMenu(int* option);

int modifyMenu(int* option);

int withdrawMenu(int* option);

int sortMenu(int* option);

void showMessage(const char message[]);

#endif /* INTERFAZ_H_ */
