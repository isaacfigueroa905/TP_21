/*
 * ArrayEmployees.c
 *
 *  Created on: 7 may. 2021
 *      Author: Isaac
 */


#include <stdio.h>

#include "ArrayEmployees.h"
#include <string.h>
#define OCUPADO 1
#define VACIO 0


void InicializadorEmpleados(Employee listado[] ,int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        listado[i].isEmpty=VACIO;
    }
}

Employee Ingreso()
{
     Employee unEmpleado;

    printf("\n\t Carga de empleado\n\n ");
    printf("\t ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", unEmpleado.nombre);
    printf("\n\t ingrese apellido: ");
    fflush(stdin);
    scanf("%[^\n]", unEmpleado.apellido);
    printf("\n\t ingrese sector (del 1 al 10): ");
    scanf("\n%d", &unEmpleado.sector);
    while(unEmpleado.sector<1 || unEmpleado.sector>10)
    {
        printf("\n\t ERROR ingrese un sector valido (1 a 10): ");
        scanf("\n%d", &unEmpleado.sector);
    }
    printf("\n\t ingrese salario: ");
    scanf("\n%f", &unEmpleado.salario);

    unEmpleado.isEmpty=OCUPADO;

    return unEmpleado;
}


int BuscarLibre(Employee listado[], int tam)
{

    int index=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(listado[i].isEmpty==VACIO)
        {
            index=i;
            break;
        }
    }


    return index;
}



int CargarEmpleados(Employee listado[] , int tam)
{
   int i;
   i=BuscarLibre(listado, tam);
   if(i!=-1)
   {
       listado[i] = Ingreso();//exito
       listado[i].id=i;//carga de legajo
   }

   return i;


}


void MostrarEmpleado(Employee unEmpleado)
{
    printf("\n%8d\t%8s\t%9s\t%9.2f\t%7d\n",unEmpleado.id,unEmpleado.nombre, unEmpleado.apellido,
    		                                             unEmpleado.salario, unEmpleado.sector );
    printf("\t________________________________________________________________\n");
}


void MostrarNominaEmpleados(Employee listado [] , int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].isEmpty==OCUPADO)
        {
             MostrarEmpleado(listado[i] );
        }

    }
}

void OrdenarEmpleadosPorApellido(Employee listado[], int tam)
{
    int i;
    int j;
    Employee auxEmpleado;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].apellido,listado[j].apellido)>0 )// A -- Z apellido
            {
                auxEmpleado=listado[i];
                listado[i]=listado[j];
                listado[j]=auxEmpleado;
            }
            if(strcmp(listado[i].apellido,listado[j].apellido)==0)// A -- Z nombre
            {
            	if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            	{
            		auxEmpleado=listado[i];
            		listado[i]=listado[j];
            		listado[j]=auxEmpleado;
            	}
            }

        }
    }
}

void OrdenarEmpleadosPorSector(Employee listado[], int tam)
{
    int i;
    int j;
    Employee auxEmpleado;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(listado[i].sector > listado[j].sector)
            {
                auxEmpleado=listado[i];
                listado[i]=listado[j];
                listado[j]=auxEmpleado;
            }
            if(listado[i].sector == listado[j].sector)
            {
                OrdenarEmpleadosPorApellido(listado,tam);//mismo sector se ordena por apellido/nombre
            }


        }
    }
}


int EliminarEmpleado(Employee listado[], int tam)
{
    int i;
    int legajoIngresado;
    int retorno=1;//por defecto no encontro el legajo
    char decidir;
    printf("\n\t\t ingrese legajo del empleado a eliminar: ");
    scanf("%d", &legajoIngresado);

    for(i=0;i<tam;i++)
    {
       if(listado[i].id==legajoIngresado&&listado[i].isEmpty==OCUPADO)
       {
    	   printf("\n\t\t¿Esta seguro que desea eliminar este empleado?\n\t\t('s'.Si  | 'otra letra'.Volver al menu principal)\n");
    	   MostrarEmpleado(listado[i]);
    	   fflush(stdin);
    	   scanf("\n %s",& decidir);
    	   if(decidir=='s')//elimina
    	   {
    		   listado[i].isEmpty=VACIO;
    		   retorno=0;
    		   break;
    	   }
    	   else
    	   {
    		   printf("\n\t\t volviendo al menu!!!\n\n");//niega
    		   retorno=-1;
    	   }


       }
       else
       {

           retorno=1;//no encuentra

       }
    }
    return retorno;

}


int ModificarDatoEmpleado(Employee listado[], int tam)
{
    int i;
    int legajoIngresado;
    int opc;
    int retorno=-1;


    printf("\n\t\t Ingrese numero de legajo del empleado a modificar: ");
    scanf("%d", &legajoIngresado);
    for(i=0;i<tam;i++)
    {
        if(listado[i].id==legajoIngresado&&listado[i].isEmpty==OCUPADO)
        {
            printf("\n\t\t ¿Que cambio desea realizar a este empleado?\n\n ");
            MostrarEmpleado(listado[i]);
            printf("\t\t1.Nombre  2.Apellido   3.Sector   4.Sueldo:  ");
            scanf(" %d",&opc);
             while(opc!=1 &&opc!=2 &&opc!=3 &&opc!=4)
            {

                printf("Error reingrese una opcion valida!!!");
                printf("\n\t\t ¿Que cambio desea realizar?\n\n ");
                printf("\t\t 1.Nombre  2.Apellido   3.Sueldo   4.Sector:  ");
                scanf(" %d",&opc);

            }
            switch(opc)
            {
                case 1:
                    printf("\n\t\t Ingrese nuevo nombre : ");
                    fflush(stdin);
                    scanf("%[^\n]", listado[i].nombre);
                    retorno=0;
                break;

                case 2:
                    printf("\n\t\t Ingrese nuevo apellido : ");
                    fflush(stdin);
                    scanf("%[^\n] ", listado[i].apellido);
                    retorno=0;
                break;

                case 3:
                    printf("\n\t\t Ingrese nuevo sector : ");
                    scanf("%d", &listado[i].sector);
                    retorno=0;
                break;

                case 4:
                    printf("\n\t\t Ingrese nuevo sueldo : ");
                    scanf("%f", &listado[i].salario);
                    retorno=0;
                break;


            }
        }

    }
    return retorno;

}


float TotalSueldos(Employee listado[], int tam )
{
    int i;
    float acumuladorDeSueldos=0;

    for(i=0; i<tam; i++)
    {
    	if(listado[i].isEmpty==OCUPADO)
    	{
    		acumuladorDeSueldos=acumuladorDeSueldos+listado[i].salario;
    	}

    }
    return acumuladorDeSueldos;
}

int ContadorDeEmpleados(Employee listado[], int tam)
{
	int i;
	int cantidad=0;
	int index;

	index=BuscarLibre(listado,tam);
	for(i=0; i<tam; i++)
	{
		if( index!=-1&& listado[i].isEmpty==OCUPADO)
		{
			cantidad++;

		}




	}
	return cantidad;
}

