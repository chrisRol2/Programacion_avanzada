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
*	Ejercicio: Se debe desarrollar un software que permita a una tienda de venta de pasajes de avion realizar el seguimiento, análisis y segmentación de sus ventas. Por cada venta realizada se registra la siguiente información:

            • Código de identificación (entero, entre 100000 y 900000)
            • Tipo de asiento (1 caracter, V: ventanilla, P: pasillo, M: medio)
            • Apellido comprador (3 caracteres)
            · Edad comprador (entero, entre 18 y 75)
            · Modalidad de pago (entero, 1: contado, 2: crédito)
            · Precio del pasaje (entero, entre 30000 y 120000 si es pago contado y entre 50000 y 150000 si es pago a credito)
            · Mes de venta (1 entero, entre 1 y 12)
       Se pide que:

    1. Genere, sin intervención del usuario, un archivo binario de pasajes vendidos en un mes (considere una cantidad de 100 pasajes). (1Punto).
    2. Genere una función que muestre los datos guardados en el archivo de pasajes (1Punto)
    3. Genere una función que, a partir de un apellido ingresado por el usuario, muestre los datos del pasaje que compró. (2Puntos)
    4. Ordene los pasajes vendidos por precio, luego imprima nuevamente el archivo (2Punto).
    5. Genere un nuevo archivo que contenga sólo las ventas realizadas en las temporadas otoño-invierno (meses 4 al 8). Muestre los datos guardados en este nuevo archivo (2Puntos).
    6. Genere un archivo de texto con el siguiente formato (2Puntos):
    Apellido Edad Tipo de Pago Precio
    BH 50 1 18500
    IK 23 2 20300
*
*	ñ -> \xA4
*	° -> \xF8
*
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//CONSTANTES
#define MAX_PASAJES   100
#define MAX_APELLIDO  2 + 1
#define GENERAR       1
#define MOSTRAR       2
#define BUSCAR        3
#define ORDENAR       4
#define OTOINVIERNO   5
#define GENTXT        6
#define SALIR         0
#define FILENAME "pasajes.bin"
#define FILENAMEOI "pasajesOI.bin"
#define FILENAMETXT "pasajes.TXT"
//ESTRUCTURA
typedef struct {
    int codID;
    char tipoAsiento;
    char apellido[MAX_APELLIDO];
    int edad;
    char modPago;
    int precio;
    int mesVenta;
}pasaje;
//funciones ejercicio
int createFILE(char fileName[]);
int fillFILE(char fileName[]);
int printFILE(char fileName[]);
int buscarPasaje(char fileName[], char nombre[]);
int ordenarFILE(char fileName[]);
int genOtoNoInvierno(char fileName[], char fileNameOI[]);
int genTEXT(char fileNameBIN[], char fileNameTXT[]);
// funciones auxiliares
int random(int minimo, int maximo);
void encabezado();
void FileRead(pasaje *var, int locate, FILE *file);
void FileWrite(pasaje *var, int locate, FILE *file);
int isallalpha(char codigo[]);
void mayus(char str[]);
void verifApellido(char apellido[MAX_APELLIDO]);
void ingresarDato(int *dato, int min, int max);
void menu(int *selector);
int main(void) {
    char buscado[MAX_APELLIDO];
    srand(getpid());
    int flag = -1;
  /*  printf("Crear archivo? (1: Si | 2: No): ");
    ingresarDato(&flag, 1, 2);
    if( flag == 1 )createFILE(FILENAME);*/
    do {
        menu(&flag);
        system("cls");
        switch( flag ) {
            case GENERAR:
                fillFILE(FILENAME);
                break;
            case MOSTRAR:
                printFILE(FILENAME);
                break;
            case BUSCAR:
                verifApellido(buscado);
                buscarPasaje(FILENAME, buscado);
                break;
            case ORDENAR:
                ordenarFILE(FILENAME);
                printFILE(FILENAME);
                break;
            case OTOINVIERNO:
                genOtoNoInvierno(FILENAME, FILENAMEOI);
                printFILE(FILENAMEOI);
                break;
            case GENTXT:
                genTEXT(FILENAME, FILENAMETXT);
                break;
            default:
                printf("Salir.");
                break;
        }
    } while( flag != 0 );
    printf("\n"); system("PAUSE");
    return 0;
}
//funciones ejercicio
int createFILE(char fileName[]) {
    FILE * archivo;
    archivo = fopen(fileName, "wb");
    if (archivo == NULL){
        puts("no se puede crear el archivo");
        return 1;
    }
    fclose(archivo);
    return 0;
}
int fillFILE(char fileName[]) {
    FILE * archivo;
    pasaje creador;
    int i, npas;
    char tipoAsiento[3] = { 'V','P','M' };
    archivo = fopen(fileName, "wb");
    if (archivo == NULL){
        puts("no se puede crear el archivo");
        return 1;
    }
    for( npas = 0; npas < MAX_PASAJES; npas++ ) {
        creador.codID = random(100000, 900000);
        creador.tipoAsiento = tipoAsiento[random(0, 2)];
        for( i = 0; i < MAX_APELLIDO; i++ ) {
            creador.apellido[i] = 'A' + random(0, 25);
        }creador.apellido[MAX_APELLIDO - 1] = '\0';
        creador.edad = random(18, 75);
        creador.modPago = random(1, 2);
        if( creador.modPago == 1 )
            creador.precio = random(30000, 120000);
        else
            creador.precio = random(50000, 150000);
        creador.mesVenta = random(1, 12);
        fwrite(&creador, sizeof(pasaje), 1, archivo);
    }
    fclose(archivo);
    return 0;
}
int printFILE(char fileName[]) {
    FILE *archivo;
    int i;
    pasaje lector;
    archivo = fopen(fileName, "rb");
    if (archivo == NULL){
        puts("no se puede crear el archivo");
        return 1;
    }
    encabezado();
    fread(&lector, sizeof(pasaje), 1, archivo);
    while( !feof(archivo) ) {
        printf("\n");
        printf("%d\t", lector.codID);
        printf("\t%c\t", lector.tipoAsiento);
        printf("\t%s\t", lector.apellido);
        printf("\t%d\t", lector.edad);
        printf("%d\t", lector.modPago);
        printf("\t%d\t", lector.precio);
        printf("\t%d\t", lector.mesVenta);
        fread(&lector, sizeof(pasaje), 1, archivo);
    }
    fclose(archivo);
    return 0;
}
int buscarPasaje(char fileName[], char nombre[]){
    FILE * archivo;
    pasaje lector;

    archivo = fopen(fileName, "rb");
    if (archivo == NULL){
        puts("no se puede crear el archivo");
        return 1;
    }
    fread(&lector, sizeof(pasaje), 1, archivo);
    while( !feof(archivo) ) {
        if( strcmp(nombre, lector.apellido) == 0 ) {
            encabezado();
            printf("\n");
            printf("%d\t", lector.codID);
            printf("\t%c\t", lector.tipoAsiento);
            printf("\t%s\t", lector.apellido);
            printf("\t%d\t", lector.edad);
            printf("%d\t", lector.modPago);
            printf("\t%d\t", lector.precio);
            printf("\t%d\t", lector.mesVenta);
            printf("\n");
        }
        fread(&lector, sizeof(pasaje), 1, archivo);
    }

    fclose(archivo);
    return 0;
}
int ordenarFILE(char fileName[]){
    pasaje valor1, valor2;
    FILE *archivo;
    archivo = fopen(fileName, "rb+");
    if( archivo == NULL ) {
        puts("No se pudo abrir el archivo");
        return 1;
    }
    for( int i = 0; i < MAX_PASAJES; i++ ) {
        for( int j = i + 1; j < MAX_PASAJES; j++ ) {
            FileRead(&valor1, i, archivo);
            FileRead(&valor2, j, archivo);
            if( valor1.precio > valor2.precio ) {
                FileWrite(&valor1, j, archivo);
                FileWrite(&valor2, i, archivo);
            }
        }
    }
    fclose(archivo);
    return 0;
}
int genOtoNoInvierno(char fileName[], char fileNameOI[]){
    pasaje aux;
    FILE * archivo;
    archivo = fopen(fileName, "rb");
    if (archivo == NULL){
        puts("no se puede crear el archivo");
        return 1;
    }
    FILE * archivoOTOINV;
    archivoOTOINV = fopen(fileNameOI, "wb");
    if (archivo == NULL){
        puts("no se puede crear el archivo");
        return 1;
    }

    fread(&aux, sizeof(pasaje), 1, archivo);
    while( !feof(archivo) ) {
        if( (aux.mesVenta > 4) && (aux.mesVenta < 8) ) {
            fwrite(&aux, sizeof(pasaje), 1, archivoOTOINV);
        }
        fread(&aux, sizeof(pasaje), 1, archivo);

    }
    fclose(archivo);
    fclose(archivoOTOINV);
    return 0;
}
int genTEXT(char fileNameBIN[], char fileNameTXT[]){
    FILE * archivoBIN;
    archivoBIN = fopen(fileNameBIN, "rb");
    if (archivoBIN == NULL){
        puts("no se puede crear el archivo");
        return 1;
    }
    FILE * archivoTXT;
    archivoTXT = fopen(fileNameTXT, "wt");
    if (archivoTXT == NULL){
        puts("no se puede crear el archivo");
        return 1;
    }
    pasaje lector;

    fprintf(archivoTXT, "Apellido\tEdad\tTipo de Pago\tPrecio");
    fread(&lector, sizeof(pasaje), 1, archivoBIN);
    while( !feof(archivoBIN) ) {
        fprintf(archivoTXT,"\n");
        fprintf(archivoTXT,"%s\t", lector.apellido);
        fprintf(archivoTXT,"\t%d\t", lector.edad);
        fprintf(archivoTXT,"%c\t", lector.tipoAsiento);
        fprintf(archivoTXT,"\t%d\t", lector.precio);
        fread(&lector, sizeof(pasaje), 1, archivoBIN);
    }
    fclose(archivoTXT);    
    fclose(archivoBIN);
    return 0;
}
// funciones auxiliares
int random(int minimo, int maximo) {

    return rand() % (maximo - minimo + 1) + minimo;
}
void encabezado() {
    int i;
    char encabezadoS[8][30][30] = {
        {"Codigo de","Identificaci\xA2n"},//hay un espacio en có digo porque me tira un error que no comprendo
        {"Tipo de\t","Asiento\t"},
        {"Apellido","Comprador"},
        {"Edad",""},
        {"Modalidad","De Pago\t"},
        {"Precio del","Pasaje\t"},
        {"Mes de","Venta"}
    };
    printf("\n");
    for( i = 0; i < 8; i++ )printf("%s\t", encabezadoS[i][0]);
    printf("\n");
    for( i = 0; i < 8; i++ )printf("%s\t", encabezadoS[i][1]);
}
void FileRead(pasaje *var, int locate, FILE *file) {
    fseek(file, locate * sizeof(pasaje),SEEK_SET);
    fread(var, sizeof(pasaje), 1, file);
}
void FileWrite(pasaje *var, int locate, FILE *file) {
    fseek(file, locate * sizeof(pasaje),SEEK_SET);
    fwrite(var, sizeof(pasaje), 1, file);
}
void verifApellido(char apellido[MAX_APELLIDO]) {
    char buscado[10];
    int flag = 0;
    do {
        flag = 0;
        printf("\nIngrese apellido del pasaje que busca: ");
        scanf("%s", &buscado);
        if( (strlen(buscado) != MAX_APELLIDO - 1) ) {
            printf("El apellido debe ser solo 3 letras\n");
            flag = 1;
        }
        if( (!isallalpha(buscado))) {
            printf("El apellido debe ser letras\n");
            flag = 1;
        }
        
    } while(flag);
    mayus(buscado);
    strcpy(apellido, buscado);
}
void mayus(char str[]) {
    for( int i = 0; i < strlen(str); i++ ) {
        if( str[i] > 'Z' ) {
            str[i] -= 32;
        }
    }
    str[MAX_APELLIDO - 1] = '\0';
}
int isallalpha(char codigo[]) {
    int resultado = 1;
    int i;
    for( i = 0; i < strlen(codigo); i++ ) {
       
        if( codigo[i] <'A' ) {
            resultado = 0;
            break;
        }
    }

    return resultado;
}
void ingresarDato(int *dato, int min, int max) {
    do {
        scanf("%d", dato);
        if( (*dato > max) || (*dato < min) )printf("\nDato fuera de rango.\n");
    } while( (*dato > max) || (*dato < min) );
}
void menu(int *selector) {
    printf("\nPasajes.\n");
    printf("\t1. Generar listado.\n");
    printf("\t2. Mostrar listado.\n");
    printf("\t3. Buscar pasaje.\n");
    printf("\t4. Ordenar por precio.\n");
    printf("\t5. Oto\xA4o-Invierno.\n");
    printf("\t6. Generar txt.\n");
    printf("\t0. Salir.\n");
    printf("Seleccion: "); ingresarDato(selector, 0, 6);
}