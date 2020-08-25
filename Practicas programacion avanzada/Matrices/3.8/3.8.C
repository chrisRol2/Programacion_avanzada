/*
 *	File:   3.8.c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio:  8.	Dadas dos matrices cuadradas A y B de dimensión NxN,
 *                  obtener una matriz C de dimensión NxN, que contenga el producto de
 *                  las dos primeras, sabiendo que:
 *
 *
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define DIM 20
// Declaro funciones
void imprimirMatriz(int mat[DIM][DIM], int  n, int m);
void imprimirVec(int vec[], int n);
int random(int minimo, int maximo);
void matRand(int mat[DIM][DIM]);
void productoMat(int mat[DIM][DIM], int mat1[DIM][DIM], int res[DIM][DIM], int n, int m);

int main(void) {
    srand(getpid());
    int mat1[DIM][DIM]; matRand(mat1);
    int mat2[DIM][DIM]; matRand(mat2);
    int res[DIM][DIM]; matRand(res);
    printf("-----------------\n");
    imprimirMatriz(mat1, DIM, DIM);
    printf("-----------------\n");
    imprimirMatriz(mat2, DIM, DIM);
    printf("-----------------\n");
    productoMat(mat1,mat2,res, DIM, DIM);
    imprimirMatriz(res, DIM, DIM);

    printf("\n"); system("PAUSE");
    return 0;
}

void productoMat(int mat1[DIM][DIM], int mat2[DIM][DIM], int res[DIM][DIM], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }

    }
}

int random(int minimo, int maximo) {

    return rand() % (maximo - minimo + 1) + minimo;
}

void imprimirMatriz(int mat[DIM][DIM], int  n, int m) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void imprimirVec(int vec[], int n) {


    for (int i = 0; i < n; i++)printf("%d\t", vec[i]);

}
void matRand(int mat[DIM][DIM]) {

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            mat[i][j] = random(0, 100);
        }
    }
}