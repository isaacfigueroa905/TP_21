/*
 ============================================================================
 Name        : TP1_2021Calculadora.c
 Author      : Figueroa Isaac
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"


int main(void)
{
	setbuf(stdout,NULL);
	float primerNumero;
	float segundoNumero;
	long int  numeroA;
	long int numeroB;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    long int resultadoFactorialA;
    long int resultadoFactorialB;
	int opcion;
	int banderaDelTres;
	int banderaDelDos;
	int banderaDelUno;

		banderaDelUno=0;
		banderaDelDos=0;
	    banderaDelTres=0;
	    printf("\t------------CALCULADORA------------\n");//MENU
	    do
	    {
	        printf("\t***********************************\n");
	        printf("\tElija una opcion:\n");
	        printf("\t1.Ingresar primer operando (A=x) \n");
	        printf("\t2.Ingresar segundo operando (B=y) \n");
	        printf("\t3.Calcular todas las operaciones \n");
	        printf("\t4.Informar resultados \n");
	        printf("\t5.Salir\n");
	        scanf("%d", &opcion);
	        printf("\t***********************************\n");

	        while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5)
	        {
	            printf("\t***********************************\n");
	            printf("\tError!!! ingrese una opcion valida:\n");
	            printf("\t1.Ingresar primer operando (A =x) \n");
	            printf("\t2.Ingresar segundo operando (B =y) \n");
	            printf("\t3.Calcular todas las operaciones \n");
	            printf("\t4.Informar resultados\n");
	            printf("\t5.Salir\n");
	            scanf("%d", &opcion);
	            printf("\t*************************************\n");
	        }

	        switch(opcion)
	        {
	            case 1://ingresa primer valor.
	            	banderaDelUno=1;
	                printf("\tIngrese primer operando: X = ");
	                scanf("%f", &primerNumero);
	                printf("\t...X =%.2f\n",primerNumero);

	                break;

	            case 2://ingresa el segundo valor.
	            	banderaDelDos=1;
	                printf("\tIngrese segundo operando: y = ");
	                scanf("%f", &segundoNumero);
	                printf("\t...Y =%.2f\n", segundoNumero);

	                break;

	            case 3://realiza el calculo de todas las operaciones.
	                banderaDelTres=1;

	                if(banderaDelUno==0)//al no ingresar ningun valor, a=0
	                {
	                	primerNumero=0;
	                }
	                if(banderaDelDos==0)//al no ingresar ningun valor, b=0
	                {
	                	segundoNumero=0;
	                }

	                printf("\tCalculando operaciones...\n");

	                printf("\ta)-Suma (A+B)\n ");
	                suma=SumarNumeros(primerNumero,segundoNumero);//suma.

	                printf("\tb)-Resta (A-B)\n ");
	                resta=RestarNumeros(primerNumero,segundoNumero);//resta.

	                if(segundoNumero!=0)//  ignorar division si se ingresa 0 como divisor(B).
	                {
	                	 printf("\tc)-Division (A/B)\n ");
	                     division=DividirNumeros(primerNumero,segundoNumero);//divide.
	                }
	                else
	                {
	                	printf("\tError matemático, imposible dividir por 0!!!\n");
	                }


	                printf("\td)-Multiplicacion (A*B)\n ");
	                multiplicacion=MultiplicarNumeros(primerNumero,segundoNumero);//multiplica.

	                printf("\te)-Factorial (A!) y Factorial (B!)\n ");//factorial

	                numeroA=(long int) primerNumero;
	                numeroB=(long int) segundoNumero;

	                //el programa rompia al ingresar numeros negativos...
	                if(numeroA >= 0)//calculo factorial numeros positivos
	                {
	                	resultadoFactorialA=CalcularFactorial(numeroA);

	                }
	                else
	                {
	                	numeroA=numeroA*-1;//transforma numero negativo en positivo
	                	resultadoFactorialA=CalcularFactorial(numeroA);//ahora puede calcular sin romper
	                }
	                if(numeroB >=0)//calculo factorial numeros positivos
	                {
	                	resultadoFactorialB=CalcularFactorial(numeroB);
	                }
	                else
	                {
	                	numeroB=numeroB*-1;
	                	resultadoFactorialB=CalcularFactorial(numeroB);
	                }





	                break;

	            case 4://muestra resultado de operaciones.
	                if(banderaDelTres==1)// verifica que para "mostrar resultados" primero se haya "calculado".
	                {
	                    printf("\tResultados: \n");

	                    printf("\ta)-El resultado de %.2f + %.2f es: %.2f\n ",primerNumero,segundoNumero,suma);
	                   	printf("\tb)-El resultado de %.2f - %.2f es: %.2f\n ",primerNumero,segundoNumero,resta);

	                   	if(segundoNumero==0)
	                   	{
	                   		printf("\tc)-Error matematico!!! imposible dividir por 0...\n");//mostrar si 0 como denominador
	                   	}
	                   	else
	                   	{
	                   		printf("\tc)-El resultado de %.2f / %.2f es: %.2f\n ",primerNumero,segundoNumero,division);
	                   	}

	                   	printf("\td)-El resultado de %.2f X %.2f es: %.2f\n ",primerNumero,segundoNumero,multiplicacion);


//------------Factorial: La capacidad maxima del long int es superada por los factoriales mayores a 12...,

	                   	if(primerNumero<0 && primerNumero>=-13)
	                   	{
	                   		printf("\te)-El factorial de -%ld es: -%ld\n",numeroA,resultadoFactorialA);//mostrar si A es negativo y mayor que -13
	                   	}
	                   	else
	                   	{
	                   		if(primerNumero>=0 && primerNumero<=13)
	                   		{
	                   			printf("\te)-El factorial de %ld es: %ld\n",numeroA,resultadoFactorialA);//mostrar si A es positivo y menor que 13
	                   		}
	                   	    if(primerNumero<=-13||primerNumero>=13)
	                   	    {
	                   		    printf("\te)-El resultado de !A supera la capacidad de memoria!!!\n");//mostrar si A es mayor que 13 o menor que -13
	                   	    }

	                   	}
	              //------

	                   	if(segundoNumero<0 && segundoNumero>=-13)
	                   	{
	                   		printf("\t  -El factorial de -%ld es: -%ld\n",numeroB,resultadoFactorialB);//mostrar si B es negativo y mayor que -13
	                   	}
	                   	else
	                   	{
	                   		if(segundoNumero>=0 && segundoNumero<=13)
	                   		{
	                   			printf("\t  -El factorial de %ld es: %ld\n",numeroB,resultadoFactorialB);//mostrar si B es positivo y menor que 13
	                   		}
	                   		if(segundoNumero<=-13||segundoNumero>=13)
	                   		{
	                   		    printf("\t  -El resultado de !B supera la capacidad de memoria!!!\n");//mostrar si B es mayor que 13 o menor que -13
	                   		}

	                   	}

	                   	break;
	                }
	                else
	                {
	                	printf("\tPara mostrar resultados,\n\tprimero seleccione opcion 3...\n");//no muestra resultados sin antes opcion calcular
	                	break;

	                }


	            case 5:

	            	printf("\t\t\t\t...Saliendo !!!\n");
	            	break;




	        }


	    }while(opcion!=5);

	return EXIT_SUCCESS;
}
