/*
 * operaciones.h
 *
 *  Created on: 3 abr. 2021
 *      Author: Isaac
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_




/**------------FACTORIAL.
 * @fn long int CalcularFactorial(long int)
 * @brief : Calcula el factorial de un numero.
 *
 * @param : numero ingresado por el usuario, sobre el cual se realizar� el c�lculo factorial.
 * @return: retorna el resultado (el factorial del numero ingresado).
 */
long int CalcularFactorial(long int);




/**-------------DIVISION.
 * @fn float DividirNumeros(float, float)
 * @brief : Divide entre dos numeros ingresados.
 *
 * @param : primer numero ingresado, ser� el dividendo.
 * @param : segundo numero ingresado, ser� el divisor.
 * @return: retorna el resultado (cociente).
 */
float DividirNumeros(float,float);




/**-------------MULTIPLICACION.
 * @fn float MultiplicarNumeros(float, float)
 * @brief : Multiplica dos numeros ingresados.
 *
 * @param : primer numero ingresado, ser� el multiplicando.
 * @param : segundo numero ingresado, ser� el multiplicador.
 * @return: retorna el resultado (producto).
 */
float MultiplicarNumeros(float,float);




/**--------------RESTA.
 * @fn float RestarNumeros(float, float)
 * @brief : Resta dos numeros ingresados.
 *
 * @param : primer numero ingresado, ser� el minuendo.
 * @param : segundo numero ingresado, ser� el sustraendo.
 * @return. retorna el resultado (resto).
 */
float RestarNumeros(float,float);




/**--------------SUMA.
 * @fn float SumarNumeros(float, float)
 * @brief : Suma dos numeros ingresados.
 *
 * @param : primer numero ingresado, ser� el primer sumando.
 * @param : segundo numero ingresado, ser� el segundo sumando.
 * @return: retorna el resultado (total).
 */
float SumarNumeros(float,float);

#endif /* OPERACIONES_H_ */


