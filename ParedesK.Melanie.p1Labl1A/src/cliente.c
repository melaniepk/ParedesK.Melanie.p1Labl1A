/*
 * cliente.c
 *
 *  Created on: 27 oct. 2021
 *      Author: mkale
 */


#include "cliente.h"
int cargarNombreCliente(eCliente clientes[], int tam, int idCliente, char nombre[])
{
	int todoOk = 0;
	if(clientes != NULL && tam >0 && nombre != NULL)
	{
		for(int i = 0;i <tam;i++)
		{
			if(clientes[i].id == idCliente)
			{
				strcpy(nombre, clientes[i].nombre);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarClientes(eCliente clientes[], int tam)
{
	int todoOk = 0;
	char auxSexo[10];

	if(clientes != NULL && tam >0)
	{
		printf("   *** Clientes ***\n");
		printf("    Id    Nombre     Sexo\n");
		for(int i = 0;i<tam;i++)
		{
			if(clientes[i].sexo == 'f')
			{
				strcpy(auxSexo,"Mujer");
			}
			else
			{
				strcpy(auxSexo,"Hombre");

			}
			printf("    %d     %10s    %s\n", clientes[i].id,clientes[i].nombre,auxSexo);
		}
		printf("\n\n");
		todoOk = 1;
	}
	return todoOk;
}

int validarIdCliente(eCliente clientes[], int tam, int idBuscado)
{
	int existe = 0;

	if(clientes != NULL && tam >0)
	{
		for(int i = 0;i <tam;i++)
		{
			if(clientes[i].id == idBuscado)
			{
				existe = 1;
				break;
			}
		}
	}
	return existe;
}

