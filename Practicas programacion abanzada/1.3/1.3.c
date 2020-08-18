/*
 *	File:	1.3.c
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
 *   3.	Realizar una función que reciba el año como parámetro y devuelva verdadero si el año es bisiesto o falso si no lo es. Se recuerda que un año es bisiesto cuando es divisible por 4.
 *       Sin embargo aquellos años que sean divisibles por 4 y también por 100 no son bisiestos, a menos que también sean divisibles por 400. Por ejemplo,
 *       1900 no fue bisiesto pero sí lo fueron el 2000 y 2004.
 *
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
// Declaro funciones
bool  bisiesto(int year);

int main(void) {
    int year = 0;

    printf("Introduzca año: "); scanf("%d", &year);

    if (bisiesto(year))printf("%d es un año bisieto", year);
    else printf("%d no es un año bisieto", year);
 
    printf("\n"); system("PAUSE");    
    return 0;
}

bool  bisiesto(int year) {

    if (year % 4 == 0) {
        if ((year % 100 == 0) && (year % 400)) {
            return false;
        }
        return true;
    }
    return false;
}