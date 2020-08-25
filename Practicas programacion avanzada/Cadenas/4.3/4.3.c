/*
 *	File:   4.3.c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio:  3.	Hacer una función que devuelva la cantidad de palabras 
(separados por uno o más espacios) que tiene una frase.

 *
 *
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// Declaro funciones
int contPalabras(char cadena[]);
int main(void) {
    char cadena[200];
    printf("Ingresar cadena: "); scanf("%[^\n]", cadena);
 

    printf("La cadena %s tiene %d palabras", cadena, contPalabras(cadena));

    printf("\n"); system("PAUSE");
    return 0;
}

int contPalabras(char cadena[]) {
    int contador = 0;
    if (cadena[0] == ' ') contador = -1;
    for (int i = 0; i < strlen(cadena); i++) {
        if ((cadena[i] == ' ') && (cadena[i + 1] > 0) &&(cadena[i+1] != ' ')) {
            contador++;
        }
    }
    return (contador == 0 ? contador : contador + 1);
}