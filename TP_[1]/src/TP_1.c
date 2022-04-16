/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);

	int opcion;
	float kilometros = 0.00;
	float precioLatam = 0.00;
	float precioAerolineas = 0.00;
	float resultadosPreciosLatam[6];
	float resultadosPreciosAerolineas[6];

	initArray(resultadosPreciosLatam, 6);
	initArray(resultadosPreciosAerolineas, 6);

	do {

		printMenu(kilometros,precioLatam,precioAerolineas);
		utn_getNumero(&opcion,"Ingrese una opcion, por favor :   ", "Error, Ingrese una opcion correcta\n",1,6,5);

	} while ( evaluate(opcion, &kilometros, &precioLatam, &precioAerolineas, resultadosPreciosLatam, resultadosPreciosAerolineas) );


	return EXIT_SUCCESS;
}
