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
 int resto = strlen(cadena) % 8; // creo una variable y controlo que el numero sea multiplo de 8
 int guion = 3, espacio = 7;// contadores para saber cuando poner guion y cuando un espacio 
/* guion empieza en 3 para poner el guion en el primer cuarto lugar
   espacio empieza en 7 para poner el primer espacio en el octavo lugar*/
 char aux[200]=""; // variable char para usar de auxiliar 
    while( resto != 0 ) { // mientras no sea multipo de 8 agrego un '0' al principio del vector
        concatenar('0',cadena);// agrego un '0' al principio del vector
        resto = strlen(cadena) % 8; // vuelvo a controlar que sea multiplo de 8
    }
    for ( int i = 0; i < strlen(cadena); i++ ) { // recorro el vector
        espacio++; // sumo uno al  contador espacio 
        guion++; // sumo uno al contador de guion 
        if( !(guion % 8) )concatenarDer(aux, "-"); // si la posicion es multiplo de 8 apartir del cuarto lugar pongo un guion al final de mi auxiliar 
        if( !(espacio % 8) && espacio != 8 )concatenarDer(aux, " "); // si la posicion es multiplo de 8 apartir del octavio lugar pongo un espacio
        concatenarDer(aux, &cadena[i]); // agrego el sig caracter de mi cadena 
    }
    printf("Cadena: %s", aux); // imprimo el resultado
    for( int i = 0; i < strlen(aux); i++ )cadena[i] = aux[i]; // guardo  el resultado en la cadena
}

void concatenarDer(char destino[], char *origen) {

	int pos = 0; // variable para encontrar la posicion final
	while( destino[pos] != '\0' ) {
		pos++;  // simo uno si aun no es '\0'
	}
	destino[pos] = *origen; // en la ultima posicion del vector pongo mi valor a agregar
	destino[pos+1] = '\0'; // en la posicion siguiente agrego el '\0' para indicar el final de la cadena 

}

void concatenar(char origen, char destino[]) {

	int i;
	char aux[200]=" ";

	for( i = strlen(destino) + 1; i >= 0; i-- ) { // recorro el vector  desde el final incluyendo el '\0'
		destino[i + 1] = destino[i]; // desplazo el vector una posicion hacia adelante
	}
	destino[0] = origen; // agrego mi caracter a agregar al principio del vector
	
}

int strlen(char cadena[]){ // calculo el largo de la cadena de caracteres
	int length = 0;
	while( cadena[length] != '\0' ) {
		length++;
	}
	return length;
}
