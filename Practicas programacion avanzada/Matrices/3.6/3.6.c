/*
 *	File:   3..c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio: 6.	Hacer una función que cargue una matriz con números al azar entre 0 y 999,
 *                     la cual representa la lluvia mensual caída del año 1995 al 2008.
 *                     Las filas representan los años y las columnas correponden a los 12 meses del año.		
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
// Declaro funciones
int random(int minimo,int maximo);
void lluviasR(int mat[12][12]);
void imprimirMatriz(int mat[12][12], int  n, int m);

int main(void) {
    srand(getpid());
    int mat[12][12];

    lluviasR(mat);
    imprimirMatriz(mat, 12, 12);
    printf("\n"); system("PAUSE");
    return 0;
}

void lluviasR(int mat[12][12]) {

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            mat[i][j] = random(0,999);
        }
    }
}

int random(int minimo, int maximo) {

    return rand() % (maximo - minimo + 1) + minimo;
}

void imprimirMatriz(int mat[12][12], int  n, int m) {
    printf("-------------------\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("-----------------\n");
}