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
/**
 * @fn int cargarDescripcionTipos(eTipo[], int, int, char[])
 * @brief
 * carga la descripcion de un determinado tipo a la variable descTipo
 * @param tipos -> lista de tipos
 * @param tam -< tamaño de la lista
 * @param idTipo -> id del tipo a buscar descripcion
 * @param descTipo -< variable a cargar con la descripcion
 * @return
 */
int cargarDescripcionTipos(eTipo tipos[], int tam, int idTipo, char descTipo[]);

/**
 * @fn int mostrarTipos(eTipo[], int)
 * @brief
 * muestra la lista de los tipos con su descripcion y id
 * @param tipos -> lista de tipos
 * @param tam -> tamaño de la lista
 * @return
 */
int mostrarTipos(eTipo tipos[], int tam);
/**
 * @fn int validarIdTipo(eTipo[], int, int)
 * @brief
 * valida la existencia de un id en la lista de tipos
 * @param tipos -> lista de tipos
 * @param tam -> tamaño de la lista
 * @param idBuscado -> is a buscar
 * @return
 */
int validarIdTipo(eTipo tipos[], int tam, int idBuscado);
