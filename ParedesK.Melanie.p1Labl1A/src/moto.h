/*
 * moto.h
 *
 *  Created on: 20 oct. 2021
 *      Author: mkale
 */

#ifndef MOTO_H_
#define MOTO_H_
#include "tipo.h"
#include "color.h"

typedef struct
{
	int id;
	char marca[20];
	int idTipo;
	int idColor;
	int cilindrada;
	int puntaje; //1 a 10
	int isEmpty;
}eMoto;


#endif /* MOTO_H_ */

/**
 * @fn int menuModificacion()
 * @brief
 * muestra el emnu en la funcion modificarMoto
 * @returndevuelve la opcion elegida
 */
int menuModificacion();
/**
 * @fn int modificarMoto(eMoto[], eTipo[], eColor[], int, int, int)
 * @brief
 * ofrece la opcion de modiciar el campo color o puntaje de la moto
 * @param lista -> lista de motos
 * @param tipos ->lista de tipos
 * @param colores -> lista de colores
 * @param tamTipos -> tamaño de lista de tipos
 * @param tamColores -> tamaño de lista de colores
 * @param tam ->tamaño de lista de motos
 * @return devuelve 1 si pudo entrar a la modificacion, 0 si no
 */
int modificarMoto(eMoto lista[],eTipo tipos[], eColor colores[], int tamTipos, int tamColores, int tam);

/**
 * @fn int bajaMoto(eMoto[], eTipo[], eColor[], int, int, int)
 * @brief
 * realiza una baja logica de la moto seleccionada a traves de su id
 * @param lista -> lista de motos
 * @param tipos -> lista de tipos
 * @param colores -> lista de colores
 * @param tamTipos -> tamaño de la lista de tipos
 * @param tamColores -> tamaño de la lista de colores
 * @param tam -> tamaño de la lista de motos
 * @return
 */
int bajaMoto(eMoto lista[],eTipo tipos[], eColor colores[], int tamTipos, int tamColores,int tam);

/**
 * @fn int buscarMotoId(eMoto[], int, int)
 * @brief
 * busca una moto segun su id
 * @param lista -> lita de motos
 * @param tam -> tamaño de la lista
 * @param id -> id buscado
 * @return devuelve el indice del id
 */
int buscarMotoId(eMoto lista[], int tam,int id);
/**
 * @fn int mostrarMotos(eMoto[], eTipo[], eColor[], int, int, int)
 * @brief
 * muestra una lista de las motos
 * @param lista -> lista de motos
 * @param tipos -> lista de tipos
 * @param colores -> lista de colores
 * @param tamTipos >_ tamaño de la lista de tipos
 * @param tamColores -> tamaño de la lista de colores
 * @param tam -> taaño de la lista de motos
 * @return devuelve 1 si mostro, 0 si no
 */
int mostrarMotos(eMoto lista[], eTipo tipos[], eColor colores[], int tamTipos,int tamColores,  int tam);

/**
 * @fn void mostrarMoto(eMoto, eTipo[], eColor[], int, int)
 * @brief
 *muestra una moto
 * @param unaMoto -< moso a mostrar
 * @param tipos -> lista de tipos
 * @param colores -> lista de colores
 * @param tamTipos -> tamaño de la lista de tipos
 * @param tamColores -> tamaño de la lkista de colores
 */
void mostrarMoto(eMoto unaMoto, eTipo tipos[], eColor colores[], int tamTipos,int tamColores);
/**
 * @fn int altaMoto(eMoto[], int, eTipo[], eColor[], int, int, int*)
 * @brief
 * da de alta una moto
 * @param lista -> lista de motos donde se busca un lugar libre
 * @param tam -> tamaño de la lista de motos
 * @param tipos -> lista de tipos
 * @param colores -> lista de colores
 * @param tamTipo -> tamaño de la lista de tipos
 * @param tamColores -> tamaño de la lista de colores
 * @param pId -> id donde se hace el alta
 * @return devuelve 1 si pudo dar de alta, 0 si no
 */
int altaMoto(eMoto lista[], int tam, eTipo tipos[],eColor colores[], int tamTipo, int tamColores, int *pId);
/**
 * @fn int buscarLibre(eMoto[], int)
 * @brief
 * busca un espacio libre en el array de motos
 * @param lista -> lista de motos
 * @param tam -> tamaño de la lista
 * @return devuelve el indice del lugar encontrado
 */
int buscarLibre(eMoto lista[], int tam);
/**
 * @fn int inicializarMotos(eMoto[], int)
 * @brief
 * incicializa el campo isEmpty de las motos en 1
 * @param lista -> lista de motos
 * @param tam -> tamaño de la lista
 * @return devuelve 1 si iniciazlizó, 0 si no
 */
int inicializarMotos(eMoto lista[], int tam);

/**
 * @fn int menu()
 * @brief
 * muestra el menu principal
 * @return devuelve la opcion seleccionada
 */
int menu();
/**
 * @fn int validadIdMoto(eMoto[], int, int)
 * @brief
 * valida la existencia de un id
 * @param lista -> lista de motos
 * @param tam -> tamaño de la lista
 * @param idBuscado -> id a validar
 * @return devuelve 1 si existe, 0 si no
 */
int validadIdMoto(eMoto lista[], int tam, int idBuscado);
/**
 * @fn int ordenarMotos(eMoto[], int, eTipo[], int)
 * @brief
 *ordena la lista de motos segun su tipo
 * @param lista -> lista de motos
 * @param tam -> tamaño de la lista
 * @param tipos -> lista de tipos
 * @param tamTipos -> tamaño e la lista
 * @return devuelev 1 si ordeno, 0 si no
 */
int ordenarMotos(eMoto lista[], int tam,eTipo tipos[],int tamTipos);


