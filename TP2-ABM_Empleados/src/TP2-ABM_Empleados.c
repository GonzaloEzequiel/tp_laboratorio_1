/*
 ============================================================================
 Name        : TP2-ABM_Empleados.c
 Author      : Pérez, Gonzalo Ezequiel 1E
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "interfaz.h"
#include "creditos.h"

int main(void) {

	setbuf(stdout, NULL);

	creditos();
	printf("Press any key to begin... ");
	getchar();

	//main interface
	interfaz();

	//exit
	creditos();
	printf("2021 All rights reserved\n\n");
	system("pause");

	return EXIT_SUCCESS;
}
