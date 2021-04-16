/*
 ============================================================================
 Name        : TP1-Calculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "interfaz.h"
#include "calculos.h"
#include "creditos.h"

int main(void) {

	setbuf(stdout, NULL);

	creditos();
	printf("Presione Cualquier Tecla Para Iniciar");
	getchar();

	interfaz();

	creditos();
	printf("2021 Todos los derechos reservados\n\n");
	system("pause");

	return EXIT_SUCCESS;
}

