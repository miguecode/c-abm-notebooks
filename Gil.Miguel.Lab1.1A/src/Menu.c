/*
 * Menu.c
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Menu.h"

int menu()
{
	int todoOk = 0;
	int opcion;

	printf("  ***** MENU DE OPCIONES *****     \n\n");
	printf("Ingrese una opción del 1 al 17: \n\n");

	printf("1. ALTA NOTEBOOK\n");
	printf("2. MODIFICAR NOTEBOOK\n");
	printf("3. BAJA NOTEBOOK\n");
	printf("4. LISTAR NOTEBOOKS\n");
	printf("5. LISTAR MARCAS\n");
	printf("6. LISTAR TIPOS\n");
	printf("7. LISTAR SERVICIOS\n");
	printf("8. ALTA TRABAJO\n");
	printf("9. LISTAR TRABAJOS\n\n");
	printf("10. INFORMAR NOTEBOOKS DE UN TIPO\n");
	printf("11. INFORMAR NOTEBOOKS DE UNA MARCA\n");
	printf("12. INFORMAR LA O LAS NOTEBOOKS MÁS BARATAS\n");
	printf("13. INFORMAR NOTEBOOKS DE CADA MARCA\n");
	printf("14. INFORMAR CANTIDAD DE NOTEBOOKS DE UNA MARCA Y UN TIPO\n");
	printf("15. INFORMAR LA O LAS MARCAS CON MÁS NOTEBOOKS\n");
	printf("16. INFORMAR EL O LOS TRABAJOS DE UNA NOTEBOOK\n\n");

	printf("17. SALIR \n\n");

	printf("Ingrese opción: ");
	fflush(stdin);
	todoOk = scanf("%d", &opcion);

	if(todoOk)
	{
		return opcion;
	}

	return todoOk;
}


void confirmarSalidaMenu(char* p)
{
	if(p != NULL)
	{
		char confirma;

		printf("¿Confirma la salida del programa? (si = 's'  no = 'n') \n");
		fflush(stdin);
		scanf("%c", &confirma);
		confirma = tolower(confirma);

		while(confirma != 's' && confirma != 'n')
		{
			printf("Error, debe responder con 's' o 'n':  \n");
			fflush(stdin);
			scanf("%c", &confirma);
			confirma = tolower(confirma);
		}
		*p = confirma;
	}
}
