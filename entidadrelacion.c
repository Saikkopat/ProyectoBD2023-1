#include <stdio.h>
#include <stdlib.h>

#include "entidadrelacion.h"

void errores(int msg);
/*
	0: Sin memoria disponible para creación de elemento.
	1: Apuntador vacío.
*/

// Operaciones del TAD ENTRLA

NODOENTIDAD crearNodoEntidad() {
	NODOENTIDAD nuevo;
	nuevo = (nodoEntidad*)malloc(sizeof(nodoEntidad));
	if(nuevo == NULL) {
		errores(0);
		exit(0);
	}
	nuevo -> nodo = NULL;
	nuevo -> siguiente = NULL;
	return nuevo;
}

NODORELACION crearNodoRelacion() {
	NODORELACION nuevo;
	nuevo = (nodoRelacion*)malloc(sizeof(nodoRelacion));
	if(nuevo == NULL) {
		errores(0);
		exit(0);
	}
	nuevo -> nodo = NULL;
	nuevo -> siguiente = NULL;
	return nuevo;
}

ENTRELA crearModelo(char* nom) {
	ENTRELA ER;
	ER = (entrela*)malloc(sizeof(entrela));
	if(ER == NULL) {
		errores(0);
		exit(0);
	}
	ER -> inicialE = crearNodoEntidad();
	ER -> inicialR = crearNodoRelacion();
	ER -> nombreER = nom;
	return ER;
}

int esERVacio (ENTRELA ER) {
	if (ER == NULL)
		return TRUE;
	else
		return FALSE;
}

ENTRELA enlistarEntidad(ENTRELA ER, ENTIDAD E) {
	if(esERVacio(ER) == TRUE) {
		errores(3);
		exit(0);
	}
	NODOENTIDAD nodoAEnlistar;
	nodoAEnlistar = crearNodoEntidad();
	if (esEntidadVacia(ER -> inicialE -> nodo) == TRUE) {
		ER -> inicialE -> nodo = E;
		ER -> inicialE -> siguiente = NULL;
	} else {
		NODOENTIDAD actual, anterior;
		actual = ER -> inicialE;
		while (actual != NULL) {
			anterior = actual;
			actual = actual -> siguiente;
		}
		nodoAEnlistar -> siguiente = NULL;
		anterior -> siguiente = nodoAEnlistar;
	}
	return ER;
}

ENTRELA enlistarRelacion(ENTRELA ER, RELACION R) {
	if(esERVacio(ER) == TRUE) {
		errores(3);
		exit(0);
	}
	NODORELACION nodoAEnlistar;
	nodoAEnlistar = crearNodoRelacion();
	if (esRelacionVacia(ER -> inicialR -> nodo) == TRUE) {
		ER -> inicialR -> nodo = R;
		ER -> inicialR -> siguiente = NULL;
	} else {
		nodoRelacion *actual, *anterior;
		actual = ER -> inicialR;
		while (actual != NULL) {
			anterior = actual;
			actual = actual -> siguiente;
		}
		nodoAEnlistar -> siguiente = NULL;
		anterior -> siguiente = nodoAEnlistar;
	}
	return ER;
}

void listaEntidades(ENTRELA ER) {
	if(esERVacio(ER) == TRUE) {
		errores(3);
		exit(0);
	}
	NODOENTIDAD actual;
	actual = ER -> inicialE;
	while (actual != NULL) {
		mostrarEntidad(actual -> nodo);
		muestraAtributos(actual -> nodo);
		actual = actual -> siguiente;
	}
}

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

ENTIDAD asignarEntidad(ENTIDAD E, char *nom, int tipo) {
	if (esEntidadVacia(E) == TRUE) {
		errores(3);
		exit(0);
	}
	E -> nombre = nom;
	E -> tipoe = tipo;
	return E;
}

int esEntidadVacia(ENTIDAD E) {
	if (E == NULL)
		return TRUE;
	else
		return FALSE;
}

void mostrarEntidad(ENTIDAD E) {
	if (esEntidadVacia(E) == TRUE) {
		errores(3);
		exit(0);
	}
	printf("\n  %s, %d", E -> nombre, E -> tipoe);
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
		errores(3);
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
		errores(3);
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

// Operaciones del TAD RELACIÓN

RELACION crearRelacion() {
	RELACION R;
	R = (relacion *)malloc(sizeof(relacion));
	if (esRelacionVacia(R) == TRUE) {
		errores(2);
		exit(0);
	}
	R -> inicial = NULL;
	R -> entidad1 = NULL;
	R -> entidad2 = NULL;
	return R;
}

RELACION asignaRelacion(RELACION R, ENTIDAD E1, ENTIDAD E2, char* nom, int cardf1, int cardf2, int tipof) {
	if (esRelacionVacia(R) == TRUE) {
		errores(3);
		exit(0);
	}
	R -> nombre = nom;
	R -> entidad1 = E1;
	R -> entidad2 = E2;
	R -> card1 = cardf1;
	R -> card2 = cardf2;
	R -> tipo = tipof;
	return R;
}

void imprimeRelacion(RELACION R) {
	if (esRelacionVacia(R) == TRUE) {
		errores(3);
		exit(0);
	}
	printf("\n %s:", R -> nombre);
	mostrarEntidad(R -> entidad1);
	printf("\n   %d,%d", R -> card1, R -> card2);
	mostrarEntidad(R -> entidad1);
	printf("\n");
}

int esRelacionVacia(RELACION R) {
	if (R == NULL)
		return TRUE;
	else
		return FALSE;
}

RELACION borraRelacion(RELACION R) {

}