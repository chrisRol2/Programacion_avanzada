/*
 *	File:   3.5.c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio:  5.	Realizar 9 funciones que generen las matrices detalladas a continuación:
 *
 *
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define DIM 4
// Declaro funciones
void clear(int mat[DIM][DIM]);
void gen1(int mat[DIM][DIM], int n, int m);
void gen2(int mat[DIM][DIM], int n, int m);
void gen3(int mat[DIM][DIM], int n, int m);
void gen4(int mat[DIM][DIM], int n, int m);
void gen5(int mat[DIM][DIM], int n, int m);
void gen6(int mat[DIM][DIM], int n, int m);
void gen7(int mat[DIM][DIM], int n, int m);
void gen8(int mat[DIM][DIM], int n, int m);
void gen9(int mat[DIM][DIM], int n, int m);
void imprimirMatriz(int mat[DIM][DIM], int  n, int m);

int main(void) {
    int matGen[DIM][DIM];

    clear(matGen);
    gen1(matGen,DIM,DIM);
    imprimirMatriz(matGen, DIM, DIM);

    clear(matGen);
    gen2(matGen,DIM,DIM);
    imprimirMatriz(matGen, DIM, DIM);
    
    clear(matGen);
    gen3(matGen,DIM,DIM);
    imprimirMatriz(matGen, DIM, DIM);
        
    clear(matGen);
    gen4(matGen,DIM,DIM);
    imprimirMatriz(matGen, DIM, DIM);
     
    clear(matGen);
    gen5(matGen,DIM,DIM);
    imprimirMatriz(matGen, DIM, DIM);
    
    clear(matGen);
    gen6(matGen,DIM,DIM);
    imprimirMatriz(matGen, DIM, DIM);
     
    clear(matGen);
    gen7(matGen,DIM,DIM);
    imprimirMatriz(matGen, DIM, DIM);

    
    clear(matGen);
    gen8(matGen,DIM,DIM);
    imprimirMatriz(matGen, DIM, DIM);
        
    clear(matGen);
    gen9(matGen,DIM,DIM);
    imprimirMatriz(matGen, DIM, DIM);


    printf("\n"); system("PAUSE");
    return 0;
}

void gen1(int mat[DIM][DIM], int n, int m) {
    int generador = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == i) {
                mat[j][i] = generador;
                generador--;
            }
        }
    }
}

void gen2(int mat[DIM][DIM], int n, int m) {
    int generador = 4;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((j + i) == 3) {
                generador = 4 - j;
                mat[j][i] = pow(2, generador);
                generador--;
            }
        }
    }
}

void gen3(int mat[DIM][DIM], int n, int m) {
    int generador = 4;

    for (int i = 0; i < n; i++) {
        generador = 0;
        for (int j = i; j < m; j++) {
            generador++;
                mat[i][j] = generador;
        }
    }
}

void gen4(int mat[DIM][DIM], int n, int m) {
    int generador = 4;

    for (int i = 0; i < n; i++) {
        generador = 5;
        for (int j = i; j < m; j++) {
            generador--;
                mat[j][i] = generador;
        }
    }
}

void gen5(int mat[DIM][DIM], int n, int m) {
    int generador = 0;

    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < m; j++) {
            generador++;
                mat[i][j] = generador;
        }
    }
}

void gen6(int mat[DIM][DIM], int n, int m) {


    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < m; j++) {
        
                mat[i][j] = i+1;
        }
    }
}

void gen7(int mat[DIM][DIM], int n, int m) {


    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < m; j++) {
        
                mat[j][i] = i+1;
        }
    }
}

void gen8(int mat[DIM][DIM], int n, int m) {
    int generador = 1;      // declaro e inicializo  la variable generador 
    bool control = false;   // variable de control para generar la matriz
    for (int i = 0; i < n; i++) {
        if (!(i % 2))control = false;
        else control = true;
        for (int j = 0; j < m; j++) {
            if (control) {
                mat[i][j] = generador;
                generador++;
                control = false;
            } else {
                control = true;
            }
        }
    }
}

void gen9(int mat[DIM][DIM], int n, int m) {
    int generador = 0;
    int i;
        for ( i = 0; i < 4; i++) {
            generador++;
            mat[0][i] = generador;
        }
        for ( i = 1; i < 4; i++) {
            generador++;
            mat[i][3] = generador;
        }
        for ( i = 2; i >= 0 ; i--) {
            generador++;
            mat[3][i] = generador;
        }
        for ( i = 2; i >= 1; i--) {
            generador++;
            mat[i][0] = generador;
        }
        for ( i = 1; i <= 2; i++) {
            generador++;
            mat[1][i] = generador;
        }
        for ( i = 2; i >= 1; i--) {
            generador++;
            mat[2][i] = generador;
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
void clear(int mat[DIM][DIM]) {

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            mat[j][i] = 0;
        }
    }
}