/*
*	File:   ppi2.c
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
#define FILA 10
#define COLUMNA 4

void cargarMAT(int mat[FILA][COLUMNA], int max_min[COLUMNA][2]);
void imprimirMat(int mat[FILA][COLUMNA], char nombre[COLUMNA][20]);
int pedirDato(int min, int max);
int maximoPos(int vec[FILA][COLUMNA]);
void ordenarBurbuja(int mat[FILA][COLUMNA], int vec[COLUMNA], int fila);
void imprimirVector(int vec[COLUMNA]);

int main(void) {

	srand(getpid());

    int empleado;
	int mat[FILA][COLUMNA];
    int vec[FILA];
    int limites_rand[COLUMNA][2] = {
        {10000,20000},
        {3000,10000},
        {12,24}
    };
    char nombre[6][20] = {
        "Legajo",
        "Sueldo basico",
        "Horas extra",
        "Sueldo total"
    };

    cargarMAT(mat, limites_rand);
    imprimirMat(mat, nombre);
    empleado = pedirDato(1, 10);
    printf(" Sueldo del empleado %d: $%d.\n",
           empleado,
           mat[empleado - 1][3]
    );
    empleado = maximoPos(mat);
    printf(" El empleado con el Sueldo total mas alto es: %d, con $%d\n",
           empleado + 1,
           mat[empleado][3]
    );
    printf(" %s ordenado\n  ",nombre[1]);
    ordenarBurbuja(mat, vec, 1);
    imprimirVector(vec);

	printf("\n\n"); system("PAUSE");
	return 0;
}

int random(int minimo, int maximo) {

	return rand() % (maximo - minimo + 1) + minimo;
}
void cargarMAT(int mat[FILA][COLUMNA], int max_min[COLUMNA][2]) {
    int i, j;

    for( i = 0; i < FILA; i++ ) {
        for( j = 0; j < 3; j++ ) {
            mat[i][j] = random(max_min[j][0], max_min[j][1]);
        }
    }
    for( i = 0; i < FILA; i++ ) {
        mat[i][3] = mat[i][1] + 250 * mat[i][2];
    }
}
void imprimirMat(int mat[FILA][COLUMNA], char nombre[COLUMNA][20]) {
    int i,j;

    printf("\t");
    for( i = 0; i < COLUMNA; i++ ) printf("%s\t", nombre[i]);
    printf("\n");
    for( i = 0; i < FILA; i++ ) {
        printf("%d", i + 1);
        for( j = 0; j < COLUMNA; j++ ) {
            if( j > 0 )printf("\t");
            printf("\t%d", mat[i][j]);
        }
        printf("\n");
    }
}
int pedirDato(int min, int max) {
    int dato;

    do {
        printf("\nSelecciones empleado:\n");scanf("%d", &dato);

        if( dato > max || dato < min ) {
            printf("\nDato fuera de rango.\n");
        }
    } while( dato > max || dato < min );
    return dato;
}
int maximoPos(int vec[FILA][COLUMNA]) {
    int max = 0;
    int posMax = 0;
    int i;
    for( i = 0; i < FILA; i++ ) {
        if( max < vec[i][3] ) {
            max = vec[i][3];
            posMax = i;
        }
    }
    return posMax;
}
void ordenarBurbuja(int mat[FILA][COLUMNA], int vec[COLUMNA], int fila) {
    int i;
    int aux;

    for( i = 0; i < FILA; i++ ) {
        vec[i] = mat[i][fila];
    }
    // algoritmo de burbuja
    for(i = 0; i < FILA; i++ ) {
        for( int j = 0; j < FILA - 1; j++ ) {
            if (vec[j] > vec[j+1]){ 
                aux = vec[j]; 
                vec[j] = vec[j+1]; 
                vec[j+1] = aux;
            }
        }
    }
}
void imprimirVector(int vec[FILA]) {
    int i;

    for( i = 0; i < FILA; i++ ) {
        printf("%d\t", vec[i]);
    }
}
