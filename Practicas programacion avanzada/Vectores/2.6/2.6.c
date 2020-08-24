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
 *    6. Realizar una función que permita eliminar un valor de un arreglo.Se sabe que todos los elementos
 *      válidos del vector se almacenan en forma consecutiva, y que los elementos no utilizados se 
 *      inicializan con - 1.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdbool.h>
// Declaro prototipos de funciones
void repetido(int vec[], int n);
void imprimir(int vec[], int n);
void desplazar(int vec[], int n,const int buscado);
//void llenador(int vec[], int n);

int main(void) {
    const int n = 10; // tamaño del vector
    const int buscado = -1; // el valor que voy a buscar repetido  
    int vec[10] = { 4,5,1,0,9,6,5,24,9,2 }; // inicializo el vector

   // printf("%d \n", sizeof(vec)/sizeof(int));
    repetido(vec, n); // elimino los repetidos
    imprimir(vec, n); // muestro como quedo luego de eliminar 

    desplazar(vec,n, buscado); // desplazo llevando el valor buscado al final
    imprimir(vec, n); // vuelvo a imprimir los valores en pantalla

    printf("\n"); system("PAUSE");
    return 0;
}

void repetido(int vec[], int n) { // metodo para buscar  el valor repetido y eliminarlo con -1
    int aux; // auxiliar para pararme en un valor a buscar
    int contador = 0; // contador de repeticiones

   // ordenar(vec, n); // ordeno para buscar numeros consecutivamente;

    for (int i = 0; i < n; i++) {   // recorro el vector un valor a la vez
        aux = vec[i]; //me paro en el valor que quiero buscar
        for (int j = i + 1; j < n; j++) { // me muevo en el vector buscando si se repite
            if (vec[j] == aux) { // si se repite
               // imprimir(vec, n);
                printf("%d se repite \n", vec[j]); // imprimo cual es el repetido
               vec[j] = -1;  // elimino el repetido
                contador++; // si se repite cuento cuantas veces se repite
               // i = j; // muevo el cursor hasta el ultimo que se repite
            }
        }
        if (contador > 1) printf("El valor %d, se repite %d veces\n", aux, contador); // si se repite, lo imprimo
        contador = 0; // llevo el contador a 0 para buscar el siguiente numero
    }
}

void imprimir(int vec[], int n) { // imprime todos los valores del vector

    printf("\n");
    for (int i = 0; i < n; i++)printf( " %d ", vec[i]); // imprimo todo el vector
    printf("\n");
}
 
void desplazar(int  vec[],int n, const int buscado) { // desplaza todos los valores del vector
    int aux; // auxiliar para desplazar valor al final del vector luedo de correr todo el vector
    
    for (int i = 0; i < n; i++) {
        if (vec[i] == buscado) {
            aux = vec[i]; // guardo el valor en el auxiliar
            for (int j = i; j < 10; j++) vec[j] = vec[j + 1]; // desplazo todo el vector hasta el lugar del buscado
            vec[9] = aux; // llevo el valor al final del vector
        }
    }
}

