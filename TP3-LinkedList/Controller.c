#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "interfaz.h"
#include "dataStore.h"
#include "funcionesUTN.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Puntero al archivo CSV
 * \param pArrayListEmployee LinkedList* Puntero al array de empleados
 * \return int -1 si hubo errores, [NULL POINTERS] ; 0 si ok
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int error = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* pFile = fopen(path, "r");

		if(pFile != NULL)
		{
			if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
			{

			}
			else
			{
				showMessage(ERR11);
				system("pause");
			}

			error = 0;
		}
		else
		{
			showMessage(ERR12);
			system("pause");
		}

		fclose(pFile);

	}

	return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* Puntero al archivo BIN
 * \param pArrayListEmployee LinkedList* Puntero al array de empleados
 * \return int -1 si hubo errores, [NULL POINTERS] ; 0 si ok
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int error = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* pFile =  fopen(path, "rb");

		if(pFile != NULL)
		{
			//hace lo que tiene que hacer
			if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
			{

			}
			else
			{
				showMessage(ERR21);
				system("pause");
			}
		}
		else
		{
			showMessage(ERR22);
			system("pause");
		}

		error = 0;
		fclose(pFile);
	}

	return error;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero al array de empleados
 * \return int -1 si hubo errores, [NULL POINTER] ; 0 si ok
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;

    if(pArrayListEmployee != NULL)
    {
    	int nextId = (ll_len(pArrayListEmployee) + 1);

    	Employee* aux = employee_new();

    	(*aux).id = nextId;

    	if(	!utn_getName((*(aux)).nombre, 128, "//                                                                                  //\n//    Ingrese Nombre: ", "//                                                                                  //\n//    Error, Reintente...                                                           //\n", 3) &&
    		!utn_getInteger(&(*(aux)).horasTrabajadas, "//                                                                                  //\n//    Ingrese Horas Trabajadas: ", "//                                                                                  //\n//    Error, Reintente...                                                           //\n", 0, 720, 3) &&
			!utn_getInteger(&(*(aux)).sueldo, "//                                                                                  //\n//    Ingrese Sueldo: $ ", "//                                                                                  //\n//    Error, Reintente...                                                           //\n", 21600, 999999, 3) //sueldo min $21600 Arg Junio 2021
    	)
    	{
    		if( !ll_add(pArrayListEmployee, aux) )
    		{
    			error = 0;
    		}
    	}
    	else
    	{
    		showMessage("//                              Error al ingresar datos                             //");
    	}
    }

    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;

    if(pArrayListEmployee != NULL)
    {
    	int auxID;
    	int auxIndex;
    	char auxNombre[128];
    	int auxHoras;
    	int auxSueldo;
    	Employee* aux = employee_new();

		if( !utn_getInteger(&auxID, "//                                                                                  //\n//    Ingrese ID: ", "//                                                                                  //\n//    Error, Reintente...                                                           //\n", 1, 9999, 3) )
		{
			auxIndex = controller_findEmployeeById(pArrayListEmployee, auxID);

			if(	auxIndex != -1)
			{
				aux = (Employee*) ll_get(pArrayListEmployee, auxIndex);

				printf("//    Empleado:                                                                     //\n");
				printf("//                                                                                  //\n");
				printf("//        ID             NOMBRE                HORAS TRABAJADAS         SUELDO      //\n");
				printf("//  ------------------------------------------------------------------------------  //\n");
				printf("//       %4d %25s              %4d              $%6d      //\n", (*aux).id, (*aux).nombre, (*aux).horasTrabajadas, (*aux).sueldo );

				if( !utn_getName(auxNombre, 128, "//                                                                                  //\n//    Ingrese Nombre: ", "//                                                                                  //\n//    Error, Reintente...                                                           //\n", 3) &&
					!utn_getInteger(&auxHoras, "//                                                                                  //\n//    Ingrese Horas Trabajadas: ", "//                                                                                  //\n//    Error, Reintente...                                                           //\n", 0, 720, 3) &&
					!utn_getInteger(&auxSueldo, "//                                                                                  //\n//    Ingrese Sueldo: $ ", "//                                                                                  //\n//    Error, Reintente...                                                           //\n", 0, 99999, 3)
				)
				{
					employee_setNombre(aux, auxNombre);
					employee_setHorasTrabajadas(aux, auxHoras);
					employee_setSueldo(aux, auxSueldo);
				}

				error = 0;
			}
			else
			{
				showMessage("//                          No se encontraron concidencias                          //");
			}
		}
    }

    return error;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero al array de empleados
 * \return int -1 si hubo errores, [NULL POINTER] ; 0 si ok
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;

	if(pArrayListEmployee != NULL)
	{
		int auxID;
		int auxIndex;

		if( !utn_getInteger(&auxID, "//                                                                                  //\n//    Ingrese ID: ", "//                                                                                  //\n//    Error, Reintente...                                                           //\n", 1, 9999, 3) )
		{
			auxIndex = controller_findEmployeeById(pArrayListEmployee, auxID);

			if(auxIndex != -1)
			{
				ll_remove(pArrayListEmployee, auxIndex);

				error = 0;
			}
			else
			{
				showMessage("//                          No se encontraron concidencias                          //");
			}
		}
	}

    return error;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero al array de empleados
 * \return int -1 si hubo errores [NULL POINTER] ; 0 si ok
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;

    if(pArrayListEmployee != NULL)
    {
    	Employee* aux;

    	showMessage(TIT60);

    	printf("//                                                                                  //\n");
    	printf("//        ID             NOMBRE                HORAS TRABAJADAS         SUELDO      //\n");
    	printf("//  ------------------------------------------------------------------------------  //\n");

    	for(int i=0; i<ll_len(pArrayListEmployee); i++)
    	{
    		aux = (Employee*) ll_get(pArrayListEmployee, i);

    		printf("//       %4d %25s              %4d              $%6d      //\n", (*aux).id, (*aux).nombre, (*aux).horasTrabajadas, (*aux).sueldo );
    	}

    	printf("//                                                                                  //\n");
    	printf("//////////////////////////////////////////////////////////////////////////////////////\n\n");

    	error = 0;
    }

    return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;

	if(pArrayListEmployee != NULL)
	{
		int option;
		int order;
		int (*ordenarCriterio)(void*, void*);

		if( menuSort(&option, &order) )
		{
			showMessage(ERR00);
		}

		switch(option)
		{
		case 1:
			ordenarCriterio = ordenarPorId;
			break;
		case 2:
			ordenarCriterio = ordenarPorNombre;
			break;
		case 3:
			ordenarCriterio = ordenarPorHorasTrabajadas;
			break;
		case 4:
			ordenarCriterio = ordenarPorSueldo;
			break;
		default:
			break;
		}

		if(option != 5)
		{
			ll_sort(pArrayListEmployee, ordenarCriterio, order);
			printf("//                              Se reordenaron empleados                            //");
		}

		system("pause");
		error = 0;
	}

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo a guardar
 * \param pArrayListEmployee LinkedList* Puntero al array de empleados
 * \return int -1 si hubo errores, [NULL POINTERS] ; 0 si ok
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int error = 1;

    if(path != NULL && pArrayListEmployee != NULL)
    {
    	FILE* pFile =  fopen(path, "w");

    	Employee* aux = employee_new();

    	if(pFile != NULL && aux != NULL)
    	{
    		fprintf(pFile, "%s,%s,%s,%s\n", "id", "nombre", "horasTrabajadas", "sueldo");

    		for(int i=0; i<ll_len(pArrayListEmployee); i++)
    		{
    			aux = (Employee*) ll_get(pArrayListEmployee, i);

    			fprintf(pFile, "%d,%s,%d,%d\n", (*aux).id, (*aux).nombre, (*aux).horasTrabajadas, (*aux).sueldo);
    		}

        	error = 0;
    	}

    	fclose(pFile);
    }

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* Nombre del archivo a guardar
 * \param pArrayListEmployee LinkedList* Puntero al array de empleados
 * \return int -1 si hubo errores, [NULL POINTERS] ; 0 si ok
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int error = 1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* pFile = fopen(path, "wb");

		Employee* aux = employee_new();

		int len = ll_len(pArrayListEmployee);

		if(pFile != NULL && aux != NULL)
		{
			for(int i=0; i<len; i++)
			{
				aux = (Employee*) ll_get(pArrayListEmployee, i);

				if(aux != NULL)
				{
					fwrite(aux, sizeof(Employee), 1, pFile);
				}
			}

			error = 0;
		}
		else
		{
			showMessage(ERR91);
		}

		fclose(pFile);

	}

	return error;
}

/** \brief Encuentra un empleado en el array y  devuelve su posicion como índice.
 *
 * \param this Employee* Punter al array de empleados
 * \param id int Numero de ID del empleado
 *
 * \return int -1 si no hubo coincidencia, [NULL POINTER] ; el indice del empleado si ok
 *
 */
int controller_findEmployeeById(LinkedList* this, int id)
{
	int index = -1;

	if(this != NULL)
	{
		//int auxID;
		int len = ll_len(this);
		Employee* aux = NULL;

		for(int i=0; i<len; i++)
		{
			aux = (Employee*) ll_get(this, i);
			if((*(aux)).id == id)
			{
				index = i;
				break;
			}

		}
	}

	return index;
}
