/*
*	File:   simulacro parcial.c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:   15-09-2020
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: Ejercicio 1:Matrices •Crear  una  matriz  de 4filas  y 6columnas.Cada  columna  corresponde  a  un diaa  partir  del  10  de agosto,  cada  fila  corresponde  a  una  variable  diferente.  Completar las  filas  según  los  siguientes rangos:Fila 1: Aleatorio entre 1000y 2500Fila 2: Aleatorio entre 10y 14Fila 3:Aleatorioentre 20 y 23Fila 4:Aleatorio entre 21y 35•Crear  una  función  que  permita  imprimir  la  matriz,  incluyendo  los  encabezados  de  los diaspara  las columnas y los nombres de variablepara las filas.•Intercambiar dos filas cualesquiera.•Intercambiar dos columnas cualesquiera. 
*
*		
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define FILA 4
#define COLUMNA 6
// Declaro funciones
int random(int minimo, int maximo);
void cargarfila(int mat[COLUMNA], int max_min[2]);
void imprimirMatriz(int mat[FILA][COLUMNA], int  n, int m);
void intercambiarFila(int mat[FILA][COLUMNA], int n, int m, int nfila1, int nfila2);
void intercambiarColumna(int mat[FILA][COLUMNA], int n, int m, int nfila1, int nfila2);

int main(void) {

    int limites_rand[4][2] = {
        {1000,2500},
        {10,14},
        {20,23},
        {21,35}
    };
    int mat[FILA][COLUMNA];
    int i;
    
    srand(getpid());

    for( i = 0; i < 4; i++ ) {
        cargarfila(mat[i], limites_rand[i]);
    }
    printf("resultado: \n");
    imprimirMatriz(mat, 4, 6);
    printf("resultado intercambio columna: \n");
    intercambiarColumna(mat, 4, 6, 2, 3);
    imprimirMatriz(mat, 4, 6);

    printf("resultado intercambio fila: \n");
    intercambiarFila(mat, 4, 6, 2, 3);
    imprimirMatriz(mat, 4, 6);

    printf("\n"); system("PAUSE");
    return 0;
}

void cargarfila(int mat[COLUMNA], int max_min[2]) {
    int i;
    for( i = 0; i < COLUMNA; i++ ) {
        mat[i] = random(max_min[0], max_min[1]);
    }   
}

void imprimirMatriz(int mat[FILA][COLUMNA], int  n, int m) {
    int i;
    printf("\t");

    for( i = 10; i < COLUMNA+10; i++ )printf("%dA\t",i);
    printf("\n");
    for ( i = 0; i < n; i++) {
        printf("var: %d\t",i);
        for (int j = 0; j < m; j++) {

            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int random(int minimo, int maximo) {

    return rand() % (maximo - minimo + 1) + minimo;
}

void intercambiarFila(int mat[FILA][COLUMNA], int n, int m, int nfila1, int nfila2) {
    int aux[COLUMNA];
    for (int i = 0; i < n; i++) {
        aux[i] = mat[nfila1][i];
        mat[nfila1][i] = mat[nfila2][i];
        mat[nfila2][i] = aux[i];
    }
}

void intercambiarColumna(int mat[FILA][COLUMNA], int n, int m, int nfila1, int nfila2) {
    int aux[FILA];
    for (int i = 0; i < n; i++) {
        aux[i] = mat[i][nfila1];
        mat[i][nfila1] = mat[i][nfila2];
        mat[i][nfila2] = aux[i];
    }
}