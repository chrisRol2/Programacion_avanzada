/*
 *	File:	2.7.c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio:  7.	Realizar una función que determine si todos los elementos de dos
 *                    vectores son iguales y están en el mismo orden.
 *              
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdbool.h>
#define bool  _Bool
#define false 0
#define true  1
// Declaro funciones
bool iguales(int vec[], int vec2[], const int n);
int main(void) {
    const int n = 10;
    int vec1[] = { 4,5,1,0,9,6,7,24,9,2 };
    int vec2[] = { 4,5,1,0,9,6,7,24,9,2 };
    if (iguales(vec1, vec2, n))printf("Los vectores son iguales");
    else printf("Los vectores son diferentes o estan en otro orden");
    printf("\n"); system("PAUSE");
    return 0;
}
bool iguales(int vec[], int vec2[], const int n) {
    
    for (int i = 0; i < n; i++) {
        if (vec[i] != vec2[i])return false;
    }
    return true;

}
