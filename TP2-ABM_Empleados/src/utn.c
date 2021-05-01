/*
	Bibliteca de funciones en C
	que permiten el ingreso y la validacion
	de los diferentes tipos de datos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Entero y validacion

int utn_getInteger(int* num, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int error = -1;
	char bufferStr[10];
	int aux;

	if(num != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			gets(bufferStr);

			for(int i=0; i<strlen(bufferStr); i++)
		    {
		        if( bufferStr[i] < 48 || bufferStr[i] > 57 )
		        {
		        	printf("%s",mensajeError);
		        	reintentos--;
		        	break;
		        }
		    }

		    aux = atoi(bufferStr);

        	if(aux >= minimo && aux <= maximo)
        	{
	        	*num = aux;
	        	error = 0;
	        	break;
        	}
        	else
			{
        		printf("%s",mensajeError);
				reintentos--;
			}

		}while(reintentos>=0);
	}

	return error;
}


// Flotante y validacion

int utn_getFloat(float* num, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int error = -1;
	int decimal = 0;
	char bufferStr[10];
	float aux;

	if(num != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			gets(bufferStr);

			for(int i=0; i<strlen(bufferStr); i++)
		    {
		        if( ( ( bufferStr[i] < 48 || bufferStr[i] > 57 ) && bufferStr[i] != '.' ) || decimal > 1 )
		        {
		        	printf("%s",mensajeError);
		        	reintentos--;
		        	break;
		        }
		        else if(bufferStr[i] == '.' )
			    {
			        decimal++;
			    }
		    }

		    aux = atoi(bufferStr);

        	if(aux >= minimo && aux <= maximo)
        	{
	        	*num = aux;
	        	error = 0;
				break;
        	}
        	else
			{
        		printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos>=0);
	}

	return error;
}


// Caracter y validacion (classroom gral)

int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &buffer);

			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos>=0);
	}

	return retorno;
}

int utn_getName(char* vec, int size, char* mensaje, char* mensajeError, int reintentos)
{
	int error = -1;
	int clear;
	char bufferStr[50];

	if(vec != NULL && size > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			clear = 1;
			printf("%s", mensaje);
			fflush(stdin);
			gets(bufferStr);
			strlwr(bufferStr);

			for(int i=0; i<strlen(bufferStr); i++)
			{
				if( bufferStr[i] < 65 || (bufferStr[i] > 90 && bufferStr[i] < 97) || bufferStr[i] > 122 )
				{
					printf("//  ERROR WITH %c %s", bufferStr[i], mensajeError);
					reintentos--;
					clear = 0;
					break;
				}

				if(!i || isspace(bufferStr[i-1]) )
				{
					bufferStr[i] = toupper(bufferStr[i]);
				}
			}

			if(clear)
			{
				strcpy(vec, bufferStr);
				error = 0;
				break;
			}

		}while(reintentos>=0);

	}

	return error;
}
