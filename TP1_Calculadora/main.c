/*
        TRABAJO PRACTICO N°1 CALCULADORA

        PEREZ GONZALO EZEQUIEL 1°G
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Calculadora.h"

int main()
{
    creditos();
    printf("Presione Cualquier Tecla Para Iniciar");
    getch();

    menu();

    creditos();
    printf("Todos los derechos reservados");

    return 0;
}
