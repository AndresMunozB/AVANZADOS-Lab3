#include <stdio.h>
#include <string.h>
#include "funciones.h"

/*
 * Funcion existsFile
*/
int existsFile(char* filename) {
	FILE* f = NULL;
	f = fopen(filename,"r");
	if (f == NULL)
		return 0;
	else {
		fclose(f);
		return 1;
	}
	return 0;
}
void loadValues(char* filename,int cantidadDisponible[],int cantidadEntregada[],int valoresDinero[] ){
	FILE* archivoEntrada;
	archivoEntrada = fopen(filename,"r");
	int buffer1;
	int buffer2;
	int indice = 0;
	while (!feof(archivoEntrada)){

		fscanf(archivoEntrada,"%d %d\n",&buffer1, &buffer2);
		printf("%d %d\n",buffer1,buffer2 );
		cantidadDisponible[indice] = buffer1;
		valoresDinero[indice] = buffer2;
		cantidadEntregada[indice] = 0;
		indice += 1;
	}
	fclose(archivoEntrada);
}
void showValues(int cantidadDisponible[],int cantidadEntregada[],int valoresDinero[] ){
	int i;
	for (i=0;i<10;i++){
		printf("%d %d %d\n",cantidadDisponible[i],cantidadEntregada[i],valoresDinero[i]  );
	}
}
void calculate(int cantidadDisponible[],int cantidadEntregada[],int valoresDinero[],int vuelto){
    int i=0;
    while (i<10){
        while (vuelto>=valoresDinero[i] && cantidadDisponible[i]>0){
            cantidadEntregada[i]+=1;
            cantidadDisponible[i]-=1;
            vuelto -= valoresDinero[i];
        }
        i++;
    }
    if(vuelto!=0){
        printf("No existen monedas suficientes\n");
    }
}
int sumarDineroEntregado(int cantidadEntregada[],int valoresDinero[]){
    int i = 0;
    int entregado = 0;
    while (i<10){
        entregado += (cantidadEntregada[i])*(valoresDinero[i]);
        i++;
    }
    return entregado
    ;
}




