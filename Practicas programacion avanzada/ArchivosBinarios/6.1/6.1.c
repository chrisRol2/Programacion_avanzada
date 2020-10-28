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
*	Ejercicio: 1.	Hacer un programa que utilice una función principal que invoque a las siguientes funciones:
					•	Hacer una función grabarArch() que genere un archivo de enteros. 
					•	Hacer una función mostrarArch() que reciba el nombre de un archivo, lo lea y muertre los datos del mismo. 
					•	Hacer una función agregarAcumulado() que reciba el nombre de un archivo, y agregue al final de éste el resultado de sumar todos los valores que contiene. 
					•	Hacer una función ordenarArch() que reciba el nombre de un archivo y lo ordene utilizando el método optimizado de ordenamiento por burbujeo.
					•	Hacer una función buscarArch() que reciba el nombre de un archivo,  y un valor e indique en que posición se encuentra del archivo. En caso de no encontrarlo devolver un valor negativo. Usar método de búsqueda binaria.
					•	Hacer una función eliminarValor() que reciba el nombre de un archivo y un valor y permita eliminarlo de forma lógica del mismo.
					•	Hacer una función eliminarValor() que reciba el nombre de un archivo y un valor y permita eliminarlo de forma física del mismo.
*	ñ -> \xA4
*	° -> \xF8
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define SIZE 32
#define FILENAME "archivo"
// Declaro funciones
int grabarArch(char nombre[SIZE]);
int mostrarArch(char nombre[SIZE]);
int agregarAcumulado(char nombre[SIZE]);
int buscarArch(char nombre[SIZE], int buscado);
int ordenarArch(char nombre[SIZE]);
void eliminarValor(char nombre[SIZE], int buscado);
void eliminarValor1(char nombre[SIZE], int buscado);

void ingresarDato(int *dato, int min, int max);
int random(int minimo, int maximo);
void ordenar    (int vec[], int n);
void imprimir(int vec[], int n);


int main(void) {
	int buscado;
	srand(getpid());
	if( grabarArch(FILENAME) ) return -1;
	mostrarArch(FILENAME);
	printf("Buscado: ");
	ingresarDato(&buscado, 0, 999);
	printf("\tEl %d esta en la pos: %d\n",
		   buscado,
		   buscarArch(FILENAME, buscado)+1
	);
	ordenarArch(FILENAME);
	//eliminarValor(FILENAME, buscado);
	//printf("Buscado 2: ");
	//ingresarDato(&buscado, 0, 999);
	//eliminarValor1(FILENAME, buscado);

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

	agregarAcumulado(FILENAME);
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
int buscarArch(char nombre[SIZE], int buscado){
	FILE *archivo;
	int aux = NULL;
	archivo = fopen(nombre, "rb");
	if( archivo == NULL ) {
		puts("No se pudo abrir el archivo");
		return -1;
	}
	for( int i = 0; i < 10; i++ ) {
		fread(&aux, sizeof(int), 1, archivo);
		if( aux == buscado) {
			return i;
		}
	}
	return -2;
}
int ordenarArch(char nombre[SIZE]){
	int valor1,valor2,aux;
	valor1 = valor2 = aux = 0;
	FILE *archivo;
	archivo = fopen(nombre, "rb+");
	if( archivo == NULL ) {
		puts("No se pudo abrir el archivo");
		return 1;
	}

	for( int i = 0; i < 10; i++ ) {
		fseek(archivo, i, SEEK_SET);
		fread(&valor1, sizeof(int), 1, archivo);

		for( int j = i; j < 9 ; j++ ){
			fread(&valor2, sizeof(int), 1, archivo);
			printf("i: %d j: %d valor1: %d valor2: %d\n", i, j, valor1, valor2);
			if( valor1 > valor2 ) {
				//fseek(archivo, -1, SEEK_CUR);
				//fwrite(valor1, sizeof(int), 1, archivo);
				//fseek(archivo, i, SEEK_SET);
				//fwrite(valor1, sizeof(int), 1, archivo);
				//fseek(archivo, j, SEEK_SET);

			}
		}
	}
	fclose(archivo);
	mostrarArch(FILENAME);
	return 0;
}
void ordenar(int vec[], int n) {
	int aux;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (vec[i] > vec[j]) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}
void eliminarValor(char nombre[SIZE], int buscado){
	FILE *archivo;
	int aux[10];

	archivo = fopen(nombre, "rb+");
	if( archivo == NULL ) {
		puts("No se pudo abrir el archivo");
		return -1;
	}
	fread(aux, sizeof(int), 10, archivo);
	for( int i = 0; i < 10; i++ ) {
		if( aux[i] == buscado ) {
			aux[i] = -1;
		}
	}
	fseek(archivo, 0, SEEK_SET);
	fwrite(aux, sizeof(int),10, archivo);
	fclose(archivo);
	mostrarArch(FILENAME);
	}
void eliminarValor1(char nombre[SIZE], int buscado){
	FILE *archivo;
	FILE *temp;
	int aux[11];

	archivo = fopen(nombre, "rb+");

	if( archivo == NULL ) {
		puts("No se pudo abrir el archivo");
		return ;
	}

	fread(aux, sizeof(int), 11, archivo);
	buscado = buscarArch(FILENAME, buscado);
	for( int i = buscado; i < 10; i++ ) {
		aux[i] = aux[i+1];
	}
	//imprimir(aux, 10);
	
	
	fclose(archivo);
	rename("archivo","archivo32.bin");
	//mostrarArch(FILENAME);
	//remove(FILENAME);
}

int random(int minimo, int maximo) {

	return rand() % (maximo - minimo + 1) + minimo;
}
void ingresarDato(int *dato, int min, int max) {

	do {
		scanf("%d", dato);
		if( (*dato > max) || (*dato < min) )printf("\nDato fuera de rango.\n");
	} while( (*dato > max) || (*dato < min) );

}
void imprimir(int vec[], int n) {


	for (int i = 0; i < n; i++)printf("%d\n", vec[i]);

}