int vec[10] = { 4,5,1,0,9,6,7,24,9,2 };

int random(int minimo, int maximo) {

    return rand() % (maximo - minimo + 1) + minimo;
}

int random(int minimo, int maximo);

for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < m; k++) {
        }
    }
}

char cadena[200];
printf("Ingresar cadena: "); scanf("%s", cadena);

int main(void) {
    char Buffer[50] = "Hola";
    printf("Buffer antes: %s\n", Buffer);
    sprintf(Buffer, "%s%s", Buffer, "amigo");
    printf("Buffer despues: %s\n", Buffer);
    return 0;
}

void concatenar(char cadena1[], char cadena2[]) {
    printf("\ncadena1: %s\ncadena2: %s\n", cadena1, cadena2);
    char aux[200];
    sprintf(aux, "%s", cadena2);
    sprintf(cadena2, "%s%s", cadena1, aux);
}

#define false 0
#define true  1

