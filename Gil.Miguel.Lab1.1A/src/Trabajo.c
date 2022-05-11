/*
 * Trabajo.c
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

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



    printf("  %4d         %10s       %10s             %02d/%02d/%d\n",
    lista.id, descNotebook, descServicio, lista.fPactada.dia, lista.fPactada.mes, lista.fPactada.anio);

        todoOk = 1;
    }
    return todoOk;
}

int listarTrabajos(eTrabajo vec[], eNotebook notebooks[], int tamNot, eServicio servicios[], int tamSer)
{
    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && notebooks != NULL && tamNot > 0 && servicios != NULL && tamSer > 0)
    {
        printf("          *** Listado de Trabajos ***\n\n");
        printf("   ID             Notebook       Servicio       Fecha Pactada    \n");
        printf("-----------------------------------------------------------------\n");
        for(int i=0; i < 5; i++)
        {
        	if(!vec[i].isEmpty)
        	{
                mostrarTrabajo(vec[i], notebooks, tamNot, servicios, tamSer);
                flag++;
        	}
        }
        if(flag == 0)
        {
            printf("     No hay trabajos en el sistema");
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
            }
            else
            {


            	listarNotebooks(notebooks, marcas, tamMar, tipos, tamTip);

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
					printf("Error, esa ID no corresponde a ningún servicio. Reingrese ID: ");
					fflush(stdin);
					scanf("%d", &nuevoTrabajo.idServicio);
				}

      	  	  	printf("Ingrese Fecha Pactada dd/mm/aaaa: ");
      	  	  	fflush(stdin);
                validFecha = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                while(validFecha != 3 || validarFecha(&fecha) != 1)
                {
                	printf("Fecha inválida. Recuerde que debe separar día, mes y año (máx 2030) usando / / / \n");
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
            }
        }
        else
        {
            printf("Ocurrio un problema con los parámetros\n");
        }
    }
    return todoOk;
}




