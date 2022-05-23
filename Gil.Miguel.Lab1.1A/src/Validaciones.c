/*
 * Validaciones.c
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Validaciones.h"

int validarPalabra(char* palabra)
{
	int todoOk = -1;

	for(int i = 0; i < strlen(palabra); i++)
	{
		while((palabra == NULL) || (strlen(palabra) < 2) || (strlen(palabra) > 19)
			|| ((!(palabra[i] >= 65 && palabra[i] <= 90)) && (!(palabra[i] >= 97 && palabra[i] <= 122))))
		{
			printf("Modelo inválido. Debe ingresar entre 2-49 caracteres. Sólo letras, sin tildes ni espacios. \n");
			printf("Reingrese: ");
			fflush(stdin);
			gets(palabra);
		}

		todoOk = 1;
	}

	return todoOk;
}


int validarInt(int validarInt, int* pNum)
{
	int todoOk = 0;
	int num;
	num = *pNum;

	while(validarInt != 1 || pNum == NULL || num < 0)
	{
		printf("Error, debe ingresar un número entero mayor a 0. Reingrese número: ");
		fflush(stdin);
		validarInt = scanf("%d", &num);
	}

	*pNum = num;
	return todoOk;
}


int validarFloat(int validarFloat, float* pNum)
{
	int todoOk = 0;
	float num;
	num = *pNum;

	while(validarFloat != 1 || pNum == NULL  || num <= 0)
	{
		printf("Error, debe ingresar un precio numérico y mayor a 0. Reingrese precio: ");
		fflush(stdin);
		validarFloat = scanf("%f", &num);
	}

	*pNum = num;
	return todoOk;
}


int validarCodigo(char* codigo)
{
	int todoOk = 0;

	if(codigo != NULL)
	{
		for(int i = 0; i < strlen(codigo); i++)
		{
			while(strlen(codigo) < 3 || strlen(codigo) > 19
			|| ((!(codigo[i] >= 65 && codigo[i] <= 90)) && (!(codigo[i] >= 97 && codigo[i] <= 122))
			&& (!(codigo[i] >= 48 && codigo[i] <= 57))))
			{
				printf("Modelo inválido. Recuerde que debe tener entre 3-19 caracteres, sólo letras sin tilde y números.\n");
				printf("Reingrese modelo: ");
				fflush(stdin);
				gets(codigo);
			}
		}
	}

	return todoOk;
}
