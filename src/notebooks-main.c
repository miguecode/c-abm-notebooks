#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Menu.h"
#include "Notebook.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Fecha.h"

#define TAM_NOTEBOOKS 10
#define TAM_MARCAS 4
#define TAM_TIPOS 4
#define TAM_SERVICIOS 4
#define TAM_TRABAJOS 10

int main()
{
	setbuf(stdout, NULL);

	char salir = 'n';
	int proximaId = 10000;
	int idTrabajo = 7000;

	eNotebook lista[TAM_NOTEBOOKS];
	eTrabajo listaT[TAM_TRABAJOS];
	eMarca marcas[TAM_MARCAS] = {
			{1000, "Compaq"},
			{1001, "Asus"},
			{1002, "Acer"},
			{1003, "HP"}};
	eTipo tipos[TAM_TIPOS] = {
			{5000, "Gamer"},
			{5001, "Disenio"},
			{5002, "Ultrabook"},
			{5003, "Normalita"}};
	eServicio servicios[TAM_SERVICIOS] = {
			{20000, "Bateria", 2250},
			{20001, "Display", 10300},
			{20002, "Mantenimiento", 4400},
			{20003, "Fuente", 5600}};

	inicializarNotebooks(lista, TAM_NOTEBOOKS);
	inicializarTrabajos(listaT, TAM_TRABAJOS);

	hardcodearNotebooks(lista, TAM_NOTEBOOKS, 5, &proximaId);
	hardcodearTrabajos(listaT, TAM_TRABAJOS, 5, &idTrabajo);

	do
	{
		int opcionElegida = menu();

		switch (opcionElegida)
		{
		case 1:
			altaNotebook(lista, TAM_NOTEBOOKS, &proximaId, marcas, TAM_MARCAS, tipos, TAM_TIPOS);
			break;

		case 2:
			modificarNotebook(lista, TAM_NOTEBOOKS, marcas, TAM_MARCAS, tipos, TAM_TIPOS);
			break;

		case 3:
			bajaNotebook(lista, TAM_NOTEBOOKS, marcas, TAM_MARCAS, tipos, TAM_TIPOS);
			break;

		case 4:
			listarNotebooks(lista, TAM_NOTEBOOKS, marcas, TAM_MARCAS, tipos, TAM_TIPOS);
			break;

		case 5:
			listarMarcas(marcas, TAM_MARCAS);
			break;

		case 6:
			listarTipos(tipos, TAM_TIPOS);
			break;

		case 7:
			listarServicios(servicios, TAM_SERVICIOS);
			break;

		case 8:
			altaTrabajo(listaT, TAM_TRABAJOS, &idTrabajo, lista, TAM_NOTEBOOKS, marcas, TAM_MARCAS, tipos, TAM_TIPOS, servicios, TAM_SERVICIOS);
			break;

		case 9:
			listarTrabajos(listaT, TAM_TRABAJOS, lista, TAM_NOTEBOOKS, servicios, TAM_SERVICIOS);
			break;

		case 10:
			informarNotebooksTipo(lista, TAM_NOTEBOOKS, tipos, TAM_TIPOS, marcas, TAM_MARCAS);
			break;

		case 11:
			informarNotebooksMarca(lista, TAM_NOTEBOOKS, marcas, TAM_MARCAS, tipos, TAM_TIPOS);
			break;

		case 12:
			informarNotebookMenorPrecio(lista, TAM_NOTEBOOKS, marcas, TAM_MARCAS, tipos, TAM_TIPOS);
			break;

		case 13:
			informarNotebooksXMarca(lista, TAM_NOTEBOOKS, marcas, TAM_MARCAS, tipos, TAM_TIPOS);
			break;

		case 14:
			informarCantidadNotMarcaYTipo(lista, TAM_NOTEBOOKS, marcas, TAM_MARCAS, tipos, TAM_TIPOS);
			break;

		case 15:
			informarMarcaMayorNotebooks(lista, TAM_NOTEBOOKS, marcas, TAM_MARCAS);
			break;

		case 16:
			informarTrabajosNotebook(listaT, TAM_TRABAJOS, lista, TAM_NOTEBOOKS, marcas, TAM_MARCAS, tipos, TAM_TIPOS, servicios, TAM_SERVICIOS);
			break;

		case 0:
			confirmarSalidaMenu(&salir);
			break;

		default:
			printf("Opcion invalida. Debe ingresar una opcion del 1 al 16\n");
			break;
		}
		system("pause");
		system("cls");
	} while (salir != 's');

	printf("¡Gracias por usar ABM Notebooks!");

	return 0;
}