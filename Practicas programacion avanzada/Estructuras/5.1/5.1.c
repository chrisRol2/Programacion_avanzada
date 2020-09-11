/*
*	File:   5.1.c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 1.	Definir estructuras para almacenar los siguientes tipos de datos:
    a)	fecha
    b)	hora
    c)	Datos de un producto
        código de barras (21 dígitos)
        nombre  (cadena de caracteres)
        precio unitario (número real)
        stock (número entero)
        fecha de actualización de stock (día, mes, año)
*
*		
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Declaro funciones

int main(void) {
    typedef struct {
        int dia;
        int mes;
        int anio;

    }fecha;
    typedef struct {
        int hora;
        int minuto;
        int segundos;
    }hora;

    typedef struct {
        char codigoBarras[21];
        char nombre[100];
        float precio;
        fecha actualizacion;
    }datoProducto;


    printf("\n"); system("PAUSE");
    return 0;
}