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
 *	Ejercicio:  7.	Dada una matriz cargada utilizando la función del ejercicio anterior, realizar funciones para:
 *                  a)	Almacenar en un vector la lluvia promedio caida en cada uno de los meses 
 *                  b)	Almacenar en un vector la lluvia promedio caida durante cada uno de los años
 *                  c)	Mostrar los resultados obtenidos en los puntos a y b 
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define  MESES 12
#define  ANIOS 2008-1995
// Declaro funciones

void lluviasR(int mat[ANIOS][MESES]);
void imprimirMatriz(int mat[ANIOS][MESES], int  n, int m);
void imprimirVec(int vec[], int n);
int random(int minimo, int maximo);
void lluviaMensual(int mat[ANIOS][MESES], int vec[MESES]);
void lluviaAnual(int mat[ANIOS][MESES],int vec[ANIOS]);

int main(void) {
    srand(getpid());
    int mat[ANIOS][MESES];
    int lluviasMensuales[MESES];
    int lluviasAnuales[ANIOS];

    lluviasR(mat);imprimirMatriz(mat, ANIOS, MESES);

    printf("Lluvias mensuales  promedio\n");
    printf("Ene\tFeb\tMar\tAbr\tMay\tJun\tJul\tAgo\tSep\tOct\tNov\tDic\n");
    lluviaMensual(mat, lluviasMensuales);
    imprimirVec(lluviasMensuales,MESES);

    printf("\n\nLluvias anuales promedio");
    printf("\n1995\t1996\t1997\t1998\t1999\t2000\t2001\t2002\t2003\t2004\t2005\t2007\t2008\n");
    lluviaAnual(mat, lluviasAnuales);
    imprimirVec(lluviasAnuales,ANIOS);

    printf("\n\n"); system("PAUSE");
    return 0;
}

void lluviaMensual(int mat[ANIOS][MESES], int vec[MESES]) {
    int aux = 0;

    for (int i = 0; i < MESES; i++) {
        for (int j = 0; j < ANIOS; j++) {
            aux += mat[i][j];
        }
        vec[i] = aux / 12;
        aux = 0;
    }
}

void lluviaAnual(int mat[ANIOS][MESES], int vec[ANIOS]) {
    int aux = 0;

    for (int i = 0; i < ANIOS; i++) {
        for (int j = 0; j < MESES; j++) {
            aux += mat[j][i];
        }
        vec[i] = aux / 13;
        aux = 0;
    }
}

void lluviasR(int mat[ANIOS][MESES]) {

    for (int i = 0; i < ANIOS; i++) {
        for (int j = 0; j < MESES; j++) {
            mat[i][j] = random(0, 999);
        }
    }
}

int random(int minimo, int maximo) {

    return rand() % (maximo - minimo + 1) + minimo;
}

void imprimirMatriz(int mat[ANIOS][MESES], int  n, int m) {
    printf("Ene\tFeb\tMar\tAbr\tMay\tJun\tJul\tAgo\tSep\tOct\tNov\tDic\n\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("-----------------\n");
}

void imprimirVec(int vec[], int n) {


    for (int i = 0; i < n; i++)printf("%d\t", vec[i]);

}