/* ------------------------------------------------------------- */
/*          Implementación de una cola circular estática         */
/* ------------------------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define TAM 5

/* Variables globales                                */
int  dato;       /* elemento a ingresar en la pila               */
int  cola[TAM]; /* vector donde se almacena los elem.de la cola */
int* poner = cola, /* dirección del elemento a poner               */
* sacar = cola; /* dirección del próximo elemento a sacar       */

/* prototipos de las funciones                                   */
void acolar(void);
void desacolar(void);
int  colavacia(void);
int  colallena(void);
int  primerocola(void);

/* programa principal                                            */
int main(void) {
	/* Carga la cola hasta que se llene o ingrese un cero */
	printf("Ingrese un número distinto a 0: ");
	scanf("%d", &dato);

	while (dato != 0 && !colallena()) {
		acolar();
		printf("Ingrese un número distinto a 0: ");
		scanf("%d", &dato);
	}
	/* Muestra la cola, perdiendo todos los    */
	/* elementos que estaban cargados en ella  */
	printf("Datos cargados en la cola\n");
	while (!colavacia()) {
		printf("%d\n", primerocola());
		desacolar();
	}
	printf("Fin de datos\n");
}
/* ------------------------------------------ */
/* Función acolar: coloca un elemento nuevo en*/
/* la cola en la posición poner y desplaza    */
/* este a la posición del siguiente elemento  */
/* ------------------------------------------ */
void acolar(void) {
	*poner = dato;
	poner++;
	if (poner == cola + TAM)
		poner = cola;
}
/* ------------------------------------------ */
/* Función desacolar: elimina el primer       */
/* elemento ingresado en la cola              */
/* ------------------------------------------ */
void desacolar(void) {
	*sacar = dato;
	sacar++;
	if (sacar == cola + TAM)
		sacar = cola;
}
/* --------------------------------------------- */
/* Función colavacia: determina si la cola tiene */
/* elementos. Devuelve 1 si la cola está vacía   */
/* --------------------------------------------- */
int colavacia(void) {
	return (poner == sacar) ? 1 : 0;
}
/* -------------------------------------------- */
/* Función colallena: Determina si la cola está */
/* llena. Devuelve 1 en caso afirmativo         */
/* -------------------------------------------- */
int colallena(void) {
	return (poner + 1 == sacar || poner == sacar + TAM - 1) ? 1 : 0;
}
/* ------------------------------------------ */
/* Función primerocola: Devuelve el primer    */
/* elemento a salir de la cola                */
/* ------------------------------------------ */
int primerocola(void) {
	return *(sacar);
}
