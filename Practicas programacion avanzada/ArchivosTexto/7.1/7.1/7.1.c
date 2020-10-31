/*
*	File:   6..c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 1.	Hacer una función que permita eliminar todos los comentarios 
                    de una o varias líneas de un programa fuente escrito en lenguaje “C”,.

*
*	ñ -> \xA4
*	° -> \xF8
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define FILENAME "test.c"
// Declaro funciones
void eliminarLinea(char fileName[], char caracter);

int main(void) {

    eliminarLinea(FILENAME,'/');
    printf("\n"); system("PAUSE");
    return 0;
}
void eliminarLinea(char fileName[], char caracter) {
    FILE* archivo;
    char lectura;
    archivo=fopen(fileName, "rt+");
    if (archivo==NULL){
        puts("Error");
    }
    lectura = fgetc(archivo);
    while( !feof(archivo) ) {
        if( lectura == '/' ) {
            lectura = fgetc(archivo);
            if( lectura == '/' ) {
                printf("eliminando");
                fwrite("hola", sizeof("hola"), 1, archivo);
            }
        }
    lectura = fgetc(archivo);
    }
    fclose(archivo);
}