#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{
	int id;
	char descripcion[25];
	float precio;
}eServicio;

#endif /* SERVICIO_H_ */

/// @brief Muestra un listado de todas las Notebooks del sistema, con su ID y descripci�n.
///
/// @param servicios recibe el array de la estructura eServicio
/// @param tam recibe el tama�o del array de la estructura eServicio
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int listarServicios(eServicio servicios[], int tam);


/// @brief Le pasa el valor de descripci�n de la estructura eServicio a un array tambi�n
/// llamado descripci�n, para poder mostrarlo usando otra funci�n.
///
/// @param servicios recibe el array de la estructura eServicio
/// @param tam recibe el tama�o del array de la estructura eServicio
/// @param id recibe la id para pasarsela a la funcion buscarServicio
/// @param descripcion recibe un array en el cual va a ser cargada la descripci�n correspondiente
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[]);


/// @brief Busca por ID el servicio que se solicite, y le da valor al �ndice correspondiente (o -1).
///
/// @param servicios recibe el array de la estructura eServicio
/// @param tam recibe el tama�o del array de la estructura eServicio
/// @param id recibe el id del servicio que debe buscar
/// @param pIndice recibe la ddm de una variable en la cual va a ser cargado el indice correspondiente (o -1)
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int buscarServicio(eServicio servicios[], int tam, int id, int* pIndice);


/// @brief Valida si el ID del servicio ingresado existe o no en el sistema.
///
/// @param servicios recibe el array de la estructura eServicio
/// @param tam recibe el tama�o del array de la estructura eServicio
/// @param id recibe la id para buscarla y verificar si existe o no
/// @return devuelve 1 si es valido, y sino devuelve 0
int validarServicio(eServicio servicios[], int tam, int id);
