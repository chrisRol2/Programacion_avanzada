/* ------------------------------------------------------------- */
/*          Implementaci�n de una cola circular est�tica         */
/* ------------------------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define TAM 5

/* Variables globales                                */
int  dato;       /* elemento a ingresar en la pila               */
int  cola[TAM]; /* vector donde se almacena los elem.de la cola */
int* poner = cola, /* direcci�n del elemento a poner               */
* sacar = cola; /* direcci�n del pr�ximo elemento a sacar       */

/* prototipos de las funciones                                   */
void acolar(void);
void desacolar(void);
int  colavacia(void);
int  colallena(void);
int  primerocola(void);

/* programa principal                                            */
int main(void) {
	/* Carga la cola hasta que se llene o ingrese un cero */
	printf("Ingrese un n�mero distinto a 0: ");
	scanf("%d", &dato);

	while (dato != 0 && !colallena()) {
		acolar();
		printf("Ingrese un n�mero distinto a 0: ");
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
/* Funci�n acolar: coloca un elemento nuevo en*/
/* la cola en la posici�n poner y desplaza    */
/* este a la posici�n del siguiente elemento  */
/* ------------------------------------------ */
void acolar(void) {
	*poner = dato;
	poner++;
	if (poner == cola + TAM)
		poner = cola;
}
/* ------------------------------------------ */
/* Funci�n desacolar: elimina el primer       */
/* elemento ingresado en la cola              */
/* ------------------------------------------ */
void desacolar(void) {
	*sacar = dato;
	sacar++;
	if (sacar == cola + TAM)
		sacar = cola;
}
/* --------------------------------------------- */
/* Funci�n colavacia: determina si la cola tiene */
/* elementos. Devuelve 1 si la cola est� vac�a   */
/* --------------------------------------------- */
int colavacia(void) {
	return (poner == sacar) ? 1 : 0;
}
/* -------------------------------------------- */
/* Funci�n colallena: Determina si la cola est� */
/* llena. Devuelve 1 en caso afirmativo         */
/* -------------------------------------------- */
int colallena(void) {
	return (poner + 1 == sacar || poner == sacar + TAM - 1) ? 1 : 0;
}
/* ------------------------------------------ */
/* Funci�n primerocola: Devuelve el primer    */
/* elemento a salir de la cola                */
/* ------------------------------------------ */
int primerocola(void) {
	return *(sacar);
}
