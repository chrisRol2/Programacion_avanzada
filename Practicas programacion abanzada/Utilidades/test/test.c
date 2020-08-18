//EJERCICIO TIPOS DE TRIANGULOS

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>   
#include <time.h>

//"N" Si no corresponden a las medidas de un triangulo
//"E" equilatero, "I" isoseles, "S" escaleno
//** Un lado de un triángulo es siempre menor a la suma de los otros dos lados (a < b + c),
//pero mayor que su diferencia (a > b - c).*


// prototipo de la funcion
char TipoDeTriangulo(int n1, int n2, int n3);

// LA funcion
char TipoDeTriangulo(int n1, int n2, int n3) {
    char tipo;
    //verificar si es un triangulo
    if ((n1 < (n2 + n3)) && (n2 < (n1 + n3)) && (n3 < (n1 + n2))) {
        if ((n1 > (n2 - n3)) && (n2 > (n1 - n3)) && (n3 > (n1 - n2))) {
            if (n1 == n2 && n2 == n3) //equilatero
            {
                tipo = 'E';
            } else {
                if ((n1 != n2) && (n2 != n3) && (n1 != n3))//escaleno
                {
                    tipo = 'S';
                } else {
                    tipo = 'I';

                }
            }
        }
        return tipo;
        //return tipo;
    } else {
        return 'f';
    }

}


//el programa
int main(void) {
    int n1;
    int n2;
    int n3;
    char tipo_triangulo;


    printf("Ingrese lado 1 del triangulo ");
    scanf("%d", &n1);
    printf("Ingrese lado 2 del triangulo ");
    scanf("%d", &n2);
    printf("Ingrese lado 3 del triangulo ");
    scanf("%d", &n3);
    printf("------------------------------------------------\n");
    tipo_triangulo = TipoDeTriangulo(n1, n2, n3);
    printf("Los datos ingresados son:\n");
    printf("Lado 1: %d\n", n1);
    printf("Lado 2: %d\n", n2);
    printf("Lado 3: %d\n", n3);
    printf("------------------------------------------------\n");
    printf("El tipo de triangulo es: %c\n", tipo_triangulo);


    system("pause");

    return 0;
}