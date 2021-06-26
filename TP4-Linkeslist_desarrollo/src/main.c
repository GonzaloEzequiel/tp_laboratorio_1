/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "dataStore.h"


int main(void)
{
	setbuf(stdout,NULL);

//	startTesting(1);  // ll_newLinkedList
//	startTesting(2);  // ll_len
//	startTesting(3);  // getNode - test_getNode
//	startTesting(4);  // addNode - test_addNode
//	startTesting(5);  // ll_add
//	startTesting(6);  // ll_get
//	startTesting(7);  // ll_set
//	startTesting(8);  // ll_remove
//	startTesting(9);  // ll_clear
//	startTesting(10); // ll_deleteLinkedList
//	startTesting(11); // ll_indexOf
//	startTesting(12); // ll_isEmpty
//	startTesting(13); // ll_push
//	startTesting(14); // ll_pop
//	startTesting(15); // ll_contains
//	startTesting(16); // ll_containsAll
//	startTesting(17); // ll_subList
//	startTesting(18); // ll_clone
//	startTesting(19); // ll_sort

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

































