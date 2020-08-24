/*
 *	File:	1..c
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
 *          4.	Realizar una función que devuelva la posición en que se haya un valor dado mediante el método de búsqueda binaria.
 *                      En caso que no lo encuentre devolver - 1
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
// Declaro funciones
void imprimir(int vec[], int n);
int busqueda_binaria(int vec[], int n, int buscado);
void ordenar(int vec[], int n);
int main(void) {
        int vec[10] = { 4,5,1,0,9,6,7,24,9,2 };
        int buscado;
        ordenar(vec, 10);
        imprimir(vec, 10);

        printf("Inserte valor a buscar: "); scanf("%d", &buscado);
        printf("Valor en la pos: %d", busqueda_binaria(vec, 10, buscado));
        printf("\n"); system("PAUSE");
        return 0;
}

void imprimir(int vec[], int n) {


    for (int i = 0; i < n; i++)printf("%d\n", vec[i]);

}
int busqueda_binaria(int vec[], int n, int buscado) {
    int inferior = 0;
    int superior = n;
    int mitad;
    int i = 0;
    while ((inferior <= superior) && (i < 5)) {
        mitad = (inferior + superior) / 2;
        if (vec[mitad] == buscado)return mitad;
        if (vec[mitad] > buscado) {
            superior = mitad;
            mitad = (inferior + superior) / 2;
        }
        if (vec[mitad] < buscado) {
            inferior = mitad;
            mitad = (inferior + superior) / 2;
        }
        i++;
    }
    return -1;


}

void ordenar(int vec[], int n) {

    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vec[i] > vec[j]) {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

}