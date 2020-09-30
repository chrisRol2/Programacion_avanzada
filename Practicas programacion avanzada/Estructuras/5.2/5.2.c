/*
*	File:   5.2.c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 2.	Desarrollar las siguientes funciones para manejar “tiempos”:
    a)	Ingresar un horario (horas, minutos, segundos) desde teclado, validando que sea correcto
    b)	Calcular la diferencia de horas. En el caso que la primera fecha es mayor a la segunda, 
        considerar que la primera hora corresponde a la hora del día anterior.
        La diferencia en horas no supera las 24 horas.
    c)	Generar una cadena con formato hh:mm:ss
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Declaro estructura
typedef struct {
	int hora;
	int minuto;
	int segundos;
}horas;
// Declaro funciones
void ingresarDato(int *dato, int min, int max);
horas restarTiempos( horas dato_1, horas dato_2);
int main(void) {


	horas tiempos;
	horas tiempos2;
	horas diferencia;
	int *horasP = &tiempos.hora;
	int *horas2P = &tiempos2.hora;
	int *diferenciaP = &diferencia.hora;
	char cadena[9];
	int cont = 0;
	printf("\nIngrese hora: "); ingresarDato(&tiempos.hora, 0, 23);
	printf("\nIngrese minutos: "); ingresarDato(&tiempos.minuto, 0, 59);
	printf("\nIngrese segundos: "); ingresarDato(&tiempos.segundos, 0, 59);

	printf("\n\nSegundo horario posterior\n\nIngrese hora2: ");
	ingresarDato(&tiempos2.hora,tiempos.hora, 23);
	printf("\nIngrese minutos2: ");
	ingresarDato(&tiempos2.minuto, 0, 59);
	printf("\nIngrese segundos2: ");
	ingresarDato(&tiempos2.segundos, 0, 59);
	diferencia = restarTiempos(tiempos, tiempos2);
	/*for( int i = 0; i < 3; i++ ) {
		*(diferenciaP + i) = *(horas2P + i) - *(horasP + i);
	}*/
	printf("\n\n");
	for( int i = 0; i < 8; i++ ) {
		if( i == 2 || i == 5 ) {
			cadena[i] = ':';
			i++;
		}
		if( *(diferenciaP + cont) < 10 ) {
			cadena[i] = '0';
			i++;
			cadena[i] = *(diferenciaP + cont) + 48;
		} 
		else {
			cadena[i] = (*(diferenciaP + cont) / 10 + 48);
			i++;
			cadena[i] = (*(diferenciaP + cont) % 10) + 48;
		}
		cont++;
		
	}
	cadena[8] = '\0';
	printf("diferencia: %s",cadena);
	
    printf("\n"); system("pause");
    return 0;
}
void ingresarDato(int *dato, int min, int max) {

	do {
		scanf("%d", dato);
		if( (*dato > max) || (*dato < min) )printf("\nDato fuera de rango.\n");
	} while( (*dato > max) || (*dato < min) );
	
}

horas restarTiempos(horas dato_1, horas dato_2) {
	int sumaSegundos = 0;
	int sumaSegundos2 = 0;
	int restaSegundos = 0;
	horas diferencia;

	sumaSegundos += ((dato_1.hora * 60) * 60) + (dato_1.minuto * 60) + dato_1.segundos;
	sumaSegundos2 += ((dato_2.hora * 60) * 60) + (dato_2.minuto * 60) + dato_2.segundos;

	restaSegundos = sumaSegundos2 - sumaSegundos;

	
	diferencia.hora = restaSegundos / 3600;
	restaSegundos = restaSegundos % 3600;
	diferencia.minuto = restaSegundos / 60;
	diferencia.segundos = restaSegundos % 60;

	return diferencia;
}