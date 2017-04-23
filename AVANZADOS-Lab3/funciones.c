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

void initCantidadEntregada(int ce[]){
	int i;
	for (i=0;i<10;i++){
		ce[i]=0;
	}
}

/*
 * Funcion loadValues
*/
void loadValues(char* filename,int cd[],int vd[] ){
	FILE* archivoEntrada;
	archivoEntrada = fopen(filename,"r");
	int cantidad;
	int valor;
	int indice = 0;
	while (!feof(archivoEntrada)){

		fscanf(archivoEntrada,"%d %d\n",&cantidad, &valor);
		cd[indice] = cantidad;
		vd[indice] = valor;
		indice += 1;
	}
	fclose(archivoEntrada);
}

/*
 * Funcion showValues
*/
void showValues(int cd[],int ce[],int vd[] ){
	int i;
	for (i=0;i<10;i++){
		printf("%d %d %d\n",cd[i],ce[i],vd[i]  );
	}
}
void showVueltoMinimo(int ce[],int vd[]){
	int i;
	for (i=0;i<10;i++){
		if (ce[i]!=0){
			if(vd[i]>=1000){
				printf("%2d billete(s) de $%d\n",ce[i],vd[i] );
			}
			else{
				printf("%2d moneda(s)  de $%d\n",ce[i],vd[i] );
			}
		}
	}
}

/*
 * Funcion calculate
*/
int calculate(int cd[],int ce[],int vd[],int totalPagar,int clientePaga,FILE* outfile,int* pago){
	initCantidadEntregada(ce);
	int vuelto = clientePaga - totalPagar;
	int vueltoAux = vuelto;
	int i=0;
	//Aqui se agrega el efectivo a la caja (el que paga el cliente)
	while (i<10){
        while (clientePaga>=vd[i]){
			cd[i]+=1;
			clientePaga -= vd[i];
        }
        i++;
    }
	i=0;
	// Aqui se calcula lo que se debe entregar al cliente
    while (i<10){
        while (vuelto>=vd[i] && cd[i]>0){
            ce[i]+=1;
			cd[i]-=1;
			vuelto -= vd[i];
        }
        i++;
    }
	// Se verifica si el efectivo alcanza para el vuelto
    if(vuelto!=0){
        printf("No existen monedas suficientes\n");
		return 0;
    }else{
		//Mostrando el dinero que se debe entregar
		printf("Vuelto: %d\n", vueltoAux );
		showVueltoMinimo(ce,vd);
		//Guardando el dinero que deberia llevarse en el archivo de salida
		int suma = sumarDineroCaja(cd,vd);
		fprintf(outfile, "Pago %2d: $%d\n", *pago, suma );
		//showValues(cd, ce, vd );
		*pago+=1;
		return 1;
	}
}


int sumarDineroCaja(int cd[],int vd[]){
	int i = 0;
	int caja = 0;
	while (i<10){
		caja += (cd[i]) * (vd[i]);
		i++;
	}
	return caja;
}
