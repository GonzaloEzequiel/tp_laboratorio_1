/*
 * ArrayEmployees.h
 *
 *  Created on: 21 abr. 2021
 *      Author: Flor y Gonza
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} typedef Employee;


/** \brief 	To indicate that all position in the array are empty,
 * 			this function put the flag (isEmpty) in TRUE in all
 * 			position of the array
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);


/** \brief 	add in a existing list of employees the values received as parameters
 * 			in the first empty position
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int New employee id number
 * \param name[] char New employee name
 * \param lastName[] char New employee lastname
 * \param salary float New employee salary amount
 * \param sector int New employee sector number
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Employee ID number
 *
 * \return index int Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len, int id);


/** \brief Remove an Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Employee ID number
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);


/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [2] and [4] indicate UPWARDS - [3][5] indicate DOWNWARDS
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);


/** \brief print the content of employees array
 *
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee* list, int length);

#endif /* ARRAYEMPLOYEES_H_ */
