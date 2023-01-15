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
	int res, act, idf, tipof, tipoe, idfg;
	printf("\n Ingresa las entidades del modelo Entidad - Relacion:\n");
	do {
		ENTIDAD E1 = crearEntidad();
		printf("\n  Ingresa el nombre para una entidad: ");
		entidad = crearString();
		scanf("%s", entidad);
		printf("\n  ¿Es una entidad fuerte o debil?\n   1. Fuerte\n   2. Debil\n   ");
		asignarEntidad(E1, entidad, tipoe);
		printf("\nIngresa un atributos:");
		act = TRUE;
		idf = FALSE;
		idfg = FALSE;
		do {
			printf("\n  Atributo #%d:\n   Nombre: ", act);
			atributo = crearString();
			scanf("%s", atributo);
			if(idfg == FALSE) {
				printf("   ¿Es llave primaria?\n   1. Sí.\n   2. No\n   ");
				scanf("%d", &idf);
				if (idf == TRUE)
					idfg == TRUE;
			} else idf == FALSE;
			printf("   ¿Qué tipo de atributo es?\n   1. Simple\n   2. Compuesto\n   3. Multivalor\n   4. Derivado\n   ");
			scanf("%d", &tipof);
			E1 = insertarAtributo(E1, atributo, idf, tipof);
			printf("\n  ¿Deseas ingresar otro atributo?\n   1. Sí\n   2. No\n   ");
			scanf("%d", &res);
			act++;
			mostrarEntidad(E1);
			mostrarAtributos(E1);
		} while(res == TRUE);
		printf("\n  ¿Deseas ingresar otra entidad?\n   1. Sí\n   2. No\n   ");
		scanf("%d", &res);
	} while (res == TRUE);
	printf("\n");
	return 0;
}