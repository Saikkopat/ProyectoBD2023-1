#ifndef _entidadrelacion_
#define _entidadrelacion_

#define TRUE 1
#define FALSE 0

typedef struct nodoLista {
	int dato;
	struct nodoLista* siguiente;
} nodoLista;

typedef nodoLista* LISTA;

LISTA crearLista();
int esVaciaLista(LISTA L);
nodoLista * crearNodoLista();
LISTA insertar(LISTA L, int e);
void mostrarLista(LISTA L);
void  buscarElem(LISTA L, int elem);
LISTA borrar(LISTA L, int elem);
void mensajes(int e, int msg, int p);

// Definición TAD ENTIDAD

typedef struct entidad {
	char nombre[25];
	struct atributo* inicial;
} entidad;

typedef entidad* ENTIDAD;

ENTIDAD crearEntidad(); //Crea una entidad, inicial = NULL hasta crear atributos.
ENTIDAD asignarNombre(ENTIDAD E); //Asigna o modifica nombre de entidad.
ENTIDAD borrarEntidad(ENTIDAD E); //Elimina una entidad, borra atributos asociados y relaciones.
void mostrarAtributos(ENTIDAD E); //Muestra los atributos de la entidad.

// Definición TAD ATRIBUTO

typedef struct atributo {
	char nombre[25];
	int id;
	int tipo;
	struct atributo* siguiente;
} atributo;

typedef atributo* ATRIBUTO;

ATRIBUTO crearAtributo(); //Crea un atributo.
ATRIBUTO insertarAtributo(ENTIDAD E, char nombre[25], int id, int tipo); //Realiza recorrido si ya existe.
ATRIBUTO modificaAtributo(ENTIDAD E, char nombre[25], int id, int tipo); //Actualización de atributo.
ATRIBUTO borraAtributo(ENTIDAD E, char nombre[25]); //Elimina un atributo buscando por nombre.

// Definición TAD RELACIÓN

// Definición TAD ENTRELA (more like FLDSMDFR).

#endif