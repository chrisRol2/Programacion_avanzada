/*
*	File:   4.7.c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 7.	Hacer una función que permita insertar una sub-cadena en
*                       una cadena a partir de una posición dada.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// Declaro funciones
void insertar(char cadena[], char sub_cadena[], int pos);
void concatenarDer(char cadena1[], char *cadena2);
int main(void) {
    char cadena[200] = "Hola que tal?";
    char sub_cadena[200] = ", che ";
    int pos;
   /* printf("Ingresar cadena: "); scanf("%[^\n]", cadena);
    printf("\n");
    printf("\nIngresar sub-cadena: "); scanf("%[^\n]", sub_cadena);
    printf("Ingresar posicion: "); scanf("%d", &pos);*/
    insertar(cadena, sub_cadena,12);
    printf("\n"); system("PAUSE");
    return 0;
}
void insertar(char cadena[], char sub_cadena[], int pos) {
    char aux[200] = "";
    int control = 0;
    for( int i = 0; i <= strlen(cadena) + strlen(sub_cadena); i++) {
        if( i == pos ) {
            sprintf(aux, "%s%s", aux,sub_cadena );
            i += strlen(sub_cadena);
        }
        else {
            sprintf(aux, "%s%c", aux, cadena[control]);
            control++;
        }

    }
    printf("\n%s", aux);
}

void concatenarDer(char cadena1[], char *cadena2) {
    sprintf(cadena1, "%s%s", cadena1, cadena2);
}