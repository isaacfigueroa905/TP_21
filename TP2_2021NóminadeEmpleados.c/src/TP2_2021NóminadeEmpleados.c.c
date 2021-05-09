/*
 ============================================================================
 Name        : NóminadeEmpleados.c
 Author      : Figueroa Isaac
 Version     : 2021
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define T 1000







int main(void)
{
	setbuf(stdout,NULL);
	Employee empleado[T];
	int retornoCarga;
	int retornoEliminar;
	int retornoModificacion;
	float sueldosEmpleados;
	float promediar;
	int opcion;
	int opcionSubmenu;
	int banderaPrimerEmpleado=0;

	InicializadorEmpleados(empleado ,T);

	 do
	    {
		 	printf("\n\t\t********************");
	        printf("\n\t\t\t  MENU:");
	        printf("\n\t\t 1. ALTAS");
	        printf("\n\t\t 2. MODIFICAR");
	        printf("\n\t\t 3. BAJAS");
	        printf("\n\t\t 4. INFORMAR");
	        printf("\n\t\t 0. SALIR");
	        printf("\n\t\t********************\n");
	        printf("\n\n\t\t Seleccione una opcion:  ");

	        scanf("%d",&opcion);
	        while(opcion<0 || opcion>4)
	        {
	        	printf("\n\t\t********************\n");
	            printf("\nSeleccione una opcion valida!!!:  ");
	            scanf("%d",&opcion);
	        }
	        switch(opcion)
	        {
	            case 1:
	            	banderaPrimerEmpleado=1;
	            	printf("\n\t\t\t Carga de empleados\n ");
	            	retornoCarga=CargarEmpleados(empleado,T);
	            	if(retornoCarga!=-1)
	            	{
	            		printf ("\n\t\t\t Carga de empleado realizada con exito!\n");
	            	}
	            	else
	            		{
	            			printf ("\n\t\t\t Sin espacio para realizar otra carga!\n");
	            		}


	            break;
	            case 2:
	            	if(banderaPrimerEmpleado==1)
	            	{
	            		printf("\n\t\tModificar\n");
	            		printf("\n  LEGAJO \t NOMBRE \t APELLIDO  \t SALARIO\t SECTOR\n\n ");
	            	    OrdenarEmpleadosPorApellido(empleado,T);
	            	    MostrarNominaEmpleados(empleado,T);
	            	    retornoModificacion=ModificarDatoEmpleado(empleado,T);
	            	    if(retornoModificacion==0)
	            	    {
	            			printf("\n\t\t Modificacion realizada con exito!");

	            		}
	            	    else
	            		{
	            			 printf("\n\t\t No se encontro el legajo ingresado, intente nuevamente!");
	            		}


	            	}
	            	else
	            	{
	            		printf("\n\t\t todavia no se ingreso ningun empleado!!!");
	            	}


	            break;
	            case 3:
	            	if(banderaPrimerEmpleado==1)
	            	{
	            		printf("\n\t\tEliminar\n");
	            		printf("\n  LEGAJO \t NOMBRE \t APELLIDO  \t SALARIO\t SECTOR\n\n ");
	            	    OrdenarEmpleadosPorApellido(empleado,T);
	            		MostrarNominaEmpleados(empleado,T);
	            	    retornoEliminar=EliminarEmpleado(empleado,T);
	            	    if(retornoEliminar==0)
	            		{
	            			  printf("\n\t\t Empleado eliminado exitosamente!\n");
	            	    }
	            		if(retornoEliminar==1)
	            	    {
	            			  printf("\n\t\t No se encontro legajo!\n");
	            		}


	            	}
	            	else
	            	{
	            		printf("\n\t\t todavia no se ingreso ningun empleado!!!");
	            	}


	            break;

	            case 4:
	            	if(banderaPrimerEmpleado==1)
	            	{
	            		do
	            		{
	            			  printf("\n\tSUBMENU DE INFORMES ");
	            			  printf("\n\t\t\t 1.Mostrar nomina por apellido");
	            			  printf("\n\t\t\t 2.Mostrar nomina por sector");
	            			  printf("\n\t\t\t 3.Mostrar promedio de sueldos");
	            			  printf("\n\t\t\t 4.Mostrar total de sueldos");
	            			  printf("\n\t\t\t 0.Volver menu principal");
	            			  printf("\n\t\t\t Seleccione una opcion: ");
	            			  scanf("%d",&opcionSubmenu);
	            			  while(opcionSubmenu!=0 && opcionSubmenu!=1 && opcionSubmenu!=2&& opcionSubmenu!=3&& opcionSubmenu!=4)
	            			  {
	            			         printf("\n\t\t\t\t ERROR ingrese una opcion valida!!!\n");
	            			         scanf("%d",&opcionSubmenu);
	            			  }
	            			          switch(opcionSubmenu)
	            			          {
	            			           	   	   case 1:
	            			            		   printf("\n  LEGAJO \t NOMBRE \t APELLIDO  \t SALARIO\t SECTOR\n\n ");
	            			            		   OrdenarEmpleadosPorApellido(empleado,T);
	            			            		   MostrarNominaEmpleados(empleado,T);
	            			            		   break;

	            			            		case 2:
	            			            			printf("\n  LEGAJO \t NOMBRE \t APELLIDO  \t SALARIO\t SECTOR\n\n ");
	            			            			OrdenarEmpleadosPorSector(empleado,T);
	            			            			MostrarNominaEmpleados(empleado,T);
	            			            			break;

	            			            		case 3:


	            			            			promediar=TotalSueldos(empleado,T)/ContadorDeEmpleados(empleado,T);
	            			          	            printf("\n\t\t El promedio salarial es : %.2f\n", promediar);
	            			          	            break;

	            			            		case 4:
	            			            			sueldosEmpleados=TotalSueldos(empleado,T);
	            			            			printf("\n\t\t El sueldo total de los empleados es : %.2f\n",sueldosEmpleados);
	            			            			break;

	            			         }

	          	        }while(opcionSubmenu!=0);

	            	}
	            	else
	            	{
	            		printf("\n\t\t todavia no se ingreso ningun empleado!!!");
	            	}




	            	 break;


	            case 0:
	                printf("\n\t\t\t\t saliendo...\n");

	            break;

	        }





	    }while(opcion!=0);

	return EXIT_SUCCESS;
}



