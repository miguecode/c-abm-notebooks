/*
 * Notebook.c
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Notebook.h"
#include "Marca.h"
#include "Tipo.h"
#include "Menu.h"
#include "Validaciones.h"

int mostrarNotebook(eNotebook lista, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
    int todoOk = 0;
    char descMarca[20];
    char descTipo[20];

    if(marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
    {

    cargarDescripcionMarca(marcas, tamMar, lista.idMarca, descMarca);
    cargarDescripcionTipo(tipos, tamTip, lista.idTipo, descTipo);


    printf("  %4d  %15s  %10s  %10s     %9.2f\n",
    		lista.id, lista.modelo, descMarca, descTipo, lista.precio);

        todoOk = 1;
    }
    return todoOk;
}

int listarNotebooks(eNotebook vec[], eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
    {
        printf("          *** Listado de Notebooks ***\n\n");
        printf("   ID             Modelo       Marca       Tipo       Precio\n");
        printf("-----------------------------------------------------------------\n");
        for(int i=0; i < 10; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarNotebook(vec[i], marcas, tamMar, tipos, tamTip);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("     No hay notebooks en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}



int inicializarNotebooks(eNotebook vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty == 1)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaNotebook(eNotebook vec[], int tam, int* pId, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
    int todoOk = 0;
    int indice;
    char auxCad[100];
    eNotebook nuevaNotebook;
    int validPrecio = 0;

    if(vec != NULL && tam > 0 && pId != NULL && marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
    {
        if(buscarNotebookLibre(vec, tam, &indice))
        {
            if(indice == -1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {


            	printf("Ingrese el modelo de la Notebook: ");
                fflush(stdin);
                gets(auxCad);
                validarPalabra(auxCad);
				strcpy(nuevaNotebook.modelo, auxCad);


				listarMarcas(marcas, tamMar); //Primero muestro los sectores

			    printf("Ingrese la ID de la marca a la que pertenece: ");
				scanf("%d", &nuevaNotebook.idMarca);

				while(!validarMarca(marcas, tamMar, nuevaNotebook.idMarca))
				{
					printf("Error, esa ID no corresponde a ninguna marca. Reingrese ID: ");
					fflush(stdin);
					scanf("%d", &nuevaNotebook.idMarca);
				}

				listarTipos(tipos, tamTip);

				printf("Ingrese la ID del tipo al que pertenece: ");
				scanf("%d", &nuevaNotebook.idTipo);

				while(!validarTipo(tipos, tamTip, nuevaNotebook.idTipo))
				{
					printf("Error, esa ID no corresponde a ningún tipo. Reingrese ID: ");
					fflush(stdin);
					scanf("%d", &nuevaNotebook.idTipo);
				}


				printf("Ingrese precio: ");
				validPrecio = scanf("%f", &nuevaNotebook.precio);
                validarFloat(validPrecio, &nuevaNotebook.precio);


                nuevaNotebook.isEmpty = 0;
                nuevaNotebook.id = *pId;
                *pId = *pId + 1;
                vec[indice] = nuevaNotebook;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parámetros\n");
        }
    }
    return todoOk;
}


int buscarNotebook(eNotebook vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && id > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {
            if(vec[i].isEmpty == 0 && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int bajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(vec != NULL && tam > 0 && marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
    {
        listarNotebooks(vec, marcas, tamMar, tipos, tamTip);
        printf("Ingrese ID: ");
        scanf("%d", &id);

        if(buscarNotebook(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un empleado con legajo %d\n", id);
            }
            else //Si lo encuentra...
            {
                mostrarNotebook(vec[indice], marcas, tamMar, tipos, tamTip); //Le muestro el empleado que seleccionó
                printf("Si desea hacer la baja, ingrese 's': ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;  //Lo doy de baja. Es decir, le pongo el isEmpty en 1
                    printf("Baja realizada correctamente\n");
                    todoOk = 1;
                }
            }
        }
        else
        {
            printf("Ocurrió un problema al buscar la Notebook\n");
        }

        todoOk = 1;
    }
    return todoOk;
}


int modificarNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';
    int validPrecio = 0;


    if(vec != NULL && tam > 0 && marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
    {
        listarNotebooks(vec, marcas, tamMar, tipos, tamTip);
        printf("Ingrese ID: ");
        scanf("%d", &id);

        if(buscarNotebook(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una notebook con ID %d\n", id);
            }
            else
            {
            	mostrarNotebook(vec[indice], marcas, tamMar, tipos, tamTip);

                do
                {
                    switch(menuModificarNotebook())
                    {
                    case 1:
                    	printf("Ingrese precio: ");
						validPrecio = scanf("%f", &vec[indice].precio);
						validarFloat(validPrecio, &vec[indice].precio);

						printf("Precio modificado correctamente");
                        break;

                    case 2:
                    	listarTipos(tipos, tamTip);

						printf("Ingrese la ID del tipo al que pertenece: ");
						scanf("%d", &vec[indice].idTipo);

						while(!validarTipo(tipos, tamTip, vec[indice].idTipo))
						{
							printf("Error, esa ID no corresponde a ningún tipo. Reingrese ID: ");
							fflush(stdin);
							scanf("%d", &vec[indice].idTipo);
						}

						printf("Tipo modificado correctamente");
                    	break;

                    case 3:
                        salir = 's';

                        break;
                    }
                    system("pause");

                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrió un problema al buscar Notebook\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int menuModificarNotebook()
{
    int opcion;
    printf("   *** Menu Modificar ***\n\n");
    printf("1- Precio\n");
    printf("2- Tipo\n");
    printf("3- Salir\n\n");
    printf("Ingrese opción: ");
    scanf("%d", &opcion);
    return opcion;
}

int hardcodearNotebooks(eNotebook vec[], int tam, int cant, int* pId)
{
    int todoOk = 0;
    eNotebook impostores[] =
    {
        {0, "Modelo_1", 1000, 5000, 20000,0},
        {0, "Modelo_2", 1001, 5000, 25000,0},
        {0, "Modelo_3", 1001, 5000, 35750,0},
        {0, "Modelo_4", 1003, 5000, 40000,0},
        {0, "Modelo_5", 1002, 5000, 15800,0}
    };

    if(vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {
        for(int i = 0; i < cant; i++)
        {
            vec[i] = impostores[i];
            vec[i].id = *pId;
            *pId = *pId +1;
        }
        todoOk = 1;
    }
    return todoOk;

}


int cargarDescripcionNotebook(eNotebook notebooks[], int tam, int id, char descripcion[])
{
	int todoOk = 0;
	int indice;

	buscarNotebook(notebooks, tam, id, &indice);

    if(descripcion != NULL && indice != -1)
    {
		strcpy(descripcion, notebooks[indice].modelo);
		todoOk = 1;
    }

  return todoOk;
}


int validarNotebook(eNotebook notebooks[], int tam, int id)
{
	int esValido = 0;
	int indice;

	buscarNotebook(notebooks, tam, id, &indice);

	if(!(indice == -1))
	{
		esValido = 1;
	}


	return esValido;
}











