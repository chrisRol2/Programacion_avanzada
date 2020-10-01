/*
*	File:   5.4.c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 4.	Un supermercado desea contar con un programa que le permita registrar los datos de sus artículos.
        En el mismo no existen más de 1000 productos distintos. Realizar un programa ABM utilizando
        la estructura indicada en el punto 1.c, en el que los datos deberán estar ordenados por nombre. 
        Contemplar las siguientes funciones:  
    •	altaProd: parámetros recibidos serán el vector y la cantidad cargados hasta el momento. 
            Esta función deberá permitir cargar productos hasta que se llene el vector o hasta 
            que ingresen un nombre vacío en el campo nombre. 
    •	bajaProd: parámetros recibidos serán el vector y la cantidad cargados hasta el momento.
            Esta función deberá permitir ingresar un nombre y eliminar los datos del producto. 
    •	mostrarProductos: parámetros recibidos serán el vector y la cantidad cargados hasta el momento. 
            Esta función deberá permitir mostrar los datos de todos los productos del supermercado.
*	ñ -> \xA4
	° -> \xF8
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

typedef struct {
	int dia;
	int mes;
	int anio;

}fecha;

typedef struct {
	int hora;
	int minuto;
	int segundos;
}hora;
typedef struct {
	char codigoBarras[23];
	char nombre[100];
	float precio;
	fecha actualizacion;
}datoProducto;

// Declaro funciones

int fecha_gregoriana(fecha fecha);
int bisiesto(int year);
void ingresarDato(int *dato, int min, int max);
void ingresarDatoF(float *dato, int min, int max);
fecha ingresarFecha();
void concatenar(char origen, char destino[]);
int altaProd(datoProducto producto[]);
void bajaProd(datoProducto producto[],int *cantidad);
void mostrarProductos(datoProducto producto[],int cantidad);
void ingresarCod(char codigo[], int cantidad);
int isalldigits(char codigo[]);
int main(void) {
	datoProducto producto[1000];
	int cantidad;
	int decision;
	cantidad = altaProd(producto);
	mostrarProductos(producto, cantidad);

	printf("\n1. Eliminar producto.\n2. Salir.\n");
	ingresarDato(&decision, 1, 2);
	if( decision == 1 ) {
		bajaProd(producto, &cantidad);
		mostrarProductos(producto, cantidad);
	}

	printf("\n"); system("PAUSE");
	return 0;
}
int altaProd(datoProducto producto[]){
	int cantidad = 0;

	while( 1 ) {
		printf("\nIngrese nombre del producto: ");
		
		gets(producto[cantidad].nombre);

		if( !strcmp(producto[cantidad].nombre, "") )break;

		printf("\nIngrese precio: ");
		ingresarDatoF(&producto[cantidad].precio, 0, 32767);

	
		printf("Ingrese fecha de actualizacion\n");
		producto[cantidad].actualizacion = ingresarFecha();

		ingresarCod(&producto[cantidad].codigoBarras, 21);
		 
		cantidad++;

	}
	return cantidad;
}
void bajaProd(datoProducto producto[],int *cantidad){
	char buscado[100];
	int encontrado;
	datoProducto aux;
	getchar();
	while( 1 ) {
		printf("\nIngrese nombre del producto a eliminar: ");
		
		gets(buscado);
		if( strcmp(buscado, "") == 0 ) {
			puts("Saliendo...");
			break;
		}
		encontrado = 0;
		for( int i = 0; i < *cantidad + 1; i++ ) {
			if( strcmp(producto[i].nombre, buscado) == 0 ) {
				printf("Eliminando %s", buscado);
				*cantidad-=1;
				for( i; i < *cantidad; i++ ) {
					producto[i] = producto[i + 1];
				}
				encontrado = 1;
				break;
			}
		}
		if( encontrado == 0 )puts("Producto desconocido.");
	}
}
void mostrarProductos(datoProducto producto[], int cantidad) {
	char categoria1[4][25]= {"Codigo\t\t","Nombre\t","Precio\t","Fecha de"};
	char categoria2[4][25]= {"De barras\t","\t","\t","Actualizacion"};
	char categoria3[4][25]= {"Dia","Mes","A\xA4o"};
	int i;
	puts("\n");
	for( i = 0; i < 4; i++ )printf("%s\t", categoria1[i]);
	puts("");
	for( i = 0; i < 4; i++ )printf("%s\t", categoria2[i]);
	puts("");
	for( i = 0; i < 7; i++ )printf("\t");
	for( i = 0; i < 4; i++ )printf("%s\t", categoria3[i]);
	puts("");
	for( i = 0; i < 80; i++ )printf("-");
	puts("");
	for( i = 0; i < cantidad; i++ ) {
		printf("%s\t", producto[i].codigoBarras);
		printf("%s\t\t", producto[i].nombre);
		printf("%.2f\t\t", producto[i].precio);
		printf("%d\t", producto[i].actualizacion.dia);
		printf("%d\t", producto[i].actualizacion.mes);
		printf("%d\n", producto[i].actualizacion.anio);
	}
	puts("");
	for( i = 0; i < 80; i++ )printf("-");
}

int isalldigits(char codigo[]) {
	int resultado = 1;
	int i;
	for( i = 0; i < strlen(codigo); i++ ) {
		if( !isdigit(codigo[i]) ) {
			resultado = 0;
			
			break;
		}
	}
	
	return resultado;
}
void ingresarCod(char codigo[], int cantidad) {
	int digitos;
	getchar();
	
	do {
		printf("Ingrese codigo de barras(21): ");
		gets(codigo);
		digitos = isalldigits(codigo);
		if( !digitos) {
			puts("EL codigo debe ser numerico.");
		}
	} while( !digitos );

	if( strlen(codigo) < 21 ) {
		while( strlen(codigo) < 21 ) {
			concatenar('0', codigo);
		}

	}
}
int fecha_gregoriana(fecha fecha) {

	volatile int mes_dia[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if( bisiesto(fecha.anio) )mes_dia[1] = 29; //Corroboro si es bisiesto
	if( fecha.dia <= fecha.mes[mes_dia - 1] ) { // contolo que el dia exista en el calendario
		return true;
	}
	if( fecha.mes <= 12 )return false;
	return false;
}
int bisiesto(int year) {

	if (year % 4 == 0) {
		if ((year % 100 == 0) && (year % 400)) {
			return false;
		}
		return true;
	}
	return false;
}
void ingresarDato(int *dato, int min, int max) {

	do {
		scanf("%d", dato);
		if( (*dato > max) || (*dato < min) )printf("\nDato fuera de rango.\n");
	} while( (*dato > max) || (*dato < min) );

}
void ingresarDatoF(float *dato, int min, int max) {

	do {
		scanf("%f", dato);
		if( (*dato > max) || (*dato < min) )printf("\nDato fuera de rango.\n");
	} while( (*dato > max) || (*dato < min) );

}
fecha ingresarFecha() {
	fecha fecha1;
	do {
		printf("\tA\xA4o: ");
		ingresarDato(&fecha1.anio, -2020, 3000);
		printf("\tMes: ");
		ingresarDato(&fecha1.mes, 1, 12);
		printf("\tDia: ");
		ingresarDato(&fecha1.dia, 1, 31);
		if( !fecha_gregoriana(fecha1) ) {
			printf("\tFecha no gregoriana. Vuelva a intentarlo.\n");
		}
	} while( !fecha_gregoriana(fecha1) );
	return fecha1;
}
void concatenar(char origen, char destino[]) {

	int i;
	char aux[200]=" ";

	for( i = strlen(destino) + 1; i >= 0; i-- ) { // recorro el vector  desde el final incluyendo el '\0'
		destino[i + 1] = destino[i]; // desplazo el vector una posicion hacia adelante
	}
	destino[0] = origen; // agrego mi caracter a agregar al principio del vector

}