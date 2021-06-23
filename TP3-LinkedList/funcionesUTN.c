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
	int aux;
	int clear;
	char bufferStr[10];

	if(num != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			gets(bufferStr);

			clear = 1;

			for(int i=0; i<strlen(bufferStr); i++)
		    {
		        if( bufferStr[i] < 48 || bufferStr[i] > 57 )
		        {
		        	printf("%s",mensajeError);
		        	reintentos--;
		        	clear = 0;
		        	break;
		        }
		    }

			if(clear)
			{
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
			}

		}while(reintentos>=0);
	}

	return error;
}


// Flotante y validacion

int utn_getFloat(float* num, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int error = -1;
	int decimal;
	int clear;
	char bufferStr[10];
	float aux;

	if(num != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			gets(bufferStr);

			decimal = 0;
			clear = 1;

			for(int i=0; i<strlen(bufferStr); i++)
		    {
		        if( (bufferStr[i] < 48 && bufferStr[i] != 46) || bufferStr[i] > 57 || decimal > 1 )
		        {
		        	printf("%s",mensajeError);
		        	reintentos--;
		        	clear = 0;
		        	break;
		        }
		        else if(bufferStr[i] == 46)
			    {
			        decimal++;
			    }
		    }

		    if(clear)
		    {
			    aux = atof(bufferStr);

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

			buffer = toupper(buffer);

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

// Puntero y validación



// Cadena de caracteres y validacion

int utn_getName(char* vec, int size, char* mensaje, char* mensajeError, int reintentos)
{
	int error = -1;
	int clear;
	char bufferStr[size];

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
				if( ( bufferStr[i] < 65 && bufferStr[i] != 32 ) || (bufferStr[i] > 90 && bufferStr[i] < 97) || bufferStr[i] > 122 )
				{
					printf("//  ERROR WITH \"%c\" %s", bufferStr[i], mensajeError);
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

int utn_getDate(int* day, int* month, int* year, char* mensaje, char* mensajeError, int reintentos)
{
	int error = -1;
	int clear;

	char bufferDay[2];
	char bufferMonth[2];
	char bufferYear[4];

	if(day != NULL && month != NULL && year != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			clear = 0;
			printf("%s dd/mm/aaaa", mensaje);
			scanf("%s/%s/%s", bufferDay, bufferMonth, bufferYear);

			if( 
				(bufferDay[0] >= 48 && bufferDay[0] <= 51) &&
				(bufferDay[1] >= 48 && bufferDay[1] <= 57) &&
				(bufferMonth[0] >= 48 &&  bufferMonth[0] <= 57) &&
				(bufferMonth[1] == 48 || bufferMonth[1] == 49) &&
				bufferYear[0] == 50 &&
				(bufferYear[1] >= 48 && bufferYear[1] <= 57) &&
				(bufferYear[2] >= 48 && bufferYear[2] <= 57) &&
				(bufferYear[3] >= 48 && bufferYear[3] <= 57) 
				)
			{
				clear = 1;
			}

			if(clear)
			{
				*day = atoi(bufferDay);
				*month = atoi(bufferMonth);
				*year = atoi(nufferYear);
			}
			else
			{
				reintentos--;
			}

		}while(reintentos >= 0);		

		error = 0;
	}

	return error;
}