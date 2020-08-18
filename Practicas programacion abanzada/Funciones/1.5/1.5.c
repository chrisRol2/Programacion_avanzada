/*
 *	File:	1.5.c
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
 *          5.	Realizar una función que reciba como parámetros día, mes, año y una cantidad de días, y devuelva la fecha resultante de sumar a la fecha recibida la cantidad de días. 
 *                  La fecha resultante debe ser una fecha gregoriana.
 *
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
int mes_dia[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Declaro funciones
bool bisiesto(int year);
bool fecha_gregoriana(int dia, int mes, int anio);
void fecha_futura(int *dia, int *mes, int *anio, int futuro);

int main(void) {

    int dia, mes, anio;// declaro variables
    int  cantida_dias = 0;
    dia = mes = anio = 0; // inicializo
    //Solicito datos
    do {
        printf("Ingrese dia: "); scanf("%d", &dia);
        printf("Ingrese mes: "); scanf("%d", &mes);
        printf("Ingrese a%co: ", 164); scanf("%d", &anio);
    } while (!fecha_gregoriana(dia, mes, anio));

    printf("Ingrese dias en el futuro: "); scanf("%d", &cantida_dias);
    
    printf("%d dias despues del %d/%d/%d es el: ",cantida_dias, dia, mes, anio);
    fecha_futura(&dia, &mes, &anio,cantida_dias); 
    printf("%d/%d/%d", dia, mes, anio);
    
    printf("\n"); system("PAUSE");
    return 0;
}

void fecha_futura(int *dia, int *mes, int *anio, int futuro) {
    int resto_mes = mes_dia[*mes] - *dia;
    printf("%d", resto_mes);

    
    
}


bool fecha_gregoriana(int dia, int mes, int anio) {
    if (mes >= 12)return false;
    if (bisiesto(anio))mes_dia[1] = 29; //Corroboro si es bisiesto
    else mes_dia[1] = 28;
    if (dia <= mes[mes_dia - 1]) { // contolo que el dia exista en el calendario
        return true;
    }
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