/*
 * dataWarehouse.h
 *
 *  Created on: 20 oct. 2021
 *      Author: mkale
 */

#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"
#include "moto.h"
#include "color.h"
#include "tipo.h"
#include "fecha.h"
#include "trabajo.h"
#include "cliente.h"


#endif /* DATAWAREHOUSE_H_ */
/**
 * @fn int hardcodearMotos(eMoto[], int, int, int*)
 * @brief
 * hardcodea motos
 * @param lista -> lista de motos
 * @param tam -> tamaño dela lista
 * @param cant -> cantidad de motos a hardcodear
 * @param pId -> id a asigna a la moto
 * @return
 */
int hardcodearMotos(eMoto lista[], int tam, int cant, int* pId);
int hardcodearTrabajos(eTrabajo lista[], int tam, int cant,int *pId);
