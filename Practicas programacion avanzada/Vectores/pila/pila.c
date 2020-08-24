/* ----------------------------------------------------- */
/*          Implementaci�n de una pila est�tica          */
/* ----------------------------------------------------  */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define TAM 5

/* Variables globales                                */
int  dato;       /* elemento a ingresar en la pila               */
int  pila[TAM]; /* vector donde se almacena los elem.de la pila */
int* tope = pila + TAM;  /* dir. del pr�ximo elem. a ingresar en la pila */

/* prototipos de las funciones                                   */
void apilar(void);
void desapilar(void);
int  pilavacia(void);
int  pilallena(void);
int  primeropila(void);

/* programa principal                                            */
int main(void) {
	/* Carga la pila hasta que se llene o ingrese un cero */
	printf("ingrese un n�mero distinto a 0: ");
	scanf("%d", &dato);
	while (dato != 0 && !pilallena()) {
		apilar();
		printf("ingrese un n�mero distinto a 0: ");
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
/* Funci�n apilar: coloca un elemento nuevo en*/
/* la pila en la posici�n tope y desplaza     */
/* este a la posici�n del siguiente elemento  */
/* ------------------------------------------ */
void apilar(void) {
	tope--;
	*tope = dato;
}
/* ------------------------------------------ */
/* Funci�n desapilar: elimina el �ltimo       */
/* elemento ingresado en la pila              */
/* ------------------------------------------ */
void desapilar(void) {
	tope++;
}
/* --------------------------------------------- */
/* Funci�n pilavacia: determina si la pila tiene */
/* elementos. Devuelve 1 si la pila est� vac�a.  */
/* --------------------------------------------- */
int pilavacia(void) {
	return(tope == pila + TAM) ? 1 : 0;
}
/* -------------------------------------------- */
/* Funci�n pilallena: Determina si la pila est� */
/* llena. Devuelve 1 en caso afirmativo         */
int pilallena(void) {
	return(tope == pila) ? 1 : 0;
}
/* ------------------------------------------ */
/* Funci�n primeropila: Devuelve el primer    */
/* elemento a salir de la pila                */
/* ------------------------------------------ */
int primeropila(void) {
	return *tope;
}
