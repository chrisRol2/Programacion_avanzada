/*
 *	File:   3.4.c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio:  4.	Dada una matriz de 5x5 de números enteros, ordenar en forma ascendente
 *                       cada una de sus filas.
 *
 *
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define DIM 5
// Declaro funciones
void ordenarMat(int mat[DIM][DIM], int n, int m);
void imprimirMatriz(int mat[DIM][DIM], int  n, int m);

int main(void) {
    int mat1[DIM][DIM] = {
        {1,1,1,1,2},
        {3,2,4,5,2},
        {2,9,2,7,4},
        {1,9,3,1,6},
        {4,3,2,10,6} };

    imprimirMatriz(mat1, DIM, DIM);
    ordenarMat(mat1, DIM, DIM);
    imprimirMatriz(mat1, DIM, DIM);

    printf("\n"); system("PAUSE");
    return 0;
}

void ordenarMat(int mat[DIM][DIM], int n, int m) {
    int aux;
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mat[k][i] > mat[k][j]) {
                    aux = mat[k][i];
                    mat[k][i] = mat[k][j];
                    mat[k][j] = aux;
                }
            }
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