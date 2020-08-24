/* ----------------------------------------------------- */
/*          Implementación de una pila estática          */
/* ----------------------------------------------------  */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define TAM 5

/* Variables globales                                */
int  dato;       /* elemento a ingresar en la pila               */
int  pila[TAM]; /* vector donde se almacena los elem.de la pila */
int* tope = pila + TAM;  /* dir. del próximo elem. a ingresar en la pila */

/* prototipos de las funciones                                   */
void apilar(void);
void desapilar(void);
int  pilavacia(void);
int  pilallena(void);
int  primeropila(void);

/* programa principal                                            */
int main(void) {
	/* Carga la pila hasta que se llene o ingrese un cero */
	printf("ingrese un número distinto a 0: ");
	scanf("%d", &dato);
	while (dato != 0 && !pilallena()) {
		apilar();
		printf("ingrese un número distinto a 0: ");
		scanf("%d", &dato);
	}
	/* Muestra la pila, perdiendo todos los    */
	/* elementos que estaban cargados en ella  */
	printf("Datos cargados en la pila\n");
	while (!pilavacia()) {
		printf("%d\n", primeropila());
		desapilar();
	}
	printf("Fin de datos\n");
	return 0;
}
/* ------------------------------------------ */
/* Función apilar: coloca un elemento nuevo en*/
/* la pila en la posición tope y desplaza     */
/* este a la posición del siguiente elemento  */
/* ------------------------------------------ */
void apilar(void) {
	tope--;
	*tope = dato;
}
/* ------------------------------------------ */
/* Función desapilar: elimina el último       */
/* elemento ingresado en la pila              */
/* ------------------------------------------ */
void desapilar(void) {
	tope++;
}
/* --------------------------------------------- */
/* Función pilavacia: determina si la pila tiene */
/* elementos. Devuelve 1 si la pila está vacía.  */
/* --------------------------------------------- */
int pilavacia(void) {
	return(tope == pila + TAM) ? 1 : 0;
}
/* -------------------------------------------- */
/* Función pilallena: Determina si la pila está */
/* llena. Devuelve 1 en caso afirmativo         */
int pilallena(void) {
	return(tope == pila) ? 1 : 0;
}
/* ------------------------------------------ */
/* Función primeropila: Devuelve el primer    */
/* elemento a salir de la pila                */
/* ------------------------------------------ */
int primeropila(void) {
	return *tope;
}
