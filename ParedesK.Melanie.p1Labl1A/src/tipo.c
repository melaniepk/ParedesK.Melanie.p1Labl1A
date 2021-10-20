/*
 * tipo.c
 *
 *  Created on: 20 oct. 2021
 *      Author: mkale
 */


#include "tipo.h"

int cargarDescripcionTipos(eTipo tipos[], int tam, int idTipo, char descTipo[])
{
	int todoOk = 0;
	if(tipos != NULL && tam >0 && descTipo != NULL)
	{
		for(int i = 0;i <tam;i++)
		{
			if(tipos[i].id == idTipo)
			{
				strcpy(descTipo, tipos[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarTipos(eTipo tipos[], int tam)
{
	int todoOk = 0;

	if(tipos != NULL && tam >0)
	{
		printf("   *** Tipos ***\n");
		printf("    Id    Descripcion\n");
		for(int i = 0;i<tam;i++)
		{
			printf("    %d     %10s\n", tipos[i].id,tipos[i].descripcion);
		}
		printf("\n\n");
		todoOk = 1;
	}
	return todoOk;
}

int validarIdTipo(eTipo tipos[], int tam, int idBuscado)
{
	int existe = 0;

	if(tipos != NULL && tam >0)
	{
		for(int i = 0;i <tam;i++)
		{
			if(tipos[i].id == idBuscado)
			{
				existe = 1;
				break;
			}
		}
	}
	return existe;
}

