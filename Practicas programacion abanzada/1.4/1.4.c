/*
 *	File:	1.4.c
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
 *      4.	Realizar una función que reciba como parámetros día, mes y año indique si la fecha es un fecha gregoriana válida.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  // lib para usar standard input outpus
#include <stdbool.h> // lib para usar bool

// Declaro funciones
bool fecha_gregoriana(int dia, int mes, int anio);
bool  bisiesto(int year);

int main(void) {
    int dia, mes, anio;// declaro variables
    dia = mes = anio = 0; // inicializo
    //Solicito datos
    printf("Ingrese dia: "); scanf("%d", &dia);
    printf("Ingrese mes: "); scanf("%d", &mes);
    printf("Ingrese a%co: ", 164); scanf("%d", &anio);

    if (fecha_gregoriana(dia, mes, anio)) {
        printf("%d/%d/%d es fecha valida", dia, mes, anio);
    }
    else {
        printf("%d/%d/%d no es fecha valida", dia, mes, anio);
    }

    printf("\n"); system("PAUSE");
    return 0;

}
// 
bool fecha_gregoriana(int dia, int mes, int anio) { 
    volatile int mes_dia[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (bisiesto(anio))mes_dia[1] = 29; //Corroboro si es bisiesto
    if (dia <= mes[mes_dia - 1]) { // contolo que el dia exista en el calendario
        return true;
    }
    if (mes <= 12)return false;
    return false;
}

bool  bisiesto(int year) {

    if (year % 4 == 0) {
        if ((year % 100 == 0) && (year % 400)) {
            return false;
        }
        return true;
    }
    return false;
}