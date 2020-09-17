/*
*	File:   ppiEj2.c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 
*/
#define TAMANOMAXIMO 50
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void reemplazar(char cadena[TAMANOMAXIMO], char insertar[TAMANOMAXIMO]);
int strlen(char cadena[]);

int main(void) {

	char cadena[TAMANOMAXIMO] = "Para los proximos 12 meses,no hay vacantes";
	reemplazar(cadena, "si");
	printf("%s", cadena);

	printf("\n"); system("PAUSE");
	return 0;
}
void reemplazar(char cadena[TAMANOMAXIMO], char insertar[TAMANOMAXIMO]) {
	int i;
	for( i = 27; i < 27 + strlen(insertar); i++ ) {
		cadena[i] = insertar[i - 27];
	}
}
int strlen(char cadena[]){ // calculo el largo de la cadena de caracteres
	int length = 0;
	while( cadena[length] != '\0' ) {
		length++;
	}
	return length;
}
