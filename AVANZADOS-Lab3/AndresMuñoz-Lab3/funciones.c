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



/*
 * Funcion loadValues
*/
void loadValues(char* filename,int numberCoins[],int valueCoins[] ){
	FILE* inputFile;
	inputFile = fopen(filename,"r");
	int quantity;
	int value;
	int index = 0;
	while (!feof(inputFile)){
		fscanf(inputFile,"%d %d\n",&quantity, &value);
		numberCoins[index] = quantity;
		valueCoins[index] = value;
		index += 1;
	}
	fclose(inputFile);
}

/*
 * Funcion initDeliveredCoins
*/
void initDeliveredCoins(int deliveredCoins[]){
	int i;
	for (i=0;i<10;i++){
		deliveredCoins[i]=0;
	}
}

/*
 * Funcion showChange
*/
void showChange(int deliveredCoins[],int valueCoins[]){
	int i;
	for (i=0;i<10;i++){
		if (deliveredCoins[i]!=0){
			if(valueCoins[i]>=1000){
				printf("%2d billete(s) de $%d\n",deliveredCoins[i],valueCoins[i] );
			}
			else{
				printf("%2d moneda(s)  de $%d\n",deliveredCoins[i],valueCoins[i] );
			}
		}
	}
}
int addCash(int numberCoins[],int valueCoins[]){
	int i = 0;
	int total = 0;
	while (i<10){
		total += (numberCoins[i]) * (valueCoins[i]);
		i++;
	}
	return total;
}

/*
 * Funcion calculate
*/
int calculate(int numberCoins[],int deliveredCoins[],int valueCoins[],int totalToPay,int customerPayment,FILE* outfile,int* payment){
	initDeliveredCoins(deliveredCoins);
	int change = customerPayment - totalToPay;
	int changeAux = change;
	int i=0;
	//Aqui se agrega el efectivo a la caja (el que paga el cliente)
	while (i<10){
        while (customerPayment>=valueCoins[i]){
			numberCoins[i]+=1;
			customerPayment -= valueCoins[i];
        }
        i++;
    }
	i=0;
	// Aqui se calcula lo que se debe entregar al cliente
	// SE APLICA METODO GOLOSO
    while (i<10){
        while (change>=valueCoins[i] && numberCoins[i]>0){
            deliveredCoins[i]+=1;
			numberCoins[i]-=1;
			change -= valueCoins[i];
        }
        i++;
    }
	// FIN METODO GOLOSO
	// Se verifica si el efectivo alcanza para el vuelto
    if(change!=0){
        printf("No existen monedas suficientes\n");
		return 0;
    }else{
		//Mostrando el dinero que se debe entregar
		printf("Vuelto          : %d\n", changeAux );
		showChange(deliveredCoins,valueCoins);
		//Guardando en el archivo de salida, la suma total que se tiene en la caja.
		int total = addCash(numberCoins,valueCoins);
		fprintf(outfile, "Pago %2d: $%d\n", *payment, total );
		*payment+=1;
		return 1;
	}
}
