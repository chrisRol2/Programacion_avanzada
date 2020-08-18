/*
 *	File:	1..c
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
 *         2.	Realizar una función que devuelva la suma de todos los elementos de un vector de N elementos.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
// Declaro funciones
int suma(int vec[],int tamano);

int main(void) {
    int vec[10] = { 1,2,3,4,5,6,7,8,9,0 };

    printf("%d", suma(vec, 10));

    printf("\n"); system("PAUSE");
    return 0;
}

int suma(int vec[], int tamano) {
    int resultado = 0;
    for (int i = 0; i < tamano; i++) resultado += vec[i];
    return  resultado;
}