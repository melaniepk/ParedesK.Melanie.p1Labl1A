/*
 * trabajo.c
 *
 *  Created on: 20 oct. 2021
 *      Author: mkale
 */


#include "trabajo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "utn1.h"
#include "moto.h"



int inicializarTrabajos(eTrabajo lista[], int tam)
{
	int todoOk = 0;
	if(lista != NULL && tam >0)
	{
		for(int i = 0;i<tam ;i++)
		{
			lista[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarLibreT(eTrabajo lista[], int tam)
{
	int indice = -1;
	if(lista != NULL && tam >0)
	{
		for(int i = 0;i<tam ;i++)
		{
			if(lista[i].isEmpty == 1)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
int altaTrabajo(eTrabajo trabajo[],int tamTra,eMoto lista[], int tam,eServicio servicios[],
		int tamServicios,eTipo tipos[], eColor colores[],int tamTipos, int tamColores, int *pId,int *pIdMoto)
{
	int todoOk = 0;
	int indice;
	eTrabajo auxTrabajo;
	eFecha auxFecha;

	if(lista!= NULL && tam >0 && pId != NULL && trabajo != NULL && servicios != NULL && tipos != NULL && colores != NULL && tamTra >0
			&& tamServicios >0 && tamTipos >0 && tamColores >0 )
	{
		system("cls");
		printf("    *** Alta Trabajo ***\n");
		indice = buscarLibreT(trabajo,tamTra);
		if(indice == -1)
		{
			printf("No hay lugar en el sistema\n");
		}
		else
		{
			auxTrabajo.id = *pId;
			(*pId)++;

			mostrarMotos(lista,tipos, colores,tamTipos,tamColores,tam);
			printf("Ingrese id de la moto: \n");
			scanf("%d",&auxTrabajo.idMoto);
			while(!validarIdMoto(lista,tam,auxTrabajo.idMoto))
			{
				mostrarMotos(lista,tipos,colores,tamTipos,tamColores,tam);
				printf("Id no registrado, volver a ingresar\n");
				scanf("%d",&auxTrabajo.idMoto);
			}


			mostrarServicios(servicios,tamServicios);

			utn_getNumero(&auxTrabajo.idServicio,"Ingrese id del servicio", "Error\n", 20000,20003,10);
			while(!validarIdServicio(servicios,tamServicios,auxTrabajo.idServicio))
			{
				mostrarServicios(servicios,tamServicios);
				printf("Id no registrado, volver a ingresar\n");
				scanf("%d",&auxTrabajo.idServicio);
			}

			printf("Ingrese fecha: \n");
			scanf("%d %d %d",&auxFecha.dia, &auxFecha.mes,&auxFecha.anio);
			while(auxFecha.dia >31 || auxFecha.dia <1 || auxFecha.mes >12 || auxFecha.mes <1 || auxFecha.anio >2021)
			{
				printf("Error\n");
				printf("Ingrese fecha: \n");
				scanf("%d %d %d",&auxFecha.dia, &auxFecha.mes,&auxFecha.anio);
			}

			auxTrabajo.fecha = auxFecha;


		}
			auxTrabajo.isEmpty = 0;

			trabajo[indice] = auxTrabajo;
			todoOk = 1;



		}


	return todoOk;

}


int listarTrabajo(eTrabajo trabajos, eMoto lista[],eServicio servicios[], int tam, int tamServicios)
{
	int todoOk = 0;
	char descServicio[20];

	cargarDescripcionServicio(servicios, tamServicios, trabajos.idServicio, descServicio);

	printf("  %d\t %d\t    %s\t   %d/%d/%d\n", trabajos.id,
											trabajos.idMoto,
											descServicio,
											trabajos.fecha.dia,
											trabajos.fecha.mes,
											trabajos.fecha.anio);

	return todoOk;
}

int mostrarTrabajos(eTrabajo trabajos[],int tamTra,eMoto lista[],eServicio servicios[],int tamServicios, int tam)
{
	int todoOk = 0;
	int flag = 1;
	if(lista != NULL && tam >0 && trabajos != NULL && servicios != NULL && tamServicios >0 && tamTra >0)
	{
		system("cls");
		printf("   *** Listado de Trabajos ***\n");
		printf("ID  Id Moto     Servicio     Fecha\n");
		printf("------------------------------------------\n");

		for(int i = 0;i <tamTra ;i++)
		{
				if(!trabajos[i].isEmpty)
				{
					listarTrabajo(trabajos[i],lista,servicios,tam,tamServicios);
					flag = 0;
				}


		}
		if(flag)
		{
			printf("    NO hay trabajos para mostrar\n");
		}
		todoOk = 1;

	}
	return todoOk;
}
