/*
*	File:   6.1.c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 1.	Hacer un programa que utilice una funci�n principal que invoque a las siguientes funciones:
					�	Hacer una funci�n grabarArch() que genere un archivo de enteros. 
					�	Hacer una funci�n mostrarArch() que reciba el nombre de un archivo, lo lea y muertre los datos del mismo. 
					�	Hacer una funci�n agregarAcumulado() que reciba el nombre de un archivo, y agregue al final de �ste el resultado de sumar todos los valores que contiene. 
					�	Hacer una funci�n ordenarArch() que reciba el nombre de un archivo y lo ordene utilizando el m�todo optimizado de ordenamiento por burbujeo.
					�	Hacer una funci�n buscarArch() que reciba el nombre de un archivo,  y un valor e indique en que posici�n se encuentra del archivo. En caso de no encontrarlo devolver un valor negativo. Usar m�todo de b�squeda binaria.
					�	Hacer una funci�n eliminarValor() que reciba el nombre de un archivo y un valor y permita eliminarlo de forma l�gica del mismo.
					�	Hacer una funci�n eliminarValor() que reciba el nombre de un archivo y un valor y permita eliminarlo de forma f�sica del mismo.
*	� -> \xA4
*	� -> \xF8
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 32
#define FILENAME "archivo.bin"
// Declaro funciones
int grabarArch(char nombre[SIZE]);
int mostrarArch(char nombre[SIZE]);
int agregarAcumulado(char nombre[SIZE]);
int ordenarArch(char nombre[SIZE]);
int buscarArch(char nombre[SIZE], int buscado);
void eliminarValor(char nombre[SIZE], int buscado);
void eliminarValor1(char nombre[SIZE], int buscado);

int random(int minimo, int maximo);

int main(void) {
	srand(getpid());
	if( grabarArch(FILENAME) ) return -1;
	mostrarArch(FILENAME);
	agregarAcumulado(FILENAME);
	mostrarArch(FILENAME);

	printf("\n"); system("PAUSE");
	return 0;
}

int grabarArch(char nombre[SIZE]){
	int entero;
	FILE *archivo;
	archivo = fopen(nombre, "wb");
	if( archivo == NULL ) {
		puts("No se pudo abrir el archivo");
		return 1;
	}
	for( int i = 0; i < 10; i++ ) {
		entero = random(0, 999);
		fwrite(&entero, sizeof(int), 1, archivo);
	}
	fclose(archivo);
}
int mostrarArch(char nombre[SIZE]){
	int entero=0;
	int suma = 0;
	FILE *archivo;
	archivo = fopen(nombre, "rb");
	if( archivo == NULL ) {
		puts("No se pudo abrir el archivo");
		return 1;
	}
	for( int i = 0; i < 10; i++ ) {
		fread(&entero, sizeof(int), 1, archivo);
		printf("entero: %d\n", entero);
	}
	fread(&suma, sizeof(int), 1, archivo);
	printf("Suma: %d\n\n", suma);
	fclose(archivo);
}
int agregarAcumulado(char nombre[SIZE]){
	int entero;
	int suma = 0;
	FILE *archivo;
	archivo = fopen(nombre, "ab+");
	if( archivo == NULL ) {
		puts("No se pudo abrir el archivo");
		return 1;
	}
	for( int i = 0; i < 10; i++ ) {
		fread(&entero, sizeof(int), 1, archivo);
		suma += entero;
	}
		
	fwrite(&suma, sizeof(int), 1, archivo);
	fclose(archivo);
}
int ordenarArch(char nombre[SIZE]){}
int buscarArch(char nombre[SIZE], int buscado){}
void eliminarValor(char nombre[SIZE], int buscado){}
void eliminarValor1(char nombre[SIZE], int buscado){}

int random(int minimo, int maximo) {

	return rand() % (maximo - minimo + 1) + minimo;
}