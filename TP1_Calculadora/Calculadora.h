#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED



#endif // CALCULADORA_H_INCLUDED



//FUNCIONES QUE NO DEVUELVEN NINGUN VALOR

/** \brief PANTALLA PRINCIPAL DEL PROGRAMA, MENU DE OPCIONES DE LA CALCULADORA, DA O RESTRINGE ACCESO
 *
 * \return void
 *
 */
void menu();

/** \brief MUESTRA AL USUARIO TODAS LAS OPERACIONES QUE SE EJECUTARAN ENTRE LOS DOS OPERANDOS
 *
 * \return void
 *
 */
void operaciones();

/** \brief MUESTRA EN PANTALLA LOS RESULTADOS DE TODAS LAS OPERACIONES QUE SE EJECUTARON ENTRE LOS DOS OPERANDOS
 *
 * \param num1 int PRIMER OPERANDO ASIGNADO POR EL MENU
 * \param num2 int SEGUNDO OPERANDO ASIGNADO POR EL MENU
 * \return void
 *
 */
void resultados(int num1, int num2);

/** \brief ALERTA EN MENU, NO SE INGRESO EL PRIMER OPERANDO
 *
 * \return void
 *
 */
void alerta1();

/** \brief ALERTA EN MENU, NO SE INGRESO EL SEGUNDO OPERANDO
 *
 * \return void
 *
 */
void alerta2();

/** \brief ALERTA EN MENU, NO SE INGRESO NINGUN OPERANDO
 *
 * \return void
 *
 */
void alerta3();

/** \brief ALERTA EN MENU, AUN NO SE HAN REALIZADO LAS OPERACIONES
 *
 * \return void
 *
 */
void alerta4();

/** \brief PANTALLA INICAL, FIRMA DIGITAL, LOGO CORPORATIVO, MENSAJE, PANTALLA FINAL
 *
 * \return void
 *
 */
void creditos();




//FUNCIONES QUE DEVUELVEN UN CHAR

/** \brief SOLICITA CONFIRMACION PARA REESCRIBIR OPERANDO
 *
 * \return char s PARA COMFIRMAR SOBREESCRITURA, n PARA NO MODIFICAR
 *
 */
char sobreescribir();




//FUNCIONES QUE DEVUELVEN UN ENTERO

/** \brief LIMPIA LA PANTALLA, SOLICITA UN VALOR ENTERO
 *
 * \return int DEVUELVE EL VALOR SOLICITADO PARA PODER OPERAR
 *
 */
 int ingresarOperando();

/** \brief FUNCION DE ADICION
 *
 * \param num1 int PRIMER VALOR A SUMAR
 * \param num2 int SEGUNDO VALOR A SUMAR
 * \return int LA SUMA DE AMBOS PARAMETROS
 *
 */
int suma(int num1, int num2);

/** \brief CALCULA LA RESTA ENTRE DOS VALORES
 *
 * \param num1 int PRIMER OPERADOR
 * \param num2 int NUMERO A RESTAR
 * \return int RESULTADO DE RESTAR EL SEGUNDO OPERADOR AL PRIMERO
 *
 */
int resta(int num1, int num2);

/** \brief CALCULA EL PRODUCTO ENTRE DOS VALORES
 *
 * \param num1 int PRIMER VALOR
 * \param num2 int SEGUNDO VALOR
 * \return int RESULTADO DE MULTIPLICAR ENTRE LOS OPERANDOS
 *
 */
int producto(int num1, int num2);




//FUNCIONES QUE DEVUELVEN UN FLOTANTE

/** \brief CALCULA LA DIVISION ENTRE DOS VALORES
 *
 * \param num1 int DIVIDENDO
 * \param num2 int DIVISOR
 * \return float RESULTADO DE DIVIR ENTRE LOS OPERANDOS
 *
 */
float division(int num1, int num2);




//FUNCIONES QUE DEVUELVEN UN ENTERO (MUY) GRANDE

/** \brief CALCULA EL FACTORIAL DE UN NUMERO INGRESADO
 *
 * \param num int NUMERO INGRESADO A CALCULAR
 * \return long long int FACTORIAL DEL NUMERO INGRESADO
 *
 */
long long int factorial (int num);
