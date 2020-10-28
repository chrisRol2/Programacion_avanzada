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
*	Ejercicio: 3.	Desarrollar las siguientes funciones para manejar �fechas�:
    a)	Ingresar una fecha (d�a, mes, a�o) desde teclado, validando que corresponda a una fecha gregoriana.
    b)	Indicar cual de dos fechas es la mayor.
 //   c)	Sumar n d�as a una fecha
    d)	Generar una cadena con formato dd/mm/aaaa

	� -> \xA4
	� -> \xF8
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define true 1
#define false 0
// Declaro estructuras
typedef struct {
	int dia;
	int mes;
	int anio;
	char cadena[11];
}fechas;
// Declaro funciones

int fecha_gregoriana(fechas fecha);
int bisiesto(int year);
void ingresarDato(int *dato, int min, int max);
fechas ingresarFecha();
int mayor(fechas fecha1, fechas fecha2);
void aCadena(fechas *fecha);
int main(void) {
	fechas fecha1;
	fechas fecha2;
	int nDias;
	
	printf("\tIngrese 1\xF8 Fecha:\n");
	fecha1 = ingresarFecha();
	printf("\tIngrese 2\xF8 Fecha:\n");
	fecha2 = ingresarFecha();
	aCadena(&fecha1);
	aCadena(&fecha2);
	//printf("La %d\xF8 fecha es la mayor", mayor(fecha1, fecha2));
	switch( mayor(fecha1, fecha2) ) {
		case 0:
			printf("Las fechas son iguales: %s", fecha1.cadena);
			break;
		case 1:
			printf("%s es la fecha mayor", fecha1.cadena);
			break;
		case 2:
			printf("%s es la fecha mayor", fecha2.cadena);
			break;
		default:
			printf("Error al introducir fechas");
			break;
	}



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
int mayor(fechas fecha1, fechas fecha2) {
	
	if( (fecha1.anio > fecha2.anio) )return 1;
	else if( (fecha1.anio < fecha2.anio) ) return 2;
	else if( fecha1.mes > fecha2.mes ) return 1;
	else if( fecha1.mes < fecha2.mes ) return 2;
	else if( fecha1.dia > fecha2.dia ) return 1;
	else if( fecha1.dia < fecha2.dia ) return 2;
	else return 0;
	return -1;
}
void aCadena(fechas *fecha) { //   dd/mm/aaaa
	char aux[10];
	char aux1[10];
	char aux2[10];
	
	if( fecha->dia < 10 ) sprintf(aux, "0%d",fecha->dia);
	else sprintf(aux, "%d/",fecha->dia);
	if( fecha->mes < 10 ) sprintf(aux1, "0%d", fecha->mes);
	else sprintf(aux1, "%d/",fecha->mes);
	if( fecha->mes < 10 )        sprintf(aux2, "000%d", fecha->mes);
	else if( fecha->mes < 100 )  sprintf(aux2, "00%d", fecha->mes);
	else if( fecha->mes < 1000 ) sprintf(aux2, "0%d", fecha->mes);

	sprintf(fecha->cadena, "%s/%s/%s", aux,aux1,aux2);
}