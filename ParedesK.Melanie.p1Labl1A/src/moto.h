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
#include "cliente.h"

typedef struct
{
	int id;
	char marca[20];
	int idTipo;
	int idColor;
	int cilindrada;
	int puntaje; //1 a 10
	eCliente cliente;
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
int modificarMoto(eCliente clientes[], int tamCli,eMoto lista[],eTipo tipos[], eColor colores[], int tamTipos, int tamColores, int tam);

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
int bajaMoto(eCliente clientes[], int tamCli,eMoto lista[],eTipo tipos[], eColor colores[], int tamTipos, int tamColores,int tam);

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
int mostrarMotos(eCliente clientes[], int tamCli,eMoto lista[], eTipo tipos[], eColor colores[], int tamTipos,int tamColores,  int tam);

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
void mostrarMoto(eCliente clientes[], int tamCli,eMoto unaMoto, eTipo tipos[], eColor colores[], int tamTipos,int tamColores);
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
int altaMoto(eCliente clientes[],int tamCli,eMoto lista[], int tam, eTipo tipos[],eColor colores[], int tamTipo, int tamColores,int *pId);
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
int validarIdMoto(eMoto lista[], int tam, int idBuscado);
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
int ordenarMotos(eCliente clientes[], int tamCli,eMoto lista[], int tam,eTipo tipos[],int tamTipos);

/**
 * @fn int cargarDescripcionMoto(eMoto[], int, int, char[])
 * @brief
 * carga en la variavle descMoto el nombre de la marca de la moto buscada por id
 * @param motos lista de motos
 * @param tam tamaño de la lista
 * @param idMoto id de la moto buscada
 * @param descMoto variable a cargar
 * @return devuelve 1 si funcionó, 0 si no
 */
int cargarDescripcionMoto(eMoto motos[], int tam, int idMoto, char descMoto[]);

/**
 * @fn int informeMotosColor(eCliente[], int, eMoto[], int, eTipo[], int, eColor[], int)
 * @brief
 * muestra todas las motos con un color seleccionado por el ususario
 * @param clientes -> lista de cleintes
 * @param tamCli ->tamaño de la lista de clientes
 * @param lista-> lista de motos
 * @param tam ->tamaño de la lista de motos
 * @param tipos -> lisyta de tipos
 * @param tamt -> tamaño de la lista de tipos
 * @param colores ->lista de colores
 * @param tamc-> tamaño de la lista de colores
 * @return 1 si pudo informar, 0 si no
 */
int informeMotosColor(eCliente clientes[],int tamCli,eMoto lista[],int tam,eTipo tipos[],int tamt, eColor colores[], int tamc);
/**
 * @fn int mostrarMotosPorColorId(eCliente[], int, eMoto[], int, eTipo[], int, eColor[], int, int)
 * @brief
 * muestra las motos con determinado color seleccionado por el cliente
 * @param clientes -> lista de clientes
 * @param tamCli->tamaño de la lista
 * @param lista ->lista de motos
 * @param tam ->tamaño de la lista
 * @param tipos-> lista de tipos
 * @param tamt ->tamaño de la lista
 * @param colores ->lista de colores
 * @param tamc -> tamaño de la lista
 * @param idColor ->id del color cuyas motos hay que mostrar
 * @return 1 si muestra, 0 si no
 */
int mostrarMotosPorColorId(eCliente clientes[],int tamCli,eMoto lista[],int tam,eTipo tipos[],int tamt, eColor colores[], int tamc,int idColor);


/**
 * @fn int informePromedioMotosTipo(eCliente[], int, eMoto[], int, eTipo[], int, eColor[], int)
 * @brief
 * muestra el promedio de puntaje en un tipo de moto seleccionado por el usuario
 * @param clientes ->lista de clientes
 * @param tamCli ->tamaño de la lista
 * @param lista ->lista de motos
 * @param tam->tamaño de la lista de motos
 * @param tipos ->lista de tipos
 * @param tamt ->tamaño de la lista de tipos
 * @param colores ->lista de colores
 * @param tamc ->tamaño de la lista de colores
 * @return 1 si pudo informar, 0 si no
 */
int informePromedioMotosTipo(eCliente clientes[],int tamCli,eMoto lista[],int tam,eTipo tipos[],int tamt, eColor colores[], int tamc);

/**
 * @fn int mostrarMotosPorTipoId(eCliente[], int, eMoto[], int, eTipo[], int, eColor[], int, int)
 * @brief
 * muestra las motos de un determinado tipo segun el id seleccionado
 * @param clientes->lista de clientes
 * @param tamCli ->tamaño de la lista
 * @param lista ->lista de motos
 * @param tam -> tamaño de la lista
 * @param tipos ->lista de tipos
 * @param tamt ->tamaño de la lista
 * @param colores ->lista de colores
 * @param tamc ->tamaño de la lista
 * @param idTipo ->id del tipo de las motos a mostrar
 * @return 1 si puede mostrar, 0 si no
 */
int mostrarMotosPorTipoId(eCliente clientes[], int tamCli,eMoto lista[],int tam,eTipo tipos[],int tamt, eColor colores[], int tamc,int idTipo);
/**
 * @fn int motoMayorCilindrada(eCliente[], int, eMoto[], int, eTipo[], int, eColor[], int)
 * @brief
 * muestra la moto con mayor cilindrada
 * @param clientes ->lista de clientes
 * @param tamCli ->tamaño de la lista de clientes
 * @param lista ->lista de motos
 * @param tam ->tamaño de la lista de motos
 * @param tipos ->lista de tipos
 * @param tamt ->tamaño de la loista de tipos
 * @param colores ->lista de colores
 * @param tamc ->tamaño de la lista de colores
 * @return 1 si pudo mostrar, 0 si no
 */
int motoMayorCilindrada(eCliente clientes[], int tamCli,eMoto lista[], int tam, eTipo tipos[], int tamt,eColor colores[], int tamc);
/**
 * @fn int informeMotosAllTipos(eCliente[], int, eMoto[], int, eTipo[], int, eColor[], int)
 * @brief
 * lista las motos de todos los tipos
 * @param clientes ->lista de clientes
 * @param tamCli ->tamaño de la lista de cleintes
 * @param lista ->lista de motos
 * @param tam->tamaño de la lista de motos
 * @param tipos ->lista de tipos
 * @param tamt->tamaño de la lista de tipos
 * @param colores->lista de colores
 * @param tamc ->tamaño de la lista de colores
 * @return 1 si pudo encontrar la moto, 0 si no
 */
int informeMotosAllTipos(eCliente clientes[],int tamCli,eMoto lista[],int tam, eTipo tipos[], int tamt,eColor colores[],int tamc);
/**
 * @fn int cantidadMotosPorTipoYColor(eMoto[], int, eTipo[], int, eColor[], int)
 * @brief
 * cuenta la cantidad de motos de un tipo y color seleccionado por el usuario
 * @param lista ->lista de motos
 * @param tam ->tamaño de la lista
 * @param tipos ->lista de tipos
 * @param tamt->tamaño de la lista de tipos
 * @param colores ->lista de colores
 * @param tamc->tamaño de la lista de colores
 * @return 1 si pudo calcular, 0 si no
 */
int cantidadMotosPorTipoYColor(eMoto lista[], int tam,eTipo tipos[], int tamt,eColor colores[], int tamc);
/**
 * @fn int informeColoresMasElegidos(eMoto[], int, eTipo[], int, eColor[], int)
 * @brief
 * muestra el color mas elegido para las motos
 * @param lista ->lista de motos
 * @param tam->tamaño de la lista de motos
 * @param tipos->lista de tipos
 * @param tamt ->tamaño de la lista de tipos
 * @param colores ->lista de colores
 * @param tamc >_tamaño de la lista de colores
 * @return 1 si encontró el color, 0 si no
 */
int informeColoresMasElegidos(eMoto lista[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc);
/**
 * @fn int menuInformes()
 * @brief
 * muestra un submenú de los informes que se pueden realizar
 * @return
 */
int menuInformes();



