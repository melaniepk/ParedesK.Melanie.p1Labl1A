/*
 * dataWarehouse.c
 *
 *  Created on: 20 oct. 2021
 *      Author: mkale
 */


#include "dataWarehouse.h"


int tipos[10]= {1000,1001,1002,1001,1000,1003,1004,1002,1003,1000};
int colores[10]= {10000,10001,10002,10003,10001,10003,10001,10000,10002,10003};
int cilindradas[10]= {50,125,600,500,750,125,750,500,600,50};
char marcas[10][20] = {"marcax","marcaz","marcae","otramarca","otramas","jimin","marcax","marcaz","jimin","otrmas"};
int puntajes[10] = {1,5,4,6,2,4,7,8,9,10};

int hardcodearMotos(eMoto lista[], int tam, int cant,int *pId)
{
	int contador = -1;
	if(lista != NULL && tam >0 && cant >= 0 && cant <= tam && pId != NULL)
	{
		contador = 0;
		for(int i = 0;i <cant ;i++)
		{
			lista[i].id = *pId;
			(*pId)++;
			strcpy(lista[i].marca,marcas[i]);
			lista[i].idTipo = tipos[i];
			lista[i].idColor = colores[i];
			lista[i].cilindrada = cilindradas[i];
			lista[i].puntaje = puntajes[i];
			lista[i].isEmpty = 0;
			contador++;
		}
	}
	return contador;
}
