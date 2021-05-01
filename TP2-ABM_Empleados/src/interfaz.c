#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "interfaz.h"
#include "utn.h"

#define msg00 "//      TO MANY RETRIES, ABORTED OPERATION      //"
#define msg01 "//       EMPLOYEES SUCCESFULLY INITIALIZED      //"
#define msg02 "//        EMPLOYEE SUCCESFULY REGISTRATED       //"
#define msg03 "//         EMPLOYEE SUCCESFULY MODIFIED         //"
//#define msg04 ""
//#define msg05 ""

#define err00 "//  UNEXPECTED ERROR, CONTACT YOUR SYS. ADMIN   //"
#define err01 "//         ERROR INITIALIZING EMPLOYEES         //"
#define err02 "//      ERROR WHEN REGISTERING NEW EMPLOYEE     //"
#define err03 "//        ERROR WHILE MODIFYING EMPLOYEE        //"
//#define err04 ""
//#define err05 ""

#define CANT 1000

void interfaz()
{
	int option;
	int nextId = 20210001;
	int flagEmployee = 0;
	int auxIndex;

	char confirm;
	char exit = 'N';

	/*
	int auxInt;
	float auxFloat1;
	float auxFloat2;
	*/

	Employee list[CANT];
	Employee aux;


	//employee initialization
	system("cls");
	if( !initEmployees(list, CANT) )
	{
		showMessage(msg01);
	}
	else
	{
		showMessage(err01);
	}
	system("pause");



	//iteracion de menu de opciones
	do
	{
		mainMenu(&option);

		switch(option)
		{
			case 1:			// ------------------------------------------------------- OPTION 1 REGISTRATE NEW EMPLOYEES ------------------------------- //

				system("cls");

				printf("//////////////////////////////////////////////////\n");
				printf("//                                              //\n");
				printf("//                 NEW EMPLOYEE                 //\n");
				printf("//                                              //\n");
				printf("//////////////////////////////////////////////////\n");
				printf("//                                              //\n");
				printf("//  ASSIGNED ID: %d                       //\n", nextId);

				aux.id = nextId;

				if( utn_getName(aux.name, 51, "//                                              //\n//  ENTER NAME: ", "\n//           INVALID CHARACTER, RETRY           //\n", 2) )
				{
					showMessage(msg00);
					system("pause");
					break;
				}

				if( utn_getName(aux.lastName, 51, "//                                              //\n//  ENTER LASTNAME: ", "\n//           INVALID CHARACTER, RETRY           //\n", 2) )
				{
					showMessage(msg00);
					system("pause");
					break;
				}

				// minimum wage in Argentina 05/2021 = $21600
				if( utn_getFloat(&aux.salary, "//                                              //\n//  ENTER SALARY ( min $21600 ): $", "//\n//          ERROR ENTERING SALARY, RETRY        //\n", 21600, 5000000, 2) )
				{
					showMessage(msg00);
					system("pause");
					break;
				}

				if( utn_getInteger(&aux.sector, "//                                              //\n//  ENTER SECTOR ( 100 ~ 900 ): ", "//\n//          ERROR ENTERING SECTOR, RETRY        //\n", 100, 900, 2) )
				{
					showMessage(msg00);
					system("pause");
					break;
				}

				if ( !addEmployee(list, CANT, aux.id, aux.name, aux.lastName, aux.salary, aux.sector) )
				{
					showMessage(msg02);
					flagEmployee = 1;
					nextId++;
				}
				else
				{
					showMessage(err02);
				}

				system("pause");
				break;

			case 2:		// ------------------------------------------------------- OPTION 2 MODIFY EMPLOYEES ------------------------------------------- //

				if( flagEmployee )
				{
					system("cls");

					printf("//////////////////////////////////////////////////\n");
					printf("//                                              //\n");
					printf("//               MODIFY EMPLOYEE                //\n");
					printf("//                                              //\n");
					printf("//////////////////////////////////////////////////\n");

					utn_getInteger(&aux.id, "//                                                \n//  ENTER EMPLOYEE ID: ", "//\n//    ID MUST BE BETWEEN 20210001 - 20211000    //\n", 20210001, 20211000, 2);

					auxIndex = findEmployeeById(list, CANT, aux.id);

					if( auxIndex != -1 )
					{
						printf("//    MATCHING EMPLOYEE:                          \n");
						printf("//                                                \n");
						printf("//      ID               NAME             LASTNAME              SALARY        SECTOR 	   \n");
						printf("//  -----------------------------------------------------------------------------------    \n");

						showEmployee(list);

						printf("//                                                \n");
						printf("//                                                \n");

						modifyMenu(&option);

						switch(option)
						{
							case 1:
								showMessage("//             MODIFY EMPLOYEE NAME             //\n");
								printf("//                                              //\n");
								printf("//  CURRENT VALUE: %s                              \n", list[auxIndex].name);

								if( utn_getName(aux.name, 51, "//                                              //\n//  ENTER NAME: ", "\n//           INVALID CHARACTER, RETRY           //\n", 2) )
								{
									showMessage(msg00);
									system("pause");
									break;
								}

								printf("//                                              //\n");
								printf("// REPLACE %s WITH %s ?", list[auxIndex].name, aux.name);
								printf("//                                              //\n");
								printf("//  CONFIRM?   Y/N   ");
								fflush(stdin);
								scanf("%c", &confirm);
								confirm = toupper(confirm);
								if(confirm == 'Y')
								{
									strcpy(list[auxIndex].name, aux.name);
								}


								break;

							case 2:
								showMessage("//           MODIFY EMPLOYEE LASTNAME           //\n");
								printf("//                                              //\n");
								printf("//  CURRENT VALUE: %s                              \n", list[auxIndex].lastName);

								if( utn_getName(aux.lastName, 51, "//                                              //\n//  ENTER LASTNAME: ", "\n//           INVALID CHARACTER, RETRY           //\n", 2) )
								{
									showMessage(msg00);
									system("pause");
									break;
								}

								printf("//                                              //\n");
								printf("// REPLACE %s WITH %s ?", list[auxIndex].lastName, aux.lastName);
								printf("//                                              //\n");
								printf("//  CONFIRM?   Y/N   ");
								fflush(stdin);
								scanf("%c", &confirm);
								confirm = toupper(confirm);
								if(confirm == 'Y')
								{
									strcpy(list[auxIndex].lastName, aux.lastName);
								}

								break;

							case 3:
								showMessage("//            MODIFY EMPLOYEE SALARY            //\n");
								printf("//                                              //\n");
								printf("//  CURRENT VALUE: %.2f                              \n", list[auxIndex].salary);

								if( utn_getFloat(&aux.salary, "//                                              //\n//  ENTER SALARY ( min $21600 ): $", "//\n//          ERROR ENTERING SALARY, RETRY        //\n", 21600, 5000000, 2) )
								{
									showMessage(msg00);
									system("pause");
									break;
								}

								printf("//                                              //\n");
								printf("// REPLACE %.2f WITH %.2f ?", list[auxIndex].salary, aux.salary);
								printf("//                                              //\n");
								printf("//  CONFIRM?   Y/N   ");
								fflush(stdin);
								scanf("%c", &confirm);
								confirm = toupper(confirm);
								if(confirm == 'Y')
								{
									list[auxIndex].salary = aux.salary;
								}

								break;

							case 4:
								showMessage("//            MODIFY EMPLOYEE SECTOR            //\n");
								printf("//                                              //\n");
								printf("//  CURRENT VALUE: %d                              \n", list[auxIndex].sector);

								if( utn_getInteger(&aux.sector, "//                                              //\n//  ENTER SECTOR ( 100 ~ 900 ): ", "//\n//          ERROR ENTERING SECTOR, RETRY        //\n", 100, 900, 2) )
								{
									showMessage(msg00);
									system("pause");
									break;
								}

								printf("//                                              //\n");
								printf("// REPLACE %.d WITH %d ?", list[auxIndex].sector, aux.sector);
								printf("//                                              //\n");
								printf("//  CONFIRM?   Y/N   ");
								fflush(stdin);
								scanf("%c", &confirm);
								confirm = toupper(confirm);
								if(confirm == 'Y')
								{
									list[auxIndex].sector = aux.sector;
								}

								break;

							default:
								break;
						}


					}
					else
					{
						showMessage("//            NO MATCHING EMPLOYEES             //");
					}

				}

				else
				{
					showMessage("//      THERE ARE NO REGISTERED EMPLOYEES       //");
				}

				system("pause");
				break;

			case 3:
				printf("ESTA ES LA OPCION 3");
				system("pause");
				break;

			case 4:
				printf("INDICE: ");
				scanf("%d", &auxIndex);

				printf("\n  %d", list[auxIndex].id);
				system("pause");
				break;

			case 0:
				printf("//                                              //\n");
				printf("//  CONFIRM TO EXIT? Y/N   ");
				fflush(stdin);
				scanf("%c", &exit);
				exit = toupper(exit);
				break;

			default:
				break;
		}

	}while(exit != 'Y');
}

int mainMenu(int* option)
{
	system("cls");

	int error = -1;

	if(option != NULL)
	{
		printf("//////////////////////////////////////////////////\n");
		printf("//                                              //\n");
		printf("//                  MAIN MENU                   //\n");
		printf("//                                              //\n");
		printf("//////////////////////////////////////////////////\n");
		printf("//                                              //\n");
		printf("//    1. REGISTRATE NEW EMPLOYEES               //\n");
		printf("//    2. MODIFY EMPLOYEE                        //\n");
		printf("//    3. WITHDRAW EMPLOYEE                      //\n");
		printf("//    4. LIST EMPLOYEES                         //\n");
		printf("//                                              //\n");
		printf("//    0. EXIT                                   //\n");
		printf("//                                              //\n");
		printf("//////////////////////////////////////////////////\n");

		if ( utn_getInteger(option, "//                                              //\n//  SELECT AN OPTION : ", "//\n//             INVALID OPTION, RETRY            //\n", 0, 4, 2) )
		{
			showMessage(err00);
		}
		else
		{
			error = 0;
		}
	}

	return error;
}

int modifyMenu(int* option)
{
	int error = -1;

	if(option != NULL)
	{
		printf("//////////////////////////////////////////////////\n");
		printf("//                                              //\n");
		printf("//              MODIFICATION MENU               //\n");
		printf("//                                              //\n");
		printf("//////////////////////////////////////////////////\n");
		printf("//                                              //\n");
		printf("//  SELECT FIELD TO MODIFY                      //\n");
		printf("//                                              //\n");
		printf("//    1. EMPLOYEE NAME                          //\n");
		printf("//    2. EMPLOYEE LASTNAME                      //\n");
		printf("//    3. EMPLOYEE SALARY                        //\n");
		printf("//    4. EMPLOYEE SECTOR                        //\n");
		printf("//                                              //\n");
		printf("//    0. EXIT                                   //\n");
		printf("//                                              //\n");
		printf("//////////////////////////////////////////////////\n");

		if ( utn_getInteger(option, "//                                              //\n//  SELECT AN OPTION : ", "//\n//             INVALID OPTION, RETRY            //\n", 0, 4, 2) )
		{
			showMessage(err00);
		}
		else
		{
			error = 0;
		}
	}

	return error;
}

void showMessage(const char message[])
{
	printf("//                                              //\n");
	printf("//////////////////////////////////////////////////\n");
	printf("//                                              //\n");
	puts(message);
	printf("//                                              //\n");
	printf("//////////////////////////////////////////////////\n\n");
}
