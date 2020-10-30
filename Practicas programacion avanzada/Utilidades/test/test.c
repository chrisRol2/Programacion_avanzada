/*
•	Crear el archivo, ingresando los datos por teclado.
•	Borrar del archivo los registros de aquellos lotes que se encuentren vencidos, comparando la fecha de vencimiento de cada uno con una fecha testigo que se ingresa por teclado. Para borrar los registros es necesario generar un nuevo archivo que contenga solamente los lotes no vencidos, emitiendo además un listado por pantalla con los registros eliminados.
•	Generar e imprimir un listado con el código, el nombre y la cantidad de unidades en stock para cada medicamento, sin importar el lote al que pertenezca. El archivo no está ordenado, y los medicamentos son a lo sumo 130. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <time.h>


void crearArchivo(char nombreA[]);
void mostrarArchivo(char nombreA[]);
void ordenarBurbujaVectores(char nombreA[]);
int leerregistro(FILE * f, int numreg);
void grabarregistro(FILE * f, int numreg, int dato);

int main(void)
{
	char nombreArch[] = "prueba1.bin";

	// funcion para crear el archivo
	crearArchivo(nombreArch);

	// funcion para mostrar el archivo
	mostrarArchivo(nombreArch);

	// lo ordeno
	ordenarBurbujaVectores(nombreArch);

	// funcion para mostrar el archivo
	mostrarArchivo(nombreArch);

	system("pause");
	return 0;


}

void ordenarBurbujaVectores(char nombreA[])
{
	FILE* arch;
	int cantreg;
	int dato1;
	int dato2;
	int i, j;

	// si lo abro con rb+, el archivo tiene que existir y puedo leerlo y escribirlo
	arch=fopen(nombreA, "rb+");
	if (arch==NULL){
		puts("Error");

	}

	// Dos pasos para obtener la cantidad de registros totales del archivo
	fseek(arch, 0, SEEK_END); //ubico indicador al final
	cantreg = ftell(arch)/sizeof(int); //obtengo cantidad de reg.

									   //Metodo de burbuja
	for(i=0;i<cantreg-1;i++)
	{
		for (j=i+1;j<cantreg;j++)
		{
			dato1=leerregistro(arch,i);
			dato2=leerregistro(arch,j);
			if (dato1>dato2)
			{
				grabarregistro(arch,j,dato1);
				grabarregistro(arch,i,dato2);
			}
		}
	}

	fclose(arch);

}

int leerregistro(FILE * f, int numreg)
{
	int dato;
	// con fseek me posiciono en el numero de registro que me piden
	fseek(f, numreg * sizeof(int),SEEK_SET);
	// una vez posicionado, leo con fread
	fread(&dato, sizeof(int), 1, f);
	return dato;
}

void grabarregistro(FILE * f, int numreg, int dato)
{
	// con fseek me posiciono en el numero de registro que me piden
	fseek(f, numreg * sizeof(int),SEEK_SET);
	// una vez posicionado, escribo con fwrite
	fwrite(&dato,sizeof(int),1,f);
}

void mostrarArchivo(char nombreA[])
{
	// 1) Creo la variable para manejar el archivo
	FILE * archivoC;
	int aux;

	// 2) Abrir el archivo (en este caso lo abro para lectura (r) y es binario (b)
	archivoC = fopen(nombreA, "rb");
	if (archivoC == NULL)
	{
		printf("no se puede crear el archivo");
		return 1;
	}

	// 3) Proceso el archivo

	fread(&aux, sizeof(int), 1, archivoC);
	while(!feof(archivoC))
	{
		printf("Entero: %d\n", aux);
		fread(&aux, sizeof(int), 1, archivoC);
	}

	// Cierro el archivo
	fclose(archivoC);
}

void crearArchivo(char nombreA[])
{
	int i;
	int aux;

	// 1) Creo la variable para manejar el archivo
	FILE * archivo1;

	// 2) Abrir el archivo (en este caso lo abro para escritura (w) y es binario (b)
	archivo1 = fopen(nombreA, "wb");
	if (archivo1 == NULL)
	{
		puts("no se puede crear el archivo");
		return 1;
	}

	for (i = 0; i < 100; i++)
	{
		aux = rand()%(1000);
		fwrite(&aux, sizeof(int), 1, archivo1);
	}

	// 4) Cierro el archivo
	fclose(archivo1);
}