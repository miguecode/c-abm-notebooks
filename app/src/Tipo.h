#ifndef TIPO_H_
#define TIPO_H_

typedef struct{
	int id;
	char descripcion[20];
}eTipo;

#endif /* TIPO_H_ */

/// @brief Muestra un listado de todos los tipos del sistema, con su ID y descripci�n.
///
/// @param tipos recibe el array de la estructura eTipo
/// @param tam recibe el tama�o del array de la estructura eTipo
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int listarTipos(eTipo tipos[], int tam);


/// @brief Le pasa el valor de descripci�n de la estructura eTipo a un array tambi�n
/// llamado descripci�n, para poder mostrarlo usando otra funci�n.
///
/// @param tipos recibe el array de la estructura eTipo
/// @param tam recibe el tama�o del array de la estructura eTipo
/// @param id recibe la id para pasarsela a la funcion buscarTipo
/// @param descripcion recibe un array en el cual va a ser cargada la descripci�n correspondiente
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);


/// @brief Busca por ID el tipo que se solicite, y le da valor al �ndice correspondiente (o -1).
///
/// @param tipos recibe el array de la estructura eTipo
/// @param tam recibe el tama�o del array de la estructura eTipo
/// @param id recibe el id del tipo que debe buscar
/// @param pIndice recibe la ddm de una variable en la cual va a ser cargado el indice correspondiente (o -1)
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int buscarTipo(eTipo tipos[], int tam, int id, int* pIndice);


/// @brief Valida si el ID del tipo ingresado existe o no en el sistema.
///
/// @param tipos recibe el array de la estructura eTipo
/// @param tam recibe el tama�o del array de la estructura eTipo
/// @param id recibe la id para buscarla y verificar si existe o no
/// @return devuelve 1 si es valido, y sino devuelve 0
int validarTipo(eTipo tipos[], int tam, int id);
