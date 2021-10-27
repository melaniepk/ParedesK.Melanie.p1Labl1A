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
	printf("10.Desplegar menú de informes\n");
	/*printf("10.Seleccionar color y mostrar motos\n");
	printf("11.Seleccionar tipo y mostrar promedio de puntajes\n");
	printf("12.Informe de motos con mayor cilindrada\n");
	printf("13.Listado de motos separadas por tipo\n");
	printf("14.Cantidad de motos segun tipo y color seleccionado\n");
	printf("15.El/los colores mas elegidos\n");
	printf("16.Mostrar trabajos realizados en determinada moto\n");
	printf("17.Suma de los servicios aplicados a determinada moto\n");
	printf("18.Motos a las que se les realizo determinado servicio\n");
	printf("19.Servicios realizados en una fecha\n");*/
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

int altaMoto(eCliente clientes[],int tamCli,eMoto lista[], int tam, eTipo tipos[],eColor colores[], int tamTipo, int tamColores,int *pId)
{
	int todoOk = 0;
	int indice;
	eMoto auxMoto;

	if(lista!= NULL && tam >0 && pId != NULL && tipos != NULL && colores != NULL && clientes != NULL && tamCli >0 && tamTipo >0 && tamColores >0)
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

			mostrarClientes(clientes,tamCli);
			utn_getNumero(&auxMoto.cliente.id,"Ingrese el id del cliente","Error,id incorrecto",1,10,10);
			while(!validarIdCliente(clientes,tamCli,auxMoto.cliente.id))
			{
				mostrarClientes(clientes,tamCli);
				printf("Cliente no registrado, volver a ingresar\n");
				scanf("%d",&auxMoto.cliente.id);
			}
			auxMoto.isEmpty = 0;

			lista[indice] = auxMoto;
			todoOk = 1;



		}


	return todoOk;

}



void mostrarMoto(eCliente clientes[], int tamCli,eMoto unaMoto, eTipo tipos[], eColor colores[], int tamTipos,int tamColores)
{
	char descColor[20];
	char descTipo[20];
	char nombre[20];
	cargarDescripcionColores(colores, tamColores, unaMoto.idColor, descColor);
	cargarDescripcionTipos(tipos,tamTipos,unaMoto.idTipo,descTipo);
	cargarNombreCliente(clientes,tamCli,unaMoto.cliente.id,nombre);



	printf("  %d\t    %7s\t    %7s\t     %7s\t         %d\t      %d\t    %s\n", unaMoto.id,
											unaMoto.marca,
											descTipo,
											descColor,
											unaMoto.cilindrada,
											unaMoto.puntaje,
											nombre
												);

}

int mostrarMotos(eCliente clientes[], int tamCli,eMoto lista[], eTipo tipos[], eColor colores[], int tamTipos,int tamColores,  int tam)
{
	int todoOk = 0;
	int flag = 1;
	if(lista != NULL && tam >0 && tipos != NULL && colores != NULL && tamTipos >0 && tamColores >0)
	{
		system("cls");
		printf("              *** Listado de Motos ***\n");
		printf("   ID         Marca        Tipo            Color        Cilindrada     Puntaje     Cliente\n");
		printf("-------------------------------------------------------------------------------------------\n");

		for(int i = 0;i <tam ;i++)
		{
			if(!lista[i].isEmpty)
			{
				mostrarMoto(clientes,tamCli,lista[i],tipos,colores,tamTipos,tamColores);
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

int bajaMoto(eCliente clientes[], int tamCli,eMoto lista[],eTipo tipos[], eColor colores[], int tamTipos, int tamColores,int tam)
{
	int todoOk = 0;
	int id;
	int indice;
	char confirma;

	if(lista!= NULL && tam >0)
	{
		system("cls");
		printf("     *** Baja Moto ***\n");
		mostrarMotos(clientes, tamCli,lista,tipos,colores,tamTipos,tamColores,tam);

		printf("Ingrese Id :\n");
		scanf("%d", &id);

		indice = buscarMotoId(lista,tam,id);
		if(indice == -1)
		{
			printf("No existe una moto con id :%d\n",id);

		}
		else
		{
			mostrarMoto(clientes,tamCli,lista[indice],tipos,colores,tamTipos,tamColores);
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

int modificarMoto(eCliente clientes[], int tamCli,eMoto lista[],eTipo tipos[], eColor colores[], int tamTipos, int tamColores, int tam)
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
		mostrarMotos(clientes, tamCli,lista,tipos,colores,tamTipos,tamColores,tam);
		printf("Ingrese Id :\n");
		scanf("%d", &id);

		indice = buscarMotoId(lista,tam,id);
		if(indice == -1)
		{
			printf("No existe una moto con id :%d\n",id);

		}
		else
		{
			mostrarMoto(clientes,tamCli,lista[indice],tipos,colores,tamTipos,tamColores);
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

					lista[indice].idColor = auxColor;
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



int ordenarMotos(eCliente clientes[], int tamCli,eMoto lista[], int tam,eTipo tipos[],int tamTipos)
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


				if(strcmp(descTipo,descTipo2) > 0 /*||
				(!strcmp(descTipo,descTipo2) &&
				lista[i].id > lista[j].id )*/)
				{
					auxMoto = lista[i];
					lista[i] = lista[j];
					lista[j] = auxMoto;
				}
				else
					if(lista[i].idTipo == lista[j].idTipo &&
							lista[i].id > lista[j].id)
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

int cargarDescripcionMoto(eMoto motos[], int tam, int idMoto, char descMoto[])
{
	int todoOk = 0;
	if(motos != NULL && tam >0 && descMoto != NULL)
	{
		for(int i = 0;i <tam;i++)
		{
			if(motos[i].id == idMoto)
			{
				strcpy(descMoto, motos[i].marca);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}


int informeMotosColor(eCliente clientes[],int tamCli,eMoto lista[],int tam,eTipo tipos[],int tamt, eColor colores[], int tamc)
{
	int todoOk = 0;
	int auxIdColor;
	if(lista != NULL && tam >0 && tipos != NULL && tamt>0 && colores != NULL && tamc >0 )
	{
		system("cls");
		printf("   *** Informe de Motos segun su color ***\n");
		printf("--------------------------------------------\n");

		mostrarColores(colores,tamc);
		printf("Ingrese id del color: \n");
		scanf("%d",&auxIdColor);
		while(!validarIdColor(colores,tamc, auxIdColor))
		{
			mostrarColores(colores,tamc);
			printf("ID no registrado, volver a ingresar\n");
			scanf("%d",&auxIdColor);
		}


		mostrarMotosPorColorId(clientes,tamCli,lista,tam,tipos,tamt,colores,tamc,auxIdColor);
		todoOk=1;


	}
	return todoOk;
}


int mostrarMotosPorColorId(eCliente clientes[],int tamCli,eMoto lista[],int tam,eTipo tipos[],int tamt, eColor colores[], int tamc,int idColor)
{
	int todoOk = 0;
	int flag = 1;

	if(lista!= NULL && tam >0 && colores != NULL && tamc > 0 && tipos != NULL && tamt >0)
	{
		printf("   ID       Marca       Tipo              Color       Cilindrada        Puntaje\n");
		printf("----------------------------------------------------------------------------------\n");
		for(int i = 0;i<tam;i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].idColor == idColor)
			{

				mostrarMoto(clientes,tamCli,lista[i],tipos,colores,tamt,tamc);
				flag = 0;
			}
		}
		if(flag)
		{
			printf("No hay motos de este color\n");
		}

		printf("\n\n");
		todoOk = 1;
	}

	return todoOk;
}

int informePromedioMotosTipo(eCliente clientes[],int tamCli,eMoto lista[],int tam,eTipo tipos[],int tamt, eColor colores[], int tamc)
{
	int todoOk = 0;
	int auxIdTipo;
	int acumulador=0;
	int contador=0;
	float promedio;
	char descTipo[20];

	if(lista != NULL && tam >0 && tipos != NULL && tamt>0 && colores != NULL && tamc >0 )
	{
		system("cls");
		printf("   *** Informe del promedio de puntaje segun el tipo de moto ***\n");
		printf("-------------------------------------------------------------------\n");

		mostrarTipos(tipos,tamt);
		printf("Ingrese id del tipo: \n");
		scanf("%d",&auxIdTipo);
		while(!validarIdTipo(tipos,tamt, auxIdTipo))
		{
			mostrarTipos(tipos,tamt);
			printf("ID no registrado, volver a ingresar\n");
			scanf("%d",&auxIdTipo);
		}


		for(int i = 0;i<tamt;i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].idTipo == auxIdTipo)
			{

				acumulador = acumulador + lista[i].puntaje;
				contador++;
			}
		}

		if(contador != 0)
		{
			promedio = (float) acumulador / contador;
		}

		cargarDescripcionTipos(tipos,tamt, auxIdTipo, descTipo);

		printf("promedio del puntaje de motos tipo %10s: %.2f\n",descTipo, promedio );

		todoOk=1;


	}
	return todoOk;
}


int mostrarMotosPorTipoId(eCliente clientes[], int tamCli,eMoto lista[],int tam,eTipo tipos[],int tamt, eColor colores[], int tamc,int idTipo)
{
	int todoOk = 0;
	int flag = 1;

	if(lista!= NULL && tam >0 && colores != NULL && tamc > 0 && tipos != NULL && tamt >0)
	{
		printf("   ID       Marca       Tipo              Color       Cilindrada        Puntaje\n");
		printf("----------------------------------------------------------------------------------\n");
		for(int i = 0;i<tam;i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].idTipo == idTipo)
			{

				mostrarMoto(clientes,tamCli,lista[i],tipos,colores,tamt,tamc);
				flag = 0;
			}
		}
		if(flag)
		{
			printf("No hay motos de este tipo\n");
		}

		printf("\n\n");
		todoOk = 1;
	}

	return todoOk;
}


int motoMayorCilindrada(eCliente clientes[], int tamCli,eMoto lista[], int tam, eTipo tipos[], int tamt,eColor colores[], int tamc)
{
	int todoOk = 0;
	int mayorCilindrada;
	int flagPrimera = 1;

	if(lista != NULL && tam >0 && tipos != NULL && tamc >0 && tamt>0 && colores != NULL)
	{

		system("cls");
		printf("     *** Informe moto/s con mayor cilindrada ***\n");
		for(int i =0; i<tam ;i++)
		{
			if(!lista[i].isEmpty)
			{
				if(flagPrimera || lista[i].cilindrada > mayorCilindrada)
				{
					mayorCilindrada = lista[i].cilindrada;
					flagPrimera = 0;
				}
			}
		}

		printf("Moto/s con mayor cilindrada:\n");
		printf("   ID       Marca       Tipo              Color       Cilindrada        Puntaje\n");

		for(int i=0; i <tam;i++)
		{
			if(!lista[i].isEmpty && lista[i].cilindrada == mayorCilindrada)
			{

				mostrarMoto(clientes,tamCli,lista[i],tipos,colores,tamt,tamc);
			}
		}
		printf("\n\n");
		todoOk = 1;
	}

	return todoOk;
}


int informeMotosAllTipos(eCliente clientes[],int tamCli,eMoto lista[],int tam, eTipo tipos[], int tamt,eColor colores[],int tamc)
{
	int todoOk = 0;

	if(lista!= NULL && tam >0 && colores != NULL && tamc >0 && tipos != NULL && tamt >0)
	{
		system("cls");
		printf("   *** Informe motos de cada tipo ***\n");
		for(int i = 0; i < tamt;i++)
		{
			printf("Tipo: %s\n\n", tipos[i].descripcion);

			mostrarMotosPorTipoId(clientes,tamCli,lista,tam,tipos,tamt,colores,tamc,tipos[i].id);
			todoOk = 1;

		}
	}

	return todoOk;
}


int cantidadMotosPorTipoYColor(eMoto lista[], int tam,eTipo tipos[], int tamt,eColor colores[], int tamc)
{
	int todoOk = 0;
	int contador;
	int auxTipo;
	int auxColor;
	char unidad[20] =("Motos\n");

	if(lista!= NULL && tam >0 && tipos != NULL && tamt >0 && colores != NULL && tamc >0)
	{
		system("cls");
		printf("    *** Informe Cantidad de Motos por tipo y color ***\n");

			mostrarTipos(tipos,tamt);
			printf("Ingrese id del tipo: \n");
			scanf("%d",&auxTipo);
			while(!validarIdTipo(tipos,tamt, auxTipo))
			{
				mostrarTipos(tipos,tamt);
				printf("ID no registrado, volver a ingresar\n");
				scanf("%d",&auxTipo);
			}


			mostrarColores(colores,tamc);
			printf("Ingrese id del color: \n");
			scanf("%d",&auxColor);
			while(!validarIdColor(colores,tamc, auxColor))
			{
				mostrarColores(colores,tamc);
				printf("ID no registrado, volver a ingresar\n");
				scanf("%d",&auxColor);
			}

			contador = 0;
			for(int i =0;i>tam ;i++)
			{
				if(!lista[i].isEmpty && lista[i].idColor == auxColor && lista[i].idTipo == auxTipo)
				{
					contador++;
				}

			}
			if(contador ==0)
			{
				printf("No hay Motos\n");
			}
			if(contador ==1)
			{
				strcpy(unidad,"Moto\n");
				printf("%d %s\n",contador,unidad);
			}
			else
			{
				printf("%d %s\n",contador,unidad);
			}


			todoOk = 1;


	}




	return todoOk;
}


int informeColoresMasElegidos(eMoto lista[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc)
{

	int todoOk =0;
	int contadores[5];
	int colorMasElegido;

	for(int i =0;i<5;i++)
	{
		contadores[i] =0;
	}
	if(lista!= NULL && tam >0 && tipos != NULL && tamt >0 && colores != NULL && tamc>0)
	{
		system("cls");
		printf("     *** Color/es mas elegidos ***\n");
		for(int i =0;i<tamc;i++)
		{
			for(int j =0;j<tam;j++)
			{
				if(!lista[j].isEmpty && lista[j].idColor == colores[i].id)
				{
					contadores[i]++;
				}
			}
		}

		for(int i =0;i<tamc;i++)
		{
			if(i==0 || colorMasElegido < contadores[i])
			{
				colorMasElegido = contadores[i];
			}
		}

		for(int i =0;i<tamc;i++)
		{
			if(contadores[i]== colorMasElegido)
			{
				printf("%s\n", colores[i].nombreColor);
			}
		}
		printf("\n\n");
		todoOk =1;

	}
	return todoOk;

}

int menuInformes()
{
	int opcion;
	system("cls");
	printf("        *** Informes ***\n");
	printf("----------------------------\n");
	printf("1.Seleccionar color y mostrar motos\n");
	printf("2.Seleccionar tipo y mostrar promedio de puntajes\n");
	printf("3.Informe de motos con mayor cilindrada\n");
	printf("4.Listado de motos separadas por tipo\n");
	printf("5.Cantidad de motos segun tipo y color seleccionado\n");
	printf("6.El/los colores mas elegidos\n");
	printf("7.Mostrar trabajos realizados en determinada moto\n");
	printf("8.Suma de los servicios aplicados a determinada moto\n");
	printf("9.Motos a las que se les realizo determinado servicio\n");
	printf("10.Servicios realizados en una fecha\n");

	printf("Ingrese opcion:\n");
	scanf("%d", &opcion);
	return opcion;
}




