/*
*	File:   PrimerParcialEjercicio1.c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:	22-09-2020
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: Primer Parcial
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define COLUMNAS 7
#define FILAS 7
// Declaro funciones
void cargarMAT(float mat[FILAS][COLUMNAS], int max_min[COLUMNAS][2]);
void imprimirMat(float mat[FILAS][COLUMNAS], char nombre1[COLUMNAS][25], char nombre2[COLUMNAS][25]);
int random(int minimo, int maximo);
int pedirDato(int min, int max);
float promedioColumna(float  mat[FILAS][COLUMNAS], int  columna, int limite);
void Codvalormaximo(float mat[FILAS][COLUMNAS], float *codigo1, float *codigo2);
float promedioUnidades(float mat[FILAS][COLUMNAS], int anio);
int main(void) {
    srand(getpid());

    int limites_rand[COLUMNAS][2] = {
        {1000,10000},
        {2001,2020},
        {100,4000},
        {1,4},
        {800,5000},
        {1,10}
    };
    char nombres1[7][25] = {
        "Codigo\t",
        "Anio\t",
        "Unidades",
        "Plataformas",
        "Precio",
        "Cantidad",
        "Precio"
    }; 
    char nombres2[7][25] = {
        "Videojuego",
        "Publicado",
        "Vendidas",
        "Disponibles",
        "Base",
        "Paises\t",
        "Actualizado"
    };
    int columnaSelaccionada = 0;
    int datCaract[COLUMNAS][FILAS];
    float codigo1, codigo2;

    cargarMAT(datCaract, limites_rand);
    
    imprimirMat(datCaract,nombres1,nombres2);

    columnaSelaccionada = pedirDato(1, FILAS);

    printf("El promedio de las ultimas 3 filas de \"%s %s\" es: %.2f\n",
           nombres1[columnaSelaccionada - 1],
           nombres2[columnaSelaccionada - 1],
           promedioColumna(datCaract, columnaSelaccionada - 1, 4)
    );
    Codvalormaximo(datCaract, &codigo1, &codigo2);
    printf("los codigos de mayor precio son: %.0f y %.0f", codigo1, codigo2);
    
    
    printf("\nPromedio de unidades vendidas luego del 2005: %.0f", 
           promedioUnidades(datCaract, 2005)
    );
    printf("\n"); system("PAUSE");
    return 0;
}

void cargarMAT(float mat[FILAS][COLUMNAS], int max_min[COLUMNAS][2]) {
    int i, j;

    for( i = 0; i < FILAS; i++ ) for( j = 0; j < 6; j++ ) {
            mat[i][j] = (float)random(max_min[j][0], max_min[j][1]);
        }
    
    for( i = 0; i < FILAS; i++ ) {
        mat[i][6] = mat[i][4] + mat[i][4] * 0.2 * (2020 - mat[i][1]);
    }
}

void imprimirMat(float mat[FILAS][COLUMNAS], 
                 char nombre1[COLUMNAS][25], char nombre2[COLUMNAS][25]) {
    int i,j;

    printf("\t");
    for( i = 0; i < COLUMNAS; i++ ) printf("%s\t", nombre1[i]);
    printf("\n\t");
    for( i = 0; i < COLUMNAS; i++ ) printf("%s\t", nombre2[i]);
    printf("\n\n");
    for( i = 0; i < FILAS; i++ ) {
        printf("%d", i + 1);
        for( j = 0; j < COLUMNAS; j++ ) {
            if( ((j > 0) && (j < 5)) || (j == 6) )printf("\t");
            if(j==6)printf("\t%.2f", mat[i][j]);
            else printf("\t%.0f", mat[i][j]);
        }
        printf("\n");
    }
}

int random(int minimo, int maximo) {

    return rand() % (maximo - minimo + 1) + minimo;
}

int pedirDato(int min, int max) {
    int dato;

    do {

        printf("\nSeleccione columna:\t");scanf("%d", &dato);
        if( (dato > max) || (dato < min) )printf("\nDato fuera de rango.\n");
     } while( (dato > max) || (dato < min) );
    return dato;
}

float promedioColumna(float  mat[FILAS][COLUMNAS], int  columna, int limite) {
    float promedio = 0;
    int i;
 
    for( i = limite; i < FILAS; i++ )promedio += mat[i][columna];
    promedio /= COLUMNAS - limite + 1;
    return promedio;
}

void Codvalormaximo(float mat[FILAS][COLUMNAS], float *codigo1, float *codigo2) {
    float maximo1 = mat[0][6];
    float maximo2 = mat[0][6];
    int i;
    int pos1 = 0;
    int pos2 = 0;
    for( i = 0; i < FILAS; i++ ) {
        for( i = 0; i < FILAS; i++ ) {
            if( maximo1 < mat[i][6] ) {
                maximo2 = maximo1;
                maximo1 = mat[i][6];
                pos2 = pos1;
                pos1 = i;
            }
        }
    }
    *codigo1 = mat[pos1][0];
    *codigo2 = mat[pos2][0];
}
float promedioUnidades(float mat[FILAS][COLUMNAS], int anio) {
    float promedio = 0;
    int i;
    int contador = 0;

    for( i = 0; i < FILAS; i++ ) {
        if( mat[i][1] > anio ) {
            contador++;
            promedio += mat[i][2];
        }
    }
    promedio /= contador;
    return promedio;
}