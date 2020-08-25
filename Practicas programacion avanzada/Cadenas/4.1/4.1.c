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
#include <string.h>
// Declaro funciones
void invertir(char cadena[]);
int main(void) {
        char cadena[200];
        printf("Ingresar cadena: "); scanf("%s", cadena);
    invertir(cadena);
    printf("Invertido O: %s", cadena);

    printf("\n"); system("PAUSE");
    return 0;

}

void invertir(char cadena[]) {
    char aux[200];

    strcpy(aux, cadena);
    for (int i = 0; i < strlen(cadena); i++) {
        aux[strlen(cadena)-1 -i] = cadena[i];
    }
    strcpy(cadena, aux);
    printf("Invertido: %s\n", aux);

}