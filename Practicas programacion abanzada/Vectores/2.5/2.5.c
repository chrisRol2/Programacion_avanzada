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
 *          5.	Realizar una función que permita determinar la cantidad de veces que se repite un valor en un vector dado.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
// Declaro funciones
void repetido   (int vec[], int n);
void ordenar    (int vec[], int n);
int main(void) {

    int vec[10] = { 4,2,1,4,9,6,7,24,9,2 };
    
    repetido(vec, 10);

    printf("\n"); system("PAUSE");
    return 0;
}

void repetido(int vec[], int n) {
    int aux; // auxiliar para pararme en un valor a buscar
    int contador = 0; // contador de repeticiones

    ordenar(vec, n); // ordeno para buscar numeros consecutivamente;

    for (int i = 0; i < n; i++) {   // recorro el vector un valor a la vez
        aux = vec[i]; //me paro en el valor que quiero buscar
        for (int j = 0; j < n; j++) { // me muevo en el vector buscando si se repite
            if (vec[j] == aux) { // si se repite

                contador++; // si se repite cuento cuantas veces se repite
                i = j; // muevo el cursor hasta el ultimo que se repite
            }
        }
        if(contador > 1) printf("El valor %d, se repite %d veces\n", aux, contador); // si se repite, lo imprimo
        contador = 0; // llevo el contador a 0 para buscar el siguiente numero
    }
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