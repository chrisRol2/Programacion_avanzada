/*
*	File:   Primer parcial  ejercicio 2.c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:	22-09-2020
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 2  primer parcial
*/
#define TAMANOMAXIMO 124
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void insertarCadena(char cadena[TAMANOMAXIMO], char insertar[TAMANOMAXIMO]);
int strlen(char cadena[]);

int main(void) {

	char cadena[TAMANOMAXIMO] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
	printf("Cadena origina: %s\n\n", cadena);
	insertarCadena(cadena, "repo");
	printf("Cadena con elit reemplazado por repo: %s\n", cadena);

	printf("\n"); system("PAUSE");
	return 0;
}
void insertarCadena(char cadena[TAMANOMAXIMO], char insertar[TAMANOMAXIMO]) {
	int i;
	for( i = 51; i < 51 + strlen(insertar); i++ ) {
		cadena[i] = insertar[i - 51];
	}
}
int strlen(char cadena[TAMANOMAXIMO]){ // calculo el largo de la cadena de caracteres
	int length = 0;
	while( cadena[length] != '\0' ) {
		length++;
	}
	return length;
}
