/*
 *	File:	1.6.c
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
 *          6.	La tarifa de un videoclub  para el alquiler de sus videos es: Dibujos = $2; Estrenos = $3; Otros = $2.5. Además cobra por devolución tardía $1 por el primer día y
 *                  $0.5 por cada no de los días siguientes. Realizar una función que devuelva el alquiler a pagar por un cliente, sabiendo que recibe como parámetros el tipo de video y 
 *                  la cantidad de días desfasados en devolución. Si la devolución es anterior al día de devolución recibirá un entero negativo.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define DIBUJOS     2
#define ESTRENOS    3
#define OTROS       2.5
#define DIBUJO      1
#define ESTRENO     2
#define OTRO        3

// Declaro funciones
float calc_precio(int tipo, int dias);

int main(void) {

    int tipo_video;
    int dias_atrazo;
    float precio = 0;
    printf("Seleccione tipo de video:\n");
    printf("\t1. Dibujos\n\t2. Estrenos\n\t3. Otros\nTipo: ");
    scanf("%d", &tipo_video);
    printf("Ingrese dias de atrazo: "); scanf("%d", &dias_atrazo);
    
  
    precio = calc_precio(tipo_video, dias_atrazo);
    if (precio > 0)printf("El monto a abonar es de: %.2f$", precio);
    else
    {
        switch (tipo_video) {
            case DIBUJO:
                precio = DIBUJOS;
                break;
            case ESTRENO:
                precio = ESTRENOS;
                break;
            case OTRO:
                precio = OTROS;
                break;
            default:
                printf("tipo erroneo");
                return -2;
                break;
        }
        printf("No hay dia de atrasos, el monto a abonar es de: %.2f", precio);
    }

    printf("\n"); system("PAUSE");
    return 0;
}

float calc_precio(int tipo, int dias) {
    float precio = 0;
    
    if (dias != 0) {
        switch (tipo) {
            case DIBUJO:
                precio = DIBUJOS;
                break;
            case ESTRENO:
                precio = ESTRENOS;
                break;
            case OTRO:
                precio = OTROS;
                break;
            default:
                printf("tipo erroneo");
                return -2;
                break;
        }
        
        precio++;
        precio += ((float)dias - 1.0) * 0.5;
        return precio;
         
    }
        
    return -1;
}