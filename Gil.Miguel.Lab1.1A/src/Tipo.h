/*
 * Tipo.h
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct{

int id;
char descripcion[20];

}eTipo;

#endif /* TIPO_H_ */

int listarTipos(eTipo tipos[], int tam);
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);
int buscarTipo(eTipo tipos[], int tam, int id, int* pIndice);
int validarTipo(eTipo tipos[], int tam, int id);
