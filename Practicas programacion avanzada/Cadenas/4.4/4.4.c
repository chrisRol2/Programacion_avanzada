/*
 *	File:   4.4.c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio:4.	Hacer una función que permita reemplazar en una secuencia de caracteres 
todos los guiones (-) por el carácter numeral (#).

 *
 *
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // Declaro funciones
void cambio(char cadena[]);
int strlen(char cadena[]);
void strcpy(char destino[], char origen[]);
int main(void) {
    char cadena[200];
    printf("Ingresar cadena: "); scanf("%s", cadena);
    printf("La cadena es: %s", cadena);

    cambio(cadena);
    printf("Ahora la cadena es: %s", cadena);

    printf("\n"); system("PAUSE");
    return 0;
}
void cambio(char cadena[]) {
    for (int i = 0; i < strlen(cadena); i++) {
        if (cadena[i] == '-')cadena[i] = '#';
    }

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


