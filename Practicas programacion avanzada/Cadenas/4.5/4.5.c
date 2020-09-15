/*
 *	File:   4.6.c
 *	Author:	Christopher Roldan Sanchez
 *	Mail:	Christopher_Rol@hotmail.es
 *	Date:
 *	Description:
 *
 *	Materia:		Programacion avanzada
 *	Universidad:	Universidad Argentina De La Empresa (UADE)
 *	Docente:        Iervasi Scokin, Juan Jose
 *
 *	Ejercicio:  5.	Hacer una función que permita insertar en una secuencia de dígitos 
 *                      los caracteres guión cada 8 dígitos a partir del cuarto dígito, 
 *                      y un espacio cada 8 dígitos a partir del octavo dígito.
 *                      Si la cantidad de dígitos no es múltiplo de ocho agregar delante
 *                      de la cadena caracteres ‘0’ hasta que la misma sea múltiplo de 8.
 *
 *	Ejemplos:	472348237388539055823012	->	4723-4823 7388-5390 5582-3012
 *		8237388539055823012		->	0000-0823 7388-5390 5582-3012
 *
 *
 *
 *
 */



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 // Declaro funciones
 void insertarGuion(char cadena[200]);
 void concatenar(char origen,char destino[]);
 void concatenarDer(char destino[], char *orige);
 int strlen(char cadena[]);
int main(void) {
    char cadena[200];
    printf("Ingresar cadena: "); scanf("%s", cadena);


    insertarGuion(cadena);
  //  printf("\nCadena resultante: %s ,de largo: %d",cadena,(strlen(cadena)));

    printf("\n"); system("PAUSE");
    return 0;
}

void insertarGuion(char cadena[200]) {
 int resto = strlen(cadena) % 8;
 int guion = 3, espacio = 7;
 char aux[200]="";
    while( resto != 0 ) {
        concatenar('0',cadena);
        resto = strlen(cadena) % 8;
    }
    for ( int i = 0; i < strlen(cadena); i++ ) {
        espacio++;
        guion++;
        if( !(guion % 8) )concatenarDer(aux, "-");
        if( !(espacio % 8) && espacio != 8 )concatenarDer(aux, " ");
        concatenarDer(aux, &cadena[i]);
    }
    printf("Cadena: %s", aux);
    for( int i = 0; i < strlen(aux); i++ )cadena[i] = aux[i];
}

void concatenarDer(char destino[], char *origen) {
//    printf("\ncaracter1: %c\tcadena2: %s", *cadena1, cadena2);
    //sprintf(cadena2, "%s%c", cadena2, *cadena1);
	int pos = 0;
	while( destino[pos] != '\0' ) {
		pos++;
	}
	destino[pos] = *origen;
	destino[pos+1] = '\0';

}

void concatenar(char origen, char destino[]) {
  //  printf("\ncadena1: %s\ncadena2: %s\n", cadena1, cadena2);
	int i;
	char aux[200]=" ";
	/*for( i = 0; destino[i - 1] != '\0'; i++ ) {
		aux[i] = destino[i];
	}
	destino[0] = '0';
	for( i = 1; aux[i-1] != '\0'; i++ ) {
		destino[i] = aux[i-1];
	}
	destino[i] = '\0';
	*/
	for( i = strlen(destino) + 1; i >= 0; i-- ) {
		destino[i + 1] = destino[i];
	}
	destino[0] = origen;

	printf("cadena2: %s", destino);
	
	
	//sprintf(destino, "%c%s", origen, aux);
	
}

int strlen(char cadena[]){
	int length = 0;
	while( cadena[length] != '\0' ) {
		length++;
	}
	return length;
}
