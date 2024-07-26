#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Marca.h"

int listarMarcas(eMarca marcas[], int tam)
{
	int todoOk = 0;

		if(marcas != NULL && tam > 0)
		{
			printf("\n***  Lista de Marcas  ***\n\n");
			printf("    ID        Descripcion\n");
			printf("----------------------------\n");
			for(int i = 0; i < tam; i++){
				printf("   %4d    %10s\n", marcas[i].id, marcas[i].descripcion);
			}
			printf("\n\n");
			todoOk = 1;
		}
	 return todoOk;
}

int cargarDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[])
{
	int todoOk = 0;
	int indice;

	buscarMarca(marcas, tam, id, &indice);

    if(descripcion != NULL && indice != -1)
    {
		strcpy(descripcion, marcas[indice].descripcion);

		todoOk = 1;
    }

  return todoOk;
}

int buscarMarca(eMarca marcas[], int tam, int id, int* pIndice)
{
	int todoOk = 0;

	if(marcas != NULL && tam > 0 && pIndice != NULL)
	{
		*pIndice = -1;
		for(int i=0; i < tam; i++)
		{
			if(marcas[i].id == id)
			{
				*pIndice = i;
				break;
			}
		}

		todoOk = 1;
	}

	return todoOk;
}

int validarMarca(eMarca marcas[], int tam, int id)
{
	int esValido = 0;
	int indice;

	buscarMarca(marcas, tam, id, &indice);

	if(!(indice == -1))
	{
		esValido = 1;
	}

	return esValido;
}
