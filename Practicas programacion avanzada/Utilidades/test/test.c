#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //permite utilizar funciones de random
#include <time.h>

#define COLU 4
#define FILAS 10

//Declaro funciones a Utilizar
void llenarmatriz(int mat[FILAS][COLU]);
void imprimirmatriz(int mat[FILAS][COLU]);
void sueldoTotalporfila(int mat[FILAS][COLU]);

int main(void)
{

    int mat[FILAS][COLU];
    

    srand(time(NULL));
    llenarmatriz(mat);
    imprimirmatriz(mat); // Punto A
    sueldoTotalporfila(mat); // Punto B


    system("PAUSE");
    return 0;


}


void llenarmatriz(int mat[FILAS][COLU]) //Lleno Columnas (j)
{
    int i;


    for (i = 0; i < FILAS; i++)
    {

        //Semilla rand()%(Máximo-Mínimo+1)+Mínimo
        mat[i][0] = rand() % (20000 - 10000 + 1) + 10000;
        mat[i][1] = rand() % (10000 - 3000 + 1) + 3000;
        mat[i][2] = rand() % (24 - 12 + 1) + 12; 
        mat[i][3] = ( mat[i][1] + 250) * mat[i][2];
    }
}


void imprimirmatriz(int mat[FILAS][COLU])

{
    int c = 0;


    printf("\n Matriz \n");
    printf("\t\tLegajo\tSueldoB\tOT\tSueldoT\n");

    printf("Fila 1  : \t");
    for (c = 0; c < COLU; c++)
    {
        printf("%d\t", mat[0][c]);
    }
    printf("\n");
    printf("Fila 2  : \t");
    for (c = 0; c < COLU; c++)
    {
        printf("%d\t", mat[1][c]);
    }
    printf("\n");
    printf("Fila 3 : \t");
    for (c = 0; c < COLU; c++)
    {
        printf("%d\t", mat[2][c]);
    }
    printf("\n");
    printf("Fila 4 : \t");
    for (c = 0; c < COLU; c++)
    {
        printf("%d\t", mat[3][c]);
    }
    printf("\n");
    printf("Fila 5 : \t");
    for (c = 0; c < COLU; c++)
    {
        printf("%d\t", mat[4][c]);
    }
    printf("\n");
    printf("Fila 6 : \t");
    for (c = 0; c < COLU; c++)
    {
        printf("%d\t", mat[5][c]);
    }
    printf("\n");
    printf("Fila 7 : \t");
    for (c = 0; c < COLU; c++)
    {
        printf("%d\t", mat[6][c]);
    }
    printf("\n");
    printf("Fila 8 : \t");
    for (c = 0; c < COLU; c++)
    {
        printf("%d\t", mat[7][c]);
    }
    printf("\n");
    printf("Fila 9 : \t");
    for (c = 0; c < COLU; c++)
    {
        printf("%d\t", mat[8][c]);
    }
    printf("\n");
    printf("Fila 10 : \t");
    for (c = 0; c < COLU; c++)
    {
        printf("%d\t", mat[9][c]);
    }
    printf("\n");

}

void sueldoTotalporfila(int mat[FILAS][COLU])

{
    int nfila;
    printf("Ingrese un numero de fila: \n");
    scanf("%d", &nfila);
    printf(" El sueldo maximo del empleado %d: $%d.\n", nfila, mat[nfila - 1][3]);


}