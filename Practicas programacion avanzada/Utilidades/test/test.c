#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define COL 7
#define FIL 7

int aleatorio(int,int);
void crearMatriz(int [FIL][COL]);
void imprimirMatriz(int [FIL][COL]);
void promColFila(int [FIL][COL]);
void codMax2(int [FIL][COL]);
void promUVend2005(int [FIL][COL]);
void reemplazaChar(char []);


int main() {
    int mat[FIL][COL];
    char cad[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

    srand(time(NULL));

    crearMatriz(mat);

    imprimirMatriz(mat);

    promColFila(mat);

    codMax2(mat);

    promUVend2005(mat);

    reemplazaChar(cad);

    return 0;
}


int aleatorio(int inf,int sup){
    return inf + rand() % (sup + 1 - inf);
}

void crearMatriz(int mat[FIL][COL]){
    int f,c,val;

    for (f = 0; f < FIL; f++) {
        for (c = 0; c < COL; c++){
            switch(c){
                case 0: val = aleatorio(1000,10000);
                    break;
                case 1: val = aleatorio(2001,2020);
                    break;
                case 2: val = aleatorio(100,4000);
                    break;
                case 3: val = aleatorio(1,4);
                    break;
                case 4: val = aleatorio(800,5000);
                    break;
                case 5: val = aleatorio(1,10);
                    break;
                default: val = mat[f][4] + mat[f][4] * 0.2 * (2020 - mat[f][1]);
            }
            mat[f][c] = val;
        }
    }
}
void imprimirMatriz(int mat[FIL][COL]){
    int f,c;

    printf("\nIMPRESION MATRIZ\n");
    printf("    Codigo      Anio         Unidades   Plataformas    Precio   Cant    Precio\n");
    printf("    Videojuego  Publicacion  Vendidas   Disponibles    Base     Paises  Actualizado\n");
    for (f = 0; f < FIL; f++) {
        for (c = 0; c < COL; c++){
            if(c == 0){
                printf("%d    ",f + 1);
            }
            printf("%d         ",mat[f][c]);
        }
        printf("\n");
    }
}

void promColFila(int mat[FIL][COL]){
    int col;
    float prom;

    printf("\nPto 3: Ingrese el numero de columna: ");
    scanf("%d",&col);

    prom = (float)(mat[4][col - 1] + mat[5][col - 1] + mat[6][col - 1]) / 3;

    printf("El promedio de las 3 ultimas filas de esa columna es: %.2f\n",prom);
}

void codMax2(int mat[FIL][COL]){
    int f, max1,max2, cod1, cod2;

    //pongo en max1 el mayor y en max2 el siguiente
    if (mat[0][6] > mat[1][6]){
        max1 = mat[0][6];
        cod1 = mat[0][0];
        max2 = mat[1][6];
        cod2 = mat[1][0];
    } else {
        max2 = mat[0][6];
        cod2 = mat[0][0];
        max1 = mat[1][6];
        cod1 = mat[1][0];
    }

    //despues comparo el resto
    for(f = 2; f < FIL; f++) {
        if(mat[f][6] > max1){
            max2 = max1;
            cod2 = cod1;
            max1 = mat[f][6];
            cod1 = mat[f][0];
        } else if(mat[f][6] > max2){
            max2 = mat[f][6];
            cod2 = mat[f][0];
        }
    }
    printf("\nPto 4: Codigos de los dos videojuegos de mayores precios actualizados: %d, %d\n",cod1,cod2);
}


void promUVend2005(int mat[FIL][COL]){
    int f, sumaUV = 0, cont = 0;
    float prom = 0;

    for (f = 0; f < FIL; f++) {
        if(mat[f][1] > 2005){
            cont++;
            sumaUV = sumaUV + mat[f][2];
        }
    }

    if(cont != 0){
        prom = (float) sumaUV / cont;
    }

    printf("\nPto 5: Promedio de unidades vendidas de los videojuegos publicados luego de 2005: %.2f\n",prom);

}

void reemplazaChar(char cad[]){
    int i = 0,flag = 0;

    while(i < strlen(cad) && flag == 0){
        if(cad[i] == 'e' && cad[i + 1] == 'l'){
            cad[i] = 'r';
            cad[i+1] = 'e';
            cad[i+2] = 'p';
            cad[i+3] = 'o';
            flag = 1;
        }
        i++;
    }

    printf("\nEjercicio 2, cadena resultante: %s\n",cad);
}
