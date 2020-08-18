/*
 *	File:	1.1.c
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
 *		1.	Realizar una función que reciba tres números y devuelva “N” si estos no corresponden
 *		a las medidas de los lados de un triángulo, “E” si corresponden a un triángulo equilátero,
 *		“I” si corresponden a un triángulo isósceles y “S” si corresponde a un triángulo escaleno.
 *		No usar operadores lógicos.
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Declaro funciones
 char Triangulo_Valido( int A,  int B,  int C); //Funcion para corroborar validez de los  datos
 char triangulo( int A,  int B,  int C);        //Funcion para identificar triangulo
int main(void) {

    int a, b, c; // declaro variables
    a = b = c = 0; // inicializo variables

    // pido los valores
    printf("Ingrese A: "); scanf("%d", &a);
    printf("Ingrese B: "); scanf("%d", &b);
    printf("Ingrese C: "); scanf("%d", &c);

    //Guardo el resultado
    char res = triangulo(a, b, c);
    // Imprimo el resultado
    printf("Resultado: %c\n", res);

    system("PAUSE");
    return 0;

}

 char Triangulo_Valido( int A,  int B,  int C) {

     if ((A + B) > C) {
         if ((A + C) > B) {
             if ((B + C) > A) {
                 return 1;
             }
         }
     }
     else return 0;
}
 char triangulo( int A,  int B,  int C) {

    if (Triangulo_Valido(A, B, C)) {

        if (A == B) {
            if (B == C) {
                return 'E';
            } else return 'I';
        } else {
            if (A == C) {
                if (C != B) {
                    return 'I';
                }
            } else if (C == B) {
                return 'I';
            } else return 'S';

        }
    } else return 'N';
}