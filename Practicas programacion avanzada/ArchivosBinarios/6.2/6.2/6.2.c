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
    C�digo de barras: 21 caracteres
    Nombre: 40 caracteres
    Costo: n�mero real
    Stock: N�mero entero: Cantidad de envases almacenados
    Mes, A�o: Enteros: Mes y a�o de vencimiento de la medicaci�n

    El archivo contiene un registro por cada lote, es decir que pueden existir varios registros para un mismo medicamento si �stos pertenecen a lotes distintos. Se solicita desarrollar uno o m�s programas para:

    �	Crear el archivo, ingresando los datos por teclado.
    �	Borrar del archivo los registros de aquellos lotes que se encuentren vencidos, comparando la fecha de vencimiento de cada uno con una fecha testigo que se ingresa por teclado. Para borrar los registros es necesario generar un nuevo archivo que contenga solamente los lotes no vencidos, emitiendo adem�s un listado por pantalla con los registros eliminados.
    �	Generar e imprimir un listado con el c�digo, el nombre y la cantidad de unidades en stock para cada medicamento, sin importar el lote al que pertenezca. El archivo no est� ordenado, y los medicamentos son a lo sumo 130. 

    Ejemplo:

    CODIGO	NOMBRE		CANTIDAD EN STOCK
    10000		TERRAMICINA			xxxx
    10001		CARBOPLAT			yyyy
    .....		............		....
*	� -> \xA4
*	� -> \xF8
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define SIZE 32
#define FILENAME "archivo.bin"
// Declaro funciones

int main(void) {


    printf("\n"); system("PAUSE");
    return 0;
}