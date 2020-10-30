/*
*	File:   6..c
*	Author:	Christopher Roldan Sanchez
*	Mail:	Christopher_Rol@hotmail.es
*	Date:
*	Description:
*
*	Materia:		Programacion avanzada
*	Universidad:	Universidad Argentina De La Empresa (UADE)
*	Docente:        Iervasi Scokin, Juan Jose
*
*	Ejercicio: 2.	Un laboratorio de especialidades medicinales posee un archivo en disco cuyos registros contienen los siguientes campos:

    Lote: 5 caracteres
    Código de barras: 21 caracteres
    Nombre: 40 caracteres
    Costo: número real
    Stock: Número entero: Cantidad de envases almacenados
    Mes, Año: Enteros: Mes y año de vencimiento de la medicación

    El archivo contiene un registro por cada lote, es decir que pueden existir varios registros para un mismo medicamento si éstos pertenecen a lotes distintos. Se solicita desarrollar uno o más programas para:

    •	Crear el archivo, ingresando los datos por teclado.
    •	Borrar del archivo los registros de aquellos lotes que se encuentren vencidos, comparando la fecha de vencimiento de cada uno con una fecha testigo que se ingresa por teclado. Para borrar los registros es necesario generar un nuevo archivo que contenga solamente los lotes no vencidos, emitiendo además un listado por pantalla con los registros eliminados.
    •	Generar e imprimir un listado con el código, el nombre y la cantidad de unidades en stock para cada medicamento, sin importar el lote al que pertenezca. El archivo no está ordenado, y los medicamentos son a lo sumo 130. 

    Ejemplo:

    CODIGO	NOMBRE		CANTIDAD EN STOCK
    10000		TERRAMICINA			xxxx
    10001		CARBOPLAT			yyyy
    .....		............		....
*	ñ -> \xA4
*	° -> \xF8
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
typedef struct {
    int dia;
    int mes;
    int anio;
}fecha;
typedef struct {
    char nombre[40];
    char codBarras[21];
    float costo;
    char lote[5];
    int stock;
    fecha vencimiento;
}especialidades;
#define SIZE 32
#define FILENAME "archivo.bin"
#define NEWFILENAME "Sin Vencidos.bin"
#define true 1
#define false 0
#define MAXFLOAT (3.4*pow(10,38))
#define MAXINT 32767
#define AGREGAR 1
#define QUITAR 2
#define ELIMINAR 3
#define MOSTRAR 4
#define SALIR 0
// Declaro funciones
void ingresarDato(int *dato, int min, int max);
void ingresarDatoF(float *dato, int min, int max);
fecha ingresarFecha();
void ingresarCod(char codigo[], int cantidad);
void concatenar(char origen, char destino[]);
int mayor(fecha fecha1, fecha fecha2);
/*
int fecha_gregoriana(fecha fecha);
int bisiesto(int year);
void ingresarCod(char codigo[], int cantidad);
int isalldigits(char codigo[]);
*/

int crearArchivo(char filename[]);
int agregarRegistro(char filename[]);
int quitarRegistro(char filename[]);
int quitarVencidos(char filename[], char newFileName[]);
int mostrarArchivo(char filename[]);
int main(void) {
    int menu = -1;
    crearArchivo(FILENAME);
    while( menu != 0 ) {
        printf("\nSeleccione accion:\n");
        printf("\t1. Agregar\n");
        printf("\t2. Quitar\n");
        printf("\t3. Eliminar Vencidos\n");
        printf("\t4. Mostrar listado\n");
        printf("\t0. Salir\n");
        printf("Opcion: ");
        ingresarDato(&menu, 0, 4);
        switch( menu ) {
            case AGREGAR:
                agregarRegistro(FILENAME);
                break;
            case QUITAR:
                quitarRegistro(FILENAME);
                break;
            case ELIMINAR:
                quitarVencidos(FILENAME,NEWFILENAME);
                break;
            case MOSTRAR:
                mostrarArchivo(FILENAME);
                break;
            default: 
                printf("Saliendo...");
                break;
        }
    }
   // printf("\n"); system("PAUSE");
    return 0;
}
int crearArchivo(char filename[]){
    FILE * archivo;
    archivo = fopen(filename, "ab");
    if (archivo == NULL){
        puts("no se puede crear el archivo");
        return 1;
    }
    fclose(archivo);
    return 0;
}
int agregarRegistro(char filename[]) {
    FILE *archivo;
    especialidades medicina;
    archivo = fopen(filename, "ab");
    if( archivo == NULL ) {
        puts("no se puede crear el archivo");
        return 1;
    }
    printf("Ingrese datos:\n");
    printf("\tNombre(40): "); scanf("%s", &medicina.nombre);
    printf("\tCodigo de Barras(21): "); ingresarCod(medicina.codBarras, 21);
    printf("\tCosto: "); ingresarDatoF(&medicina.costo, 0, MAXINT);
    printf("\tStock: "); ingresarDato(&medicina.stock, 0, MAXINT);
    printf("\tVencimiento:\n"); medicina.vencimiento = ingresarFecha();
    printf("\tLote(5): "); ingresarCod(medicina.lote, 5);
    fwrite(&medicina, sizeof(especialidades), 1, archivo);
    fclose(archivo);
    return 0;
}
int quitarRegistro(char filename[]){
    char cod[30];
    mostrarArchivo(FILENAME);
    printf("\nCodigo de barras del producto: "); ingresarCod(cod, 21);
    FILE *archivo;
    especialidades medicina;
    archivo = fopen(filename, "rb+");
    if( archivo == NULL ) {
        puts("no se puede crear el archivo");
        return 1;
    }
    fread(&medicina, sizeof(especialidades), 1, archivo);
    while( !feof(archivo) ) {
        if( !strcmp(cod, medicina.codBarras) ) {
            fseek(archivo, -1 * sizeof(especialidades), SEEK_CUR);
            medicina.stock = -1;
            fwrite(&medicina, sizeof(especialidades), 1, archivo);
            fseek(archivo, 1 * sizeof(especialidades), SEEK_CUR);
        }
        fread(&medicina, sizeof(especialidades), 1, archivo);

    }

    fclose(archivo);

    return 0;
}
int quitarVencidos(char filename[], char newFileName[]){
    fecha fechaTestigo;
    especialidades medicina;
    FILE *archivo;
    archivo = fopen(filename, "rb");
    if( archivo == NULL ) {
        puts("no se puede crear el archivo");
        return 1;
    }
    FILE *archivoNuevo;
    archivoNuevo = fopen(newFileName, "wb");
    if( archivoNuevo == NULL ) {
        puts("no se puede crear el archivo");
        return 1;
    }
    printf("Ingrese Fecha: "); fechaTestigo = ingresarFecha();
    fread(&medicina, sizeof(especialidades), 1, archivo);
    while( !feof(archivo) ) {
        if( mayor(medicina.vencimiento,fechaTestigo ) == 2) {
            fwrite(&medicina, sizeof(especialidades), 1, archivoNuevo);
        }
        fread(&medicina, sizeof(especialidades), 1, archivo);
    }
    fclose(archivo);
    fclose(archivoNuevo);
    printf("\n No vencidos\n");
    mostrarArchivo(newFileName);

    return 0;
}
int mostrarArchivo(char filename[]){
    FILE *archivo;
    especialidades medicina;
    archivo = fopen(filename, "rb");
    if( archivo == NULL ) {
        puts("no se puede crear el archivo");
        return 1;
    }
    printf("\xC9");
    for( int i = 0; i < 100; i++ )printf("\xCD");
    printf("\xBB\n");
    printf("\xBALote\tStock\tCosto\t  Vencimiento| Mes\ta\xA4o |");
    printf("\tCod. Barras\t\tNombre\n\xCC");
    for( int i = 0; i < 100; i++ )printf("\xCD");
    printf("\xB9");
    fread(&medicina, sizeof(especialidades), 1, archivo);
    while( !feof(archivo) ) {
        printf("\n\xBA");
        printf("%s\t%d\t%.2f\t\t\t%d\t%d\t%s\t%s",
               medicina.lote,
               medicina.stock,
               medicina.costo,
               medicina.vencimiento.mes,
               medicina.vencimiento.anio,
               medicina.codBarras,
               medicina.nombre
        );
        fread(&medicina, sizeof(especialidades), 1, archivo);
    }
    printf("\n\xC8");
    for( int i = 0; i < 100; i++ )printf("\xCD");
    printf("\xBC");
    fclose(archivo);
    return 0;
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
        printf("\t\tA\xA4o: ");
        ingresarDato(&fecha1.anio, -2020, 3000);
        printf("\t\tMes: ");
        ingresarDato(&fecha1.mes, 1, 12);
        if( !fecha_gregoriana(fecha1) ) {
            printf("\tFecha no gregoriana. Vuelva a intentarlo.\n");
        }
    } while( !fecha_gregoriana(fecha1) );
    return fecha1;
}
int fecha_gregoriana(fecha fecha) {

    int mes_dia[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
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
void ingresarCod(char codigo[], int cantidad) {
    int digitos;
    getchar();
    do {
        gets(codigo);
        digitos = isalldigits(codigo);
        if( !digitos) {
            puts("EL codigo debe ser numerico.");
        }
    } while( !digitos );
    if( strlen(codigo) < cantidad ) {
        while( strlen(codigo) < cantidad ) {
            concatenar('0', codigo);
        }
    }
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
void concatenar(char origen, char destino[]) {

    int i;
    char aux[200]=" ";

    for( i = strlen(destino) + 1; i >= 0; i-- ) { // recorro el vector  desde el final incluyendo el '\0'
        destino[i + 1] = destino[i]; // desplazo el vector una posicion hacia adelante
    }
    destino[0] = origen; // agrego mi caracter a agregar al principio del vector

}
int mayor(fecha fecha1, fecha fecha2) {

    if( (fecha1.anio > fecha2.anio) )return 1;
    else if( (fecha1.anio < fecha2.anio) ) return 2;
    else if( fecha1.mes > fecha2.mes ) return 1;
    else if( fecha1.mes < fecha2.mes ) return 2;
    else return 0;
    return -1;
}