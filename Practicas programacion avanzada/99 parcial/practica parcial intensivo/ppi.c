/*
*	File:   ppi.c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define FILA 6
#define COLUMNA 11
// Declaro funciones
int ordenarMatriz(int mat[FILA][COLUMNA]);
int random(int minimo, int maximo);
void cargarfila(int mat[COLUMNA], int max_min[2]);
void imprimirMatriz(int m[FILA][COLUMNA], char nombre[6][20]);
int random(int minimo, int maximo);
int solicitarFila(char nombre[6][20]);
float promediofila(int  mat[FILA][COLUMNA], int fila, int limite);
int maximoFila(int vec[COLUMNA]);
void ordenarBurbuja(int mat[FILA][COLUMNA], int vec[COLUMNA], int fila);
void imprimirVector(int vec[COLUMNA]);
int main(void) {
    int limites_rand[FILA][2] = {
        {1,5},
        {1,110},
        {1,4},
        {15,35},
        {0,102},
        {3,8}
    };
    char nombre[6][20] = {
        "Turbiedad",
        "UFC EC\t",
        "Cloro libre",
        "Temperatura",
        "Nitratos",
        "pH\t"
    };
    int mat[FILA][COLUMNA];
    int vec[COLUMNA];
    int i;
    int filaSolicitada;

    srand(getpid());

    for( i = 0; i < FILA; i++ )cargarfila(mat[i], limites_rand[i]);
    printf("--DATOS--\n");
    imprimirMatriz(mat, nombre);

    filaSolicitada = solicitarFila(nombre);
    
    printf("\n Promedio de %s: %.2f",
           nombre[filaSolicitada],
           promediofila(mat, filaSolicitada, 7)
    );

    printf("\n Maximo de %s: %d\n",
           nombre[3],
           maximoFila(mat[3])
           );

    printf(" Cloro Libre ordenadas: \n\n\t");
    ordenarBurbuja(mat, vec, 2);
    imprimirVector(vec);

    ordenarMatriz(mat);
    printf("\n\n Valor minimo de toda la matriz: %d \n",
           ordenarMatriz(mat)
    );


    printf("\n\n"); system("PAUSE");
    return 0;
}
int solicitarFila(char nombre[6][20]) {
    int seleccion;
    int i;

    do {
        printf("\nDatos a promediar:\n");
        for( i = 0; i < 6; i++ ) {

            printf("\t%d. %s\n", i, nombre[i]);
        }
        printf("Seleccion: "); scanf("%d", &seleccion);

        if( seleccion > FILA || seleccion <= 0 ) {
            printf("\nDato fuera de rango.\n");
        }
    } while( seleccion >= FILA || seleccion <= 0 );
   
    //printf("Seleccion: "); scanf("%d", &seleccion);
    return seleccion;
}
void imprimirMatriz(int m[FILA][COLUMNA], char nombre[6][20]){
    
    int c,f;
    printf("\t\t");
    for( c = 0; c < COLUMNA; c++ )printf("%d\t",2001+c);
    printf("\n");
    for( f = 0; f < FILA; f++ ){
        printf("%s\t", nombre[f]);
        for( c = 0; c < COLUMNA; c++ )printf("%d\t", m[f][c]);
        printf("\n");
    }
}
void cargarfila(int mat[COLUMNA], int max_min[2]) {
    int i;
    for( i = 0; i < COLUMNA; i++ ) {
        mat[i] = random(max_min[0], max_min[1]);
    }   
}
int random(int minimo, int maximo) {

    return rand() % (maximo - minimo + 1) + minimo;
}

float promediofila(int  mat[FILA][COLUMNA], int  fila, int limite) {
    float promedio = -1;
    int i;
    
    for( i = 0; i < limite; i++ ) {

        promedio += (int) mat[fila][i];
    }
    promedio /= limite;
    return promedio;
}

int maximoFila(int vec[COLUMNA]) {
    int maximo = 0;
    int i;
    for( i = 0; i < COLUMNA; i++ ) {
        if( maximo < vec[i] )maximo = vec[i];
    }
    return maximo;
}

void ordenarBurbuja(int mat[FILA][COLUMNA], int vec[COLUMNA], int fila) {
    int i;
    int aux;

    for( i = 0; i < COLUMNA; i++ ) {
        vec[i] = mat[fila][i];
    }
    // algoritmo de burbuja
    for(i = 0; i < COLUMNA; i++ ) {
        for (int j = 0; j< COLUMNA-1; j++){
            if (vec[j] < vec[j+1]){ 
                aux = vec[j]; 
                vec[j] = vec[j+1]; 
                vec[j+1] = aux;
            }
        }
    }
}
void imprimirVector(int vec[COLUMNA]) {
    int i;

    for( i = 0; i < COLUMNA; i++ ) {
        printf("%d\t", vec[i]);
    }
}
int ordenarMatriz(int mat[FILA][COLUMNA]) {
    int i, j;
    int k, l;
    int aux;
    for( i = 0; i < FILA; i++ )for( j = 0; j < COLUMNA; j++ ) {
        for( k = 0; k < FILA; k++ )for( l = 0; l < COLUMNA; l++ ) {
            if( mat[i][j] < mat[k][l] ) {
                aux = mat[i][j];
                mat[i][j] = mat[k][l];;
                mat[k][l] = aux;
            }
        }
    }
    return mat[0][0];
}