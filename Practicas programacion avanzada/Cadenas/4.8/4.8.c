/*
*	File:   4.8.c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 8.	Hacer una función que permita eliminar una sub-cadena a 
*                            partir de una posición y un tamaño dados.
*
*		
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// Declaro funciones
void remover(char cadena[], int pos, int tamano);
int main(void) {
    char cadena[200] = "8.Hacer una funcion que permita eliminar una sub-cadena a partir de una posicion y un tamano dados.";
    int pos = 4;
    int tamano = 10;
    printf("%s", cadena);

    remover(cadena, pos, tamano);
    printf("\n\n%s", cadena);


    printf("\n\n"); system("PAUSE");
    return 0;
}
void remover(char cadena[], int pos, int tamano){
    char aux[200] = "";
    int control = 0;
    for( int i = 0; i <= strlen(cadena); i++) {
        if( (i >= pos) && (i < pos+tamano) ) {
   
        }
        else {
//			strcat(aux, cadena[i]);
            sprintf(aux, "%s%c", aux, cadena[i]);
        }
    }
	strcpy(cadena, aux);
    //sprintf(cadena, "%s", aux);
}