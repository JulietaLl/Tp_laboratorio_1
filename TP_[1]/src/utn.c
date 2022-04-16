/*
 * utn.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Llorj
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Calculos.h"

static int getFloat(float* pResultado);


/** \ brief verifica que lo ingresado sea un numero
 * 	\ param *pResultado recibe un puntero
 * 	\ parame char mensaje: se le pide al usuario que ingrese un numero.
 * 	\ parame char mensaje error: avisa que lo ingresado no es valido.
 * 	\ int minimo : Numero minimo que se requiere.
 * 	\ int maximo: Numero máximo que se pide.
 * 	\ int reintentos: Cantidad de reintentos que tiene el usuario.
 */


int utn_getNumero(int* pResultado, char* mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{

	int retorno = -1;
	int bufferInt;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		retorno = -2;

		do
		{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d",&bufferInt);
		if(bufferInt >= minimo && bufferInt <=maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}

		reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * Brief: Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado.
 * Parametro pResultado: Puntero al espacio de memoria donde se dejará el resultado de la función.
 * Parametro mensaje: Es el mensaje a ser mostrado.
 * Parametro mensajeError: Es el mensaje de error a ser mostrado.
 * Parametro minimo: Es el numero minimo a ser aceptado.
 * Parametro máximo: Es el numero máximo a ser aceptado.
 * Return: Retorna 0 si se obtuvo el numero flotante y -1 si no.
 */



int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo,int reintentos)
{

	int retorno = -1;
	float bufferFloat;

	while(reintentos >= 0)
	{
		reintentos--;
		printf("%s", mensaje);

		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

/**
 * Brief: Verifica si la cadena ingresada es flotante.
 * Parametro pResultado: Puntero al espacio de memoria donde se dejará el resultado de la funcion.
 * Return: Retorna 0 [EXITO] si se obtiene un numero flotante y -1 [ERROR] si no.
 */



static int getFloat(float* pResultado)
{
	 int retorno = 1;
	 char buffer [64];

	 if (pResultado != NULL)
	 {
		if(myGets(buffer, sizeof(buffer)) == 0 && esFlotante(buffer))
		 {
			*pResultado = atof (buffer);
			 retorno = 0;

		 }
	 }

	 return retorno;
 }


int myGets (char* cadena, int longitud)
   {

	   int retorno = -1;
	   char bufferString[4096];

	   if(cadena != NULL && longitud > 0)
	   {
		   fflush(stdin);
		   if(fgets(bufferString,sizeof (bufferString), stdin) != NULL)
		{
			   if(bufferString[strnlen(bufferString, sizeof (bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) -1] = '\0';

			}
			   if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}



		}

	}
	return retorno;

   }

/**
 * Brief: Verifica si la cadena ingresada es flotante.
 * Parametro cadena: Cadena de caracteres a ser analizada
 * Return: Retorna 1 (verdadero) si la cadena es float y 0 (falso) si no lo es.
 */

   int esFlotante (char* cadena)
 {
	 int retorno = 1;
	 int i = 0;
	 int contadorPuntos = 0;

	 if (cadena != NULL && strlen(cadena) > 0)
	 {
		 for( i= 0 ; cadena [i] != '\0' ; i++)
		 {
			 if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
	         {
		        continue;
	         }

	           if(cadena [i] > '9' || cadena [i] < '0')
		       {
			   if (cadena [i] == '.' && contadorPuntos == 0)
			   {
				 contadorPuntos++;
			   }
			   else
			   {
				 retorno = 0;
				 break;
			   }
		    }
	      }

     }

	 return retorno;
 }

   /**
    * Brief: Imprime el menu por consola
    * Parametros flotantes: Trabaja con numeros flotantes que estarán inicializadas
    * en 0.
    */


 void printMenu(float kilometros, float precioLatam, float precioAerolineas) {
	printf( "1. Ingresar Kilomentros: (km = %.2f)\n\n"
		    "2. Ingresar Precio de Vuelos: (Aerolineas = %.2f, Latam = %.2f)\n\n"
		    "3. Calcular todos los costos:\n"
			"a) Tarjeta de debito (descuento 10)\n"
			"b) Tarjeta de credito (interes 25)\n"
			"c) Bitcoin (1 BTC -> 4606954.55 Pesos Argentinos)\n"
			"d) Mostrar precio por km (precio Unitario)\n"
			"e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n\n"
			"4. Informar Resultados\n\n"
			"5. Carga forzada de datos\n\n"
			"6. Salir\n\n",kilometros,precioAerolineas,precioLatam);
}

 /**
    * Brief: Recibe numero flotante del usuario y se le asigna el valor a "x"
    * Además verifica si el numero flotante ingresado es correcto, si no es así,
    * sale un mensaje de Error.
    */

 void altaKilometros (float *x) {

	utn_getNumeroFlotante(x,"Ingresa los kilometros deseados:  \n","Error, ingrese un numero con el formato correcto\n",0.01,50000.00,3);

 }

 /**
     * Brief: Evalua las opciones del Menu a través de un switch.
     * verifica si el numero entero ingresado (opcion) es correcto, si no es así,
     * sale un mensaje de Error.
     * Ingresa en cada case y resuelve las operaciones correspondientes con los datos ingresados por el usuario, imprimiendo
     * mensajes en cada caso para poder guiar al usuario.
     */

int evaluate(int opcion, float* x, float* y, float* z, float* r,float* q) {

	float Kms5 = 7090.00;
	float precioAerolineas5 = 162965.00;
	float precioLatam5 = 159339.00;
	float resultadosAerolineas5 [6];
	float resultadosLatam5 [6];

		switch(opcion) {

			case 1:
				altaKilometros(x);
				break;

			case 2:
				utn_getNumeroFlotante(z,"Ingrese precio Aerolineas: ","Error, ingrese un numero con el formato correcto\n\n",0.01,999999999.00,3);
				utn_getNumeroFlotante(y,"Ingrese precio Latam: ","Error, ingrese un numero con el formato correcto\n\n",0.01,999999999.00,3);
				break;
			case 3:
				if (*x == 0.00 || *y == 0.00 || *z == 0.00)
				{
					printf("Error, necesita ingresar valores para Kms y precios \n\n\n");
				}
				else {
				 *r = tarjetaDebito(*y);
				 *q = tarjetaDebito(*z);
				 *(r + 1) = tarjetaCredito(*y);
				 *(q + 1) = tarjetaCredito(*z);
				 *(r + 2) = precioBitcoins(*y);
				 *(q + 2) = precioBitcoins(*z);
				 *(r + 3) = precioPorkm(*y,*z);
				 *(q + 3) = precioPorkm(*z,*y);
				 *(r + 4) = diferencia (*y,*z);
				printf("¡Los calculos se han realizado con exito! \n");

				}



				 break;

			case 4:
					if(*r == 0.00 || *q == 0.00){

					printf ("Error, asegurese de haber realizado con exito los siguientes pasos : \n\n"
							"1) Cargado valores para poder realizar las operaciones en punto 1 y 2 \n"
							"2) Haber ingresado al punto 3 para que se realizen los calculos.\n\n");

					}
					else{

						printf("Latam:\n"
						"a) Precio con tarjeta de debito : $ %.2f \n"
						"b) Precio con tarjeta de credito : $ %.2f \n"
						"c) Precio pagando con bitcoin : %f BTC\n"
						"d) Precio unitario : $  %.2f\n"
						"Aerolineas: \n"
				        "a) Precio con tarjeta de débito : $ %.2f \n"
						"b) Precio con tarjeta de credito : $ %.2f \n"
						"c) Precio pagando con bitcoin : %f BTC\n"
					    "d) Precio unitario : $ %.2f\n"
						"La diferencia de precio es: $ %.2f \n\n\n",*r,*(r + 1),*(r + 2),*(r + 3),*q,*(q + 1),*(q + 2),*(q + 3),*(r + 4));
					 }
					break;

			case 5:
				evaluateCase5(&Kms5,&precioAerolineas5 ,&precioLatam5,resultadosAerolineas5,resultadosLatam5);
				fflush(stdin);


				break;
			case 6:
				printf("Gracias, vuelva pronto! Besitos, chau chau");
				break;

			default:
			break;

		}

		return opcion !=6;
}


/**
   * Brief: Inicializa un array.
   * Parametro fistNumber: Ingresa la primera posicion del array
   * Parametro amount: Ingresa el espacio del array.
   */

void initArray ( float* firstNumber, int amount ) {

	for (int i = 0; i < amount; i++) {

		*(firstNumber+i) = 0.00;

	}

}





