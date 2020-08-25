/*
*	File:   4..c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 9.	Hacer una función que permita convertir números enteros 
*                    entre 0 y 999 a palabras. Para ello se recibe como parámetros
*                    el número y una cadena. ¿En qué cambiaría su programa si el rango 
*                    de valores fuese diferente? 
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// Declaro funciones
void separar(int numero, int *centena, int *decena, int *unidad);
void imprimirLetras(int centenas, int decenas, int unidades);
char centenasLetras[11][15] = { "","Ciento","Docientos","Trecientos","Cuatrocientos","Quinientos","Seiscientos","Setecientos","Ochocientos","Novecientos","Cien"};
char unidadesLetras[11][15] = { "","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve"};
char diezLetras[11][15] = {"", "diez","doce","trece","catorce","quince"};
char decenasLetras[12][15] = { "","dieci","veinti","treinta","cuarenta","cincuenta","sesenta", "ochenta","noventa" };
int main(void) {
    int entrada;
    int centenas, decenas, unidades;
    centenas = decenas = unidades = 0;
    do {

    printf("Ingrese valor: "); scanf("%d", &entrada);

    } while( (entrada > 999) || (entrada < 0) );

    separar(entrada, &centenas, &decenas, &unidades);
    imprimirLetras(centenas, decenas, unidades);


    printf("\n"); system("PAUSE");
    return 0;
}

void imprimirLetras(int centenas, int decenas, int unidades) {
    if( (centenas == 1) && ((decenas == 0) && (unidades == 0)) )centenas = 10;
    if((decenas == 10))

    printf("%s%s%s", centenasLetras[centenas], decenasLetras[decenas], unidadesLetras[unidades]);

}

void separar(int numero, int *centena, int *decena, int *unidad) {

    *unidad = numero % 10;
    *decena = ((numero % 100) - *unidad)/10;
    *centena = ((numero ))/100;

}