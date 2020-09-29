/*
*	File:   5..c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 3.	Desarrollar las siguientes funciones para manejar “fechas”:
    a)	Ingresar una fecha (día, mes, año) desde teclado, validando que corresponda a una fecha gregoriana.
    b)	Indicar cual de dos fechas es la mayor.
    c)	Sumar n días a una fecha
    d)	Generar una cadena con formato dd/mm/aaaa

	ñ -> \xA4
	° -> \xF8
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define true 1
#define false 0
// Declaro estructuras
typedef struct {
	int dia;
	int mes;
	int anio;
	char cadena[10];
}fechas;
// Declaro funciones

int fecha_gregoriana(fechas fecha);
int bisiesto(int year);
void ingresarDato(int *dato, int min, int max);
fechas ingresarFecha();
int main(void) {
	fechas fecha1;
	fechas fecha2;
	int nDias;

	printf("\tIngrese 1\xF8 Fecha:\n");
	fecha1 = ingresarFecha();
	printf("\tIngrese 2\xF8 Fecha:\n");
	fecha2 = ingresarFecha();

	printf("\n"); system("PAUSE");
	return 0;
}
int fecha_gregoriana(fechas fecha) {

	volatile int mes_dia[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if( bisiesto(fecha.anio) )mes_dia[1] = 29; //Corroboro si es bisiesto
	if( fecha.dia <= fecha.mes[mes_dia - 1] ) { // contolo que el dia exista en el calendario
		return true;
	}
	if( fecha.mes <= 12 )return false;
	return false;
}

int bisiesto(int year) {

	if (year % 4 == 0) {
		if ((year % 100 == 0) && (year % 400)) {
			return false;
		}
		return true;
	}
	return false;
}
void ingresarDato(int *dato, int min, int max) {

	do {
		scanf("%d", dato);
		if( (*dato > max) || (*dato < min) )printf("\nDato fuera de rango.\n");
	} while( (*dato > max) || (*dato < min) );

}
fechas ingresarFecha() {
	fechas fecha1;
	do {
		printf("Ingrese a\xA4o: ");
		ingresarDato(&fecha1.anio, -2020, 3000);
		printf("Ingrese mes: ");
		ingresarDato(&fecha1.mes, 1, 12);
		printf("Ingrese dia: ");
		ingresarDato(&fecha1.dia, 1, 31);
		if( !fecha_gregoriana(fecha1) ) {
			printf("\tFecha no gregoriana. Vuelva a intentarlo.\n");
		}
	} while( !fecha_gregoriana(fecha1) );
	return fecha1;
}