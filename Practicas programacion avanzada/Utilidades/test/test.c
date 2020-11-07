#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10


//ESTRUCTURAS
typedef struct pasajes
{
    int CI, edad, pago, precio, mes;
    char apellido[3];
    char asiento;
}tpasaje;

//PROTOTIPOS
void CargarArch(char archO[]);
void MostrarPantalla(char archO[]);
void buscar(char archO[]);

//PROGRAMA PRINCIPAL
int main()
{
    int cant;
    srand(time(NULL));
    tpasaje aux1;
    char ArchivoBinario[]="Pasajes.bin";
    char Archivo2Binario[]="Vendidos.bin";
    char ArchivoReporte[]="Reporte.txt";
    CargarArch(ArchivoBinario);
    MostrarPantalla(ArchivoBinario);
    buscar(ArchivoBinario);
    system("pause");
    return 0;
}


void CargarArch(char archO[])
{
    int cant = 0;
    int i,k;
    int azar;
    tpasaje aux;
    FILE* archivoB;
    archivoB= fopen(archO, "wb");
    if (archivoB == NULL)
    {
        printf("No se puede crear el archivo\n");
        return 1;
    }
    aux.CI=rand()%(900000-100000+1)+100000;
    while(cant<MAX)
    {
        for(k=0;k<3;k++)
        {
            aux.apellido[k] = '0' + rand() % (42-17+1) + 17;
        }
        aux.apellido[2]='\0';
        azar= rand()%(100-1+1)+1;
        if(azar<33)
        {
            aux.asiento='V';
        }
        else if(azar<66)
        {
            aux.asiento='M';
        }
        else
        {
            aux.asiento='P';
        }
        aux.edad= rand()%(75-18+1)+18;
        aux.pago= rand()%(2-1+1)+1;
        if (aux.pago==1)
        {
            aux.precio= rand()%(120000-30000+1)+30000;
        }
        else
        {
            aux.precio=  rand()%(150000-50000+1)+50000;
        }
        aux.mes=rand()%(12-1+1)+1;
        fwrite(&aux, sizeof(tpasaje), 1, archivoB);
        cant++;
    }
    fclose(archivoB);
}



void MostrarPantalla(char archO[])
{
    FILE* archivoB;
    tpasaje aux;
    archivoB = fopen(archO, "rb");
    if (archivoB == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return 1;
    }
    else
    {
        printf("CI\tNom.\tEdad\tAsiento\tMod.\tPrecio\tMes\n");
        fread(&aux,sizeof(tpasaje),1,archivoB);
        while (!feof(archivoB))
        {
            printf("%d\t", aux.CI);
            printf("%s\t", aux.apellido);
            printf("%d\t", aux.edad);
            printf("%c\t", aux.asiento);
            printf("%d\t", aux.pago);
            printf("%d\t", aux.precio);
            printf("%d\n", aux.mes);
            fread(&aux, sizeof(tpasaje),1, archivoB);
        }
    }
    fclose(archivoB);
}


void buscar(char archO[])
{
    tpasaje aux;
    FILE*archivoB;
    char dato[3];
    printf("\nINGRESE UN APELLIDO PARA BUSCAR SUS DATOS: ");
    gets(dato);
    archivoB=fopen(archO,"rb");
    if(archivoB==NULL)
    {
        printf("No se puede abrir el archivo\n");
        return 1;
    }
    fread(&aux, sizeof(tpasaje), 1, archivoB);
    while( !feof(archivoB) )
    {
        if( strcmp(dato, aux.apellido) == 0 )
        {

            printf("CI\tEdad\tAsiento\tMod.\tPrecio\tMes\n");
            printf("%d\t", aux.CI);
            printf("%d\t", aux.edad);
            printf("%c\t", aux.asiento);
            printf("%d\t", aux.pago);
            printf("%d\t", aux.precio);
            printf("%d\n", aux.mes);
        }
        fread(&aux, sizeof(tpasaje), 1, archivoB);
    }
    fclose(archivoB);
}

/*• Código de identificación (entero, entre 100000 y 900000)
• Tipo de asiento (1 caracter, V: ventanilla, P: pasillo, M: medio)
• Apellido comprador (3 caracteres)
· Edad comprador (entero, entre 18 y 75)
· Modalidad de pago (entero, 1: contado, 2: crédito)
· Precio del pasaje (entero, entre 30000 y 120000 si es pago contado y entre 50000 y 150000 si es pago a credito)
· Mes de venta (1 entero, entre 1 y 12)*/
typedef struct {
    int codID;
    char tipoAsiento;
    char apellido[4];
    int edad;
    char modPago;
    int precio;
    int mesVenta;
}pasaje;
/*
1. Genere, sin intervención del usuario, un archivo binario de pasajes vendidos en un mes (considere una cantidad de 100 pasajes). (1Punto).
2. Genere una función que muestre los datos guardados en el archivo de pasajes (1Punto)
3. Genere una función que, a partir de un apellido ingresado por el usuario, muestre los datos del pasaje que compró. (2Puntos)
4. Ordene los pasajes vendidos por precio, luego imprima nuevamente el archivo (2Punto).
5. Genere un nuevo archivo que contenga sólo las ventas realizadas en las temporadas otoño-invierno (meses 4 al 8). Muestre los datos guardados en este nuevo archivo (2Puntos).
6. Genere un archivo de texto con el siguiente formato (2Puntos):
    Apellido Edad Tipo de Pago Precio
    BH 50 1 18500
    IK 23 2 20300
    */