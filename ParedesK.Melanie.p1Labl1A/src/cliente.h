/*
 * cliente.h
 *
 *  Created on: 27 oct. 2021
 *      Author: mkale
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
	char nombre[20];
	char sexo;
}eCliente;


#endif /* CLIENTE_H_ */

int validarIdCliente(eCliente clientes[], int tam, int idBuscado);
int mostrarClientes(eCliente clientes[], int tam);
int cargarNombreCliente(eCliente clientes[], int tam, int idCliente, char nombre[]);
