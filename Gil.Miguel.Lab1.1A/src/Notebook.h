/*
 * Notebook.h
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_

#include "Marca.h"
#include "Tipo.h"

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;
} eNotebook;

#endif /* NOTEBOOK_H_ */


int mostrarNotebook(eNotebook lista, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);

int listarNotebooks(eNotebook vec[], eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);


int inicializarNotebooks(eNotebook vec[], int tam);


int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex);
int altaNotebook(eNotebook vec[], int tam, int* pId, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);


int buscarNotebook(eNotebook vec[], int tam, int id, int* pIndex);
int bajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);


int modificarNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);
int menuModificarNotebook();


int hardcodearNotebooks(eNotebook vec[], int tam, int cant, int* pLegajo);


int cargarDescripcionNotebook(eNotebook notebooks[], int tam, int id, char descripcion[]);
int validarNotebook(eNotebook notebooks[], int tam, int id);
