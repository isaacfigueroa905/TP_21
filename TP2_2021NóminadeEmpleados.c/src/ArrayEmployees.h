/*
 * ArrayEmployees.h
 *
 *  Created on: 7 may. 2021
 *      Author: Isaac
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_





typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
} Employee;



/**
 * @fn int ContadorDeEmpleados(Employee[], int)
 * @brief Cuenta la cantidad de empleados
 *
 * @param int: tamaño del array.
 * @param Employee:array.
 * @return El total de empleados.
 */
int ContadorDeEmpleados(Employee[], int);
/**
 * @fn float TotalSueldos(Employee[], int)
 * @brief Suma el total de los sueldos de todos los empleados.
 *
 * @param int: tamaño del array.
 * @param Employee:array.
 * @return El total de la suma.
 */
float TotalSueldos(Employee [], int);
/**
 * @fn int ModificarDatoEmpleado(Employee[], int)
 * @brief Modifica algun campo del empleado.
 *
 * @param int: tamaño del array.
 * @param Employee:array.
 * @return 0 si la modificacion logro efectuarse, -1 si no se encontro legajo a modificar.
 */
int ModificarDatoEmpleado(Employee[], int);
/**
 * @fn int EliminarEmpleado(Employee[], int)
 * @brief  Elimina un empleado si el usuario confirma, mediante una baja logica.
 *
 * @param int: tamaño del array.
 * @param Employee:array.
 * @return 0 si el usuario confirma; -1 si niega; 1 si no encuentra el legajo a eliminar.
 */
int EliminarEmpleado(Employee[], int);


/**
 * @fn void OrdenarEmpleadosPorSector(Employee[], int)
 * @brief  Ordena empleados por sector, en caso de ser iguales compara por apellido usando la funcion creada para tal fin.
 *
 * @param int: tamaño del array.
 * @param Employee:array.
 */
void OrdenarEmpleadosPorSector(Employee[], int);

/**
 * @fn void OrdenarEmpleadosPorApellido(Employee[], int)
 * @brief Ordena empleados por apellido, en caso de ser iguales compara por nombre.
 *
 * @param int: tamaño del array.
 * @param Employee:array.
 */
void OrdenarEmpleadosPorApellido(Employee[], int);
/**
 * @fn void MostrarNominaEmpleados(Employee[], int)
 * @brief Muestra todos los empleados cargados.
 *
 * @param int: tamaño del array.
 * @param Employee:array.
 */
void MostrarNominaEmpleados(Employee[] , int);

/**
 * @fn void MostrarEmpleado(Employee)
 * @brief Muestra un solo empleado.
 *
 * @param Employee: tipo de dato que recibe.
 */
void MostrarEmpleado(Employee);
/**
 * @fn int CargarEmpleados(Employee[], int)
 * @brief Carga empleado en lugar libre y a su vez asigna un legajo.
 *
 * @param int:tamaño del array.
 * @param Employee:array.
 * @return numero de indice que sera usado en el main para deducir si queda espacio.
 */
int CargarEmpleados(Employee listado[] , int tam);
/**
 * @fn int BuscarLibre(Employee[], int)
 * @brief Busca lugar libre dentro del array.
 *
 * @param int: tamaño del array.
 * @param Employee: array.
 * @return numero de indice si encuentra lugar libre, -1 si no encuentra.
 */
int BuscarLibre(Employee[], int );

/**
 * @fn void InicializadorEmpleados(Employee[], int)
 * @brief Inicializa el campo isEmpty en VACIO de todo el array.
 *
 * @param int: tamaño del array
 * @param Employee: array
 */
void InicializadorEmpleados(Employee [] ,int);
/**
 * @fn Employee Ingreso()
 * @brief Pide los datos de un empleado al usuario
 *
 * @return Retorna un dato del tipo eEmpleado
 */
Employee Ingreso();











#endif /* ARRAYEMPLOYEES_H_ */
