#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define FILA 6
#define COLUMNA 11
// Declaro funciones
int random(int minimo, int maximo);
void cargarfila(int mat[COLUMNA], int max_min[2]);
void imprimirMatriz(int m[FILA][COLUMNA], char nombre[6][20]);
int random(int minimo, int maximo);
int solicitarFila(char nombre[6][20]);
float promediofila(int  mat[FILA][COLUMNA], int fila, int limite);
int maximoFila(int vec[COLUMNA]);
void ordenarBurbuja(int mat[FILA][COLUMNA], int vec[COLUMNA], int fila);
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
    int i;
    int filaSolicitada;

    srand(getpid());

    for( i = 0; i < FILA; i++ ) {
        cargarfila(mat[i], limites_rand[i]);
    }
    printf("--DATOS--\n");
    imprimirMatriz(mat, nombre);

    do {
        printf("\nDatos a promediar:\n");
        filaSolicitada = solicitarFila(nombre);

        if( filaSolicitada > 7 || filaSolicitada <= 0 ) {
            printf("\nDato fuera de rango.\n");
        }
    } while( filaSolicitada > 7 || filaSolicitada <= 0 );

    printf("\n Promedio de %s: %.2f",
           nombre[filaSolicitada],
           promediofila(mat, filaSolicitada, 7)
    );

    printf("\n Maximo de %s: %d",
           nombre[3],
           maximoFila(mat[3])
           );


    printf("\n"); system("PAUSE");
    return 0;
}
int solicitarFila(char nombre[6][20]) {
    int seleccion;
    int i;
    for( i = 0; i < 6; i++ ) {

        printf("\t%d. %s\n", i, nombre[i]);
    }
    printf("Seleccion: "); scanf("%d", &seleccion);
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

    for( i = 0; i < COLUMNA, i++ ) {
        vec[i] = mat[fila][i];
    }
    // algoritmo de burbuja
}