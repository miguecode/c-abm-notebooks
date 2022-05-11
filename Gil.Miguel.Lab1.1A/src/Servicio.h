/*
 * Servicio.h
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_


typedef struct{

int id;
char descripcion[25];
float precio;

}eServicio;

#endif /* SERVICIO_H_ */

int listarServicios(eServicio servicios[], int tam);
int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[]);
int buscarServicio(eServicio servicios[], int tam, int id, int* pIndice);
int validarServicio(eServicio servicios[], int tam, int id);
