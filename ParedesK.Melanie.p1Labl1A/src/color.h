/*
 * color.h
 *
 *  Created on: 20 oct. 2021
 *      Author: mkale
 */

#ifndef COLOR_H_
#define COLOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id; // comienza en 5000
	char nombreColor[20];
}eColor;




#endif /* COLOR_H_ */
int cargarDescripcionColores(eColor colores[], int tam, int idColor, char descColor[]);
int mostrarColores(eColor colores[], int tam);
int validarIdColor(eColor colores[], int tam, int idBuscado);
