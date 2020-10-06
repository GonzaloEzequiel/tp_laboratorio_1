#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} typedef Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief FORMATS THE STRUCT
 *
 * \param list Employee* STRUCT TO WORK WITH
 * \param len int STRUCT LENGHT
 * \return int RETURNS INDEX, OR -1 IF ERRROR
 *
 */
int openSlot(Employee* list, int len);

/** \brief CHECKS STRING ENTRIES, FORMATING CAPITAL LETTERS ON INICIAL NAMES
 *
 * \param string[] char STRING TO FORMAT
 * \param len int STRING LENGHT
 * \return int RETURNS 0 IF OK, OR -1 IF ERROR
 *
 */
int stringFormat(char string[], int len);

/** \brief CHECKS STRING ENTRIES AS FLOAT CHARS
 *
 * \param string[] char STRING TO CHECK
 * \param len int STRING LENGHT
 * \return int RETURNS 0 IF OK, OR -1 IF ERROR
 *
 */
int floatFormat(char string[], int len);

/** \brief CHECKS STRING ENTRIES AS INTEGER CHARS
 *
 * \param string[] char STRING TO CHECK
 * \param len int STRING LENGHT
 * \return int RETURNS 0 IF OK, OR -1 IF ERROR
 *
 */
int integerFormat(char string[], int len);

/** \brief VALIDATES STRING ENTRIES AS INTEGER
 *
 * \param vec[] char STRING TO VALIDATE
 * \param vec2[] char STRING NAME TO USE AS OUTPUT MESSAGES
 * \return int VALIDATED INTEGER
 *
 */
int getInteger(char vec[], char vec2[]);

/** \brief SHOWS HOW MANY EMPLOYEES ARE ABOVE AVERAGE SALARY
 *
 * \param list Employee* STRUCT TO WORK WITH
 * \param len int STRUCT LENGHT
 * \param average float AVERAGE SALARY
 * \return int QUANTITY OF EMPLOYEES
 *
 */
int avobeAverage(Employee* list, int len, float average);



/** \brief VALIDATES STRING ENTRIES AS FLOAT
 *
 * \param vec[] char STRING TO VALIDATE
 * \param vec2[] char STRING NAME TO USE AS OUTPUT MESSAGES
 * \return float VALIDATED FLOAT
 *
 */
float getFloat(char vec[], char vec2[]);

/** \brief SHOWS THE TOTAL SUM OF THE SALARIES
 *
 * \param list Employee* STRUCT TO WORK WITH
 * \param len int STRUCT LENGHT
 * \return float TOTAL SUM
 *
 */
float totalSalaries(Employee* list, int len);

/** \brief SHOWS THE AVERAGE SALARY
 *
 * \param list Employee* STRUCT TO WORK WITH
 * \param len int STRUCT LENGHT
 * \return float AVERAGE SALARY
 *
 */
float averageSalary(Employee* list, int len);




/** \brief MAIN MENU, OPTION MENU, MAIN SCREEN
 *
 * \param list Employee* STRUCT TO WORK WITH
 * \param len int STRUCT LENGTH
 * \return void
 *
 */
void menu(Employee* list, int len);

/** \brief SWAPS THE INDEX ORDER ON PARALLEL ARRAYS
 *
 * \param list Employee* STRUCT TO WORK WITH
 * \param a int FIRST INDEX
 * \param b int SECOND INDEX
 * \return void
 *
 */
void swap(Employee* list, int a, int b);

/** \brief VALIDATES STRING ENTRIES
 *
 * \param vec[] char STRING TO VALIDATE
 * \param vec2[] char STRING NAME TO USE AS OUTPUT MESSAGES
 * \return void
 *
 */
void getString(char vec[], char vec2[]);

/** \brief PRINTS A VISUAL STRUCTURE FOR GUIDANCE
 *
 * \param list Employee* STRUCT TO WORK WITH
 * \param title[] char MESSAGE TO DISPLAY AS TITLE
 * \param i int INDEX TO DISPLAY
 * \return void
 *
 */
void header(Employee* list, char title[],int i);

/** \brief PRINTS INDEX DATA
 *
 * \param list Employee* STRUCT TO WORK WITH
 * \return void
 *
 */
void showEmployee(Employee* list);

/** \brief INICIAL SCREEN, DIGITAL SIGANTURE, CORPORATIVE LOGO, MESSAGE, FINAL SCREEN
 *
 * \return void
 *
 */
void credits();
