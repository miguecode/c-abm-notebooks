#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Menu.h"

int menu()
{
  int todoOk = 0;
  int opcion;

  printf("|=====================================================|\n");
  printf("|         *****  ABM NOTEBOOKS - MENU  *****          |\n");
  printf("|=====================================================|\n");
  printf("|                  Seccion Principal                  |\n");
  printf("|=====================================================|\n");
  printf("|  1  | ALTA NOTEBOOK                                 |\n");
  printf("|  2  | MODIFICAR NOTEBOOK                            |\n");
  printf("|  3  | BAJA NOTEBOOK                                 |\n");
  printf("|  4  | LISTAR NOTEBOOKS                              |\n");
  printf("|  5  | LISTAR MARCAS                                 |\n");
  printf("|  6  | LISTAR TIPOS                                  |\n");
  printf("|  7  | LISTAR SERVICIOS                              |\n");
  printf("|  8  | ALTA TRABAJO                                  |\n");
  printf("|  9  | LISTAR TRABAJOS                               |\n");
  printf("|=====================================================|\n");
  printf("|                  Seccion de Informes                |\n");
  printf("|=====================================================|\n");
  printf("|  10 | INFO. NOTEBOOKS DE UN TIPO                    |\n");
  printf("|  11 | INFO. NOTEBOOKS DE UNA MARCA                  |\n");
  printf("|  12 | INFO. LA O LAS NOTEBOOKS MAS BARATAS          |\n");
  printf("|  13 | INFO. NOTEBOOKS DE CADA MARCA                 |\n");
  printf("|  14 | INFO. CANTIDAD DE NOTEBOOKS POR MARCA Y TIPO  |\n");
  printf("|  15 | INFO. LA O LAS MARCAS CON MAS NOTEBOOKS       |\n");
  printf("|  16 | INFO. EL O LOS TRABAJOS DE UNA NOTEBOOK       |\n");
  printf("|=====================================================|\n");
  printf("|  0  | SALIR                                         |\n");
  printf("|=====================================================|\n\n");
  printf("[>] Ingrese opcion: ");

  fflush(stdin);
  todoOk = scanf("%d", &opcion);

  if (todoOk)
  {
    return opcion;
  }

  return todoOk;
}

void confirmarSalidaMenu(char *p)
{
  if (p != NULL)
  {
    char confirma;
    printf("\n");
    printf("|=====================================================|\n");
    printf("|                 Salir del programa?                 |\n");
    printf("|=====================================================|\n\n");
    printf("[>] Ingrese 's' o 'n': ");
    fflush(stdin);
    scanf("%c", &confirma);
    confirma = tolower(confirma);

    while (confirma != 's' && confirma != 'n')
    {
      printf("[>] Error, debe responder con 's' o 'n':  \n");
      fflush(stdin);
      scanf("%c", &confirma);
      confirma = tolower(confirma);
    }
    *p = confirma;
  }
}