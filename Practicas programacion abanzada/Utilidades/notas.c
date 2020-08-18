int vec[10] = { 4,5,1,0,9,6,7,24,9,2 };

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Declaro funciones
char Triangulo_Valido(int A, int B, int C); //Funcion para corroborar validez de los  datos
char triangulo(int A, int B, int C);        //Funcion para identificar triangulo
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

char Triangulo_Valido(int A, int B, int C) {

    if ((A + B) > C) {
        if ((A + C) > B) {
            if ((B + C) > A) {
                return 1;
            }
        }
    } else return 0;
}
char triangulo(int A, int B, int C) {

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