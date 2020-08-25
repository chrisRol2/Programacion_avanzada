/*
 *	File:   3.9.c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio:  9.	Dada una matriz de dimension NxN. realizar las siguientes operaciones:
 *                      a)	Intercambiar dos filas cualquiera.  
 *                      b)	Intercambiar dos columnas cualesquiera. 
 *                      c)	Intercambiar una fila y una columna dada
 *                      d)	Transponer la matriz sobre si misma
 *                 
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define DIM 4
// Declaro funciones
void intercambiarFila(int mat[DIM][DIM], int n, int m, int nfila1, int nfila2);
void intercambiarColumna(int mat[DIM][DIM], int n, int m, int nfila1, int nfila2);
void intercambiarFilaColumna(int mat[DIM][DIM], int n, int m, int nfila1, int nfila2);
void transponer(int mat[DIM][DIM], int n, int m);

void imprimirMatriz(int mat[DIM][DIM], int  n, int m);
void matRand(int mat[DIM][DIM]);
int  random(int minimo, int maximo);


int main(void) {
    srand(getpid());

    int mat1[DIM][DIM]; matRand(mat1);
    printf("----ORIGINAL-----\n");

    imprimirMatriz(mat1, DIM, DIM);

    printf("------FILA-------\n");
    intercambiarFila(mat1, DIM, DIM, 1, 2);
    imprimirMatriz(mat1, DIM, DIM);
    printf("-----------------\n");

    printf("-----COLUMNA-----\n");
    intercambiarColumna(mat1, DIM, DIM, 1, 2);
    imprimirMatriz(mat1, DIM, DIM);
    printf("-----------------\n");

    printf("-FILA COLUMNA----\n");
    intercambiarFilaColumna(mat1, DIM, DIM, 1, 2);
    imprimirMatriz(mat1, DIM, DIM);
    printf("-----------------\n");

    printf("----TRANSPUESTA--\n");
    transponer(mat1,DIM,DIM);
    imprimirMatriz(mat1, DIM, DIM);
    printf("-----------------\n");

    printf("\n"); system("PAUSE");
    return 0;
}

void intercambiarFila(int mat[DIM][DIM], int n, int m, int nfila1, int nfila2) {
    int aux[DIM];
    for (int i = 0; i < n; i++) {
        aux[i] = mat[nfila1][i];
        mat[nfila1][i] = mat[nfila2][i];
        mat[nfila2][i] = aux[i];
    }
}

void intercambiarColumna(int mat[DIM][DIM], int n, int m, int nfila1, int nfila2) {
    int aux[DIM];
    for (int i = 0; i < n; i++) {
        aux[i] = mat[i][nfila1];
        mat[i][nfila1] = mat[i][nfila2];
        mat[i][nfila2] = aux[i];
    }
}

void intercambiarFilaColumna(int mat[DIM][DIM], int n, int m, int nfila1, int nfila2) {
    int aux[DIM];
    for (int i = 0; i < n; i++) {
        aux[i] = mat[i][nfila1];
        mat[i][nfila1] = mat[nfila2][i];
        mat[nfila2][i] = aux[i];
    }
}

void transponer(int mat[DIM][DIM], const int n, const int m) {
    int aux[DIM][DIM]; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            aux[i][j] = mat[j][i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = aux[i][j];
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

void matRand(int mat[DIM][DIM]) {

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            mat[i][j] = random(0, 100);
        }
    }
}