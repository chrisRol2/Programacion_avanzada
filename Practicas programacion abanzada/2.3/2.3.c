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
 *           3.	Realizar una función que devuelva el mínimo elemento de un vector.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
// Declaro funciones
void ordenar(int vec[], int n);
void imprimir(int vec[], int n);

int main(void) {
    int vec[10] = { 4,5,1,0,9,6,7,24,9,2 };

    ordenar(vec, 10);
    imprimir(vec, 10);

    printf("\n"); system("PAUSE");
    return 0;
}

void ordenar(int vec[], int n) {

    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if(vec[i] > vec[j]){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

}

void imprimir(int vec[], int n) {


    for (int i = 0; i < n; i++)printf("%d\n", vec[i]);

}