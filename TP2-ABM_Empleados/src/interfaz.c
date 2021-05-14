#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "OtherEmployeesFunctions.h"
#include "interfaz.h"
#include "utn.h"
#include "defines.h"

#define CANT 1000

void interfaz()
{
	//var declarations
	int option;							//selectable option in menus
	int nextId = 20210001;				//numeric self-incremental for employee
	int flagEmployee = 0;				//register flag of at least one employee
	int auxIndex;						//auxiliary index to search element by ID
	int aboveAverageSalaries = 0;		//above average wage accountant

	float totalSalaries = 0;			//totalSalaries accumulator
	float averageSalary;				//average wage

	char confirm;						//execution, modifications or cancellation confirmation
	char exit = 'N';					//exit confirmation

	Employee list[CANT], aux;			//array of employee structures, auxiliary


	//employee initialization
	system("cls");
	if( !initEmployees(list, CANT) )
	{
		//successful initialization message
		showMessage(msg01);
	}
	else
	{
		//initialization error message
		showMessage(err01);
	}
	printf("\n");
	system("pause");


	//main menu iteration
	do
	{
		if( mainMenu(&option) == -1 )
		{
			//main menu's option pointer error message
			showMessage(erroR);
			break;
		}

		switch(option)
		{
			case 1:			// ------------------------------------------------------- OPTION 1 REGISTRATE NEW EMPLOYEES ------------------------------- //

				system("cls");

				//option title
				showMessage("//                 NEW EMPLOYEE                 //");
				printf("//                                              //\n");
				printf("//  ASSIGNED ID: %d                       //\n", nextId); //new employee id

				//unique primary key mapping
				aux.id = nextId;

				//name entry
				if( utn_getName(aux.name, 51, "//                                              //\n//  ENTER NAME: ", "\n//           INVALID CHARACTER, RETRY           //\n", 2) ) //new employee name
				{
					//message in case of exceeding retries
					showMessage(msg00);
					printf("\n");
					system("pause");
					break;
				}

				//lastname entry
				if( utn_getName(aux.lastName, 51, "//                                              //\n//  ENTER LASTNAME: ", "\n//           INVALID CHARACTER, RETRY           //\n", 2) ) //new employee lastname
				{
					//message in case of exceeding retries
					showMessage(msg00);
					printf("\n");
					system("pause");
					break;
				}

				//salary entry; minimum wage in Argentina 05/2021 = $21600
				if( utn_getFloat(&aux.salary, "//                                              //\n//  ENTER SALARY ( min $21600 ): $ ", "//\n//          ERROR ENTERING SALARY, RETRY        //\n", 21600, 5000000, 2) )
				{
					//message in case of exceeding retries
					showMessage(msg00);
					printf("\n");
					system("pause");
					break;
				}

				//sector entry
				if( utn_getInteger(&aux.sector, "//                                              //\n//  ENTER SECTOR ( 100 ~ 900 ): ", "//\n//          ERROR ENTERING SECTOR, RETRY        //\n", 100, 900, 2) ) //new employee sector
				{
					//message in case of exceeding retries
					showMessage(msg00);
					printf("\n");
					system("pause");
					break;
				}


				//assigns the auxiliary data set to an element in a free index of the array
				if ( !addEmployee(list, CANT, aux.id, aux.name, aux.lastName, aux.salary, aux.sector) )
				{
					//successful registration message
					showMessage(msg02);

					//flag modification / at least one registered employee
					flagEmployee = 1;

					//primary key increment
					nextId++;
				}
				else
				{
					//registration error message
					showMessage(err02);
				}

				printf("\n");
				system("pause");
				break;

			case 2:		// ------------------------------------------------------- OPTION 2 MODIFY EMPLOYEES ------------------------------------------- //

				if( flagEmployee )
				{
					system("cls");

					//option title
					showMessage("//               MODIFY EMPLOYEE                //");

					//employee id entry
					if( utn_getInteger(&aux.id, "//                                                \n//  ENTER EMPLOYEE ID: ", "//\n//    ID MUST BE BETWEEN 20210001 - 20211000    //\n", 20210001, 20211000, 2) )
					{
						//message in case of exceeding retries
						showMessage(msg00);
						printf("\n");
						system("pause");
						break;
					}

					//set array index by finding empoyee by id
					auxIndex = findEmployeeById(list, CANT, aux.id);

					if( auxIndex != -1 )
					{
						do
						{
							printf("//    MATCHING EMPLOYEE:                          \n");
							printf("//                                                \n");
							printf("//      ID               NAME             LASTNAME              SALARY        SECTOR 	   \n");
							printf("//  -----------------------------------------------------------------------------------    \n");

							//data printing of the matching employee
							showEmployee(list[auxIndex]);

							printf("//                                                \n");
							printf("//                                                \n");

							if( modifyMenu(&option) == -1 )
							{
								//modification menu's option pointer error message
								showMessage(erroR);
								break;
							}

							switch(option)
							{
								case 1:		// ------------------------------ SUBMENU OPTION 1 NAME ------------------------------ //
									//option title
									showMessage("//             MODIFY EMPLOYEE NAME             //");
									printf("//                                              //\n");
									printf("//  CURRENT VALUE: %s                              \n", list[auxIndex].name);

									//input for the new name value
									if( utn_getName(aux.name, 51, "//                                              //\n//  ENTER NAME: ", "\n//           INVALID CHARACTER, RETRY           //\n", 2) )
									{
										//message in case of exceeding retries
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
										//modification success message
										showMessage(msg04);
									}
									else
									{
										//modification error message
										showMessage(err04);
									}

									break;

								case 2:		// ------------------------------ SUBMENU OPTION 2 LASTNAME ------------------------------ //
									//option title
									showMessage("//           MODIFY EMPLOYEE LASTNAME           //");
									printf("//                                              //\n");
									printf("//  CURRENT VALUE: %s                              \n", list[auxIndex].lastName);

									//input for the new lastname value
									if( utn_getName(aux.lastName, 51, "//                                              //\n//  ENTER LASTNAME: ", "\n//           INVALID CHARACTER, RETRY           //\n", 2) )
									{
										//message in case of exceeding retries
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
										//modification success message
										showMessage(msg04);
									}
									else
									{
										//modification error message
										showMessage(err04);
									}

									break;

								case 3: 	// ------------------------------ SUBMENU OPTION 3 SALARY ------------------------------ //
									//option title
									showMessage("//            MODIFY EMPLOYEE SALARY            //");
									printf("//                                              //\n");
									printf("//  CURRENT VALUE: $ %.2f                              \n", list[auxIndex].salary);

									//input for the new salary value
									if( utn_getFloat(&aux.salary, "//                                              //\n//  ENTER SALARY ( min $21600 ): $ ", "//\n//          ERROR ENTERING SALARY, RETRY        //\n", 21600, 5000000, 2) )
									{
										//message in case of exceeding retries
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
										//modification success message
										showMessage(msg04);
									}
									else
									{
										//modification error message
										showMessage(err04);
									}

									break;

								case 4:		// ------------------------------ SUBMENU OPTION 4 SECTOR ------------------------------ //
									//option title
									showMessage("//            MODIFY EMPLOYEE SECTOR            //");
									printf("//                                              //\n");
									printf("//  CURRENT VALUE: %d                              \n", list[auxIndex].sector);

									//input for the new sector value
									if( utn_getInteger(&aux.sector, "//                                              //\n//  ENTER SECTOR ( 100 ~ 900 ): ", "//\n//          ERROR ENTERING SECTOR, RETRY        //\n", 100, 900, 2) )
									{
										//message in case of exceeding retries
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
										//modification success message
										showMessage(msg04);
									}
									else
									{
										//modification error message
										showMessage(err04);
									}

									break;

								case 0:		// ------------------------------ SUBMENU OPTION 0 EXIT ------------------------------ //
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

					}
					else
					{
						showMessage("//            NO MATCHING EMPLOYEES             //");
					}
				}
				else
				{
					//registered employee flag error message
					showMessage(err00);
				}

				printf("\n");
				system("pause");
				break;

			case 3:		// ------------------------------------------------------- OPTION 3 WITHDRAW EMPLOYEES ------------------------------------------- //

				if(flagEmployee)
				{
					system("cls");

					//option title
					showMessage("//              WITHDRAW EMPLOYEE               //");

					//employee id entrt
					if( utn_getInteger(&aux.id, "//                                                \n//  ENTER EMPLOYEE ID: ", "//\n//         ID MUST BE 20210001 OR HIGER         //\n", 20210001, 30000000, 2) )
					{
						//message in case of exceeding retries
						showMessage(msg00);
						printf("\n");
						system("pause");
						break;
					}

					//set array index by finding empoyee by id
					auxIndex = findEmployeeById(list, CANT, aux.id);

					if(auxIndex != -1)
					{
						printf("//    MATCHING EMPLOYEE:                          \n");
						printf("//                                                \n");
						printf("//      ID               NAME             LASTNAME              SALARY        SECTOR 	   \n");
						printf("//  -----------------------------------------------------------------------------------    \n");

						//data printing of the matching employee
						showEmployee(list[auxIndex]);

						printf("//                                                \n");
						printf("//                                                \n");

						if( withdrawMenu(&option) == -1 )
						{
							//withdraw menu's option pointer error message
							showMessage(erroR);
							break;
						}

						if( option && !removeEmployee(list, CANT, aux.id) )		// ------- SUBMENU OPTION 1 REMOVE ------- //
						{
							//withdrawal success message
							showMessage(msg05);
						}
						else		// ------------------------------ SUBMENU OPTION 0 EXIT ------------------------------ //
						{
							//withdrawal error message
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
					//registered employee flag error message
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

						//option title
						if( sortMenu(&option) == -1 )
						{
							//sorting menu's option pointer error message
							showMessage(erroR);
							break;
						}

						switch(option)
						{
							case 1:
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

							case 0:		// ------------------------------ SUBMENU OPTION 0 EXIT ------------------------------- //
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

						if(option) //if employees were sorted and printed, calculates and shows total and average salaries
						{
							if( salaries(list, CANT, &totalSalaries, &averageSalary, &aboveAverageSalaries) )
							{
								showMessage("//        ERROR WHILE DISPLAYING SALARIES       //");
							}

							printf("//                                                \n");
							printf("//                                              //\n");
							printf("//////////////////////////////////////////////////\n");
							printf("//                                              //\n");
							printf("//  TOTAL SALARIES: $ %.2f\n", totalSalaries);
							printf("//  AVERAGE SALARY: $ %.2f\n", averageSalary);
							printf("//  EMPLOYEES ABOVE AVERAGE SALARY: %d\n", aboveAverageSalaries);
							printf("//                                              //\n");
							printf("//////////////////////////////////////////////////\n");

							aboveAverageSalaries = 0;
							totalSalaries = 0;

							printf("\n");
							system("pause");

						}

					}while(exit != 'Y');

					exit = 'N';
				}
				else
				{
					//registered employee flag error message
					showMessage(err00);
				}

				printf("\n");
				system("pause");
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
		printf("//    0. CANCEL / BACK TO MAIN MENU             //\n");
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
