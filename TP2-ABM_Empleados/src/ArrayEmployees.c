#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

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
        	printf("//SYSTEM COMPLETE, NO OPEN SLOT FOR NEW EMPLOYEE//\n");
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
        else
        {
            printf("\nERROR REMOVING EMPLOYEE\n"); //IF SOMETHING GOES WRONG
        }
    }

    return error;
}


int sortEmployees(Employee* list, int len, int order)
{
    int error = -1;

    if( list != NULL && len > 0)
    {
        error = 0;
        switch(order) //I STATED 4 CRITERIA
        {
        case '1':
            for (int i=0; i<len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if( strcmp(list[i].lastName, list[j].lastName) > 0 || ((!strcmp(list[i].lastName, list[j].lastName) ) && list[i].name < list[j].name) )
                    {
                        swap(list, i, j);
                    }
                }
            }
            break;

        case '2':
            for (int i=0; i<len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if( strcmp(list[i].lastName, list[j].lastName) < 0 || ((!strcmp(list[i].lastName, list[j].lastName) ) && list[i].name < list[j].name) )
                    {
                        swap(list, i, j);
                    }
                }
            }
            break;

        case '3':
            for (int i=0; i<len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if(list[i].sector > list[j].sector || (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) < 0 )  )
                    {
                        swap(list, i, j);
                    }
                }
            }
            break;

        case '4':
            for (int i=0; i<len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if(list[i].sector < list[j].sector || (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) < 0 ) )
                    {
                        swap(list, i, j);
                    }
                }
            }
            break;

        case '5':
            break;
        default:
            printf("NON VALID OPTION\n");
            break;
        }
    }

    return error;
}


int printEmployees(Employee* list, int length)
{
    int flag = 0;

    printf("   ID             NAME              LASTNAME              SALARY        SECTOR 		    \n");
    printf(" -------------------------------------------------------------------------------    	\n");

    for(int i=0; i<length; i++)
    {
        if(!list[i].isEmpty)
        {
            showEmployee(&list[i]);
            flag = 1;
        }
    }

    if(!flag)
    {
        system("cls");
        printf("THERE ARE NO EMPLOYEES REGISTERED");
    }

    printf("\n\n");

    return 0;
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

void showEmployee(Employee* list)
{
    printf("//   %8d %20s %20s        %6.2f        %4d\n", list->id, list->name, list->lastName, list->salary, list->sector);
}
