/*
 * color.c
 *
 *  Created on: 20 oct. 2021
 *      Author: mkale
 */


#include "color.h"
int cargarDescripcionColores(eColor colores[], int tam, int idColor, char descColor[])
{
	int todoOk = 0;
	if(colores != NULL && tam >0 && descColor != NULL)
	{
		for(int i = 0;i <tam;i++)
		{
			if(colores[i].id == idColor)
			{
				strcpy(descColor, colores[i].nombreColor);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarColores(eColor colores[], int tam)
{
	int todoOk = 0;

	if(colores != NULL && tam >0)
	{
		printf("   *** Colores ***\n");
		printf("    Id    Nombre del Color\n");
		for(int i = 0;i<tam;i++)
		{
			printf("    %d     %10s\n", colores[i].id,colores[i].nombreColor);
		}
		printf("\n\n");
		todoOk = 1;
	}
	return todoOk;
}

int validarIdColor(eColor colores[], int tam, int idBuscado)
{
	int existe = 0;

	if(colores != NULL && tam >0)
	{
		for(int i = 0;i <tam;i++)
		{
			if(colores[i].id == idBuscado)
			{
				existe = 1;
				break;
			}
		}
	}
	return existe;
}

