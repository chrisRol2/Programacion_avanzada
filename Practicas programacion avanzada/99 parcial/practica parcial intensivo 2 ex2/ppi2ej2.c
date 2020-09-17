/*
*	File:   ppi2ej2.c
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
*
*		
*
*/

#define TAMANOMAXIMO 100
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void reemplazar(char cadena[TAMANOMAXIMO], int *inicio, int *fin);
int strlen(char cadena[]);

int main(void) {
	int inicio, final;
	char cadena[TAMANOMAXIMO] = "Mi padre se llama Roberto Alarcon; Su edad es: 49 años.";

	reemplazar(cadena, &inicio,&final);
	printf("Inicio: %d.\nFinal: %d.", inicio, final);

	printf("\n\n"); system("PAUSE");
	return 0;
}
void reemplazar(char cadena[TAMANOMAXIMO], int *inicio,int *fin) {
	int i;
	for( i = 0; i < strlen(cadena); i++ ) {
		if( cadena[i] == ':' )*inicio = i;
		if( cadena[i] == '.' )*fin = i;
	}
}
int strlen(char cadena[]){ // calculo el largo de la cadena de caracteres
	int length = 0;
	while( cadena[length] != '\0' ) {
		length++;
	}
	return length;
}
