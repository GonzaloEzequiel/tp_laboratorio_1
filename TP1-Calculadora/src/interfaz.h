/*
 * Calculadora.h
 *
 *  Created on: 3 abr. 2021
 *      Author: Pérez, Gonzalo Ezequiel 1E
 */

#ifndef INTERFAZ_H_
#define INTERFAZ_H_


/** \brief ES LA INTERFAZ GRAFICA, MUESTRA EL MENU ITERADO, MUESTRA LOS SUB-MENUS DE LAS OPCIONES SELECCIONADAS, INDICA LOS MENSAJES DE ERROR
 *
 * \return void
 */
void interfaz();


/** \brief PANTALLA PRINCIPAL DEL PROGRAMA, MENU DE OPCIONES DE LA CALCULADORA A SELECCIONAR QUE SE PASARA POR REFERENCIA
 *
 * \param x int* DIRECCION DE MEMORIA DE LA OPCION SELECCIONADA
 * \param x float* VALOR DEL PRIMER OPERADOR, PARA MOSTRARLO EN PANTALLA
 * \param y float* VALOR DEL SEGUNDO OPERADOR, PARA MOSTRARLO EN PANTALLA
 * \param flagX int BANDERA DE INGRESO DEL PRIMER OPERADOR, PARA MOSTRARLO EN PANTALLA
 * \param flagY int BANDERA DE INGRESO DEL SEGUNDO OPERADOR, PARA MOSTRARLO EN PANTALLA
 *
 * \return void
 */
void menuPrincipal(int* opcion, float* x, float* y, int flagX, int flagY);


/** \brief PERMITE AL USUARIO INGRESAR UN NUMERO PARA OPERAR, SI ESTE YA SE INGRESO PERMITE SOBREESCRIBIR
 *
 * \param num float* DIRECCION DE MEMORIA DEL OPERADOR A INGRESAR
 * \param flag int BANDERA DE OPERADOR NO INGRESADO / IGRESADO A SOBREESCIBIR
 *
 * \return int '0' SI NO SE PRODUJO NINGUN ERROR AL INGRESAR EL OPERANDO ; '1' SI SE PRODUJO ALGNUN ERROR AL INGRESAR EL OPERANDO
 */
int ingresarOperando(float* num, int flag);


/** \brief PERMITE SOBREESCRIBIR UN VALOR YA INGRESADO, PREVIA CONFIRMACION DEL USUARIO
 *
 * \return int '0' SI EL USUARIO CANCELA SOBREESCRITURA ; '1' SI EL USUARIO CONFIRMA SOBREESCRITURA
 */
int sobreescribir();


/** \brief ALERTA EN INTERFAZ, NO SE INGRESO EL PRIMER OPERANDO
 *
 * \return void
 */
void alerta1();


/** \brief ALERTA EN INTERFAZ, NO SE INGRESO EL SEGUNDO OPERANDO
 *
 * \return void
 *
 */
void alerta2();


/** \brief ALERTA EN INTERFAZ, NO SE INGRESO NINGUN OPERANDO
 *
 * \return void
 *
 */
void alerta3();


/** \brief ALERTA EN INTERFAZ, AUN NO SE HAN REALIZADO LAS OPERACIONES
 *
 * \return void
 *
 */
void alerta4();


/** \brief MUESTRA AL USUARIO LOS OPERADORES Y LAS OPERACIONES A REALIZAR, RESULVE LAS OPERACIONES LISTADAS LLAMANDO A LAS FUNCIONES EN calculos.c
 *
 * \param num1 float* DIRECCION DE MEMORIA DEL PRIMER OPERADOR
 * \param num2 float* DIRECCION DE MEMORIA DEL SEGUNDO OPERADOR
 * \param resSuma float* DIRECCION DE MEMORIA DEL RESULTADO DE LA SUMA
 * \param resResta float* DIRECCION DE MEMORIA DEL RESULTADO DE LA RESTA
 * \param resProducto float* DIRECCION DE MEMORIA DEL RESULTADO DEL PRODUCTO
 * \param resDivision float* DIRECCION DE MEMORIA DEL RESULTADO DE LA DIVISION
 * \param resFact1 long long int* DIRECCION DE MEMORIA DEL RESULTADO DEL FACTORIAL DEL PRIMER OPERANDO
 * \param resFact2 long long int* DIRECCION DE MEMORIA DEL RESULTADO DEL FACTORIAL DEL SEGUNDO OPERANDO
 * \param flags int BANDERA DE INGRESO DE OPERADORES
 *
 * \return void
 *
 */
void operaciones(float* num1, float* num2, float* resSuma, float* resResta, float* resProducto, float* resDivision, long long int* resFact1,long long int* resFact2, int flags);


/** \brief MUESTRA EN PANTALLA LOS RESULTADOS DE LAS OPERACIONES QUE SE REALIZARON
 *
 * \param num1 float* DIRECCION DE MEMORIA DEL PRIMER OPERADOR
 * \param num2 float* DIRECCION DE MEMORIA DEL SEGUNDO OPERADOR
 * \param resSuma float* DIRECCION DE MEMORIA DEL RESULTADO DE LA SUMA
 * \param resResta float* DIRECCION DE MEMORIA DEL RESULTADO DE LA RESTA
 * \param resProducto float* DIRECCION DE MEMORIA DEL RESULTADO DEL PRODUCTO
 * \param resDivision float* DIRECCION DE MEMORIA DEL RESULTADO DE LA DIVISION
 * \param resFact1 long long int* DIRECCION DE MEMORIA DEL RESULTADO DEL FACTORIAL DEL PRIMER OPERANDO
 * \param resFact2 long long int* DIRECCION DE MEMORIA DEL RESULTADO DEL FACTORIAL DEL SEGUNDO OPERANDO
 * \param flags int BANDERA DE INGRESO DE OPERADORES
 *
 * \return void
 *
 */
void resultados(float* num1, float* num2, float* resSuma, float* resResta, float* resProducto, float* resDivision, long long int* resFact1,long long int* resFact2, int flags);


#endif /* INTERFAZ_H_ */
