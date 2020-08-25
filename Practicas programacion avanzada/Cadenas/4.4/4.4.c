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
#include <string.h>
 // Declaro funciones
void cambio(char cadena[]);
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