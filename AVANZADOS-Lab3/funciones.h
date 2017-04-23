#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/*
 * Funcion existFile
 * Funcion que verifica si un archivo existe
 * @param char* filename, nombre del archivo
 * @return entero 1 en caso de que si exista y 0 en caso contrario
*/
int existsFile(char* filename) ;
void loadValues(char* filename,int cantidadDisponible[],int valoresDinero[] );
void showValues(int cantidadDisponible[],int cantidadEntregada[],int valoresDinero[] );
int calculate(int cantidadDisponible[],int cantidadEntregada[],int valoresDinero[],int totalPagar,int clientePaga,FILE* outfile,int* pago);
void initCantidadEntregada(int cantidadEntregada[]);
int sumarDineroCaja(int cd[],int vd[]);
void showVueltoMinimo(int ce[],int vd[]);



#endif // FUNCIONES_H_INCLUDED
