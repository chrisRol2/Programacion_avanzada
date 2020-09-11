/*
 *	File:   3.3.c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio: 3.	Realice una función devuelva verdadero si todas sus columnas de una matriz son palíndromos.
 *
 *
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define false 0
#define true 1
#define DIM 4
// Declaro funciones
void cargarMatriz(int mat[DIM][DIM], int  n, int m);
void imprimirMatriz(int mat[DIM][DIM], int  n, int m);
int ColumnasPalindromas(int mat[DIM][DIM], int n, int m);
int main(void) {
    int mat1[DIM][DIM] = {
        {1,1,1,1},
    {2,2,2,2},
    {2,2,2,2},
        {1,1,1,1} };

   // cargarMatriz(mat1, DIM, DIM);
    imprimirMatriz(mat1, DIM, DIM);

    if (ColumnasPalindromas(mat1, DIM, DIM))printf("Todas las columnas son palindromas\n");
    else printf("Alguna columna no es palindroma");

    printf("\n"); system("PAUSE");
    return 0;
}

int ColumnasPalindromas(int mat[DIM][DIM], int n, int m) {
    int aux;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            aux = m - j - 1;
            if (mat[j][i] != mat[aux][i]) return false;
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