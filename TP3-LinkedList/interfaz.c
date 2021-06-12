#include <stdio.h>
#include <stdlib.h>
#include "dataStore.h"
#include "funcionesUTN.h"
#include "interfaz.h"
#include "LinkedList.h"

int menu(int* option)
{
	int error = -1;

	system("cls");
	if(option != NULL)
	{
		printf("//////////////////////////////////////////////////////////////////////////////////////\n");
		printf("//                                                                                  //\n");
		printf("//             MENU                                                                 //\n");
		printf("//                                                                                  //\n");
		printf("//   1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)    //\n");
		printf("//   2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)  //\n");
		printf("//   3. Alta de empleado                                                            //\n");
		printf("//   4. Modificar datos de empleado                                                 //\n");
		printf("//   5. Baja de empleado                                                            //\n");
		printf("//   6. Listar empleados                                                            //\n");
		printf("//   7. Ordenar empleados                                                           //\n");
		printf("//   8. Guardar los datos de los empleados en el archivo data.csv (modo texto)      //\n");
		printf("//   9. Guardar los datos de los empleados en el archivo data.csv (modo binario)    //\n");
		printf("//  10. Salir                                                                       //\n");
		printf("//                                                                                  //\n");
		printf("//////////////////////////////////////////////////////////////////////////////////////\n");

		if ( utn_getInteger(option, "//                                                                                  //\n//    Seleccione una opcion: ", "//                                                                                  //\n//    Error, Reintente...                                                           //\n", 1, 10, 2) )
		{
			showMessage(MSG00);
			*option = 10;
		}

		error = 0;
	}

	return error;
}

int menuSort(int* option, int* order)
{
	int error = -1;

	system("cls");
	if(option != NULL)
	{
		printf("//////////////////////////////////////////////////////////////////////////////////////\n");
		printf("//                                                                                  //\n");
		printf("//             MENU SORT                                                            //\n");
		printf("//                                                                                  //\n");
		printf("//   1. Por Id (por defecto)                                                        //\n");
		printf("//   2. Por Nombre                                                                  //\n");
		printf("//   3. Por Horas Trabajadas                                                        //\n");
		printf("//   4. Por Sueldo                                                                  //\n");
		printf("//   5. Volver al Menu Principal                                                    //\n");
		printf("//                                                                                  //\n");
		printf("//////////////////////////////////////////////////////////////////////////////////////\n");

		if ( utn_getInteger(option, "//                                                                                  //\n//    Seleccione una opcion: ", "//                                                                                  //\n//    Error, Reintente...                                                           //\n", 1, 5, 2) )
		{
			showMessage(MSG00);
			*option = 5;
		}

		if(*option != 5)
		{
			printf("//                                                                                  //\n");
			printf("//    1. Ascendente                                                                 //\n");
			printf("//    2. Descendente                                                                //\n");

			utn_getInteger(order, "//                                                                                  //\n//    Seleccione una opcion: ", "//                                                                                  //\n//    Error, Reintente...                                                           //\n", 1, 2, 2);
		}

		error = 0;
	}

	return error;
}

int ordenarPorId(LinkedList* list, int len)
{
	int error = -1;

	if(list != NULL && len > 0)
	{
		error = 0;
	}

	return error;
}
int ordenarPorNombre(LinkedList* list, int len)
{
	int error = -1;

	if(list != NULL && len > 0)
	{
		error = 0;
	}

	return error;
}
int ordenarPorHorasTrabajadas(LinkedList* list, int len)
{
	int error = -1;

	if(list != NULL && len > 0)
	{
		error = 0;
	}

	return error;
}
int ordenarPorSueldo(LinkedList* list, int len)
{
	int error = -1;

	if(list != NULL && len > 0)
	{
		error = 0;
	}

	return error;
}


void showMessage(const char message[])
{
	printf("//                                                                                  //\n");
	printf("//////////////////////////////////////////////////////////////////////////////////////\n");
	printf("//                                                                                  //\n");
	puts(message);
	printf("//                                                                                  //\n");
	printf("//////////////////////////////////////////////////////////////////////////////////////\n");
}
