/*
 *	File:   3.2.c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio:  2.	Realizar una función que determine si una matriz cuadrada de dimensión
 *                       N es simétrica con respecto a su diagonal principal.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define DIM 5
// Declaro funciones
void cargarMatriz(int mat[DIM][DIM], int  n, int m);
void imprimirMatriz(int mat[DIM][DIM], int  n, int m);
bool simetrico(int mat[DIM][DIM], int  n, int m);

int main(void) {
    int mat1[DIM][DIM];
 
    cargarMatriz(mat1, DIM, DIM);
    imprimirMatriz(mat1, DIM, DIM);

    if (simetrico(mat1, DIM, DIM))printf("Es simetrica");
    else printf("no es simetrica");

    printf("\n"); system("PAUSE");
    return 0;
}

bool simetrico(int mat[DIM][DIM], int  n, int m) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            if (mat[i][j] != mat[j][i])return false;
        }
    }
    return true;
}

void cargarMatriz(int mat[DIM][DIM], int n, int m) {
    printf("Iniciamos carga de matriz %dx%d\n", n, m);
    for (int i = 0; i < n; i++) {
        printf("Cargamos los %d valores de la fila %d\n", m, i);
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