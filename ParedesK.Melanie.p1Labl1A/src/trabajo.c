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
int altaTrabajo(eCliente clientes[], int tamCli,eTrabajo trabajo[],int tamTra,eMoto lista[], int tam,eServicio servicios[],
		int tamServicios,eTipo tipos[], eColor colores[],int tamTipos, int tamColores, int *pId,int *pIdMoto)
{
	int todoOk = 0;
	int indice;
	eTrabajo auxTrabajo;
	eFecha auxFecha;

	if(lista!= NULL && tam >0 && pId != NULL && trabajo != NULL && servicios != NULL && tipos != NULL && colores != NULL && tamTra >0
			&& tamServicios >0 && tamTipos >0 && tamColores >0 && clientes != NULL && tamCli >0)
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

			mostrarMotos(clientes,tamCli,lista,tipos, colores,tamTipos,tamColores,tam);
			printf("Ingrese id de la moto: \n");
			scanf("%d",&auxTrabajo.idMoto);
			while(!validarIdMoto(lista,tam,auxTrabajo.idMoto))
			{
				mostrarMotos(clientes,tamCli,lista,tipos,colores,tamTipos,tamColores,tam);
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
	char descMoto[20];

	if(lista != NULL && servicios != NULL && tam >0 && tamServicios >0)
	{
		cargarDescripcionServicio(servicios, tamServicios, trabajos.idServicio, descServicio);
		cargarDescripcionMoto(lista,tam,trabajos.idMoto,descMoto);

		printf("  %d\t %12s\t    %12s\t   %d/%d/%d\n", trabajos.id,
												descMoto,
												descServicio,
												trabajos.fecha.dia,
												trabajos.fecha.mes,
											trabajos.fecha.anio);
	}
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
		printf("ID       Marca Moto           Servicio         Fecha\n");
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

int mostrarTrabajosMoto(eCliente clientes[], int tamCli,eTrabajo trabajos[],eServicio servicios[],eMoto lista[],eTipo tipos[],eColor colores[],int tamt,int tamSer, int tam, int tamTi, int tamc)
{

	int todoOk =0;
	eTrabajo auxTrabajo;
	int flag =0;

	if(trabajos != NULL && lista != NULL && tipos != NULL && colores != NULL && tam >0 && tamt>0 && tamTi >0 && tamc>0 && clientes != NULL && tamCli >0)
	{
		system("cls");
		printf("   *** Listado de Trabajos por Moto ***\n");

		mostrarMotos(clientes,tamCli,lista,tipos, colores,tamTi,tamc,tam);
		printf("Ingrese id de la moto: \n");
		scanf("%d",&auxTrabajo.idMoto);
		while(!validarIdMoto(lista,tam,auxTrabajo.idMoto))
		{
			mostrarMotos(clientes,tamCli,lista,tipos,colores,tamTi,tamc,tam);
			printf("Tipo no registrado, volver a ingresar\n");
			scanf("%d",&auxTrabajo.idMoto);
		}

		printf("Trabajos realizados a la moto:\n");
		printf("ID    Moto     Servicio     Fecha\n");
		printf("------------------------------------------\n");

		for(int i =0;i<tam;i++)
		{
			for(int j =0;j<tamt;j++)
			{
				if(!lista[i].isEmpty && !trabajos[j].isEmpty && lista[i].id == auxTrabajo.idMoto && lista[i].id == trabajos[j].idMoto)
				{
					listarTrabajo(trabajos[j],lista,servicios,tam,tamSer);
					flag =1;
				}

			}

		}
		if(flag == 0)
		{
			printf("No se relizaron trabajos en esta Moto\n");
		}
		todoOk =1;
	}
	return todoOk;

}

int sumaServiciosPorMoto(eCliente clientes[], int tamCli,eTrabajo trabajos[],eServicio servicios[],eMoto lista[],eTipo tipos[],eColor colores[],int tamt,int tamSer, int tam, int tamTi, int tamc)
{
	int todoOk =0;
	int auxId;
	float suma =0;
	if(trabajos != NULL && lista != NULL && tipos != NULL && colores != NULL && tam >0 && tamt>0 && tamTi >0 && tamc>0 && clientes != NULL && tamCli >0)
	{
		system("cls");
		printf("   *** Suma de Importes por los servicios por Moto ***\n");

		mostrarMotos(clientes,tamCli,lista,tipos, colores,tamTi,tamc,tam);
		printf("Ingrese id de la moto: \n");
		scanf("%d",&auxId);
		while(!validarIdMoto(lista,tam,auxId))
		{
			mostrarMotos(clientes,tamCli,lista,tipos,colores,tamTi,tamc,tam);
			printf("Id no registrado, volver a ingresar\n");
			scanf("%d",&auxId);
		}


		for(int i =0;i<tam;i++)
		{
			for(int j =0;j<tamt;j++)
			{
				for(int k =0;k< tamSer;k++)
				{
					if(!lista[i].isEmpty && !trabajos[j].isEmpty && lista[i].id == auxId && lista[i].id == trabajos[j].idMoto && trabajos[j].idServicio == servicios[k].id )
					{
						suma = suma + servicios[k].precio;
					}
				}


			}

		}
		printf("Suma de los servicios de la moto seleccionada: %6.2f\n ",suma);


		todoOk =1;
	}
	return todoOk;
}


int servicioMotoYFecha(eCliente clientes[], int tamCli,eTrabajo trabajos[],eServicio servicios[],eMoto lista[],eTipo tipos[],eColor colores[],int tamt,int tamSer, int tam, int tamTi, int tamc)
{
	int todoOk =0;
	int auxId;
	if(trabajos != NULL && lista != NULL && tipos != NULL && colores != NULL && tam >0 && tamt>0 && tamTi >0 && tamc>0 && clientes != NULL && tamCli >0)
	{
		system("cls");
		printf("   *** Motos que se realizaron determinado servicio ***\n");
		todoOk =1;

		mostrarServicios(servicios,tamSer);
		printf("Ingrese id del servicio: \n");
		scanf("%d",&auxId);
		while(!validarIdServicio(servicios,tamSer,auxId))
		{
			mostrarServicios(servicios,tamSer);
			printf("Id no registrado, volver a ingresar\n");
			scanf("%d",&auxId);
		}

		printf("   ID         Marca        Tipo            Color        Cilindrada    Puntaje    Cliente\n");

		for(int i =0;i <tamSer;i++)
		{
			for(int j =0;j<tamt;j++)

			{
				for(int k =0;k<tam;k++)
				{
					if(servicios[i].id == auxId && servicios[i].id && trabajos[j].idServicio == servicios[i].id && !trabajos[j].isEmpty && lista[k].id == trabajos[j].idMoto)
					{

						mostrarMoto(clientes,tamCli,lista[k],tipos, colores, tamTi,tamc);
						printf("Fecha: %d/%d/%d\n", trabajos[j].fecha.dia,trabajos[j].fecha.mes,trabajos[j].fecha.anio);
						printf("\n\n");
					}

				}
			}
		}

	}
	return todoOk;
}


int serviciosRealizadosPorFecha(eTrabajo trabajos[],eServicio servicios[],eMoto lista[],eTipo tipos[],eColor colores[],int tamt,int tamSer, int tam, int tamTi, int tamc)
{
	int todoOk =0;
	int auxDia;
	int auxMes;
	int auxAnio;
	int flag =0;
	if(trabajos != NULL && lista != NULL && tipos != NULL && colores != NULL && tam >0 && tamt>0 && tamTi >0 && tamc>0 && servicios != NULL && tamSer >0)
	{
		system("cls");
		printf("   *** Servicios que se realizaron en determinada fecha ***\n");

		printf("Ingrese fecha: \n");
		scanf("%d %d %d",&auxDia, &auxMes,&auxAnio);


		for(int i=0;i<tamt;i++)
		{
			if(trabajos[i].isEmpty==0 && trabajos[i].fecha.dia == auxDia && trabajos[i].fecha.mes == auxMes && trabajos[i].fecha.anio)
			{
				listarTrabajo(trabajos[i],lista,servicios,tam,tamSer);
				flag =1;
			}

		}
		if(flag ==0)
		{
			printf("No se realizaron trabajos este dia\n");
		}

		todoOk =1;
	}
	return todoOk;
}

int informes(eCliente clientes[], int tamCli,eMoto lista[],eTipo tipos[], eColor colores[], int tamTipos, int tamColores, int tam,eServicio servicios[],int tamSer,eTrabajo trabajos[], int tamTra)
{
	int todoOk = 0;

	if(lista!= NULL && tam >0 && clientes != NULL && tipos != NULL && colores != NULL && servicios != NULL&& trabajos!= NULL && tamCli >0 && tamTipos >0 && tamColores >0 && tamSer >0 && tamTra >0)
	{
		system("cls");

		switch(menuInformes())
		{
			case 1:
				system("cls");
				informeMotosColor(clientes,tamCli,lista,tam,tipos,tamTipos,colores,tamColores);
				break;
			case 2:
				system("cls");
				informePromedioMotosTipo(clientes,tamCli,lista,tam,tipos,tamTipos,colores,tamColores);
				break;
			case 3:
				system("cls");
				motoMayorCilindrada(clientes,tamCli,lista,tam,tipos,tamTipos,colores,tamColores);
				break;
			case 4:
				system("cls");
				informeMotosAllTipos(clientes,tamCli,lista,tam,tipos,tamTipos,colores,tamColores);
				break;
			case 5:
				system("cls");
				cantidadMotosPorTipoYColor(lista,tam,tipos,tamTipos,colores,tamColores);
				break;
			case 6:
				system("cls");
				informeColoresMasElegidos(lista,tam,tipos,tamTipos,colores,tamColores);
				break;
			case 7:
				system("cls");
				mostrarTrabajosMoto(clientes,tamCli,trabajos,servicios,lista,tipos,colores,tamTra,tamSer,tam,tamTipos,tamColores);
				break;
			case 8:
				system("cls");
				sumaServiciosPorMoto(clientes,tamCli,trabajos,servicios,lista,tipos,colores,tamTra,tamSer,tam,tamTipos,tamColores);
				break;
			case 9:
				system("cls");
				servicioMotoYFecha(clientes,tamCli,trabajos,servicios,lista,tipos,colores,tamTra,tamSer,tam,tamTipos,tamColores);
				break;
			case 10:
				system("cls");

				serviciosRealizadosPorFecha(trabajos,servicios,lista,tipos,colores,tamTra,tamSer,tam,tamTipos,tamColores);
				break;
			default:
				printf("opcion invalida\n");
		}

	}
	return todoOk;
}

