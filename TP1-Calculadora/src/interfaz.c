#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "interfaz.h"
#include "calculos.h"


void interfaz()
{
	float primerOperando;
	float segundoOperando;

	int flagPrimerOperando = 0;
	int flagSegundoOperando = 0;
	int flagAmbosOperandos = 0;
	int flagOperaciones = 0;
	int opcion;
	char salir = 'n';

	float suma;
	float resta;
	float division;
	float producto;
	long long int factorial1 = 1;
	long long int factorial2 = 1;

	do
	{
		menuPrincipal( &opcion, &primerOperando, &segundoOperando, flagPrimerOperando, flagSegundoOperando);

		switch(opcion)
		{
		case 1:
			if( !ingresarOperando(&primerOperando, flagPrimerOperando) )
			{
				flagPrimerOperando = 1;
			}
			else
			{
				printf("Se cancelo la sobreescritura del 1er operando.\n");
				system("pause");
			}
			break;

		case 2:
			if(flagPrimerOperando)//en caso de operando1 ya ingresado (flag positiva)
			{
				if( !ingresarOperando(&segundoOperando, flagSegundoOperando) )
				{
					flagSegundoOperando = 1;
				}
				else
				{
					printf("Se cancelo la sobreescritura del 2do operando.\n");
					system("pause");
				}
			}
			else//en caso de operando1 no ingresado (flag negativa)
			{
				alerta1();
			}
			break;

		case 3:
			if(flagAmbosOperandos)
			{
				operaciones(&primerOperando, &segundoOperando, &suma, &resta, &producto, &division, &factorial1, &factorial2, flagAmbosOperandos);
				flagOperaciones = 1;
			}
			else if(flagPrimerOperando)
			{
				alerta2();
			}
			else
			{
				alerta3();
			}
			break;

		case 4:
			if(flagOperaciones)//si ya hizo las operaciones puede mostrarlas
			{
				resultados(&primerOperando, &segundoOperando, &suma, &resta, &producto, &division, &factorial1, &factorial2, flagAmbosOperandos);

				flagPrimerOperando = 0; //permite la carga de nuevos operandos
				flagSegundoOperando = 0;
				flagOperaciones = 0;
			}
			else//aun no se han hecho las operaciones, nada para mostrar
			{
				alerta4();
			}
			break;

		case 5:
			printf("\nDesea salir? s/n\n");
			scanf("%c", &salir);
			salir = tolower(getche());
			break;

		default://si se elige opcion no listada
			printf("\n** ERROR, OPCION NO VALIDA **\n");
			system("pause");
			break;
		}

		if(flagPrimerOperando && flagSegundoOperando)
		{
			flagAmbosOperandos = 1;
		}

	}while(salir != 's');

}


void menuPrincipal(int* opcion, float* x, float* y, int flagX, int flagY)
{
	system("cls");

		printf("//////////////////////////////////////////////\n");
		printf("//                                          //\n");
		printf("//              MENU PRINCIPAL              //\n");
		printf("//                                          //\n");

	if(flagX)
	{
		printf("//  1. Ingresar 1er operando (A= %f)          \n", *x);
	}
	else
	{
		printf("//  1. Ingresar 1er operando (A= x)         //\n");
	}

	if(flagY)
	{
		printf("//  2. Ingresar 2do operando (B= %f)          \n", *y);
	}
	else
	{
		printf("//  2. Ingresar 2er operando (B= y)         //\n");
	}

		printf("//  3. Calcular todas las operaciones       //\n");
		printf("//  4. Informar resultados                  //\n");
		printf("//  5. Salir                                //\n");
		printf("//                                          //\n");
		printf("//////////////////////////////////////////////\n\n");

	printf("Seleccione una opcion: ");
	scanf("%d", opcion);
}


int ingresarOperando(float* num, int flag)
{
    int error = 0;

    system("cls");

    if(!flag || (flag && sobreescribir() ) )
    {
		printf("Ingresar Operando: ");
		scanf("%f", num);
		printf("Operando ingresado con exito.\n");
    }
	else
	{
		error = 1;
	}

    system("pause");
    return error;
}


int sobreescribir()
{
	int confirmacion = 0;
    char respuesta;

    while(respuesta != 's' && respuesta != 'n')
    {
        printf("\n!!ATENCION!! Operando ya ingresado. Desea sobrescribirlo? s/n\n");
        fflush(stdin);
        respuesta = tolower(getch());
    }

    if(respuesta == 's')
    {
    	confirmacion = 1;
    }

    return confirmacion;
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


void operaciones(float* num1, float* num2, float* resSuma, float* resResta, float* resProducto, float* resDivision, long long int* resFact1,long long int* resFact2, int flags)
{
    system("cls");
		//MUESTRA LAS OPERACIONES QUE SE EFECTUARAN
		printf("//////////////////////////////////////////////\n");
		printf("//                                          //\n");
		printf("//         REALIZANDO OPERACIONES           //\n");
		printf("//                                            \n");
		printf("//  a) Calcular la suma (%f+%f)               \n", *num1, *num2);
		printf("//  b) Calcular la resta (%f-%f)              \n", *num1, *num2);
		printf("//  c) Calcular la division (%f/%f)           \n", *num1, *num2);
		printf("//  d) Calcular la multiplicacion (%f*%f)     \n", *num1, *num2);
		printf("//  e) Calcular el factorial (%d!), (%d!)     \n", (int)*num1, (int)*num2);
		printf("//                                          //\n");
		printf("//////////////////////////////////////////////\n\n");

    printf("*nota: se tomara la parte entera a la hora de computar el factorial\n\n");
    system("pause");

    system("cls");
    	//MUESTRA LAS OPERACIONES QUE SE EFECTUARON Y LAS QUE NO
		printf("//////////////////////////////////////////////\n");
		printf("//                                          //\n");
		printf("//        OPERACIONES FINALIZADAS           //\n");
		printf("//                                          //\n");

	if( !suma(num1, num2, resSuma, flags) )
	{
		printf("//  a) Suma realizada                       //\n");
	}
	else
	{
		printf("//  a) Se produjo un error al sumar         //\n");
	}

	if( !resta(num1, num2, resResta, flags) )
	{
		printf("//  b) Resta realizada                      //\n");
	}
	else
	{
		printf("//  b) Se produjo un error al restar        //\n");
	}

	if( !division(num1, num2, resDivision, flags) )
	{
		printf("//  c) Division realizada                   //\n");
	}
	else
	{
		printf("//  c) Se produjo un error al dividir       //\n");
	}

	if( !producto(num1, num2, resProducto, flags) )
	{
		printf("//  d) Multiplicacion realizada             //\n");
	}
	else
	{
		printf("//  d) Se produjo un error al multiplicar   //\n");
	}

	if ( !factorial(num1, resFact1, flags) && !factorial(num2, resFact2, flags) )
	{
		printf("//  e) Factoriales realizados (pte. entera) //\n");
	}
	else
	{
		printf("//  e) Hubo un error calculando factorial   //\n");
	}
		printf("//                                          //\n");
		printf("//////////////////////////////////////////////\n\n");

	system("pause");

}


void resultados(float* num1, float* num2, float* resSuma, float* resResta, float* resProducto, float* resDivision, long long int* resFact1,long long int* resFact2, int flags)
{
    system("CLS");

    	printf("//////////////////////////////////////////////\n");
		printf("//                                          //\n");
		printf("//                RESULTADOS                //\n");
		printf("//                                            \n");
		printf("//  a) El resultado de %f+%f es: %f\n", *num1, *num2, *resSuma);
		printf("//  b) El resultado de %f-%f es: %f\n", *num1, *num2, *resResta);

    // VERIFICACION DE ERROR DIVISION POR CERO
    if(!*num2)
    {
        printf("//  c) No es posible dividir por CERO (error mat.)\n");
    }
    else
    {
        printf("//  c) El resultado de %f/%f es: %f\n", *num1, *num2, *resDivision);
    }

    printf("//  d) El resultado de %f*%f es:  %f\n", *num1, *num2, *resProducto);

    // VERIFICACION DE ERROR FACTORIAL DE UN NUMERO NEGATIVO
    if(*num1 < 0)
    {
        printf("//  e) El numero A es negativo, no se puede calcular su factorial, ");
    }
    else
    {
        printf("//  e) El factorial de %d es: %I64u, ", (int) *num1, *resFact1);
    }
    if(*num2 < 0)
    {
        printf("y El numero B es negativo, no se puede calcular su factorial.\n");
    }
    else
    {
        printf("y El factorial de %d es: %I64u\n", (int) *num2, *resFact2);
    }

    	printf("//                                            \n");
    	printf("//                                          //\n");
    	printf("//////////////////////////////////////////////\n\n");

    printf("PESIONE UNA TECLA PARA VOLVER AL INICIO ");
    getch();


}
