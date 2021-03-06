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
 * @fn int informes(eCliente[], int, eMoto[], eTipo[], eColor[], int, int, int, eServicio[], int, eTrabajo[], int)
 * @brief
 * contiene una lista de funciones de informes que se pueden realizar
 * @param clientes->lista de clientes
 * @param tamCli >_tama?o de la lista de clientes
 * @param lista ->lista de motos
 * @param tipos >-lista de tipos
 * @param colores ->lista de colores
 * @param tamTipos ->tam?o de la lista de tipos
 * @param tamColores ->tama?o de la lista de colores
 * @param tam ->tama?o de la lista de motos
 * @param servicios ->lista de servicios
 * @param tamSer ->tama?o de la lista de servicicios
 * @param trabajos ->ista de trabajos
 * @param tamTra ->tama?o de la lista de trabajos
 * @return 0 si no puede moostrar las funciones 1 si puede
 */
int informes(eCliente clientes[], int tamCli,eMoto lista[],eTipo tipos[], eColor colores[], int tamTipos, int tamColores, int tam,eServicio servicios[],int tamSer,eTrabajo trabajos[], int tamTra);
/**
 * @fn int altaTrabajo(eTrabajo[], int, eMoto[], int, eServicio[], int, eTipo[], eColor[], int, int, int*, int*)
 * @brief
 * da de alta un trabajo
 * @param trabajo ->lista de trabajos en la cual se busca un lugar libre para dar de alta
 * @param tamTra ->tama?o de la lista de trabajos
 * @param lista ->lista de motos con las que se puede trabajar
 * @param tam -> tama?o de la lista de motos
 * @param servicios -> lista de servicios aplicables
 * @param tamServicios -> tama?o de la lista de servicios
 * @param tipos -> lista de tipos de motos
 * @param colores -> lista de colores de motos
 * @param tamTipos -> tama?o de la lista de tipos
 * @param tamColores -> tama?o de la lista de colores
 * @param pId -> id del trabajo a dar de alta
 * @param pIdMoto -> id de la moto a dar de alta
 * @return devuelve 1 si pudo dar de alta, 0 si no
 */
int altaTrabajo(eCliente clientes[], int tamCli,eTrabajo trabajo[],int tamTra,eMoto lista[], int tam,eServicio servicios[],
		int tamServicios,eTipo tipos[], eColor colores[],int tamTipos, int tamColores, int *pId,int *pIdMoto);

/**
 * @fn int listarTrabajo(eTrabajo, eMoto[], eServicio[], int, int)
 * @brief
 * lista un trabajo registrados
 * @param trabajos -> trabajo a mostrar
 * @param lista -> lista de motos
 * @param servicios -> lista de servicios
 * @param tam -> tama?o de la lista de motos
 * @param tamServicios -> tama?o de la lista de servicios
 * @return devuelve  0
 */
int listarTrabajo(eTrabajo trabajos, eMoto lista[],eServicio servicios[],int tam, int tamServicios);

/**
 * @fn int mostrarTrabajos(eTrabajo[], int, eMoto[], eServicio[], int, int)
 * @brief
 *muestra todos los trabajos
 * @param trabajos -> lista de trabajos
 * @param tamTra -> tama?o de la lista de trabajos
 * @param lista -> lista de motos
 * @param servicios -> lista de servicios
 * @param tamServicios -> tama?o de la lista de servicios
 * @param tam tama?o de la lista de motos
 * @return devuelve 1 si pudo mostrar, 0 si no
 */
int mostrarTrabajos(eTrabajo trabajos[],int tamTra,eMoto lista[],eServicio servicios[],int tamServicios, int tam);
/**
 * @fn int buscarLibreT(eTrabajo[], int)
 * @brief
 * busca lugar libre en la memoria para almacenar un trabajo
 * fijandose en el valor del campo isEmpty
 * @param lista -> lista de trabajos
 * @param tam ->tama?o de la lista
 * @return devuelve el lugar encontrado, o -1
 */
int buscarLibreT(eTrabajo lista[], int tam);
/**
 * @fn int inicializarTrabajos(eTrabajo[], int)
 * @brief
 * inicicaliza el campo isEmpty de los trabajos en 1
 * @param lista ->lista de trabajos
 * @param tam tama?o e la lista
 * @return devuelve 1 si inicaliz?, 0 si no
 */
int inicializarTrabajos(eTrabajo lista[], int tam);

/**
 * @fn int mostrarTrabajosMoto(eCliente[], int, eTrabajo[], eServicio[], eMoto[], eTipo[], eColor[], int, int, int, int, int)
 * @brief
 * muestra los trabajos realizados a determinada moto
 * @param clientes ->lista de clientes
 * @param tamCli ->tama?o de la lista de clientes
 * @param trabajos ->lista de trabajos
 * @param servicios ->lista de servicios
 * @param lista ->lista de motos
 * @param tipos ->lista de tipos
 * @param colores->lista de colores
 * @param tamt->tama?o de la lista de trabajos
 * @param tamSer ->tama?o de la lista de servicios
 * @param tam ->tama?o de la lista de motos
 * @param tamTi ->tama?o de la lista de tipos
 * @param tamc ->tama?o de la lista de colores
 * @return 1 si pudo buscar, 0 si no
 */
int mostrarTrabajosMoto(eCliente clientes[], int tamCli,eTrabajo trabajos[],eServicio servicios[],eMoto lista[],eTipo tipos[],eColor colores[],int tamt,int tamSer, int tam, int tamTi, int tamc);

/**
 * @fn int sumaServiciosPorMoto(eCliente[], int, eTrabajo[], eServicio[], eMoto[], eTipo[], eColor[], int, int, int, int, int)
 * @brief
 * suma el precio de los servicios aplicados a determinada moto
 * @param clientes ->lista de clientes
 * @param tamCli ->tama?o de la lista de clientes
 * @param trabajos ->lista de trabajos
 * @param servicios ->lista de servicios
 * @param lista ->lista de motos
 * @param tipos ->lista de tipos
 * @param colores ->lista de colores
 * @param tamt ->tama?o de la lista de trabajos
 * @param tamSer ->tama?o de la lista de servicios
 * @param tam ->tama?o de la lista de motos
 * @param tamTi ->tama?o de tipos
 * @param tamc ->tama?o de la lista de colores
 * @return 1 si pudo sumar, 0 si no
 */
int sumaServiciosPorMoto(eCliente clientes[], int tamCli,eTrabajo trabajos[],eServicio servicios[],eMoto lista[],eTipo tipos[],eColor colores[],int tamt,int tamSer, int tam, int tamTi, int tamc);

/**
 * @fn int servicioMotoYFecha(eCliente[], int, eTrabajo[], eServicio[], eMoto[], eTipo[], eColor[], int, int, int, int, int)
 * @brief
 * muestra las motos que se ralizaron un cierto servicio con su fecha
 * @param clientes ->lista de clientes
 * @param tamCli ->tama?o de la lista de clientes
 * @param trabajos ->lista de trabajos
 * @param servicios ->lista de servicios
 * @param lista ->lista de motos
 * @param tipos ->lista de tipos
 * @param colores->lista de colores
 * @param tamt ->tama?o de la lista de trabajos
 * @param tamSer ->tama?o de la lista de servicios
 * @param tam ->tama?o de la lista de motos
 * @param tamTi ->tama?o de la lista de tipos
 * @param tamc ->tama?o de la lista de colores
 * @return 1 si pudo buscar, 0 si no
 */
int servicioMotoYFecha(eCliente clientes[], int tamCli,eTrabajo trabajos[],eServicio servicios[],eMoto lista[],eTipo tipos[],eColor colores[],int tamt,int tamSer, int tam, int tamTi, int tamc);

/**
 * @fn int serviciosRealizadosPorFecha(eTrabajo[], eServicio[], eMoto[], eTipo[], eColor[], int, int, int, int, int)
 * @brief
 * se pide una fecha y se muestra los servicios realizados en esa fecha
 * @param trabajos ->lista de trabajos
 * @param servicios->lista de servicios
 * @param lista ->lista dde motos
 * @param tipos ->lista de tipos
 * @param colores ->lista de colores
 * @param tamt->tama?o de la lista de trabajos
 * @param tamSer ->tama?o de la lista de servicios
 * @param tam ->tama?o de la lista de motos
 * @param tamTi ->tama?o de la lista de tipos
 * @param tamc ->tama?o de la lista de colores
 * @return 1 si pudo buscar, 0 si no
 */
int serviciosRealizadosPorFecha(eTrabajo trabajos[],eServicio servicios[],eMoto lista[],eTipo tipos[],eColor colores[],int tamt,int tamSer, int tam, int tamTi, int tamc);
