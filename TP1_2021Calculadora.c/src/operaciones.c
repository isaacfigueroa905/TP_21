/*
 * operaciones.c
 *
 *  Created on: 3 abr. 2021
 *      Author: Isaac
 */


#include <stdio.h>
#include <stdlib.h>



float SumarNumeros(float numeroA ,float numeroB)
{
    float resultado;

    resultado=numeroA+numeroB;

    return resultado;
}

float RestarNumeros(float numeroA,float numeroB)
{
    float resultado;

    resultado=numeroA-numeroB;

    return resultado;
}

float MultiplicarNumeros(float numeroA ,float numeroB)
{
    float resultado;

    resultado=numeroA*numeroB;

    return resultado;
}

float DividirNumeros(float numeroA,float numeroB)
{
    float resultado;

    resultado=numeroA/numeroB;

    return resultado;
}

 long int CalcularFactorial(long int numero)
{
	long int resultado;

	if(numero==0)
	{
		resultado=1;

	}
	else
	{
		resultado=numero*CalcularFactorial(numero-1);
	}
	return resultado;
}

