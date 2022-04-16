/*
 * utn.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Llorj
 */

#ifndef UTN_H_
#define UTN_H_

      /************* VALIDACIONES *****************/

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo,int reintentos);
int myGets (char* cadena, int longitud);
int esFlotante (char* cadena);

     /************ INICIALIZADOR ARRAY*************/

void initArray ( float* firstNumber, int amount );

    /*************** MENÚ/OPCIONES ****************/

void printMenu(float kilometros, float precioLatam, float precioAerolineas);
int evaluate(int opcion, float* x, float* y, float* z, float* r,float* q);
void altaKilometros(float* x);














#endif /* UTN_H_ */
