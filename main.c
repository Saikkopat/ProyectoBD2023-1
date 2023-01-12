#include <stdio.h>
#include <stdlib.h>

#include "entidadrelacion.h"

void errores(int msg) {
	char *mensajes[4] = {"\n   No hay memoria disponible (ENTIDAD).\n",
								"\n   No hay memoria disponible (ATRIBUTO).\n",
								"\n   No hay memoria disponible (RELACION).\n",
								"\n   Elemento vacío.\n"};
	printf("%s", mensajes[msg]);
}

char* crearString () {
	char *texto = (char*)malloc(25);
	return texto;
}

int main () {
	char *entidad, *atributo;
	int res, act, idf, tipof;
	ENTIDAD E1 = crearEntidad();
	printf("\nIngresa el nombre para una entidad: ");
	entidad = crearString();
	scanf("%s", entidad);
	asignarNombre(E1, entidad);
	printf("\nIngresa un atributos:");
	act = 1;
	do {
		printf("\n  Atributo #%d:\n   Nombre: ", act);
		atributo = crearString();
		scanf("%s", atributo);
		printf("   ¿Es llave primaria?\n   1. Sí.\n   2. No\n   ");
		scanf("%d", &idf);
		printf("   ¿Qué tipo de atributo es?\n   1. Simple\n   2. Compuesto\n   3. Multivalor\n   4. Derivado\n   ");
		scanf("%d", &tipof);
		E1 = insertarAtributo(E1, atributo, idf, tipof);
		printf("\n  ¿Deseas ingresar otro atributo?\n   1. Sí\n   2. No\n   ");
		scanf("%d", &res);
		act++;
	} while(res == TRUE);
	printf("\n");
	muestraAtributos(E1);
	printf("\n");
	return 0;
}