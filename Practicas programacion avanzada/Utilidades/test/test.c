#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct {
	int lu;
	char nombre[80];
	char domicilio[80];
} talumno;

int main(){
	FILE * arch;
	talumno alumno;
	arch = fopen("alumnos.dat", "wb");
	if (arch == NULL)
	{
		puts("no se puede crear el archivo");
		return 1;
	}
	printf("LU?(-1 para terminar)");
	scanf("%d", &alumno.lu);
	while(alumno.lu!=-1){
		getchar();
		printf("Nombre?");
		gets(alumno.nombre);
		printf("Domicilio?");
		gets(alumno.domicilio);
		fwrite(&alumno, sizeof(alumno), 1, arch);
		printf("LU?(-1 para terminar)");
		scanf("%d", &alumno.lu);
	}
	fclose(arch);
	return 0;
}
