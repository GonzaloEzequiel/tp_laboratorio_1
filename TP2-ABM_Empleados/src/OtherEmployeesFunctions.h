#ifndef OTHEREMPLOYEESFUNCTIONS_H_
#define OTHEREMPLOYEESFUNCTIONS_H_

// DE CREACION PERSONAL, UTILIZAN LA ESTRUCTURA EMPLOYEE //


/** \brief searchs for open slots(isEmpty = 1) in array
 *
 * \param list Employee* Pointer to array of employees
 * \param index int* Pointer to index value
 * \param length int Lenght of the array
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int openSlot(Employee* list, int* index, int len);


/** \brief prints data of one employee
 *
 * \param emp Employee Element of Employee Array
 *
 * \return void
 *
 */
void showEmployee(Employee emp);


/** \brief calculates and prints, total and average salaries, and the amount of employees above de average salary
 *
 * \param list Employee* Pointer to array of employees
 * \param size int Array length
 * \param total float* Pointer to total salary value
 * \param average float* Pointer to average salary value
 * \param aboveAverage int* Pointer to amount of employees above de average salary value
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int salaries(Employee* list, int size, float* total, float* average, int* aboveAverage);


/** \brief swaps values between two elements of Employee array
 *
 * \param list Employee* Pointer to array of employees
 * \param a int Index value of one element to swap
 * \param b int Index value of the other element to swap
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void swap2(Employee* list, int a, int b);

#endif /* OTHEREMPLOYEESFUNCTIONS_H_ */
