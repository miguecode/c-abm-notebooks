/*
 * Trabajo.h
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_

#include "Notebook.h"
#include "Servicio.h"
#include "Fecha.h"

typedef struct{
	int id;
	int idNotebook;
	int idServicio;
	eFecha fPactada;
	int isEmpty;
}eTrabajo;

#endif /* TRABAJO_H_ */

/// @brief Muestra los datos de un trabajo en fila (ID, marca, tipo, y precio).
///
/// @param lista  recibe el array de la estructura eTrabajo
/// @param notebooks recibe el array de la estructura eNotebook
/// @param tamNot recibe el tamaño del array de la estructura eNotebook
/// @param servicios recibe el array de la estructura eServicio
/// @param tamSer recibe el tamaño del array de la estructura eServicio
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int mostrarTrabajo(eTrabajo lista, eNotebook notebooks[], int tamNot, eServicio servicios[], int tamSer);


/// @brief Muestra el listado de todos los trabajos con isEmpty = 0 del sistema,
/// cada uno con su campo.
///
/// @param vec recibe el array de la estructura eTrabajo
/// @param tamTra recibe el tamaño del array de la estructura eTrabajo
/// @param notebooks recibe el array de la estructura eNotebook
/// @param tamNot recibe el tamaño del array de la estructura eNotebook
/// @param servicios recibe el array de la estructura eServicio
/// @param tamSer recibe el tamaño del array de la estructura eServicio
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int listarTrabajos(eTrabajo vec[], int tamTra, eNotebook notebooks[], int tamNot, eServicio servicios[], int tamSer);


/// @brief Inicializa el array de Trabajos, colocando a todos
/// los 'isEmpty' en '1'.
///
/// @param vec recibe el array de la estructura eTrabajo
/// @param tam recibe el tamaño del array de la estructura eTrabajo
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int inicializarTrabajos(eTrabajo vec[], int tam);


/// @brief Va a buscar un lugar libre (isEmpty = 1) en el sistema, y al encontrarlo,
/// devuelve el índice correspondiente.
///
/// @param vec recibe el array de la estructura eTrabajo
/// @param tam recibe el tamaño del array de la estructura eTrabajo
/// @param pIndex recibe la ddm de una variable en la cual va a ser cargado el indice correspondiente (o -1)
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex);


/// @brief Primero va a buscar si hay un lugar disponible en el sistema,
/// y si hay, va a pedirle al usuario que ingrese cada dato de un nuevo
/// trabajo para agregarlo al listado.
///
/// @param vec recibe el array de la estructura eTrabajo
/// @param tam recibe el tamaño del array de la estructura eTrabajo
/// @param pId recibe la ddm de una variable la cual va a tener el valor del id que viene del main
/// @param notebooks recibe el array de la estructura eNotebook
/// @param tamNot recibe el tamaño del array de la estructura eNotebook
/// @param marcas recibe el array de la estructura eMarca
/// @param tamMar recibe el tamaño del array de la estructura eMarca
/// @param tipos recibe el array de la estructura eTipo
/// @param tamTip recibe el tamaño del array de la estructura eTipo
/// @param servicios recibe el array de la estructura eServicio
/// @param tamSer recibe el tamaño del array de la estructura eServicio
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int altaTrabajo(eTrabajo vec[], int tam, int* pId, eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar,
		eTipo tipos[], int tamTip, eServicio servicios[], int tamSer);


/// @brief Le cargo datos válidos de distintos trabajos para ya tener
/// un par en el sistema y no tener que hacer un Alta.
///
/// @param vec recibe el array de la estructura eTrabajo
/// @param tam recibe el tamaño del array de la estructura eTrabajo
/// @param cant recibe un entero de la cantidad de hardcodeos que se hará (máx 5)
/// @param pId recibe la ddm de una variable la cual va a tener el valor del id que viene del main
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int hardcodearTrabajos(eTrabajo vec[], int tam, int cant, int* pId);


/// @brief Muestra un listado de los trabajos que estén vinculados a una
/// Notebook seleccionada por el usuario.
///
/// @param vec recibe el array de la estructura eTrabajo
/// @param tam recibe el tamaño del array de la estructura eTrabajo
/// @param notebooks recibe el array de la estructura eNotebook
/// @param tamNot recibe el tamaño del array de la estructura eNotebook
/// @param marcas recibe el array de la estructura eMarca
/// @param tamMar recibe el tamaño del array de la estructura eMarca
/// @param tipos recibe el array de la estructura eTipo
/// @param tamTip recibe el tamaño del array de la estructura eTipo
/// @param servicios recibe el array de la estructura eServicio
/// @param tamSer recibe el tamaño del array de la estructura eServicio
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int informarTrabajosNotebook(eTrabajo vec[], int tam, eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar,
		eTipo tipos[], int tamTip, eServicio servicios[], int tamSer);
