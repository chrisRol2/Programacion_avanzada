/*
 *	File:   3.1.c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio: 1.	Realizar una función que permita cargar con números enteros,
 *                       una matriz de 5x5, ingresando los datos desde teclado.
 *                       ¿En qué cambiaría la función si la matriz contuviera otro
 *                       tipo de datos y/o tuviese otras dimensiones?
 *
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define DIM 3
// Declaro funciones
void cargarMatriz(int mat[DIM][DIM],int  n, int m);
void imprimirMatriz(int mat[DIM][DIM], int  n, int m);
int main(void) {
    int mat[DIM][DIM];

    cargarMatriz(mat, DIM, DIM);
    imprimirMatriz(mat, DIM, DIM);
    printf("\n"); system("PAUSE");
    return 0;
}

void cargarMatriz(int mat[DIM][DIM],int n,int m) {
    printf("Iniciamos carga de matriz %dx%d\n", n, m);
    for (int i = 0; i < n; i++) {
        printf("Cargamos los %d valores de la fila %d\n",m, i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void imprimirMatriz(int mat[DIM][DIM], int  n, int m) {
    printf("-------------------\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("-----------------\n");
}