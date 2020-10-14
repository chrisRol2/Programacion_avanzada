#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct sfecha {??
int dia, mes, anio;
}??tfecha;



typedef struct sproducto {??



int codbarras[21];

char nombre[60];

float precio;

int stock;

tfecha fecha;



}??tprod;



void crearArchivo(char nombreA[]);



int main(void)

{??

char nombreArch[] = "prueba1.bin";



// 1) Creo la variable para manejar el archivo

FILE * archivoC;



tfecha t1;



// funcion para crear el archivo

crearArchivo(nombreArch);





// 2) Abrir el archivo (en este caso lo abro para lectura (r) y es binario (b)

archivoC = fopen(nombreArch, "rb");

if (archivoC == NULL)

{??

printf("no se puede crear el archivo");

return 1;

}??



// Proceso el archivo





// feof: es una funcion (que viene con C) y me devuelve verdadero

// cuando el archivo termino (cuando tengo que parar de leer)

// usando la negacion de foef (!feof) voy a entrar al while

// mientras que el archivo no haya terminado

//feof necesita una lectura previa de fread

fread(&t1, sizeof(tfecha), 1, archivoC);

while(!feof(archivoC))

{??

if (t1.dia>6)

{??

printf("Dia: %d\n", t1.dia);

}??



fread(&t1, sizeof(tfecha), 1, archivoC);

}??



// Cierro el archivo

fclose(archivoC);





system("pause");

return 0;





}??



void crearArchivo(char nombreA[])

{??

tfecha t1;



// 1) Creo la variable para manejar el archivo

FILE * archivo1;



// 2) Abrir el archivo (en este caso lo abro para escritura (w) y es binario (b)

archivo1 = fopen(nombreA, "wb");

if (archivo1 == NULL)

{??

puts("no se puede crear el archivo");

return 1;

}??



printf("Ingrese Dia ? (-1 para terminar)");

scanf("%d", &t1.dia);

while (t1.dia != -1)

{??

t1.mes = 3; t1.anio = 2020;

fwrite(&t1, sizeof(tfecha), 1, archivo1);

printf("Ingrese Dia ? (-1 para terminar)");

scanf("%d", &t1.dia);

}??



// 4) Cierro el archivo

fclose(archivo1);

}??


int selectorLetra = random(); // este random debe dar 0 o 1
if( selectorLetra )
  dato.TipoDePozo = 'G';
else 
  dato.TipoDePozo = 'P';