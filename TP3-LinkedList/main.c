#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "interfaz.h"
#include "dataStore.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    int flagDatosCargados = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

    	if( menu(&option) )
        {
        	showMessage(ERR00);
        }

        switch(option)
        {
            case 1:
        		system("cls");
            	if(!flagDatosCargados)
            	{
					if(!controller_loadFromText("data.csv", listaEmpleados))
					{
						showMessage(MSG10);
						flagDatosCargados = 1;
					}
					else
					{
						showMessage(ERR10);
					}
            	}
            	else
            	{
            		showMessage(ERR01);
            	}
            	system("pause");
                break;
            case 2:
            	system("cls");
            	if(!flagDatosCargados)
            	{
					if(!controller_loadFromBinary("data.bin", listaEmpleados))
					{
						showMessage(MSG20);
						flagDatosCargados = 1;
					}
					else
					{
						showMessage(ERR20);
					}
            	}
            	else
				{
					showMessage(ERR01);
				}
            	system("pause");
            	break;
            case 3:
            	system("cls");
            	if(!controller_addEmployee(listaEmpleados))
				{
            		showMessage(MSG30);
				}
				else
				{
					showMessage(ERR30);
				}
            	system("pause");
            	break;
            case 4:
            	system("cls");
            	if(!controller_editEmployee(listaEmpleados))
				{
            		showMessage(MSG40);
				}
				else
				{
					showMessage(ERR40);
				}
            	system("pause");
            	break;
            case 5:
            	system("cls");
            	if(!controller_removeEmployee(listaEmpleados))
				{
            		showMessage(MSG50);
				}
				else
				{
					showMessage(ERR50);
				}
            	system("pause");
            	break;
            case 6:
            	system("cls");
            	if(!controller_ListEmployee(listaEmpleados))
				{

				}
				else
				{
					showMessage(ERR60);
				}
            	system("pause");
            	break;
            case 7:
            	system("cls");
            	if(!controller_sortEmployee(listaEmpleados))
				{

				}
				else
				{
					showMessage(ERR70);
				}
            	system("pause");
            	break;
            case 8:
            	system("cls");
            	if(!controller_saveAsText("data.csv", listaEmpleados))
				{
            		showMessage(MSG80);
				}
				else
				{
					showMessage(ERR80);
				}
            	system("pause");
            	break;
            case 9:
            	system("cls");
            	if(!controller_saveAsBinary("data.bin", listaEmpleados))
				{
            		showMessage(MSG90);
				}
				else
				{
					showMessage(ERR90);
				}
            	system("pause");
            	break;
            default:
            	break;
        }
    }while(option != 10);

    free(listaEmpleados);

    return 0;
}
