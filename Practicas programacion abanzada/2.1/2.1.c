/*
 *	File:	2.1.c
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
 *          1.	Realizar una funci�n que imprima los valores de un vector de N posiciones, desde la posici�n m�xima a la posici�n m�nima.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
// Declaro funciones
void imprimir(int vec[]);

int main(void) {
    int vec[10] = { 1,2,3,4,5,6,7,8,9,0 };
    imprimir(vec);
    printf("\n"); //system("PAUSE");
    return 0;
}

void imprimir(int vec[]) {

    
    for (int i = 0; i < 10; i++)printf("%d\n", vec[i]);

}