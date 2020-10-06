#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <conio.h>
#include "ArrayEmployees.h"

#define LEN 1000

int initEmployees(Employee* list, int len)
{
    int error = -1;

    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1; //FORMATS ARRAY
        }

        error = 0;
    }

    return error;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int error = -1;
    int index;

    Employee newEmployee;

    if(list != NULL && len > 0 && id > 0)
    {
        index = openSlot(list, len);

        if (index == -1)
        {
            printf("SYSTEM COMPLETE, NO OPEN SLOT FOR NEW EMPLOYEE\n");
        }
        else
        {
            newEmployee.id = id;
            strcpy(newEmployee.name, name);
            strcpy(newEmployee.lastName, lastName);
            newEmployee.salary = salary;
            newEmployee.sector = sector;
            newEmployee.isEmpty = 0;

            list[index] = newEmployee; //ENTER ESTRIES AS STRUCT INDEX
            error = 0;
        }
    }

    return error;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int index = -1;

    for(int i=0; i<len; i++)
    {
        if(list[i].id == id && !list[i].isEmpty)
        {
            index = i;
            break;
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

int openSlot(Employee* list, int len)
{
    int index = -1;

    for(int i=0; i<len; i++)
    {
        if (list[i].isEmpty)
        {
            index = i;  //FREE INDEX
            break;
        }
    }

    return index;
}

int stringFormat(char string[], int len)
{
    int error = 0;

    string[0] = toupper(string[0]); //NAME/LASTNAME INITIAL AS CAPITAL LETTER

    for(int i=0; i<len; i++)
    {
        if( isdigit(string[i]) )
        {
            error = -1;
            break;
        }

        if( isspace (string[i-1]) )
        {
            string[i] = toupper(string[i]); //2ND NAME/LASTNAME INITIAL AS CAPITAL LETTER
        }
    }

    return error;
}

int floatFormat(char string[], int len)
{
    int error = 0;
    int format = 0;
    float number;

    for(int i=0; i<len; i++)
    {
        if( (string[i] < '0' || string[i] > '9') && string[i] != '.' ) //CHECKS STRING FOR NON NUMERIC CHARS AND DOT
        {
            error = -1;
            break;
        }
        else if(string[i] == '.')
        {
            format++;
        }

        if(format > 1)
        {
            error = -1;
            break;
        }
    }

    number = atof (string);

    if (number < 0)
    {
        error = -1;
    }

    return error;
}

int integerFormat(char string[], int len)
{
    int error = 0;
    int number;

    for(int i=0; i<len; i++)
    {
        if( string[i] < '0' || string[i] > '9' ) //CHECKS STRING FOR NON NUMERIC CHARS
        {
            error = -1;
            break;
        }
    }

    number = atoi (string);

    if (number < 0)
    {
        error = -1;
    }

    return error;
}

int getInteger(char vec[], char vec2[])
{
    int number;

    while(integerFormat(vec, strlen(vec)) != 0)
    {
        printf("\nERROR, '%s' MUST BE A NUEMERIC ENTRY. RE-ENTRY: ", vec2);
        gets(vec);
    }

    number = atoi(vec);

    return number;
}

int avobeAverage(Employee* list, int len, float average)
{
    int counter = 0;

    for(int i=0; i<len; i++)
    {
        if( list[i].salary >= average )
        {
            counter++;
        }
    }

    return counter;
}




float getFloat(char vec[], char vec2[])
{
    float number;

    while(floatFormat(vec, strlen(vec)) != 0)
    {
        printf("\nERROR, '%s' MUST BE A NUEMERIC ENTRY. RE-ENTRY: ", vec2);
        gets(vec);
    }

    number = atof(vec);

    return number;
}

float totalSalaries(Employee* list, int len)
{
    float totalSalary = 0;

    for(int i=0; i<len; i++)
    {
        totalSalary = totalSalary + list[i].salary;
    }

    return totalSalary;
}

float averageSalary(Employee* list, int len)
{
    int counter = 0;

    float average;
    float totalSalary = 0;

    for(int i=0; i<len; i++)
    {
        if(!list[i].isEmpty)
        {
            counter++;
        }

        totalSalary = totalSalary + list[i].salary;
    }

    average = (float) totalSalary / counter;

    return average;
}




void menu(Employee* list, int len)
{
    //VAR DECLARATIONS
    Employee aux;

    //int auxIndex;
    int auxInt;
    int nextID = 20000;

    float auxFloat;
    float auxFloat2;

    char auxString[51];

    char option;
    char confirm;
    char subConfirm;
    char sure;
    char flagEmployee = 'N';

    do
    {
        confirm = 'N';

        system("cls");

        printf("		*** MAIN MENU ***		          \n\n");
        printf("1. REGISTRATE NEW EMPLOYEES 				\n");
        printf("2. MODIFY EMPLOYEE 							\n");
        printf("3. WITHDRAW EMPLOYEE 						\n");
        printf("4. LIST EMPLOYEES 							\n");
        printf("5. EXIT							   		  \n\n");
        printf("SELECT OPTION: ");
        option = getch();

        switch(option)
        {
        case '1':
            //NEW ENTRY INPUTS
            system("cls");

            printf("ASSIGNED ID: %d\n", nextID);

            printf("\nNAME: ");
            gets(aux.name);
            getString(aux.name, "NAME");

            printf("\nLASTNAME: ");
            gets(aux.lastName);
            getString(aux.lastName, "LASTNAME");

            printf("\nSALARY: ");
            gets(auxString);
            aux.salary = getFloat(auxString, "SALARY");

            printf("\nSECTOR: ");
            gets(auxString);
            aux.sector = getInteger(auxString, "SECTOR");

            if( !addEmployee(list, LEN, nextID, aux.name, aux.lastName, aux.salary, aux.sector) )
            {
                //SHOWING NEW ENTRY IN LIST
                header( list, "\nEMPLOYEE SUCCESFULY REGISTRATED\n", findEmployeeById (list, LEN, nextID) );

                nextID++;
                flagEmployee = 'Y';
                printf("\n\n");
                system("pause");


            }
            else
            {
                printf("PLEASE CONTACT YOUR SYSTEM ADMINISTRATOR");
            }
            break;

        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

        case '2':
            system("cls");

            if(flagEmployee == 'N')
            {
                printf("THERE ARE NO EMPLOYEES REGISTERED\n\n");
                system("pause");
                break;

            }

            //MODIFYING PREVIOUS ENTRIES
            printf("				*** MODIFY EMPLOYEE ***\n\n");
            printf("ENTER EMPLOYEE ID NUMBER: ");
            gets(auxString);
            aux.id = getInteger(auxString, "ID");

            do
            {
                sure = 'N';
                subConfirm = 'N';

                system("cls");

                //SHOWING MATCHING ENTRY
                header(list, "\nMATCHING EMPLOYEE:\n\n", findEmployeeById (list, LEN, aux.id));

                if(findEmployeeById (list, LEN, aux.id) == -1)
                {
                    printf("NO MATCHES\n\n");
                    system("pause");
                    break;
                }

                //MODIFICATION MENU
                printf("\n\n 	*** SELECT FIELD TO MODIFY ***\n");
                printf("1. NAME 		\n");
                printf("2. LASTNAME 	\n");
                printf("3. SALARY 		\n");
                printf("4. SECTOR 		\n");
                printf("5. EXIT 	  \n\n");
                option=getch();


                switch(option)
                {
                case '1':
                    printf("ACTUAL VALUE FOR FIELD 'NAME': ");                                                                  /* HUBIERA QUERIDO OPTIMIZAR MEJOR      */
                    puts(list[findEmployeeById (list, LEN, aux.id)].name);                                                      /* ESTA PARTE DE LA OPCION(2) DE MENU   */
                    printf("\nENTER NEW VALUE FOR FIELD 'NAME': ");
                    fflush(stdin);
                    gets(aux.name);
                    getString(aux.name, "NAME");
                    printf("\n\nTHIS ACTION WILL REPLACE '%s' FOR '%s'\n", list[findEmployeeById (list, LEN, aux.id)].name, aux.name);
                    printf("PROCEED WITH MODIFICATION? Y/N ");
                    sure = toupper(getche());
                    if(sure == 'Y')
                    {
                        strcpy(list[findEmployeeById (list, LEN, aux.id)].name, aux.name);
                    }
                    break;

                case '2':
                    printf("ACTUAL VALUE FOR FIELD 'LASTNAME': ");
                    puts(list[findEmployeeById (list, LEN, aux.id)].lastName);
                    printf("\nNEW VALUE FOR FIELD 'LASTNAME': ");
                    fflush(stdin);
                    gets(aux.lastName);
                    while(stringFormat(aux.lastName, strlen(aux.name)) != 0)
                    {
                        printf("\nINVALID LASTNAME, RE-ENTRY: ");
                        gets(aux.lastName);
                    }

                    printf("\n\nTHIS ACTION WILL REPLACE '%s' FOR '%s'\n", list[findEmployeeById (list, LEN, aux.id)].lastName, aux.lastName);
                    printf("PROCEED WITH MODIFICATION? Y/N ");
                    sure = toupper(getche());
                    if(sure == 'Y')
                    {
                        strcpy(list[findEmployeeById (list, LEN, aux.id)].lastName, aux.lastName);
                    }
                    break;

                case '3':
                    printf("ACTUAL VALUE FOR FIELD 'SALARY': %5.2f\n\n", list[findEmployeeById (list, LEN, aux.id)].salary);
                    printf("NEW VALUE FOR FIELD 'SALARY': ");
                    scanf("%f", &aux.salary);
                    printf("\n\nTHIS ACTION WILL REPLACE '%5.2f' FOR '%5.2f'\n", list[findEmployeeById (list, LEN, aux.id)].salary, aux.salary);
                    printf("PROCEED WITH MODIFICATION? Y/N ");
                    sure = toupper(getche());
                    if(sure == 'Y')
                    {
                        list[findEmployeeById (list, LEN, aux.id)].salary = aux.salary;
                    }
                    break;

                case '4':
                    printf("ACTUAL VALUE FOR FIELD 'SECTOR': %4d\n\n", list[findEmployeeById (list, LEN, aux.id)].sector);
                    printf("NEW VALUE FOR FIELD 'SECTOR': ");
                    scanf("%d", &aux.sector);
                    printf("\n\nTHIS ACTION WILL REPLACE '%d' FOR '%d'\n", list[findEmployeeById (list, LEN, aux.id)].sector, aux.sector);
                    printf("PROCEED WITH MODIFICATION? Y/N ");
                    sure = toupper(getche());
                    if(sure == 'Y')
                    {
                        list[findEmployeeById (list, LEN, aux.id)].sector = aux.sector;
                    }
                    break;

                case '5':
                    printf("BACK TO MAIN MENU? Y/N ");
                    subConfirm = toupper(getche());
                    break;

                default:
                    printf("INVALID OPTION, PLEASE REENTER");
                    system("pause");
                    break;
                }

            }
            while(subConfirm != 'Y');
            break;

        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

        case '3':
            system("cls");

            if(flagEmployee == 'N')
            {
                printf("THERE ARE NO EMPLOYEES REGISTERED\n\n");
                system("pause");
                break;

            }

            //REMOVE ENTRY
            printf("				*** WITHDRAW EMPLOYEE *** 	\n\n");
            printf("ENTER EMPLOYEE ID NUMBER: ");
            gets(auxString);
            aux.id = getInteger(auxString, "ID");

            //SHOWING MATCHING ENTRY
            header(list, "MATCHING EMPLOYEE: \n\n",  findEmployeeById(list, LEN, aux.id));

            if(findEmployeeById (list, LEN, aux.id) == -1)
            {
                printf("NO MATCHES\n\n");
                system("pause");
                break;
            }

            do
            {
                subConfirm = 'N';

                //REMOVAL MENU
                printf("\n\n    *** WITHDRAW MENU ***\n");
                printf("1. REMOVE EMPLOYEE \n");
                printf("2. CANCEL \n\n");
                option = getch();

                switch(option)
                {
                case '1':
                    printf("\nCONFIRM TO REMOVE EMPLOYEE Y/N "); //VERIFICATION TO REMOVE
                    subConfirm = toupper(getche());
                    if (subConfirm == 'Y')
                    {
                        if(!removeEmployee(list, LEN, aux.id))
                        {
                            system("cls");
                            printf("SUCCESFUL WITHDRAW\n"); //OK TO REMOVE MESSAGE
                            system("pause");
                        }
                        else
                        {
                            printf("PLEASE CONTACT YOUR SYSTEM ADMINISTRATOR\n"); //SOMETHING HAPPENED
                            system("pause");
                        }
                    }
                    break;

                case '2':
                    printf("BACK TO MAIN MENU? Y/N ");
                    subConfirm = toupper(getche());
                    break;

                default:
                    printf("INVALID OPTION, PLEASE REENTER");
                    system("pause");
                    break;
                }

            }
            while(subConfirm != 'Y');
            break;

        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

        case '4':
            system ("cls");

            if(flagEmployee == 'N')
            {
                printf("THERE ARE NO EMPLOYEES REGISTERED\n\n");
                system("pause");
                break;
            }

            do
            {
                subConfirm = 'N';

                system("cls");

                printEmployees(list, LEN);

                auxFloat = totalSalaries(list, LEN);                            /*NO FUNCIONA:                          */
                printf("\nTOTAL SALARIES: %.2f\n", auxFloat);                   /*LA MUESTRA DE SALARIOS TOTATLES       */
                /*                                      */
                auxFloat2 = averageSalary(list, LEN);                           /*                                      */
                printf("AVERAGE SALARY: %.2f\n", auxFloat2);                    /*LA MUESTRA DE SALARIO PROMEDIO        */
                /*                                      */
                auxInt = avobeAverage(list, LEN, auxFloat2);                    /*LA MUESTRA DE CANTIDAD DE EMPLEADOS   */
                printf("EMPLOYEES AVOBE AVERAGE SALARY: %d\n\n", auxInt);       /*QUE SUPERAN EL SALARIO PROMEDIO       */

                //2 SORT, PUES INTERPRETE ASI EL ENUNCIADO
                printf("    *** SORT EMPLOYEES BY LASTNAME *** 	\n");
                printf("1. UPWARD\n");
                printf("2. DOWNWARD\n");
                printf("    *** SORT EMPLOYEES BY SECTOR *** 	\n");
                printf("3. UPWARD\n");
                printf("4. DOWNWARD\n\n");
                printf("5. EXIT\n\n");
                option = getch();
                sortEmployees(list, LEN, option);
                printEmployees(list, LEN);


            }
            while(option != '5');
            break;

        //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

        case '5':
            printf("\n\nARE YOU SURE YOU WANT TO EXIT? Y/N ");
            confirm = toupper(getche());
            break;

        default:
            printf("PLEASE SELECT A VALID OPTION: ");
            option = getch();
            break;
        }

    }
    while(confirm != 'Y');
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

void getString(char vec[], char vec2[])
{
    while(stringFormat(vec, strlen(vec)) != 0)
    {
        printf("\nINVALID %s, RE-ENTRY: ", vec2);
        gets(vec);
    }
}

void header(Employee* list, char title[], int  id)
{
    puts(title);

    printf("   ID             NAME              LASTNAME              SALARY        SECTOR 		    \n");
    printf(" -------------------------------------------------------------------------------    	\n");

    showEmployee(&list[id]);
}

void showEmployee(Employee* list)
{
    printf("  %4d %20s %20s        %6.2f        %04d\n", list->id, list->name, list->lastName, list->salary, list->sector);
}

void credits()
{
    system("cls");

    system("COLOR 02");

    printf("     ************************     \n");
    printf("     **   EMPLOYEES v1.0   **     \n");
    printf("     ************************     \n");
    printf("                                  \n");
    printf("  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  \n");
    printf("  @@@                   @ @@@@@@  \n");
    printf("  @@@  @@@@@@           @  @@@@@  \n");
    printf("  @@@                   @,,,@@@@  \n");
    printf("  @@@  @@@@@@                @@@  \n");
    printf("  @@@                        @@@  \n");
    printf("  @*@            @@@@@@@@@@@@@*@  \n");
    printf("  @*@@@@@@@@@@@@@,,,,,,,,,,,,,,@  \n");
    printf("  @,,,,,,,,,,,,,,,,,,,,,,,,,,,,@  \n");
    printf("  @,,,,,,,,,,,,,,,,,,,,,,,,,,,,@  \n");
    printf("  @,,,,,@@@@@@@@@@@@@@@@@@,,,,,@  \n");
    printf("  @,,,,@**//**//**//**//**@,,,,@  \n");
    printf("  @,,,,@**//**//**//**//**@,,,,@  \n");
    printf("  @,,,,,@@@@@@@@@@@@@@@@@@,,,,,@  \n");
    printf("  @,,,,,,,,,,,,,,,,,,,,,,,,,,,,@  \n");
    printf("  @,,,,,,,,,,,,,,,,,,,,,,,,,,,,@  \n");
    printf("  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  \n");
    printf("                                  \n");
    printf("      _ _ _ _   _ _ _ _  _ _ _ _  \n");
    printf("     /  _ _ _/ / _ _ _/ / _ _  /  \n");
    printf("    / /  _ _  / /__    / /__/ /   \n");
    printf("   / / /_  / / _ _/   / _ _ _/    \n");
    printf("  / /_ _/ / / /_ _   / /          \n");
    printf(" /_ _ _ _/ /_ _ _ / /_/  (R)    \n\n");

}
