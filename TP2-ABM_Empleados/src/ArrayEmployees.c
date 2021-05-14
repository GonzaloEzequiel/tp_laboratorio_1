#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defines.h"
#include "ArrayEmployees.h"
#include "OtherEmployeesFunctions.h"


int initEmployees(Employee* list, int len)
{
    int error = -1;

    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }

        error = 0;
    }

    return error;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int error = -1;
    int index = -1;

    Employee newEmployee;

    if(list != NULL && len > 0)
    {        
        if ( openSlot(list, &index, len)== -1)
        {
        	printf("//\n//  SYSTEM FULL, NO OPEN SLOT FOR NEW EMPLOYEE  //\n//");
        }
        else
        {
        	newEmployee.id = id;
			strcpy(newEmployee.name, name);
			strcpy(newEmployee.lastName, lastName);
			newEmployee.salary = salary;
			newEmployee.sector = sector;
			newEmployee.isEmpty = 0;

			list[index] = newEmployee; //ENTER ENTRIES AS STRUCT INDEX

			error = 0;
        }
    }

    return error;
}

int findEmployeeById(Employee* list, int len, int id)
{
    int index = -1;

    if(list != NULL && len > 0)
    {
    	for(int i=0; i<len; i++)
		{
			if(list[i].id == id && !list[i].isEmpty)
			{
				index = i;
				break;
			}
		}
    }

    return index;
}

int removeEmployee(Employee* list, int len, int id)
{
    int error = -1;
    int index;

    if (list != NULL && len > 0)
    {
        index = findEmployeeById(list, len, id);

        if(index != -1)
        {
            list[index].isEmpty = 1;
            error = 0;
        }
    }

    return error;
}

int sortEmployees(Employee* list, int len, int order)
{
    int error = -1;

    if( list != NULL && len > 0)
    {
    	switch(order)
		{
    		case 1:
    		for (int i=0; i<len-1; i++)
			{
				for(int j=i+1; j<len; j++)
				{
					if(list[i].id > list[j].id)
					{
						swap2(list, i, j);
					}
				}
			}
    			break;

			case 2:
				for (int i=0; i<len-1; i++)
				{
					for(int j=i+1; j<len; j++)
					{
						if(sort2)
						{
							swap2(list, i, j);
						}
					}
				}
				break;

			case 3:
				for (int i=0; i<len-1; i++)
				{
					for(int j=i+1; j<len; j++)
					{
						if(sort3)
						{
							swap2(list, i, j);
						}
					}
				}
				break;

			case 4:
				for (int i=0; i<len-1; i++)
				{
					for(int j=i+1; j<len; j++)
					{
						if(sort4)
						{
							swap2(list, i, j);
						}
					}
				}
				break;

			case 5:
				for (int i=0; i<len-1; i++)
				{
					for(int j=i+1; j<len; j++)
					{
						if(sort5)
						{
							swap2(list, i, j);
						}
					}
				}
				break;

			default:
				break;
		}

        error = 0;
    }

    return error;
}

int printEmployees(Employee* list, int length)
{
	int error = -1;

	if(list != NULL && length > 0)
	{
		printf("//                                                \n");
		printf("//      ID               NAME             LASTNAME              SALARY        SECTOR 	   \n");
		printf("//  -----------------------------------------------------------------------------------    \n");


		for(int i=0; i<length; i++)
		{
			if(!list[i].isEmpty)
			{
				showEmployee(list[i]);
			}
		}

		error = 0;
	}

    return error;
}
