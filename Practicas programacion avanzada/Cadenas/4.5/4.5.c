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
 *	Ejercicio:  5.	Hacer una función que permita insertar en una secuencia de dígitos 
                        los caracteres guión cada 8 dígitos a partir del cuarto dígito, 
                        y un espacio cada 8 dígitos a partir del octavo dígito.
                        Si la cantidad de dígitos no es múltiplo de ocho agregar delante
                        de la cadena caracteres ‘0’ hasta que la misma sea múltiplo de 8.

	Ejemplos:	472348237388539055823012	->	4723-4823 7388-5390 5582-3012
		8237388539055823012		->	0000-0823 7388-5390 5582-3012

 *
 *
 *
 */



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
 // Declaro funciones
 void insertarGuion(char cadena[200]);
 void concatenar(char cadena1[],char cadena2[]);
 void concatenarDer(char cadena1[],char* cadena2);
int main(void) {
    char cadena[200];
    printf("Ingresar cadena: "); scanf("%s", cadena);


    insertarGuion(cadena);
  //  printf("\nCadena resultante: %s ,de largo: %d",cadena,(strlen(cadena)));

    printf("\n"); system("PAUSE");
    return 0;
}

void insertarGuion(char cadena[200]) {
 int resto = strlen(cadena) % 8;
 int guion = 3, espacio = 7;
 char aux[200]="";
    while( resto != 0 ) {
        concatenar("0",cadena);
        resto = strlen(cadena) % 8;
    }
    for ( int i = 0; i < strlen(cadena); i++ ) {
        espacio++;
        guion++;
        if( !(guion % 8) )concatenarDer(aux, "-");
        if( !(espacio % 8) && espacio != 8 )concatenarDer(aux, " ");
        concatenarDer(aux, &cadena[i]);
    }
    printf("Cadena: %s", aux);
    for( int i = 0; i < strlen(aux); i++ )cadena[i] = aux[i];
}

void concatenarDer(char cadena2[], char *cadena1) {
//    printf("\ncaracter1: %c\tcadena2: %s", *cadena1, cadena2);
    sprintf(cadena2, "%s%c", cadena2, *cadena1);

}


void concatenar(char cadena1[], char cadena2[]) {
  //  printf("\ncadena1: %s\ncadena2: %s\n", cadena1, cadena2);
    char aux[200];
    sprintf(aux, "%s", cadena2);
    sprintf(cadena2, "%s%s", cadena1, aux);
}