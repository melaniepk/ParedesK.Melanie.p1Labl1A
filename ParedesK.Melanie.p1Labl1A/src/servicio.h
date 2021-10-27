/*
 * servicio.h
 *
 *  Created on: 20 oct. 2021
 *      Author: mkale
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_



typedef struct
{
	int id;// comienza en 20000
	char descripcion[25];
	float precio;

}eServicio;


#endif /* SERVICIO_H_ */

/**
 * @fn int mostrarServicios(eServicio[], int)
 * @brief
 * muestra una lista de los servicios con sus ids, descripciones y precios
 * @param servicios -> lista de servicios
 * @param tam -> tamaño de la lista
 * @return
 */
int mostrarServicios(eServicio servicios[], int tam);

/**
 * @fn int cargarDescripcionServicio(eServicio[], int, int, char[])
 * @brief
 * carga la descripcion de un servicio a la variable descServicio
 * @param servicios -> lista de servicios
 * @param tam -> tamaño de la lista
 * @param idServicio -> id del servicio a buscar descripcion
 * @param descServicio -> variable en la que se carga la descripcion del servicio
 * @return
 */
int cargarDescripcionServicio(eServicio servicios[], int tam, int idServicio, char descServicio[]);

/**
 * @fn int validarIdServicio(eServicio[], int, int)
 * @brief
 * valida la existencia de un ddterminado id en la lista de servicios
 * @param servicios -> lista de servicios
 * @param tam -> tamaño de la lista
 * @param idBuscado -> id a buscar
 * @return
 */
int validarIdServicio(eServicio servicios[], int tam, int idBuscado);
