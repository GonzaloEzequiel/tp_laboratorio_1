/*
 * interfaz.h
 *
 *  Created on: 10 jun. 2021
 *      Author: Flor y Gonza
 */

#ifndef INTERFAZ_H_
#define INTERFAZ_H_

int menu(int* option);
int menuSort(int* option, int* order);
int ordenarPorId(LinkedList* list, int len);
int ordenarPorNombre(LinkedList* list, int len);
int ordenarPorHorasTrabajadas(LinkedList* list, int len);
int ordenarPorSueldo(LinkedList* list, int len);
void showMessage(const char message[]);


#endif /* INTERFAZ_H_ */
