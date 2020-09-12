#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Calculadora.h"

//SE APLICO FORMATO AStyle
void menu()
{
    // DECLARACION DE VARIABLES ENTERAS
    int opcion; //tomo la opcion como un entero numerico como figura en el enunciado
    int primerOperando;
    int segundoOperando;

    // DECLARACION Y ASIGNACION DE BANDERAS Y CONFIRMACIONES
    char banderaPrimerOperando = 'n';
    char banderaSegundoOperando = 'n';
    char banderaOperaciones = 'n';
    char confirmacionSalida = 'n';

    //  MENU OPERATIVO Y OPCIONES
    do
    {
        system("cls");

        // MUESTRO OPERADORES ASIGADOS SI LOS HAY
        if(banderaPrimerOperando == 's')
        {
            printf("Primer Operando: %d\n",  primerOperando);
        }
        if(banderaSegundoOperando == 's')
        {
            printf("Segundo Operando: %d\n\n",  segundoOperando);
        }

        // MENU DE OPCIONES
        printf("\n* MENU DE OPCIONES *\n\n"
               "1. Ingresar 1er operando\n"
               "2. Ingresar 2do operando\n"
               "3. Calcular todas las operaciones\n"
               "4. Informar resultados\n"
               "5. Salir\n\n");

        printf("Seleccione una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
        fflush(stdin);


        // ACCESO A OPCIONES LISTADAS
        switch(opcion)
        {
        case 1:
            if(banderaPrimerOperando == 'n')//ingresa operando1 y activa bandera
            {
                primerOperando = ingresarOperando();
                banderaPrimerOperando = 's';
            }
            else//en caso de operando1 ya ingresado (flag positiva)
            {
                if(sobreescribir() == 's')
                {
                   primerOperando = ingresarOperando();
                }
                else
                {
                    break;
                }
            }

            break;

        case 2:
            if(banderaPrimerOperando == 's')//en caso de operando1 ya ingresado (flag positiva)
            {
                if(banderaSegundoOperando == 'n')//ingresa operando2 y activa bandera
                {
                    segundoOperando = ingresarOperando();
                    banderaSegundoOperando = 's';
                }
                else//en caso de operando2 ya ingresado (flag positiva)
                {
                    if(sobreescribir() == 's')
                    {
                        segundoOperando = ingresarOperando();
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else//en caso de operando1 no ingresado (flag negativa)
            {
                alerta1();
            }
            break;

        case 3:
            if(banderaPrimerOperando == 's')
            {
                if(banderaSegundoOperando == 's')
                {
                    operaciones();
                    banderaOperaciones = 's';
                }
                else//en caso de operando2 no ingresado (flag negativa)
                {
                    alerta2();
                }
            }
            else if(banderaSegundoOperando == 's')//en caso de operando1 no ingresado (flag negativa)
            {
                alerta1();
            }
            else//en caso de ambas flag negativas, no puede operar sin operandos
            {
                alerta3();
            }
            break;

        case 4:
            if(banderaOperaciones == 's')//si ya hizo las operaciones puede mostrarlas
            {
                resultados(primerOperando, segundoOperando);

                banderaPrimerOperando = 'n'; //se borran los operandos almacenados y las operaciones, resetea
                banderaSegundoOperando = 'n';
                banderaOperaciones = 'n';
            }
            else//aun no se han hecho las operaciones, nada para mostrar
            {
                alerta4();
            }
            break;

        case 5:
            printf("\nSeguro desea salir? s/n\n");
            confirmacionSalida = tolower(getch());
            break;

        default://si se elige opcion no listada
            printf("\n** ERROR, OPCION NO VALIDA **\n");
            system("pause");
        }
    }
    while(confirmacionSalida !='s');
}

void operaciones()
{
    system("cls");

    printf("* Realizando Operaciones * \n\n");//MUESTRA LAS OPERACIONES QUE SE ESTAN EFECTUANDO
    printf("a) Calcular la suma (A+B)\n");
    printf("b) Calcular la resta (A-B)\n");
    printf("c) Calcular la division (A/B)\n");
    printf("d) Calcular la multiplicacion (A*B)\n");
    printf("e) Calcular el factorial (A!), (B!)\n\n");

    system("pause");
}

void resultados(int num1, int num2)
{
    system("CLS");

    printf("A = %d\n", num1);
    printf("B = %d\n\n", num2);

    printf("** RESULTADOS **\n\n");
    printf("a) El resultado de A+B es: %d\n", suma(num1,num2));
    printf("b) El resultado de A-B es: %d\n", resta(num1,num2));

    // VERIFICACION DE ERROR DIVISION POR CERO
    if(num2==0)
    {
        printf("c) No es posible dividir por CERO (error mat.)\n");
    }
    else
    {
        printf("c) El resultado de A/B es: %.2f\n", division(num1,num2));
    }

    printf("d) El resultado de A*B es:  %d\n", producto(num1,num2));

    // VERIFICACION DE ERROR FACTORIAL DE UN NUMERO 'NO NATURAL'
    if(num1 < 0)
    {
        printf("e) El numero A es negativo, no se puede calcular su factorial, ");
    }
    else
    {
        printf("e) El factorial de A es: %I64u, ", factorial(num1));
    }
    if(num2 < 0)
    {
        printf("y El numero B es negativo, no se puede calcular su factorial.\n\n\n");
    }
    else
    {
        printf("y El factorial de B es: %I64u \n\n\n", factorial(num2));
    }

    printf("PESIONE UNA TECLA PARA VOLVER AL INICIO ");
    getch();
}

void alerta1()
{
    printf("\n!!ATENCION!! Aun no se ha cargado el 1er operando\n\n");
    system("pause");
}

void alerta2()
{
    printf("\n!!ATENCION!! Aun no se ha cargado el 2do operando\n\n");
    system("pause");
}

void alerta3()
{
    printf("\n!!ATENCION!! Aun no se han ingresado los operandos!!\n\n");
    system("pause");
}

void alerta4()
{
    printf("\n!!ATENCION!! Aun no se han realizado las Operaciones \n\n");
    system("pause");
}

void creditos()
{
    system("cls");

    system("COLOR 02");

    printf("      ************************    \n");
    printf("      **  CALCULADORA v1.0  **    \n");
    printf("      ************************  \n\n");
    printf("             __________           \n");
    printf("            | ________ |          \n");
    printf("            ||12345678||          \n");
    printf("            | -------- |          \n");
    printf("            |[M|#|C][-]|          \n");
    printf("            |[7|8|9][+]|          \n");
    printf("            |[4|5|6][x]|          \n");
    printf("            |[1|2|3][%%]|         \n");
    printf("            |[.|O|!][=]|          \n");
    printf("            '----------'          \n");
    printf("                                \n\n");
    printf("      _ _ _ _   _ _ _ _  _ _ _ _  \n");
    printf("     /  _ _ _/ / _ _ _/ / _ _  /  \n");
    printf("    / /  _ _  / /__    / /__/ /   \n");
    printf("   / / /_  / / _ _/   / _ _ _/    \n");
    printf("  / /_ _/ / / /_ _   / /          \n");
    printf(" /_ _ _ _/ /_ _ _ / /_/  (R)\n\n\n\n");
}

char sobreescribir()
{
    char confirmacion;

    while(confirmacion != 's' && confirmacion != 'n')
    {
        printf("\n!!ATENCION!! Operando ya ingresado. Desea sobrescribirlo? s/n\n");
        confirmacion = tolower(getch());
    }

    return confirmacion;
}

int ingresarOperando()
{
    int operando;

    system("cls");
    printf("Ingresar Operando: ");
    scanf("%d", &operando);

    return operando;
}

int suma(int num1, int num2)
{
    int resultado;

    resultado = num1 + num2;

    return resultado;
}

int resta(int num1, int num2)
{
    int resultado;

    resultado = num1 - num2;

    return resultado;
}

int producto(int num1, int num2)
{
    int resultado;

    resultado = num1 * num2;

    return resultado;
}

float division(int num1, int num2)
{
    float resultado;

    resultado = (float) num1 / num2;

    return resultado;
}

long long int factorial(int num)
{
    int i;
    long long int resultado = 1;

    for(i = 1; i <= num; i++)
    {
        resultado = resultado * i;
    }

    return resultado;
}
