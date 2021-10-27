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
/**
 * @fn int cargarDescripcionColores(eColor[], int, int, char[])
 * @brief
 * carga el nombre del color en la variable descColor
 * @param colores -> lista de colores
 * @param tam -> tamaño de la lista
 * @param idColor -> id del color del que se busca el nombre
 * @param descColor -> variable en donde se copia el nombre
 * @return
 */
int cargarDescripcionColores(eColor colores[], int tam, int idColor, char descColor[]);
/**
 * @fn int mostrarColores(eColor[], int)
 * @brief
 * muestra una llista de los colores con sus nombre y ids
 * @param colores -> lista de colores
 * @param tam -> tamaño de la lista
 * @return
 */
int mostrarColores(eColor colores[], int tam);
/**
 * @fn int validarIdColor(eColor[], int, int)
 * @brief
 * valida la existencia de un id determinado en la lista de colores
 * @param colores -> lista de colores
 * @param tam -> tamaño de la lista
 * @param idBuscado -> id a validar
 * @return 1 si existe, 0 si no
 */
int validarIdColor(eColor colores[], int tam, int idBuscado);
