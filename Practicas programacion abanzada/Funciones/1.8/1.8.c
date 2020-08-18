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
 *          8.	Un banco necesita para sus cajeros automáticos un programa que lea una cantidad de dinero e informe la cantidad mínima de billetes a entregar, 
 *                considerando que existen billetes de $100, $50, $10, $5 y $1. Realizar una función que calcule dichas cantidades.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
// Declaro funciones
void cant_billetes (int *_100, int* _50, int* _10, int* _5, int* _1, int _dinero);
int main(void) {
    int *cant_100 = 0;
    int cant_50  = 0;
    int cant_10  = 0;
    int cant_5   = 0;
    int cant_1   = 0;
    int dinero   = 0;
    printf("Ingrese cantidad de dinero: "); scanf("%d", &dinero);

    cant_billetes(&cant_100, &cant_50, &cant_10, &cant_5, &cant_1,dinero);

    printf("----------------\n");
    printf("\nBillete |Cantidad\n");
    printf("100\t| %d\n", cant_100);
    printf(" 50\t| %d\n", cant_50);
    printf(" 10\t| %d\n", cant_10);
    printf("  5\t| %d\n", cant_5);
    printf("  1\t| %d\n", cant_1);
    
    printf("\n"); system("PAUSE");
    return 0;
}

void cant_billetes(int* _100, int* _50, int* _10, int* _5, int* _1, int _dinero){
    
    if (_dinero >= 100) {
        *_100 = _dinero / 100;
        _dinero = _dinero - (*_100 * 100);
    }
    if (_dinero >= 50) {
        *_50 = _dinero / 50;
        _dinero = _dinero - (*_50 * 50);
    }
    if (_dinero >= 10) {
        *_10 = _dinero / 10;
        _dinero = _dinero - (*_10 * 10);
    }
    if (_dinero >= 5) {
        *_5 = _dinero / 5;
        _dinero = _dinero - (*_5 * 5);
    }
    if (_dinero >= 1) {
        *_1 = _dinero / 1;
        _dinero = _dinero - (*_1 * 1);
    }
}
