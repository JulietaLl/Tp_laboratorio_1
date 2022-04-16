/*
 * Calculos.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Llorj
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	/**
   * Brief: Realiza descuento del 10% con numero flotante
   */

	float tarjetaDebito(float y)
	{
		float descuento;

		descuento = y - (y * 10.00/100.00);
		return descuento;
	}

	   /**
	   * Brief: Realiza un aumento del 25% del valor en numero flotante.
	   */

	float tarjetaCredito (float y)
	{
		float interes;
		interes = y + (y * 25.00/100.00);
		return interes;
	}

	/**
	 * Brief: Obtiene el valor de Bitcoin de un valor en numero flotante.
	 */

	float precioBitcoins (float y)
	{
		float bitcoins;
		bitcoins = y*1/4606870.62;
		return bitcoins;
	}

		/**
		 * Brief: Obtiene el valor del precio Unitario
		 * Divide precio (Parametro y) por Kilometros (parametro x)
		 */


	float precioPorkm(float y, float x)
	{
		float precioUnitario;
		precioUnitario = y/x;
		return precioUnitario;
	}

		/**
		 * Brief: Obtiene la direrencia entre dos valores flotantes
		 * Resibe dos numeros flotantes como parámetro.
		 */

	float diferencia(float y,float z)
	{
		int diferencia;
		diferencia = y - z;
		return diferencia;
	}

		/**
		 * Brief: Realiza las operaciones correspondientes del CASE 5 del swtich principal.
		 *
		 */

	void evaluateCase5( float* x, float* y, float* z, float* r,float* q){

		float Kms5 = 7090.00;

		 *r = tarjetaDebito(*y);
		 *q = tarjetaDebito(*z);
		 *(r + 1) = tarjetaCredito(*y);
		 *(q + 1) = tarjetaCredito(*z);
		 *(r + 2) = precioBitcoins(*y);
		 *(q + 2) = precioBitcoins(*z);
		 *(r + 3) = precioPorkm(*y,*z);
		 *(q + 3) = precioPorkm(*z,*y);
		 *(r + 4) = diferencia (*y,*z);

		 printf("Kms ingresados : %.2f Kms\n\n"
				 "Aerolineas: \n"
				 "a) Precio con tarjeta de débito : %.2f \n"
				 "b) Precio con tarjeta de credito : %.2f \n"
				 "c) Precio pagando con bitcoin : %f BTC\n"
				 "d) Precio unitario : %.2f\n\n"

				"Latam:\n"
		        "a) Precio con tarjeta de debito : %.2f \n"
		 	    "b) Precio con tarjeta de credito : %.2f \n"
		 	    "c) Precio pagando con bitcoin : %f BTC \n"
		 	    "d) Precio unitario : %.2f\n\n"
		 		"La diferencia de precio es: %.2f \n\n\n",Kms5,*r,*(r + 1),*(r + 2),*(r + 3),*q,*(q + 1),*(q + 2),*(q + 3),*(r + 4));

	}

