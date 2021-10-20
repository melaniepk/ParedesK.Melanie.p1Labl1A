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

int mostrarServicios(eServicio servicios[], int tam);
int cargarDescripcionServicio(eServicio servicios[], int tam, int idServicio, char descServicio[]);
int validarIdServicio(eServicio servicios[], int tam, int idBuscado);
