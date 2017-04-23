#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main()
{
    //printTitle();
    char nameFile[100];
    memset(nameFile,0,sizeof(nameFile));
    char option[5];
    int totalPagar;
    int clienteEntrega;
    int cantidadDisponible[10];
    int cantidadEntregada[10];
    int valoresDinero[10];
    int pago = 1;


    do{
        memset(nameFile,0,255);
        printf("\nIngrese el nombre de un archivo: ");
        scanf("%s", nameFile);
        if (!existsFile(nameFile)){
            printf("El archivo ingresado no existe\n\n");
        }
    }while(!existsFile(nameFile));
    loadValues(nameFile,cantidadDisponible,valoresDinero);


    FILE* outFile= fopen("salida.out","w");
    fprintf(outFile, "Inicial: $%d\n",sumarDineroCaja(cantidadDisponible,valoresDinero) );
    do{
        printf("         MENU\n");
        printf("1) Ingresar pago.\n");
        printf("2) Salir\n" );
        printf("\nIngrese una option: ");
        memset(option,0,sizeof(option));
        fflush(stdin);
        scanf("%s",option);
        if (!strcmp(option,"1")){

            printf("Total a pagar   : ");
            scanf("%d",&totalPagar);
            printf("Cliente entrega : " );
            scanf("%d",&clienteEntrega );
            int vuelto = clienteEntrega - totalPagar;
            if (vuelto >= 0){
                if(!calculate(cantidadDisponible,cantidadEntregada,valoresDinero,totalPagar,clienteEntrega,outFile,&pago)){
                    fclose(outFile);
                    break;
                }
            }
            else{
                printf("Falta dinero para pagar, no se ha realizado ninguna accion...\n\n" );
            }

    }

    }while(strcmp(option,"2"));
    fclose(outFile);

    return 0;
}
