#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int openSlot(Employee* list, int* index, int len)
{
    int error = -1;

    if(list != NULL && index != NULL && len > 0)
    {
    	for(int i=0; i<len; i++)
		{
			if (list[i].isEmpty)
			{
				*index = i;  //FREE INDEX
				error = 0;
				break;
			}
		}
    }

    return error;
}


void showEmployee(Employee emp)
{
    printf("//   %8d %20s %20s        %7.2f        %4d\n", emp.id, emp.name, emp.lastName, emp.salary, emp.sector);
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

void swap2(Employee* list, int a, int b)
{
	Employee aux;

	aux = list[a];
	list[a] = list[b];
	list[b] = aux;
}
