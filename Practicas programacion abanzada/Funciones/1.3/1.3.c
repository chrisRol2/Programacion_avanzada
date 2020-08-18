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
 *   3.	Realizar una funci�n que reciba el a�o como par�metro y devuelva verdadero si el a�o es bisiesto o falso si no lo es. Se recuerda que un a�o es bisiesto cuando es divisible por 4.
 *       Sin embargo aquellos a�os que sean divisibles por 4 y tambi�n por 100 no son bisiestos, a menos que tambi�n sean divisibles por 400. Por ejemplo,
 *       1900 no fue bisiesto pero s� lo fueron el 2000 y 2004.
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

    printf("Introduzca a�o: "); scanf("%d", &year);

    if (bisiesto(year))printf("%d es un a�o bisieto", year);
    else printf("%d no es un a�o bisieto", year);
 
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