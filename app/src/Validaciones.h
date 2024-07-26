#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/// @brief Valida que una cadena sea de s�lo letras, sin tildes ni espacios,
/// y que tenga un m�nimo y un m�ximo de caracteres.
///
/// @param auxCad recibe la cadena escrita la cual se va a validar
/// @return retorna 1 cuando finalice la funci�n
int validarPalabra(char* auxCad);


/// @brief Valida que el caracter ingresado sea un n�mero entero,
/// y que est� entre un m�nimo y un m�ximo si es necesario.
///
/// @param validarInt recibe 1 si lo recibido es un entero, o un 0 si no lo es
/// @param num recibe la ddm de un n�mero el cual se va a validar
/// @return retorna 1 cuando finalice la funci�n
int validarInt(int validarInt, int* num);


/// @brief Valida que el caracter ingresado sea un n�mero float,
/// y que est� entre un m�nimo y un m�ximo si es necesario.
///
/// @param validarFloat recibe 1 si lo recibido es un float, o un 0 si no lo es
/// @param num recibe la ddm de un float el cual se va a validar
/// @return retorna 1 cuando finalice la funci�n
int validarFloat(int validarFloat, float* num);


/// @brief Valida que el c�digo ingresado sea correcto (s�lo n�meros y letras).
///
/// @param codigo recibe el c�digo ingresado y lo valida
/// @return retorna 1 cuando finalice la funci�n
int validarCodigo(char* codigo);


#endif /* VALIDACIONES_H_ */
