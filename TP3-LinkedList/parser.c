#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "interfaz.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* Puntero al archivo CSV
 * \param pArrayListEmployee LinkedList* Puntero al array de empleados
 * \return int -1 si hubo errores [NULL POINTERS] ; 0 si ok
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int error = -1;

	//validacion por NULL pointers
	if(pFile != NULL && pArrayListEmployee!= NULL)
	{
		//contador
		int contadorEmpleadosCargados = 0;

		//puntero auxiliar
		Employee* aux = employee_new();

		//matriz buffer
		char buffer[4][128];

		//lectura fantasma x encabezado
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			if( fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]) < 4 ) //lectura incorrecta
			{
				break;
			}
			else //lectura correcta
			{
				aux = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]); //llamo a construc c/carga
				ll_add(pArrayListEmployee, aux);
				contadorEmpleadosCargados++;
			}
		}

		printf("//                             %4d Empleados leidos                                //\n", contadorEmpleadosCargados); //mensaje por cant esperada

		error = 0;
	}

    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE* Puntero al archivo BIN
 * \param pArrayListEmployee LinkedList* Puntero al array de empleados
 * \return int -1 si hubo errores [NULL POINTERS] ; 0 si ok
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int error = -1;

	//validacion por NULL pointers
	if(pFile != NULL && pArrayListEmployee!= NULL)
	{
		//puntero auxiliar
		Employee* aux = NULL;

		//contador
		int contadorEmpleadosCargados = 0;

		while(!feof(pFile))
		{
			aux = employee_new();

			fread(aux, sizeof(Employee), 1, pFile);

			ll_add(pArrayListEmployee, aux);

			contadorEmpleadosCargados++;
		}

		printf("//                             %4d Empleados leidos                                //\n", contadorEmpleadosCargados); //mensaje por cant esperada

		error = 0;
	}

	return error;
}
