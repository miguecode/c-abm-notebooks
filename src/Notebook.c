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

  if (marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
  {
    cargarDescripcionMarca(marcas, tamMar, lista.idMarca, descMarca);
    cargarDescripcionTipo(tipos, tamTip, lista.idTipo, descTipo);

    printf("  %4d  %15s  %10s    %10s      $%9.2f\n",
           lista.id, lista.modelo, descMarca, descTipo, lista.precio);

    todoOk = 1;
  }
  return todoOk;
}

int listarNotebooks(eNotebook vec[], int tamNot, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
  int todoOk = 0;
  int flag = 0;
  if (vec != NULL && marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
  {
    printf("\n          *** Listado de Notebooks ***\n\n");
    printf("   ID             Modelo       Marca          Tipo        Precio\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < tamNot; i++)
    {
      if (!vec[i].isEmpty)
      {
        mostrarNotebook(vec[i], marcas, tamMar, tipos, tamTip);
        flag++;
      }
    }
    if (flag == 0)
    {
      printf("             No hay notebooks en el sistema");
    }
    printf("\n\n");

    todoOk = 1;
  }
  return todoOk;
}

int inicializarNotebooks(eNotebook vec[], int tam)
{
  int todoOk = 0;
  if (vec != NULL && tam > 0)
  {
    for (int i = 0; i < tam; i++)
    {
      vec[i].isEmpty = 1;
    }
    todoOk = 1;
  }
  return todoOk;
}

int buscarNotebookLibre(eNotebook vec[], int tam, int *pIndex)
{
  int todoOk = 0;
  if (vec != NULL && tam > 0 && pIndex != NULL)
  {
    *pIndex = -1;
    for (int i = 0; i < tam; i++)
    {
      if (vec[i].isEmpty == 1)
      {
        *pIndex = i;
        break;
      }
    }
    todoOk = 1;
  }
  return todoOk;
}

int altaNotebook(eNotebook vec[], int tam, int *pId, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
  int todoOk = 0;
  int indice;
  char auxCad[100];
  eNotebook nuevaNotebook;
  int validPrecio = 0;

  if (vec != NULL && tam > 0 && pId != NULL && marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
  {
    if (buscarNotebookLibre(vec, tam, &indice))
    {
      if (indice == -1)
      {
        printf("No hay lugar en el sistema\n");
      }
      else
      {
        printf("[>] Ingrese el modelo de la Notebook: ");
        fflush(stdin);
        gets(auxCad);
        validarCodigo(auxCad);
        strcpy(nuevaNotebook.modelo, auxCad);

        listarMarcas(marcas, tamMar);
        printf("[>] Ingrese la ID de la marca a la que pertenece: ");
        scanf("%d", &nuevaNotebook.idMarca);
        while (!validarMarca(marcas, tamMar, nuevaNotebook.idMarca))
        {
          printf("[>] Error, esa ID no corresponde a ninguna marca. Reingrese ID: ");
          fflush(stdin);
          scanf("%d", &nuevaNotebook.idMarca);
        }

        listarTipos(tipos, tamTip);
        printf("[>] Ingrese la ID del tipo al que pertenece: ");
        scanf("%d", &nuevaNotebook.idTipo);
        while (!validarTipo(tipos, tamTip, nuevaNotebook.idTipo))
        {
          printf("[>] Error, esa ID no corresponde a ningun tipo. Reingrese ID: ");
          fflush(stdin);
          scanf("%d", &nuevaNotebook.idTipo);
        }

        printf("[>] Ingrese precio: ");
        validPrecio = scanf("%f", &nuevaNotebook.precio);
        validarFloat(validPrecio, &nuevaNotebook.precio);

        nuevaNotebook.isEmpty = 0;
        nuevaNotebook.id = *pId;
        *pId = *pId + 1;
        vec[indice] = nuevaNotebook;
        todoOk = 1;

        printf("\nNotebook agregada correctamente\n");
      }
    }
    else
    {
      printf("Ocurrio un problema con los parametros\n");
    }
  }
  return todoOk;
}

int buscarNotebook(eNotebook vec[], int tam, int id, int *pIndice)
{
  int todoOk = 0;
  if (vec != NULL && tam > 0 && id > 0 && pIndice != NULL)
  {
    *pIndice = -1;
    for (int i = 0; i < tam; i++)
    {
      if (vec[i].isEmpty == 0 && vec[i].id == id)
      {
        *pIndice = i;
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
  if (vec != NULL && tam > 0 && marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
  {
    listarNotebooks(vec, tam, marcas, tamMar, tipos, tamTip);
    printf("[>] Ingrese ID: ");
    scanf("%d", &id);

    if (buscarNotebook(vec, tam, id, &indice))
    {
      if (indice == -1)
      {
        printf("No hay una Notebook con la ID %d\n", id);
      }
      else
      {
        mostrarNotebook(vec[indice], marcas, tamMar, tipos, tamTip);
        printf("[>] Si desea hacer la baja, ingrese 's': ");
        fflush(stdin);
        scanf("%c", &confirma);
        if (confirma != 'S' && confirma != 's')
        {
          printf("Baja cancelada por el usuario\n");
        }
        else
        {
          vec[indice].isEmpty = 1;
          printf("Baja realizada correctamente\n");
          todoOk = 1;
        }
      }
    }
    else
    {
      printf("Ocurrio un problema al buscar la Notebook\n");
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

  if (vec != NULL && tam > 0 && marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
  {
    listarNotebooks(vec, tam, marcas, tamMar, tipos, tamTip);
    printf("[>] Ingrese ID: ");
    scanf("%d", &id);

    if (buscarNotebook(vec, tam, id, &indice))
    {
      if (indice == -1)
      {
        printf("No hay una notebook con la ID %d\n", id);
      }
      else
      {
        printf("  Notebook seleccionada: \n");
        mostrarNotebook(vec[indice], marcas, tamMar, tipos, tamTip);
        printf("\n");

        do
        {
          switch (menuModificarNotebook())
          {
          case 1:
            printf("[>] Ingrese precio: ");
            validPrecio = scanf("%f", &vec[indice].precio);
            validarFloat(validPrecio, &vec[indice].precio);

            printf("Precio modificado correctamente\n");
            break;

          case 2:
            listarTipos(tipos, tamTip);

            printf("[>] Ingrese la ID del tipo al que pertenece: ");
            scanf("%d", &vec[indice].idTipo);
            while (!validarTipo(tipos, tamTip, vec[indice].idTipo))
            {
              printf("[>] Error, esa ID no corresponde a ningun tipo. Reingrese ID: ");
              fflush(stdin);
              scanf("%d", &vec[indice].idTipo);
            }

            printf("Tipo modificado correctamente\n");
            break;

          case 3:
            salir = 's';

            break;
          }
          system("pause");

        } while (salir != 's');
      }
    }
    else
    {
      printf("Ocurrio un problema al buscar Notebook\n");
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
  printf("[>] Ingrese opcion: ");
  scanf("%d", &opcion);
  return opcion;
}

int hardcodearNotebooks(eNotebook vec[], int tam, int cant, int *pId)
{
  int todoOk = 0;
  eNotebook hardcodeos[] =
      {
          {0, "Modelo1", 1000, 5003, 20000, 0},
          {0, "Modelo2", 1001, 5002, 25000, 0},
          {0, "Modelo3", 1001, 5000, 35750, 0},
          {0, "Modelo4", 1003, 5001, 40000, 0},
          {0, "Modelo5", 1002, 5003, 15800, 0}};

  if (vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
  {
    for (int i = 0; i < cant; i++)
    {
      vec[i] = hardcodeos[i];
      vec[i].id = *pId;
      *pId = *pId + 1;
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

  if (descripcion != NULL && indice != -1)
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

  if (!(indice == -1))
  {
    esValido = 1;
  }

  return esValido;
}

int informarNotebooksTipo(eNotebook vec[], int tam, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar)
{
  int todoOk = 0;
  int idTipo;
  int flag = 0;
  char descripcion[20];

  if (vec != NULL && tam > 0 && tipos != NULL && tamTip > 0 && marcas != NULL && tamMar > 0)
  {
    listarTipos(tipos, tamTip);
    printf("[>] Ingrese el ID del tipo que quiere ver su lista de Notebooks: ");
    scanf("%d", &idTipo);
    while (!validarTipo(tipos, tamTip, idTipo))
    {
      printf("[>] Error, esa ID no corresponde a ningun tipo. Reingrese ID: ");
      fflush(stdin);
      scanf("%d", &idTipo);
    }

    printf("\n           ***   Lista de Notebooks de un tipo   ***\n");
    printf("-------------------------------------------------------------------\n");
    printf("   ID             Modelo       Marca          Tipo        Precio\n");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < tam; i++)
    {
      if (!vec[i].isEmpty && vec[i].idTipo == idTipo)
      {
        mostrarNotebook(vec[i], marcas, tamMar, tipos, tamTip);
        flag = 1;
      }
    }

    if (flag == 0)
    {
      cargarDescripcionTipo(tipos, tamTip, idTipo, descripcion);
      printf("No hay Notebooks de este tipo\n");
    }

    todoOk = 1;

    printf("\n\n");
  }

  return todoOk;
}

int informarNotebooksMarca(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
  int todoOk = 0;
  int idMarca;
  int flag = 0;
  char descMarca[20];

  if (vec != NULL && tam > 0 && marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
  {
    listarMarcas(marcas, tamMar);
    printf("[>] Ingrese el ID de la marca que quiere ver su lista de Notebooks: ");
    scanf("%d", &idMarca);
    while (!validarMarca(marcas, tamMar, idMarca))
    {
      printf("[>] Error, esa ID no corresponde a ninguna marca. Reingrese ID: ");
      fflush(stdin);
      scanf("%d", &idMarca);
    }

    cargarDescripcionMarca(marcas, tamMar, idMarca, descMarca);

    printf("\n           ***   Lista de Notebooks marca %s   ***\n", descMarca);
    printf("-------------------------------------------------------------------\n");
    printf("   ID             Modelo       Marca          Tipo        Precio\n");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < tam; i++)
    {
      if (!vec[i].isEmpty && vec[i].idMarca == idMarca)
      {
        mostrarNotebook(vec[i], marcas, tamMar, tipos, tamTip);
        flag = 1;
      }
    }

    if (flag == 0)
    {
      printf("No hay Notebooks de esta marca\n");
    }

    todoOk = 1;

    printf("\n\n");
  }

  return todoOk;
}

int informarNotebookMenorPrecio(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
  int todoOk = 0;

  if (vec != NULL && tam > 0 && marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
  {
    printf("\n         ***   La/s Notebook/s mas barata/s  ***\n");
    printf("-------------------------------------------------------------------\n");
    printf("   ID             Modelo       Marca          Tipo        Precio\n");
    printf("-------------------------------------------------------------------\n");

    float menorPrecio;
    int flag = 0;

    for (int i = 0; i < tam; i++)
    {
      if ((!vec[i].isEmpty) && (vec[i].precio < menorPrecio || flag == 0))
      {
        menorPrecio = vec[i].precio;
        flag = 1;
      }
    }

    if (flag == 0)
    {
      printf("No hay Notebooks en el sistema\n");
    }
    else
    {
      for (int i = 0; i < tam; i++)
      {
        if (!vec[i].isEmpty && vec[i].precio == menorPrecio)
        {
          mostrarNotebook(vec[i], marcas, tamMar, tipos, tamTip);
        }
      }
    }
    printf("\n\n");

    todoOk = 1;
  }

  return todoOk;
}

int informarNotebooksXMarca(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
  int todoOk = 0;

  if (vec != NULL && tam > 0 && marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
  {
    printf("\n");
    for (int s = 0; s < tamMar; s++)
    {
      printf("-------------------------------------------------------------------\n");
      printf("                    ***   %s   ***\n", marcas[s].descripcion);
      printf("-------------------------------------------------------------------\n");
      printf("   ID             Modelo       Marca          Tipo        Precio\n");
      printf("-------------------------------------------------------------------\n");

      int flag = 0;

      for (int e = 0; e < tam; e++)
      {
        if (!vec[e].isEmpty && vec[e].idMarca == marcas[s].id)
        {

          mostrarNotebook(vec[e], marcas, tamMar, tipos, tamTip);
          flag = 1;
        }
      }

      if (flag == 0)
      {
        printf("No hay Notebooks de esta marca\n");
      }

      printf("\n\n");
    }

    todoOk = 1;
  }

  return todoOk;
}

int informarCantidadNotMarcaYTipo(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
  int todoOk = 0;
  int idMarca;
  int idTipo;
  char descMarca[20];
  char descTipo[20];
  int contador = 0;

  if (vec != NULL && tam > 0 && marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
  {
    listarMarcas(marcas, tamMar);
    printf("[>] Ingrese el ID de la marca: ");
    scanf("%d", &idMarca);
    while (!validarMarca(marcas, tamMar, idMarca))
    {
      printf("[>] Error, esa ID no corresponde a ninguna marca. Reingrese ID: ");
      fflush(stdin);
      scanf("%d", &idMarca);
    }

    listarTipos(tipos, tamTip);
    printf("[>] Ingrese el ID del tipo: ");
    scanf("%d", &idTipo);
    while (!validarTipo(tipos, tamTip, idTipo))
    {
      printf("[>] Error, esa ID no corresponde a ningun tipo. Reingrese ID: ");
      fflush(stdin);
      scanf("%d", &idTipo);
    }

    cargarDescripcionMarca(marcas, tamMar, idMarca, descMarca);
    cargarDescripcionTipo(tipos, tamTip, idTipo, descTipo);

    printf("\n-------------------------------------------------------\n");
    printf("***   Marca: %s   Tipo: %s   ***\n", descMarca, descTipo);
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < tam; i++)
    {
      if (!vec[i].isEmpty && vec[i].idMarca == idMarca && vec[i].idTipo == idTipo)
      {
        contador++;
      }
    }

    if (contador == 0)
    {
      printf("No hay Notebooks que sean de esta marca y de este tipo\n");
    }
    else
    {
      printf("Cantidad de Notebooks: %d\n", contador);
    }

    printf("\n\n");

    todoOk = 1;
  }

  return todoOk;
}

int informarMarcaMayorNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamMar)
{
  int todoOk = 0;
  float contadores[tamMar];
  int mayorCantidad = 0;
  int flag = 0;

  if (vec != NULL && tam > 0 && marcas != NULL && tamMar > 0)
  {
    printf("\n   *** Marca o marcas que mas se repiten ***\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < tamMar; i++)
    {
      contadores[i] = 0;
    }

    for (int m = 0; m < tamMar; m++)
    {
      for (int n = 0; n < tam; n++)
      {
        if (!vec[n].isEmpty && vec[n].idMarca == marcas[m].id)
        {
          contadores[m] = contadores[m] + 1;
        }
      }
    }

    for (int m = 0; m < tamMar; m++)
    {
      if (flag == 0 || contadores[m] > mayorCantidad)
      {
        mayorCantidad = contadores[m];
        flag = 1;
      }
    }

    if (flag == 1)
    {
      for (int m = 0; m < tamMar; m++)
      {
        if (contadores[m] == mayorCantidad)
        {
          printf("- %s\n", marcas[m].descripcion);
        }
      }
      printf("\nCantidad de Notebooks: %d\n", mayorCantidad);
    }
    else
    {
      printf("No hay Notebooks en el sistema\n");
    }
    printf("\n\n");

    todoOk = 1;
  }

  return todoOk;
}
