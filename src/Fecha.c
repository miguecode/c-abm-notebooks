#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Notebook.h"
#include "Fecha.h"
#include "Trabajo.h"


int validarFecha(eFecha* unaFecha)
{
	int todoOk = 0;

	while(!(unaFecha != NULL && (unaFecha->anio >= 1990 && unaFecha->anio <= 2022) &&
	  (unaFecha->mes > 0 && unaFecha->mes <= 12) && (unaFecha->dia > 0 && unaFecha->dia <= 31)))
	{
    	printf("Fecha invalida. Recuerde que debe separar dia, mes y anio (1990-2022) usando / / / \n");
		printf("[>] Reingrese fecha dd/mm/aaaa: ");
		fflush(stdin);
		scanf("%d/%d/%d", &unaFecha->dia, &unaFecha->mes, &unaFecha->anio);
	}

	switch(unaFecha->mes)
	{
	case 2:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 28))
		{
			printf("Dia invalido. Febrero tiene 28 dias \n");
			printf("[>] Reingrese dia: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	case 4:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 30))
		{
			printf("Dia invalido. Abril tiene 30 dias \n");
			printf("[>] Reingrese dia: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	case 6:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 30))
		{
			printf("Dia invalido. Junio tiene 30 dias \n");
			printf("[>] Reingrese dia: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	case 9:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 30))
		{
			printf("Dia invalido. Septiembre tiene 30 dias \n");
			printf("[>] Reingrese dia: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	case 11:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 30))
		{
			printf("Dia invalido. Noviembre tiene 30 dias \n");
			printf("[>] Reingrese dia: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	default:
		todoOk = 1;
	}

	todoOk = 1;


	return todoOk;
}
