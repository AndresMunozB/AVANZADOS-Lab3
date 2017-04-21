#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    int cantidadDisponible[100];
    int cantidadEntregada[100];
    int valoresDinero[100];
    int vuelto = 36665;

    loadValues("entrada.in",cantidadDisponible,cantidadEntregada,valoresDinero);
    showValues(cantidadDisponible,cantidadEntregada,valoresDinero);
    calculate(cantidadDisponible,cantidadEntregada,valoresDinero,vuelto);
    showValues(cantidadDisponible,cantidadEntregada,valoresDinero);
    printf("Entregado: %d\n",sumarDineroEntregado(cantidadEntregada,valoresDinero));
    return 0;
}
