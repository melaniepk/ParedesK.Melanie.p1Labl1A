/*
 * moto.c
 *
 *  Created on: 20 oct. 2021
 *      Author: mkale
 */


#include "moto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
#include "tipo.h"
#include "color.h"
#include "utn1.h"
int menu()
{
	int opcion;
	system("cls");
	printf("        *** ABM Service de Motos ***\n");
	printf("----------------------------\n");
	printf("1.Alta Moto\n");
	printf("2.Modificar Moto\n");
	printf("3.Baja Moto\n");
	printf("4.Listar Motos\n");
	printf("5.Listar Tipos\n");
	printf("6.Listar Colores\n");
	printf("7.Listar Servicios\n");
	printf("8.Alta Trabajo\n");
	printf("9.Listar Trabajos\n");
	printf("20.Salir\n");

	printf("Ingrese opcion:\n");
	scanf("%d", &opcion);
	return opcion;

}


int inicializarMotos(eMoto lista[], int tam)
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

int buscarLibre(eMoto lista[], int tam)
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

int altaMoto(eMoto lista[], int tam, eTipo tipos[],eColor colores[], int tamTipo, int tamColores,int *pId)
{
	int todoOk = 0;
	int indice;
	eMoto auxMoto;

	if(lista!= NULL && tam >0 && pId != NULL)
	{
		system("cls");
		printf("    *** Alta Moto ***\n");
		indice = buscarLibre(lista,tam);
		if(indice == -1)
		{
			printf("No hay lugar en el sistema\n");
		}
		else
		{
			auxMoto.id = *pId;
			(*pId)++;


			utn_getString(auxMoto.marca, sizeof(auxMoto.marca),"Ingrese marca","Marca Invalida\n",100);

			mostrarTipos(tipos,tamTipo);

			utn_getNumero(&auxMoto.idTipo,"Ingrese id del tipo","Error\n",1000,1003,10);
			while(!validarIdTipo(tipos,tamTipo,auxMoto.idTipo))
			{
				mostrarTipos(tipos,tamTipo);
				printf("Tipo no registrado, volver a ingresar\n");
				scanf("%d",&auxMoto.idTipo);
			}

			mostrarColores(colores,tamColores);

			utn_getNumero(&auxMoto.idColor,"Ingrese id del color","Error\n",10000,10004,10);

			while(!validarIdColor(colores,tamColores,auxMoto.idColor))
			{
				mostrarColores(colores,tamColores);
				printf("Color no registrado, volver a ingresar\n");
				scanf("%d",&auxMoto.idColor);
			}


			utn_getNumero(&auxMoto.cilindrada,"Ingrese cilindrada: (50,125,500,600 o 750)","Error\n",50,750,10);

			while(auxMoto.cilindrada != 50 && auxMoto.cilindrada != 125 &&
					auxMoto.cilindrada != 500 && auxMoto.cilindrada != 600 && auxMoto.cilindrada != 750)
			{
				printf("Cilindrada no registrada, volver a ingresar\n");
				scanf("%d",&auxMoto.cilindrada);
			}


			}
			utn_getNumero(&auxMoto.puntaje,"Ingrese puntaje", "Puntaje invalido\n",1,10,10);

			auxMoto.isEmpty = 0;

			lista[indice] = auxMoto;
			todoOk = 1;



		}


	return todoOk;

}



void mostrarMoto(eMoto unaMoto, eTipo tipos[], eColor colores[], int tamTipos,int tamColores)
{
	char descColor[20];
	char descTipo[20];
	cargarDescripcionColores(colores, tamColores, unaMoto.idColor, descColor);
	cargarDescripcionTipos(tipos,tamTipos,unaMoto.idTipo,descTipo);



	printf("  %d\t    %7s      %7s\t      %7s\t    %d\t         %d\t\n", unaMoto.id,
											unaMoto.marca,
											descTipo,
											descColor,
											unaMoto.cilindrada,
											unaMoto.puntaje
												);
}

int mostrarMotos(eMoto lista[], eTipo tipos[], eColor colores[], int tamTipos,int tamColores,  int tam)
{
	int todoOk = 0;
	int flag = 1;
	if(lista != NULL && tam >0 && tipos != NULL && colores != NULL && tamTipos >0 && tamColores >0)
	{
		system("cls");
		printf("              *** Listado de Motos ***\n");
		printf("   ID         Marca        Tipo            Color        Cilindrada     Puntaje\n");
		printf("---------------------------------------------------------------------------------\n");

		for(int i = 0;i <tam ;i++)
		{
			if(!lista[i].isEmpty)
			{
				mostrarMoto(lista[i],tipos,colores,tamTipos,tamColores);
				flag = 0;
			}
		}
		if(flag)
		{
			printf("    NO hay motos para mostrar\n");
		}
		todoOk = 1;

	}
	return todoOk;
}

int buscarMotoId(eMoto lista[], int tam,int id)
{
	int indice = -1;
	if(lista != NULL && tam >0)
	{
		for(int i = 0;i<tam ;i++)
		{
			if(!lista[i].isEmpty && lista[i].id == id)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int bajaMoto(eMoto lista[],eTipo tipos[], eColor colores[], int tamTipos, int tamColores,int tam)
{
	int todoOk = 0;
	int id;
	int indice;
	char confirma;

	if(lista!= NULL && tam >0)
	{
		system("cls");
		printf("     *** Baja Moto ***\n");
		mostrarMotos(lista,tipos,colores,tamTipos,tamColores,tam);

		printf("Ingrese Id :\n");
		scanf("%d", &id);

		indice = buscarMotoId(lista,tam,id);
		if(indice == -1)
		{
			printf("No existe una moto con id :%d\n",id);

		}
		else
		{
			mostrarMoto(lista[indice],tipos,colores,tamTipos,tamColores);
			printf("Confirma baja?(S/N)\n");
			fflush(stdin);
			scanf("%c", &confirma);

			if(confirma == 's')
			{
				lista[indice].isEmpty = 1;
				todoOk = 1;
			}
			else
			{
				printf("Se ha cancelado la baja\n");
			}
		}
	}
	return todoOk;

}

int modificarMoto(eMoto lista[],eTipo tipos[], eColor colores[], int tamTipos, int tamColores, int tam)
{
	int todoOk = 0;
	int id;
	int indice;
	char confirma;
	int auxColor;
	int auxPuntaje;

	if(lista!= NULL && tam >0)
	{
		system("cls");
		printf("     *** Modificar Moto ***\n");
		mostrarMotos(lista,tipos,colores,tamTipos,tamColores,tam);
		printf("Ingrese Id :\n");
		scanf("%d", &id);

		indice = buscarMotoId(lista,tam,id);
		if(indice == -1)
		{
			printf("No existe una moto con id :%d\n",id);

		}
		else
		{
			mostrarMoto(lista[indice],tipos,colores,tamTipos,tamColores);
			printf("Confirma modificacion? (S/N)\n");
			fflush(stdin);
			scanf("%c", &confirma);

			if(confirma == 's')
			{
				switch(menuModificacion())
				{
				case 1:
					mostrarColores(colores,tamColores);
					utn_getNumero(&auxColor,"Ingrese id del nuevo color","Error\n",10000,10004,10);


					while(!validarIdColor(colores,tamColores,auxColor))
					{
						mostrarTipos(tipos,tamTipos);
						printf("Color no registrado, volver a ingresar\n");
						scanf("%d",&auxColor);
					}
					lista[indice].idTipo = auxColor;
					break;
				case 2:

					utn_getNumero(&auxPuntaje,"Ingrese nuevo puntaje: (1 a 10)","Error\n",1,10,10);
					while(auxPuntaje <1 || auxPuntaje >10)
					{
						printf("Puntaje invalido, volver a ingresar\n");
						scanf("%d",&auxPuntaje);

					}
					lista[indice].puntaje = auxPuntaje;
					break;
				case 3:
					printf("Cerrando menu\n");
					break;
				default:
					printf("Opcion invalida!!\n");
				}
				todoOk = 1;
			}
			else
			{
				printf("Se ha cancelado la modificacion\n");
			}
		}
	}
	return todoOk;

}

int menuModificacion()
{
	int opcion;

	printf("1- Color\n");
	printf("2- Puntaje\n");
	printf("3- Salir\n");

	printf("   Ingrese opcion:\n");
	scanf("%d",&opcion);
	 return opcion;
}

int validarIdMoto(eMoto lista[], int tam, int idBuscado)
{
	int existe = 0;

	if(lista != NULL && tam >0)
	{
		for(int i = 0;i <tam;i++)
		{
			if(lista[i].id == idBuscado)
			{
				existe = 1;
				break;
			}
		}
	}
	return existe;
}



int ordenarMotos(eMoto lista[], int tam,eTipo tipos[],int tamTipos)
{
	int todoOk = 0;
	eMoto auxMoto;
	char descTipo[20];
	char descTipo2[20];

	if(lista != NULL && tam > 0 && tipos != NULL && tamTipos >0)
	{
		for(int i = 0;i <tam-1;i++)
		{
			cargarDescripcionTipos(tipos,tamTipos,lista[i].idTipo ,descTipo);

			for(int j = i+1;j <tam;j++)
			{
				cargarDescripcionTipos(tipos,tamTipos,lista[j].idTipo, descTipo2);


				if(strcmp(descTipo,descTipo2) > 0 ||
				(!strcmp(descTipo,descTipo2) &&
				lista[i].id > lista[j].id ))
				{
					auxMoto = lista[i];
					lista[i] = lista[j];
					lista[j] = auxMoto;
				}

			}
		}
		todoOk = 1;
	}
	return todoOk;
}

