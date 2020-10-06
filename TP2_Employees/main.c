#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <conio.h>
#include "ArrayEmployees.h"

#define LEN 1000

//SE APLICO FORMATO AStyle
int main()
{
    credits(); //OPENING CREDITS
    system("pause");

    Employee list[LEN]; //VAR DECLARATION

    system("cls");
    if( !initEmployees(list, LEN) ) //FORMATING THE EMPLOYEE ARRAY
    {
        printf("EMPLOYEES INITIALIZED SUCCESFULY\n\n");
    }
    else
    {
        printf("ERROR INITIALIZING EMPLOYEES\n\n");
    }
    system("pause");

    menu(list, LEN); //MAIN MENU

    credits();
    printf("2020 Cuarentena Studios, All Rights Reserved"); //MISC

    return 0;
}
