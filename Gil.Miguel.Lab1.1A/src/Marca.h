/*
 * Marca.h
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct{
	int id;
	char descripcion[20];
}eMarca;

#endif /* MARCA_H_ */

/// @brief Muestra un listado de todas las marcas del sistema, con su ID y descripción.
///
/// @param marcas recibe el array de la estructura eMarca
/// @param tam recibe el tamaño del array de la estructura eMarca
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int listarMarcas(eMarca marcas[], int tam);


/// @brief Le pasa el valor de descripción de la estructura eMarca a un array también
/// llamado descripción, para poder mostrarlo usando otra función.
///
/// @param marcas recibe el array de la estructura eMarca
/// @param tam recibe el tamaño del array de la estructura eMarca
/// @param id recibe la id para pasarsela a la funcion buscarMarca
/// @param descripcion recibe un array en el cual va a ser cargada la descripción correspondiente
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int cargarDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[]);


/// @brief Busca por ID la marca que se solicite, y le da valor al índice correspondiente (o -1).
///
/// @param marcas recibe el array de la estructura eMarca
/// @param tam recibe el tamaño del array de la estructura eMarca
/// @param id recibe el id de la marca que debe buscar
/// @param pIndice recibe la ddm de una variable en la cual va a ser cargado el indice correspondiente (o -1)
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int buscarMarca(eMarca marcas[], int tam, int id, int* pIndice);


/// @brief Valida si el ID de la marca ingresada existe o no en el sistema.
///
/// @param marcas recibe el array de la estructura eMarca
/// @param tam recibe el tamaño del array de la estructura eMarca
/// @param id recibe la id para buscarla y verificar si existe o no
/// @return devuelve 1 si es valido, y sino devuelve 0
int validarMarca(eMarca marcas[], int tam, int id);
