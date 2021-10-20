/*
 * tipo.h
 *
 *  Created on: 20 oct. 2021
 *      Author: mkale
 */

#ifndef TIPO_H_
#define TIPO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id; // comeinza en 1000
	char descripcion[20];
}eTipo;


#endif /* TIPO_H_ */
int cargarDescripcionTipos(eTipo tipos[], int tam, int idTipo, char descTipo[]);
int mostrarTipos(eTipo tipos[], int tam);
int validarIdTipo(eTipo tipos[], int tam, int idBuscado);
