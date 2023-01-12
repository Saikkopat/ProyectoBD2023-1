#include <stdio.h>
#include <stdlib.h>

#include "entidadrelacion.h"

void errores(int msg);
/*
	0: Sin memoria disponible para creación de elemento.
	1: Apuntador vacío.
*/

// Operaciones TAD ENTIDAD

ENTIDAD crearEntidad() {
	ENTIDAD E;
	E = (entidad *)malloc(sizeof(entidad));
	if (esEntidadVacia(E) == TRUE) {
		errores(0);
		exit(0);
	}
	E -> inicial = NULL;
	return E;
}

ENTIDAD asignarNombre(ENTIDAD E, char *nom) {
	if (esEntidadVacia(E) == TRUE) {
		errores(2);
		exit(0);
	}
	E -> nombre = nom;
	return E;
}

int esEntidadVacia(ENTIDAD E) {
	if (E == NULL)
		return TRUE;
	else
		return FALSE;
}

// Operaciones TAD ATRIBUTO

ATRIBUTO crearAtributo() {
	ATRIBUTO A;
	A = (atributo*)malloc(sizeof(atributo));
	if (esAtributoVacio(A) == TRUE) {
		errores(1);
		exit(0);
	}
	return A;
}

ENTIDAD insertarAtributo(ENTIDAD E, char *nom, int idf, int tipof) {
	if (esEntidadVacia(E) == TRUE) {
		errores(2);
		exit(0);
	}
	ATRIBUTO At = crearAtributo();
	At -> nombre = nom;
	At -> id = idf;
	At -> tipo = tipof;
	if (esAtributoVacio(E -> inicial) == TRUE) {
		At -> siguiente = NULL;
		E -> inicial = At;
	} else {
		ATRIBUTO actual, anterior;
		actual = E -> inicial;
		while (actual != NULL) {
			anterior = actual;
			actual = actual -> siguiente;
		}
		At -> siguiente = NULL;
		anterior -> siguiente = At;
	}
	return E;
}

void muestraAtributos(ENTIDAD E) {
	if(esEntidadVacia(E) == TRUE) {
		errores(2);
		exit(0);
	}
	ATRIBUTO actual;
	actual = E -> inicial;
	while (actual != NULL) {
		impresionAtributos(actual -> nombre, actual -> id, actual -> tipo);
		actual = actual -> siguiente;
	}
}

void impresionAtributos(char *nom, int idf, int tipof) {
	if(idf == TRUE && tipof == 1) {
		printf("   %s, Llave primaria, Atributo Simple.\n", nom);
	} else {
		switch(tipof) {
		case 1:
			printf("   %s, Atributo Simple.\n", nom);
			break;
		case 2:
			printf("   %s, Atributo Compuesto.\n", nom);
			break;
		case 3:
			printf("   %s, Atributo Multivalor.\n", nom);
			break;
		case 4:
			printf("   %s, Atributo Derivado.\n", nom);
			break;
		}
	}
}

int esAtributoVacio(ATRIBUTO A) {
	if (A == NULL)
		return TRUE;
	else
		return FALSE;
}