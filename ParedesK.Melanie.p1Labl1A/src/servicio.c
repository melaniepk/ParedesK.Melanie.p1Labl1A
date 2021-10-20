/*
 * servicio.c
 *
 *  Created on: 20 oct. 2021
 *      Author: mkale
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

int mostrarServicios(eServicio servicios[], int tam)
{
	int todoOk = 0;

	if(servicios != NULL && tam >0)
	{
		printf("   *** Servicios ***\n");
		printf("    Id    Descripcion     Precio\n");
		for(int i = 0;i<tam;i++)
		{
			printf("    %d     %10s    %.2f\n", servicios[i].id,servicios[i].descripcion, servicios[i].precio);
		}
		printf("\n\n");
		todoOk = 1;
	}
	return todoOk;
}

int cargarDescripcionServicio(eServicio servicios[], int tam, int idServicio, char descServicio[])
{
	int todoOk = 0;
	if(servicios != NULL && tam >0 && descServicio != NULL)
	{
		for(int i = 0;i <tam;i++)
		{
			if(servicios[i].id == idServicio)
			{
				strcpy(descServicio, servicios[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int validarIdServicio(eServicio servicios[], int tam, int idBuscado)
{
	int existe = 0;

	if(servicios != NULL && tam >0)
	{
		for(int i = 0;i <tam;i++)
		{
			if(servicios[i].id == idBuscado)
			{
				existe = 1;
				break;
			}
		}
	}
	return existe;
}

