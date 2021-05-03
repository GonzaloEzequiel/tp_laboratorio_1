/*
 * interfaz.h
 *
 *  Created on: 21 abr. 2021
 *      Author: Flor y Gonza
 */

#ifndef INTERFAZ_H_
#define INTERFAZ_H_


/** \brief OPERATIVE INTERFACE, NAVIGATES THROUGH MENUS, SHOWS OUTPUT MESSAGES
 *
 * \return void
 */
void interfaz();


/** \brief MAIN SCREEN, ITERATIVE MAIN MENU, LISTED OPTION FOR THE USER TO CHOOSE
 *
 * \param option int* POINTER TO OPTION VALUE
 *
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int mainMenu(int* option);


/** \brief MODIFICATION MENU, LISTED OPTION FOR THE USER TO CHOOSE
 *
 * \param option int* POINTER TO OPTION VALUE
 *
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int modifyMenu(int* option);


/** \brief WHITDRAWAL MENU, LISTED OPTION FOR THE USER TO CHOOSE
 *
 * \param option int* POINTER TO OPTION VALUE
 *
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int withdrawMenu(int* option);


/** \brief SORT & PRINT MENU, LISTED OPTION FOR THE USER TO CHOOSE
 *
 * \param option int* POINTER TO OPTION VALUE
 *
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int sortMenu(int* option);


/** \brief SHOWS MESSAGES IN GRAFIC FORMAT
 *
 * \param message[] const char MESSAGE TO PRINT
 *
 * \return void
 */
void showMessage(const char message[]);


#endif /* INTERFAZ_H_ */
