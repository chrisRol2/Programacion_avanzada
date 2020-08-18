/*
 *	File:	1.2.c
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
 *		2.	Hacer una función que reciba tres valores enteros positivos y devuelva el mayor estricto de los tres. 
 *          En caso de no existir devolver -1. No usar operadores lógicos.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Declaro funciones
int mayor_estricto(int a, int b, int c);
int main(void) {

   int a, b, c; // declaro variables
    a = b = c = 0; // inicializo variables

    // pido los valores
    printf("Ingrese A: "); scanf("%d", &a);
    printf("Ingrese B: "); scanf("%d", &b);
    printf("Ingrese C: "); scanf("%d", &c);
    // Guardo resultado
    int res = mayor_estricto(a, b, c);
    //Imprimo resultado
    printf("Resultado: %d\n", res);

    system("PAUSE");
    return 0;
}

int mayor_estricto(int a, int b, int c) {

    if (a > b) {
        if (a > c) return a;
    } else if (b > c) {
        if (b > a) return b;
    } else if (c > b) {
        if (c > a) return c;
    } else return -1;
}
