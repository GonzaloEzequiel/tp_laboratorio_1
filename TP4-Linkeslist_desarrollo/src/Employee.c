#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

/** \brief Contruye lugar en memoria para un empleado.
 *
 * \return Employee* Puntero al empleado construido.
 *
 */
Employee* employee_new()
{
	Employee* newEmployee = NULL;
	newEmployee = (Employee*) malloc(sizeof(Employee));

	if(newEmployee != NULL)
	{
		(*(newEmployee)).id = 0;
		strcpy((*(newEmployee)).nombre, "");
		(*(newEmployee)).horasTrabajadas = 0;
		(*(newEmployee)).sueldo = 0;
	}

	return newEmployee;
}

/** \brief Contruye con carga, lugar en memoria para un empleado.
 *
 * \return Employee* Puntero al empleado construido.
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
	Employee* newEmployee = NULL;
	newEmployee = employee_new();

	if(newEmployee != NULL)
	{
		(*(newEmployee)).id = atoi(idStr);
		strcpy((*(newEmployee)).nombre, nombreStr);
		(*(newEmployee)).horasTrabajadas = atoi(horasTrabajadasStr);
		(*(newEmployee)).sueldo = atoi(sueldo);
	}

	return newEmployee;
}

/** \brief Libera el espacio en uso del empleado.
 *
 * \param this Employee* Puntero a un empleado.
 * \return void
 *
 */
void employee_delete(Employee* this)
{
	free(this);
}

/** \brief Establece el valor del campo ID de un empleado
 *
 * \param this Employee* Puntero a un empleado
 * \id int Valor del ID a establecer
 * \return int -1 si hubo errores [NULL POINTER] ; 0 si ok
 *
 */
int employee_setId(Employee* this,int id)
{
	int error = -1;

	if(this != NULL)
	{
		this->id = id;
		error = 0;
	}

	return error;
}

/** \brief Retorna el valor del campo ID de un empleado
 *
 * \param this Employee* Puntero a un empleado
 * \id int* Puntero al valor ID(del empleado) a retornar
 * \return int -1 si hubo errores [NULL POINTER] ; 0 si ok
 *
 */
int employee_getId(Employee* this,int* id)
{
	int error = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		error = 0;
	}

	return error;
}

/** \brief Establece el valor del campo NOMBRE de un empleado
 *
 * \param this Employee* Puntero a un empleado
 * \nombre char* Puntero a la cadena de caracteres a establecer
 * \return int -1 si hubo errores [NULL POINTERS] ; 0 si ok
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int error = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		error = 0;
	}

	return error;
}

/** \brief Retorna el valor del campo NOMBRE de un empleado
 *
 * \param this Employee* Puntero a un empleado
 * \nombre char* Puntero al valor NOMBRE(del empleado) a retornar
 * \return int -1 si hubo errores [NULL POINTERS] ; 0 si ok
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int error = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		error = 0;
	}

	return error;
}

/** \brief Establece el valor del campo HORASTRABAJADAS de un empleado
 *
 * \param this Employee* Puntero a un empleado
 * \horasTrabajadas int Valor HORASTRABAJADAS a establecer
 * \return int -1 si hubo errores [NULL POINTER] ; 0 si ok
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int error = -1;

	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		error = 0;
	}

	return error;
}

/** \brief Retorna el valor del campo HORASTRABAJADAS de un empleado
 *
 * \param this Employee* Puntero a un empleado
 * \horasTrabajadas int* Puntero al valor NOMBRE(del empleado) a retornar
 * \return int -1 si hubo errores [NULL POINTERS] ; 0 si ok
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int error = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		error = 0;
	}

	return error;
}

/** \brief Establece el valor del campo SUELDO de un empleado
 *
 * \param this Employee* Puntero a un empleado
 * \sueldo int Valor SUELDO a establecer
 * \return int -1 si hubo errores [NULL POINTER] ; 0 si ok
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int error = -1;

	if(this != NULL)
	{
		this->sueldo = sueldo;
		error = 0;
	}

	return error;
}

/** \brief Retorna el valor del campo SUELDO de un empleado
 *
 * \param this Employee* Puntero a un empleado
 * \sueldo int* Puntero al valor SUELDO(del empleado) a retornar
 * \return int -1 si hubo errores [NULL POINTERS] ; 0 si ok
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int error = -1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		error = 0;
	}

	return error;
}

int employee_ordenarEmpleados(void* pEmpleado1, void* pEmpleado2)
{
	int retorno = strcmp( (*(Employee*)pEmpleado1).nombre , (*(Employee*)pEmpleado2).nombre );

	return retorno;
}
