#include <stdio.h>
#include <stdlib.h>



void reemplazar(char palabra[], char cToReplace, char cNew);
int contPalabras(char cadena[]);



int main()
{
    char palabra[40];
    char palabrainvertida[40];
    char palabras[] = " Hacer una   funcion que devuelva la cantidad de palabras (separados por uno o mas espacios) que tiene una frase";



    int cantpalabras;



    cantpalabras = contPalabras(palabras);



    printf("La cantidad de palabras es %d\n", cantpalabras);



    return 0;
}



int contPalabras(char cadena[])
{
    int longvector = 0;
    int i;
    int contador_palabras = 0;
    int vengo_de_un_espacio = 0; // En cero: NO vengo de un espacio



    while (cadena[longvector] != '\0')
    {
        longvector++;
    }



    printf("La longitud del vector es %d\n", longvector);



    if (longvector > 0)
    {
        if (cadena[0] == ' ')
        {
            vengo_de_un_espacio = 1;
        }
    }



    for (i = 0; i < longvector; i++)
    {
        if (cadena[i] == ' ')
        {
            if (vengo_de_un_espacio == 0)
            {
                contador_palabras++;
                vengo_de_un_espacio = 1;
            }
        }
        else
        {
            vengo_de_un_espacio = 0;
        }
    }



    return contador_palabras;
}



void reemplazar(char palabra[], char cToReplace, char cNew)
{
    int contador = 0;
    int i = 0;



    while (palabra[contador] != '\0')
    {
        contador++;
    }



    for (i = 0; i <= (contador - 1); i++)
    {
        if (palabra[i] == cToReplace)
        {
            palabra[i] = cNew;
        }
    }
}
