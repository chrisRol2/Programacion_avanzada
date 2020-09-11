/*
 *	File:   4..c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio:  1.	Hacer una función que permita invertir una secuencia de caracteres. 
 *
 *
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Declaro funciones
void invertir(char cadena[]);
int strlen(char cadena[]);
void strcpy(char destino[], char origen[]);
int main(void) {
	char cadena[200];
	printf("Ingresar cadena: "); scanf("%s", cadena);
	invertir(cadena);
	printf("Invertido: %s", cadena);

	printf("\n"); system("PAUSE");
	return 0;

}

void invertir(char cadena[]) {
    char aux[200];

    for (int i = 0; i < strlen(cadena); i++) {
        aux[strlen(cadena)-1 -i] = cadena[i];
    }
	aux[strlen(cadena)] = '\0';
    strcpy(cadena, aux);

}

int strlen(char cadena[]){
	int length = 0;
	while( cadena[length] != '\0' ) {
		length++;
	}
	return length;
}

void strcpy(char destino[], char origen[]) {

	for( int i = 0; i < strlen(origen); i++ ) {
		destino[i] = origen[i];
	}
	destino[strlen(origen)] = '\0';

}


