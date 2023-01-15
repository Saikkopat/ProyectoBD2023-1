#ifndef _entidadrelacion_
#define _entidadrelacion_

#define TRUE 1
#define FALSE 0

// Definición TAD ENTIDAD

typedef struct entidad {
	char *nombre;
	struct atributo* inicial;
	int tipoe;
} entidad;

typedef entidad* ENTIDAD;

ENTIDAD crearEntidad(); //Crea una entidad, inicial = NULL hasta crear atributos.
ENTIDAD asignarEntidad(ENTIDAD E, char *nom, int tipo); //Asigna o modifica nombre de entidad.
ENTIDAD borrarEntidad(ENTIDAD E); //Elimina una entidad, borra atributos asociados y relaciones.
void mostrarAtributos(ENTIDAD E); //Muestra los atributos de la entidad.
int esEntidadVacia(ENTIDAD E); //Verifica si el apuntador está vacío.
void mostrarEntidad(ENTIDAD E); //Muestra el nombre de la entidad.

// Definición TAD ATRIBUTO

typedef struct atributo {
	char *nombre;
	int id;
	int tipo;
	struct atributo* siguiente;
} atributo;

typedef atributo* ATRIBUTO;

ATRIBUTO crearAtributo(); //Crea un atributo.
ENTIDAD insertarAtributo(ENTIDAD E, char *nom, int idf, int tipof); //Realiza recorrido si ya existe.
ATRIBUTO modificaAtributo(ENTIDAD E, char *nom, int idf, int tipof); //Actualización de atributo.
void muestraAtributos(ENTIDAD E); //Muestra los atributos de una entidad.
ATRIBUTO borraAtributo(ENTIDAD E, char *nom); //Elimina un atributo buscando por nombre.
int esAtributoVacio(ATRIBUTO A); //Verifica si el atributo está vacío.

RELACION RinsertaAtributo(RELACION R, char *nom, int idf, int tipof); //Inserta los atributos para la relacion.
ATRIBUTO RmodificaAtributo(RELACION R, char *nom, int idf, int tipof); //Actualización de atributo para relación.
void RmuestraAtributos(RELACION R); //Muestra los atributos de una relación.
ATRIBUTO RborraAtributo(RELACION R, char *nom); //Elimina un atributo buscando por nombre en una relación.

// Definición TAD RELACIÓN

typedef struct relacion {
	char *nombre;
	struct atributo* inicial;
	struct entidad* entidad1;
	int card1;
	struct entidad* entidad2;
	int card2;
	int tipo;
} relacion;

typedef relacion* RELACION;

RELACION crearRelacion(); //Crea una relación.
RELACION asignaRelacion(RELACION R, ENTIDAD E1, ENTIDAD E2, char* nom, int cardf1, int cardf2, int tipof); // Asigna los datos de una relación.
void imprimeRelacion(RELACION R);
int esRelacionVacia(RELACION R);
RELACION borraRelacion(RELACION R);

// Definición TAD ENTRELA (more like FLDSMDFR).

typedef struct nodoEntidad {
	struct entidad* nodo;
	struct entidad* siguiente;
} nodoEntidad;

typedef nodoEntidad NODOENTIDAD;

typedef struct nodoRelacion {
	struct relacion* nodo;
	struct relacion* siguiente;
} nodoRelacion;

typedef nodoRelacion NODORELACION;


typedef struct entrela {
	char* nombreER;
	struct nodoEntidad* inicialE;
	struct nodoRelacion* inicialR;
} entrela;

typedef entrela* ENTRELA;

ENTRELA crearModelo(char* nom); //Inicializa el modelo asignando el nombre del modelo.
void listaEntidades(ENTRELA ER); //Lista todas las entidades asociadas al modelo.
void listaRelaciones(ENTRELA ER); //Lista todas las relaciones del modelo.
nodoEntidad* crearNodoEntidad(); //Crea un nodo para el listado de entidades.
nodoRelacion* crearNodoRelacion(); //Crea un nodo para el listado de relaciones.
ENTRELA enlistarEntidad(ENTRELA ER, ENTIDAD E); //Enlista la entidad.
ENTRELA enlistarRelacion(ENTRELA ER, RELACION R); //Enlista la relacion.

// Utilidades

void impresionAtributos(char *nom, int idf, int tipof); //Impresión en pantalla de atributos.

#endif