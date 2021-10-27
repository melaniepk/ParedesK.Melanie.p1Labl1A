/*
 ============================================================================
 Name        : p1Labl1A.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "moto.h"
#include "servicio.h"
#include "trabajo.h"
#include "tipo.h"
#include "color.h"
#include "dataWarehouse.h"
#include "cliente.h"

#define TAM 10
#define TAM_SERV 4
#define TAM_COLOR 5
#define TAM_TIPO 4
#define TAM_CILIN 4
#define TAM_TRA 10
#define TAM_CLI 10
int main(void) {

	setbuf(stdout,NULL);
		char seguir = 's';
		eMoto lista[TAM];
		int nextId = 1;
		int nextIDT = 1;
		eTrabajo listaTrabajos[TAM];
		int flag = 0;
		if(!inicializarMotos(lista,TAM))
		{
			printf("Ocurrio un error al inicializar\n");
		}
		if(!inicializarTrabajos(listaTrabajos,TAM_TRA))
		{
			printf("Ocurrio un error al inicializar\n");
		}

		eServicio servicios[TAM_SERV] =
		{
				{20000, "Limpieza",450},
				{20001, "Ajuste",300},
				{20002, "Balanceo",150},
				{20003,"Cadena",390},
		};

		eTipo tipos[TAM_TIPO]=
		{
				{1000,"Enduro"},
				{1001,"Chopera"},
				{1002,"Scooter"},
				{1003,"Vintage"}
		};

		eColor colores[TAM_COLOR] =
		{
				{10000,"Gris"},
				{10001,"Negro"},
				{10002,"Azul"},
				{10003,"Blanco"},
				{10004,"Rojo"}
		};

		eCliente clientes[TAM_CLI] =
		{
				{1,"marta",'f'},
				{2,"juan",'m'},
				{3,"antonio",'m'},
				{4,"clara",'f'},
				{5,"marcos",'m'},
				{6,"martina",'f'},
				{7,"carlos",'m'},
				{8,"reina",'f'},
				{9,"anselmo",'m'},
				{10,"love",'f'}

		};

		hardcodearMotos(lista,TAM,8,&nextId);
		hardcodearTrabajos(listaTrabajos,TAM_TRA,8,&nextIDT);

		do
		{

			switch(menu())
			{
				case 1:
					if(altaMoto(clientes,TAM_CLI,lista,TAM,tipos,colores,TAM_TIPO,TAM_COLOR,&nextId))
					{
						printf("Alta exitosa!\n");
						flag = 1;
					}
					else
					{
						printf("Hubo un problema al hacer el alta\n");
					}
					break;
				case 2:
					if(flag == 1)
					{
						if(modificarMoto(clientes,TAM_CLI,lista,tipos,colores, TAM_TIPO,TAM_COLOR,TAM))
						{
							printf("Modificacion exitosa!\n");
						}
						else
						{
							printf("Hubo un problema al hacer la modificacion\n");
						}
					}
					else
					{
						printf("Error, primero debe hacer un alta\n");
					}
					break;

				case 3:
					if(flag == 1)
					{
						if(bajaMoto(clientes,TAM_CLI,lista,tipos,colores,TAM_TIPO,TAM_COLOR,TAM))
						{
							printf("Baja exitosa!\n");
						}
						else
						{
							printf("Hubo un problema al hacer la baja\n");
						}
					}
					else
					{
						printf("Error, primero debe hacer un alta\n");
					}
					break;
				case 4:
					if(flag == 1)
					{
						ordenarMotos(clientes,TAM_CLI,lista ,TAM,tipos,TAM_TIPO);
						if(!mostrarMotos(clientes,TAM_CLI,lista,tipos,colores,TAM_TIPO,TAM_COLOR,TAM))
						{
							printf("NO se pudieron mostrar las motos\n");
						}
					}
					else
					{
						printf("No hay motos para mostrar\n");
					}

					break;
				case 5:
					if(!mostrarTipos(tipos,TAM_TIPO))
					{
						printf("NO hay tipos cargados\n");
					}
					break;
				case 6:
					if(!mostrarColores(colores,TAM_COLOR))
					{
						printf("NO hay colores cargados\n");
					}
					break;
				case 7:
					system("cls");
					mostrarServicios(servicios,TAM_SERV);
					break;
				case 8:
					system("cls");
					if(flag == 1)
					{
						altaTrabajo(clientes,TAM_CLI,listaTrabajos, TAM_TRA,lista,TAM,servicios, TAM_SERV, tipos, colores, TAM_TIPO, TAM_COLOR,&nextIDT,&nextId);
					}
					else
					{
						printf("Error, priemro debe hacer un alta\n");
					}
					break;
				case 9:
					system("cls");
					mostrarTrabajos(listaTrabajos,TAM_TRA,lista,servicios,TAM_SERV,TAM);
					break;
				case 10:
					system("cls");
					informes(clientes,TAM_CLI,lista,tipos,colores,TAM_TIPO,TAM_COLOR,TAM,servicios,TAM_SERV,listaTrabajos,TAM_TRA);
					break;
				case 20:
					seguir = 'n';
					break;
				default:
					printf("Opcion invalida\n");

			}
			system("pause");

		}while(seguir == 's');

	return EXIT_SUCCESS;
}
