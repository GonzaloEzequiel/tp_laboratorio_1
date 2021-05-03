#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "interfaz.h"
#include "utn.h"

#define msg00 "//      TO MANY RETRIES, ABORTED OPERATION      //"
#define msg01 "//      EMPLOYEES SUCCESSFULLY INITIALIZED      //"
#define msg02 "//      EMPLOYEE SUCCESSFULLY REGISTRATED       //"
#define msg03 "//        EMPLOYEE SUCCESSFULLY MODIFIED        //"
#define msg04 "//          VALUE SUCCESFULLY MODIFIED          //"
#define msg05 "//        EMPLOYEE SUCCESSFULLY WITHDRAWN       //"

#define erroR "//  UNEXPECTED ERROR, CONTACT YOUR SYS. ADMIN   //"
#define err00 "//      THERE ARE NO REGISTERED EMPLOYEES       //"
#define err01 "//      ERROR WHILE INITIALIZING EMPLOYEES      //"
#define err02 "//     ERROR WHILE REGISTERING NEW EMPLOYEE     //"
#define err03 "//        ERROR WHILE MODIFYING EMPLOYEE        //"
#define err04 "//            VALUE WAS NOT MODIFIED            //"
#define err05 "//         EMPLOYEE WITHDRAWAL CANCELLED        //"

#define CANT 1000

void interfaz()
{
	//var declarations
	int option;
	int nextId = 20210001;
	int flagEmployee = 0;
	int auxIndex;
	int avobeAverageSalaries = 0;
	float totalSalaries = 0;
	float averageSalary;

	char confirm;
	char exit = 'N';

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
	printf("\n");
	system("pause");


	//main menu iteration
	do
	{
		if( mainMenu(&option) )
		{
			showMessage(erroR);
			break;
		}

		switch(option)
		{
			case 1:			// ------------------------------------------------------- OPTION 1 REGISTRATE NEW EMPLOYEES ------------------------------- //

				system("cls");

				showMessage("//                 NEW EMPLOYEE                 //");
				printf("//                                              //\n");
				printf("//  ASSIGNED ID: %d                       //\n", nextId);

				aux.id = nextId;

				if( utn_getName(aux.name, 51, "//                                              //\n//  ENTER NAME: ", "\n//           INVALID CHARACTER, RETRY           //\n", 2) )
				{
					showMessage(msg00);
					printf("\n");
					system("pause");
					break;
				}

				if( utn_getName(aux.lastName, 51, "//                                              //\n//  ENTER LASTNAME: ", "\n//           INVALID CHARACTER, RETRY           //\n", 2) )
				{
					showMessage(msg00);
					printf("\n");
					system("pause");
					break;
				}

				// minimum wage in Argentina 05/2021 = $21600
				if( utn_getFloat(&aux.salary, "//                                              //\n//  ENTER SALARY ( min $21600 ): $ ", "//\n//          ERROR ENTERING SALARY, RETRY        //\n", 21600, 5000000, 2) )
				{
					showMessage(msg00);
					printf("\n");
					system("pause");
					break;
				}

				if( utn_getInteger(&aux.sector, "//                                              //\n//  ENTER SECTOR ( 100 ~ 900 ): ", "//\n//          ERROR ENTERING SECTOR, RETRY        //\n", 100, 900, 2) )
				{
					showMessage(msg00);
					printf("\n");
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

				printf("\n");
				system("pause");
				break;

			case 2:		// ------------------------------------------------------- OPTION 2 MODIFY EMPLOYEES ------------------------------------------- //

				if( flagEmployee )
				{
					system("cls");

					showMessage("//               MODIFY EMPLOYEE                //");

					if( utn_getInteger(&aux.id, "//                                                \n//  ENTER EMPLOYEE ID: ", "//\n//    ID MUST BE BETWEEN 20210001 - 20211000    //\n", 20210001, 20211000, 2) )
					{
						showMessage(msg00);
						printf("\n");
						system("pause");
						break;
					}

					auxIndex = findEmployeeById(list, CANT, aux.id);

					if( auxIndex != -1 )
					{
						do
						{
							printf("//    MATCHING EMPLOYEE:                          \n");
							printf("//                                                \n");
							printf("//      ID               NAME             LASTNAME              SALARY        SECTOR 	   \n");
							printf("//  -----------------------------------------------------------------------------------    \n");

							showEmployee(list[auxIndex]);

							printf("//                                                \n");
							printf("//                                                \n");

							if( modifyMenu(&option) )
							{
								showMessage(erroR);
								break;
							}

							switch(option)
							{
								case 1:
									showMessage("//             MODIFY EMPLOYEE NAME             //");
									printf("//                                              //\n");
									printf("//  CURRENT VALUE: %s                              \n", list[auxIndex].name);

									if( utn_getName(aux.name, 51, "//                                              //\n//  ENTER NAME: ", "\n//           INVALID CHARACTER, RETRY           //\n", 2) )
									{
										showMessage(msg00);
										printf("\n");
										system("pause");
										break;
									}

									printf("//                                              //\n");
									printf("//  REPLACE \"%s\" WITH \"%s\" ?\n", list[auxIndex].name, aux.name);
									printf("//                                              //\n");
									printf("//  CONFIRM?   Y/N   ");
									fflush(stdin);
									scanf("%c", &confirm);
									confirm = toupper(confirm);
									if(confirm == 'Y')
									{
										strcpy(list[auxIndex].name, aux.name);
										showMessage(msg04);
									}
									else
									{
										showMessage(err04);
									}

									break;

								case 2:
									showMessage("//           MODIFY EMPLOYEE LASTNAME           //");
									printf("//                                              //\n");
									printf("//  CURRENT VALUE: %s                              \n", list[auxIndex].lastName);

									if( utn_getName(aux.lastName, 51, "//                                              //\n//  ENTER LASTNAME: ", "\n//           INVALID CHARACTER, RETRY           //\n", 2) )
									{
										showMessage(msg00);
										printf("\n");
										break;
									}

									printf("//                                              //\n");
									printf("//  REPLACE \"%s\" WITH \"%s\" ?\n", list[auxIndex].lastName, aux.lastName);
									printf("//                                              //\n");
									printf("//  CONFIRM?   Y/N   ");
									fflush(stdin);
									scanf("%c", &confirm);
									confirm = toupper(confirm);
									if(confirm == 'Y')
									{
										strcpy(list[auxIndex].lastName, aux.lastName);
										showMessage(msg04);
									}
									else
									{
										showMessage(err04);
									}

									break;

								case 3:
									showMessage("//            MODIFY EMPLOYEE SALARY            //");
									printf("//                                              //\n");
									printf("//  CURRENT VALUE: $ %.2f                              \n", list[auxIndex].salary);

									if( utn_getFloat(&aux.salary, "//                                              //\n//  ENTER SALARY ( min $21600 ): $ ", "//\n//          ERROR ENTERING SALARY, RETRY        //\n", 21600, 5000000, 2) )
									{
										showMessage(msg00);
										printf("\n");
										system("pause");
										break;
									}

									printf("//                                              //\n");
									printf("//  REPLACE \"$ %.2f\" WITH \"$ %.2f\" ?\n", list[auxIndex].salary, aux.salary);
									printf("//                                              //\n");
									printf("//  CONFIRM?   Y/N   ");
									fflush(stdin);
									scanf("%c", &confirm);
									confirm = toupper(confirm);
									if(confirm == 'Y')
									{
										list[auxIndex].salary = aux.salary;
										showMessage(msg04);
									}
									else
									{
										showMessage(err04);
									}

									break;

								case 4:
									showMessage("//            MODIFY EMPLOYEE SECTOR            //");
									printf("//                                              //\n");
									printf("//  CURRENT VALUE: %d                              \n", list[auxIndex].sector);

									if( utn_getInteger(&aux.sector, "//                                              //\n//  ENTER SECTOR ( 100 ~ 900 ): ", "//\n//          ERROR ENTERING SECTOR, RETRY        //\n", 100, 900, 2) )
									{
										showMessage(msg00);
										printf("\n");
										system("pause");
										break;
									}

									printf("//                                              //\n");
									printf("//  REPLACE \"%.d\" WITH \"%d\" ?\n", list[auxIndex].sector, aux.sector);
									printf("//                                              //\n");
									printf("//  CONFIRM?   Y/N   ");
									fflush(stdin);
									scanf("%c", &confirm);
									confirm = toupper(confirm);
									if(confirm == 'Y')
									{
										list[auxIndex].sector = aux.sector;
										showMessage(msg04);
									}
									else
									{
										showMessage(err04);
									}

									break;

								case 0:
									printf("//                                              //\n");
									printf("//////////////////////////////////////////////////\n");
									printf("//                                              //\n");
									printf("//  BACK TO MAIN MENU? Y/N   ");
									fflush(stdin);
									scanf("%c", &exit);
									exit = toupper(exit);
									break;

								default:
									break;
							}

						}while(exit != 'Y');

						confirm = 'N';
						exit = 'N';
						//break;
					}
					else
					{
						showMessage("//            NO MATCHING EMPLOYEES             //");
					}
				}
				else
				{
					showMessage(err00);
				}

				printf("\n");
				system("pause");
				break;

			case 3:		// ------------------------------------------------------- OPTION 3 WITHDRAW EMPLOYEES ------------------------------------------- //

				if(flagEmployee)
				{
					system("cls");

					showMessage("//              WITHDRAW EMPLOYEE               //");

					if( utn_getInteger(&aux.id, "//                                                \n//  ENTER EMPLOYEE ID: ", "//\n//         ID MUST BE 20210001 OR HIGER         //\n", 20210001, 30000000, 2) )
					{
						showMessage(msg00);
						printf("\n");
						system("pause");
						break;
					}

					auxIndex = findEmployeeById(list, CANT, aux.id);

					if(auxIndex != -1)
					{
						printf("//    MATCHING EMPLOYEE:                          \n");
						printf("//                                                \n");
						printf("//      ID               NAME             LASTNAME              SALARY        SECTOR 	   \n");
						printf("//  -----------------------------------------------------------------------------------    \n");

						showEmployee(list[auxIndex]);

						printf("//                                                \n");
						printf("//                                                \n");

						if( withdrawMenu(&option) )
						{
							showMessage(erroR);
							break;
						}

						if( option && !removeEmployee(list, CANT, aux.id) )
						{
							showMessage(msg05);
						}
						else
						{
							showMessage(err05);
						}
					}
					else
					{
						showMessage("//            NO MATCHING EMPLOYEES             //");
					}
				}
				else
				{
					showMessage(err00);
				}

				printf("\n");
				system("pause");
				break;

			case 4:		// ------------------------------------------------------- OPTION 4 LIST & SORT EMPLOYEES ------------------------------------------- //

				if(flagEmployee)
				{
					do
					{
						system("cls");

						if( sortMenu(&option) )
						{
							showMessage(erroR);
							break;
						}

						switch(option)
						{
							case 1:

								if( printEmployees(list, CANT) )
								{
									showMessage("//       ERROR WHILE DISPLAYING EMPLOYEES       //");
								}

								break;

							case 2:
							case 3:
							case 4:
							case 5:

								if( sortEmployees(list, CANT, option) )
								{
									showMessage("//         ERROR WHILE SORTING EMPLOYEES        //");
								}

								if( printEmployees(list, CANT) )
								{
									showMessage("//       ERROR WHILE DISPLAYING EMPLOYEES       //");
								}

								break;

							case 0:
								printf("//                                              //\n");
								printf("//////////////////////////////////////////////////\n");
								printf("//                                              //\n");
								printf("//  BACK TO MAIN MENU? Y/N   ");
								fflush(stdin);
								scanf("%c", &exit);
								exit = toupper(exit);
								break;
								break;
						}

						if( salaries(list, CANT, &totalSalaries, &averageSalary, &avobeAverageSalaries) )
						{
							showMessage("//        ERROR WHILE DISPLAYING SALARIES       //");
						}

						printf("//                                                \n");
						printf("//                                              //\n");
						printf("//////////////////////////////////////////////////\n");
						printf("//                                              //\n");
						printf("//  TOTAL SALARIES: $ %.2f\n", totalSalaries);
						printf("//  AVERAGE SALARY: $ %.2f\n", averageSalary);
						printf("//  EMPLOYEES AVOBE AVERAGE SALARY: %d\n", avobeAverageSalaries);
						printf("//                                              //\n");
						printf("//////////////////////////////////////////////////\n");

						avobeAverageSalaries = 0;
						totalSalaries = 0;

						printf("\n");
						system("pause");

					}while(exit != 'Y');

					exit = 'N';
				}
				else
				{
					showMessage(err00);
				}

				printf("\n");
				//system("pause");
				break;

			case 0:		// ---------------------------------------------------------- OPTION 0 EXIT --------------------------------------------------------- //

				printf("//                                              //\n");
				printf("//////////////////////////////////////////////////\n");
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
			showMessage(msg00);
			*option = 0;
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
			showMessage(msg00);
			*option = 0;
		}
		else
		{
			error = 0;
		}
	}

	return error;
}

int withdrawMenu(int* option)
{
	int error = -1;

	if(option != NULL)
	{
		printf("//////////////////////////////////////////////////\n");
		printf("//                                              //\n");
		printf("//               WITHDRAWAL MENU                //\n");
		printf("//                                              //\n");
		printf("//////////////////////////////////////////////////\n");
		printf("//                                              //\n");
		printf("//    1. CONFIRM EMPLOYEE WITHDRAWAL            //\n");
		printf("//                                              //\n");
		printf("//    0. CANCEL / BACK TO MAIN MENU             //\n");
		printf("//                                              //\n");
		printf("//////////////////////////////////////////////////\n");

		if ( utn_getInteger(option, "//                                              //\n//  SELECT AN OPTION : ", "//\n//             INVALID OPTION, RETRY            //\n", 0, 1, 2) )
		{
			showMessage(msg00);
			*option = 0;
		}
		else
		{
			error = 0;
		}
	}

	return error;
}

int sortMenu(int* option)
{
	int error = -1;

	if(option != NULL)
	{
		printf("//////////////////////////////////////////////////\n");
		printf("//                                              //\n");
		printf("//                 SORTING MENU                 //\n");
		printf("//                                              //\n");
		printf("//////////////////////////////////////////////////\n");
		printf("//                                              //\n");
		printf("//  SORT EMPLOYEES BY:                          //\n");
		printf("//                                              //\n");
		printf("//    1. ID: DEFAULT                            //\n");
		printf("//    2. LASTNAME: UPWARDS, THEN SECTOR         //\n");
		printf("//    3. LASTNAME: DOWNWARDS, THEN SECTOR       //\n");
		printf("//    4. SECTOR: UPWARDS, THEN LASTNAME         //\n");
		printf("//    5. SECTOR: DOWNWARDS, THEN LASTNAME       //\n");
		printf("//                                              //\n");
		printf("//    0. CANCEL / BACK TO MAIN MENU             //\n");
		printf("//                                              //\n");
		printf("//////////////////////////////////////////////////\n");

		if ( utn_getInteger(option, "//                                              //\n//  SELECT AN OPTION : ", "//\n//             INVALID OPTION, RETRY            //\n", 0, 5, 2) )
		{
			showMessage(msg00);
			*option = 0;
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
	printf("//////////////////////////////////////////////////\n");
}
