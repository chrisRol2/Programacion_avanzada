/*
*	File:   4.6.c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 6.	Hacer una función strNcpy() que permita extraer una sub-cadena,
*                       indicando la posición inicial y la cantidad de caracteres. 
*                       Ejemplo, dada la secuencia: “El número de teléfono es 4356-7890.
*                       “ extraer la sub-cadena que comienza en la posición 26, 
*                       la cantidad de 9 caracteres.
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Declaro funciones
void strNcpy(char destino[], char origen[], int inicio, int cantidad);
int main(void) {
    char cadena[100] = "";
    char sub_cadena[50] = "";
    printf("Ingresar cadena: "); scanf("%[^\n]", cadena);

    strNcpy(sub_cadena,cadena, 25, 9);
    printf("Sub-cadena: %s", sub_cadena);

    printf("\n"); system("PAUSE");
    return 0;
}

void strNcpy(char destino[], char origen[], int inicio, int cantidad) {
    for( int i = inicio; i < inicio + cantidad; i++ )destino[i - inicio] = origen[i];
}