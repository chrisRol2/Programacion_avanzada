/*
 *	File:	1.7.c
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
 *       7.	Una editorial determina el precio de un libro seg�n la cantidad de p�ginas que contiene. El costo b�sico del libro es de $5, m�s el precio $0,02 por p�gina con
 *          encuadernaci�n r�stica. Si el n�mero de p�ginas supera las 300 la encuadernaci�n debe ser en tela, lo que incrementa el costo en $3. Adem�s, si el n�mero de p�ginas
 *          sobrepasa las 600 se hace necesario un procedimiento especial de encuadernaci�n que incrementa el costo en $8. Realizar una funci�n que devuelva el costo de un libro
 *          dado el n�mero de p�ginas.
 *
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
// Declaro funciones
float  precio(int paginas);
int main(void) {
    int paginas;
    printf("Inserte cantidad de paginas: "); scanf("%d", &paginas);

    printf("El  valor del libro es de: %.2f$", precio(paginas));

    printf("\n"); system("PAUSE");
    return 0;
}

float  precio(int paginas) {
    float  valor = 5;

    if (paginas > 300)valor += 3; // si es mayor a 300 paginas sumo 3
    if (paginas > 600)valor += 8; // si es mayor a 600 paginas sumo 8 mas
    valor += (float)paginas * 0.5;  // calculo el valor segun la cantidad de paginas y lo sumo al costo fijo
    return valor;
}