/*
 *	File:   4.2.c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio: 2.	Hacer una función que determine si una secuencia de caracteres es
		    capicúa.

 *
 *
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define true 1
#define false 0

// Declaro funciones
int strlen(char cadena[]);
void strcpy(char destino[], char origen[]);
int capicua(char cadena[]);
int main(void) {
    char cadena[200];
    printf("Ingresar cadena: "); scanf("%s", cadena);
    printf("Cadena: %s\n", cadena);
    if (capicua(cadena) == 1)printf("Es capicua");
    else printf("No es  capicua");
    printf("\n"); system("PAUSE");
    return 0;
}
int capicua(char cadena[]) {
    for (int i = 0; i < strlen(cadena); i++) {
        if (cadena[strlen(cadena) - 1 - i] != cadena[i])return false;
    }
    return true;
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


