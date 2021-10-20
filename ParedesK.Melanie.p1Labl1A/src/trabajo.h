/*
 * trabajo.h
 *
 *  Created on: 20 oct. 2021
 *      Author: mkale
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_

#include "fecha.h"
#include "servicio.h"
#include "moto.h"
#include "fecha.h"
#include "color.h"
#include "tipo.h"

typedef struct
{
	int id; //autoincremental
	int idMoto;
	int idServicio;
	eFecha fecha;
	int isEmpty;

}eTrabajo;


#endif /* TRABAJO_H_ */
/**
 * @fn int altaTrabajo(eTrabajo[], int, eMoto[], int, eServicio[], int, eTipo[], eColor[], int, int, int*, int*)
 * @brief
 * da de alta un trabajo
 * @param trabajo ->lista de trabajos en la cual se busca un lugar libre para dar de alta
 * @param tamTra ->tamaño de la lista de trabajos
 * @param lista ->lista de motos con las que se puede trabajar
 * @param tam -> tamaño de la lista de motos
 * @param servicios -> lista de servicios aplicables
 * @param tamServicios -> tamaño de la lista de servicios
 * @param tipos -> lista de tipos de motos
 * @param colores -> lista de colores de motos
 * @param tamTipos -> tamaño de la lista de tipos
 * @param tamColores -> tamaño de la lista de colores
 * @param pId -> id del trabajo a dar de alta
 * @param pIdMoto -> id de la moto a dar de alta
 * @return devuelve 1 si pudo dar de alta, 0 si no
 */
int altaTrabajo(eTrabajo trabajo[],int tamTra,eMoto lista[], int tam,eServicio servicios[],
		int tamServicios,eTipo tipos[], eColor colores[],int tamTipos, int tamColores, int *pId,int *pIdMoto);

/**
 * @fn int listarTrabajo(eTrabajo, eMoto[], eServicio[], int, int)
 * @brief
 * lista un trabajo registrados
 * @param trabajos -> trabajo a mostrar
 * @param lista -> lista de motos
 * @param servicios -> lista de servicios
 * @param tam -> tamaño de la lista de motos
 * @param tamServicios -> tamaño de la lista de servicios
 * @return devuelve  0
 */
int listarTrabajo(eTrabajo trabajos, eMoto lista[],eServicio servicios[],int tam, int tamServicios);

/**
 * @fn int mostrarTrabajos(eTrabajo[], int, eMoto[], eServicio[], int, int)
 * @brief
 *muestra todos los trabajos
 * @param trabajos -> lista de trabajos
 * @param tamTra -> tamaño de la lista de trabajos
 * @param lista -> lista de motos
 * @param servicios -> lista de servicios
 * @param tamServicios -> tamaño de la lista de servicios
 * @param tam tamaño de la lista de motos
 * @return devuelve 1 si pudo mostrar, 0 si no
 */
int mostrarTrabajos(eTrabajo trabajos[],int tamTra,eMoto lista[],eServicio servicios[],int tamServicios, int tam);
/**
 * @fn int buscarLibreT(eTrabajo[], int)
 * @brief
 * busca lugar libre en la memoria para almacenar un trabajo
 * fijandose en el valor del campo isEmpty
 * @param lista -> lista de trabajos
 * @param tam ->tamaño de la lista
 * @return devuelve el lugar encontrado, o -1
 */
int buscarLibreT(eTrabajo lista[], int tam);
/**
 * @fn int inicializarTrabajos(eTrabajo[], int)
 * @brief
 * inicicaliza el campo isEmpty de los trabajos en 1
 * @param lista ->lista de trabajos
 * @param tam tamaño e la lista
 * @return devuelve 1 si inicalizó, 0 si no
 */
int inicializarTrabajos(eTrabajo lista[], int tam);
