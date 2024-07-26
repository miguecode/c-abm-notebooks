#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Fecha.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Notebook.h"
#include "Marca.h"
#include "Tipo.h"
#include "Menu.h"
#include "Validaciones.h"

int inicializarTrabajos(eTrabajo vec[], int tam)
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


int mostrarTrabajo(eTrabajo lista, eNotebook notebooks[], int tamNot, eServicio servicios[], int tamSer)
{
    int todoOk = 0;
    char descNotebook[20];
    char descServicio[20];


    if(notebooks != NULL && tamNot > 0 && servicios != NULL && tamSer > 0)
    {

    cargarDescripcionNotebook(notebooks, tamNot, lista.idNotebook, descNotebook);
    cargarDescripcionServicio(servicios, tamSer, lista.idServicio, descServicio);



    printf("  %4d         %10s       %13s           %02d/%02d/%d\n",
    lista.id, descNotebook, descServicio, lista.fPactada.dia, lista.fPactada.mes, lista.fPactada.anio);

        todoOk = 1;
    }
    return todoOk;
}

int listarTrabajos(eTrabajo vec[], int tamTra, eNotebook notebooks[], int tamNot, eServicio servicios[], int tamSer)
{
    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && notebooks != NULL && tamNot > 0 && servicios != NULL && tamSer > 0)
    {
        printf("\n                   *** Listado de Trabajos ***\n\n");
        printf("   ID             Notebook           Servicio           Fecha Pactada    \n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i < tamTra; i++)
        {
        	if(!vec[i].isEmpty)
        	{
                mostrarTrabajo(vec[i], notebooks, tamNot, servicios, tamSer);
                flag++;
        	}
        }
        if(flag == 0)
        {
            printf("                  No hay trabajos en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex)
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



int altaTrabajo(eTrabajo vec[], int tam, int* pId, eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar,
		eTipo tipos[], int tamTip, eServicio servicios[], int tamSer)
{
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;
    eFecha fecha;
    int validFecha = 0;

    if(vec != NULL && tam > 0 && pId != NULL && notebooks != NULL && tamNot > 0 && servicios != NULL && tamSer > 0)
    {
        if(buscarTrabajoLibre(vec, tam, &indice))
        {
            if(indice == -1)
            {
                printf("No hay lugar en el sistema\n");
                return todoOk;
            }
            else
            {
            	listarNotebooks(notebooks, tamNot, marcas, tamMar, tipos, tamTip);

 	 	 	 	printf("Ingrese la ID de la notebook: ");
                fflush(stdin);
				scanf("%d", &nuevoTrabajo.idNotebook);

				while(!validarNotebook(notebooks, tamNot, nuevoTrabajo.idNotebook))
				{
					printf("Error, esa ID no corresponde a ninguna Notebook. Reingrese ID: ");
					fflush(stdin);
					scanf("%d", &nuevoTrabajo.idNotebook);
				}

				listarServicios(servicios, tamSer);

				printf("Ingrese la ID del servicio: ");
				fflush(stdin);
				scanf("%d", &nuevoTrabajo.idServicio);

				while(!validarServicio(servicios, tamSer, nuevoTrabajo.idServicio))
				{
					printf("Error, esa ID no corresponde a ning�n servicio. Reingrese ID: ");
					fflush(stdin);
					scanf("%d", &nuevoTrabajo.idServicio);
				}

      	  	  	printf("Ingrese Fecha Pactada dd/mm/aaaa: ");
      	  	  	fflush(stdin);
                validFecha = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                while(validFecha != 3 || validarFecha(&fecha) != 1)
                {
                	printf("Fecha inv�lida. Recuerde que debe separar d�a, mes y a�o (1990-2022) usando / / / \n");
					printf("Reingrese fecha dd/mm/aaaa: ");
					fflush(stdin);
					validFecha = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                }

                nuevoTrabajo.fPactada = fecha;

                nuevoTrabajo.isEmpty = 0;
                nuevoTrabajo.id = *pId;
                *pId = *pId + 1;
                vec[indice] = nuevoTrabajo;
                todoOk = 1;

                printf("\nTrabajo agregado correctamente\n");
            }
        }
        else
        {
            printf("Ocurri� un problema con los par�metros\n");
        }
    }
    return todoOk;
}


int hardcodearTrabajos(eTrabajo vec[], int tam, int cant, int* pId)
{
    int todoOk = 0;
    eTrabajo hardcodeos[] =
    {
        {0, 10000, 20000, {28,2,2005}, 0},
        {0, 10002, 20004, {28,1,2005}, 0},
        {0, 10003, 20001, {4,6,1999}, 0},
        {0, 10001, 20003, {5,3,2016}, 0},
        {0, 10004, 20002, {4,3,2016}, 0}
    };

    if(vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {
        for(int i = 0; i < cant; i++)
        {
            vec[i] = hardcodeos[i];
            vec[i].id = *pId;
            *pId = *pId +1;
        }
        todoOk = 1;
    }
    return todoOk;

}


int informarTrabajosNotebook(eTrabajo vec[], int tam, eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar,
		eTipo tipos[], int tamTip, eServicio servicios[], int tamSer)
{
	int todoOk = 0;
	int idNotebook;
	char descNotebook[20];
	int flag = 0;

    if(vec != NULL && tam > 0 && notebooks != NULL && tamNot > 0 && servicios != NULL && tamSer > 0)
    {
    	listarNotebooks(notebooks, tamNot, marcas, tamMar, tipos, tamTip);

    	printf("Ingrese la ID de la notebook: ");
    	fflush(stdin);
    	scanf("%d", &idNotebook);
    	if(!validarNotebook(notebooks, tamNot, idNotebook))
    	{
    		printf("Error, esa ID no corresponde a ninguna Notebook.\n\n");
    		return todoOk;
    	}

        cargarDescripcionNotebook(notebooks, tamNot, idNotebook, descNotebook);

        printf("\n           ***   Trabajos de la Notebook %s   ***\n", descNotebook);
        printf("-----------------------------------------------------------------------\n");
        printf("   ID             Notebook           Servicio           Fecha Pactada    \n");
        printf("-----------------------------------------------------------------------\n");


        for(int i = 0; i < tam; i++)
        {
        	if(!vec[i].isEmpty && vec[i].idNotebook == idNotebook)
        	{
        		 mostrarTrabajo(vec[i], notebooks, tamNot, servicios, tamSer);
                flag = 1;
        	}
        }

        if(flag == 0)
        {
        	printf("Esta Notebook no tiene trabajos\n");
        }

        todoOk = 1;

    	printf("\n\n");
    }

	return todoOk;
}
