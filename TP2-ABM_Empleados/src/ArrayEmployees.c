#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define sort2 strcmp(list[i].lastName, list[j].lastName) > 0 || ( !strcmp(list[i].lastName, list[j].lastName) && strcmp(list[i].name, list[j].name) > 0 ) || ( !strcmp(list[i].lastName, list[j].lastName) && !strcmp(list[i].name, list[j].name) && list[i].sector > list[j].sector )
#define sort3 strcmp(list[i].lastName, list[j].lastName) < 0 || ( !strcmp(list[i].lastName, list[j].lastName) && strcmp(list[i].name, list[j].name) < 0 ) || ( !strcmp(list[i].lastName, list[j].lastName) && !strcmp(list[i].name, list[j].name) && list[i].sector < list[j].sector )
#define sort4 list[i].sector > list[j].sector || ( list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) > 0 ) || ( list[i].sector == list[j].sector && !strcmp(list[i].lastName, list[j].lastName) && strcmp(list[i].name, list[j].name) > 0 )
#define sort5 list[i].sector < list[j].sector || ( list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) < 0 ) || ( list[i].sector == list[j].sector && !strcmp(list[i].lastName, list[j].lastName) && strcmp(list[i].name, list[j].name) < 0 )

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
        openSlot(list, &index, len);

        if (index == -1)
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

int salaries(Employee* list, int size, float* total, float* average, int* avobeAverage)
{
    int error = -1;
    int counter = 0;
    int aboveCounter = 0;

    if(list != NULL && size > 0 && total != NULL && average != NULL)
    {
        for(int i = 0; i < size; i++)
        {
            if(!list[i].isEmpty)
            {
                *total += list[i].salary;
                counter++;
            }
        }

        *average = *total / counter;

        for(int j = 0; j < size; j++)
        {
            if(!list[j].isEmpty && (list[j].salary > *average) )
            {
                aboveCounter++;
            }
        }

        *avobeAverage = aboveCounter;

        error = 0;
    }

    return error;
}

void swap(Employee* list, int a, int b)
{
    int auxInt;
    float auxFloat;
    char auxString[51];

    strcpy(auxString, list[a].lastName);
    strcpy(list[a].lastName, list[b].lastName);
    strcpy(list[b].lastName, auxString);

    strcpy(auxString, list[a].name);
    strcpy(list[a].name, list[b].name);
    strcpy(list[b].name, auxString);

    auxInt = list[a].id;
    list[a].id = list[b].id;
    list[b].id = auxInt;

    auxFloat = list[a].salary;
    list[a].salary = list[b].salary;
    list[b].salary = auxFloat;

    auxInt = list[a].sector;
    list[a].sector = list[b].sector;
    list[b].sector = auxInt;

    auxInt = list[a].isEmpty;
    list[a].isEmpty = list[b].isEmpty;
    list[b].isEmpty = auxInt;
}


void swap2(Employee* list, int a, int b)
{
	Employee aux;

	aux = list[a];
	list[a] = list[b];
	list[b] = aux;
}


int openSlot(Employee* list, int* index, int len)
{
    int error = -1;

    for(int i=0; i<len; i++)
    {
        if (list[i].isEmpty)
        {
            *index = i;  //FREE INDEX
            error = 0;
            break;
        }
    }

    return error;
}

void showEmployee(Employee emp)
{
    printf("//   %8d %20s %20s        %6.2f        %4d\n", emp.id, emp.name, emp.lastName, emp.salary, emp.sector);
}
