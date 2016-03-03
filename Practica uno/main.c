#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/mi_utilitario.h"
#include "../bibliotecas/numero.h"
#include "../bibliotecas/fecha.h"
#include "../bibliotecas/vectores.h"

#define FILA 7
#define COL 40
void menu_numeros();
void menu_fecha();
void menu_vectores();
int main()
{
    char op, texto[FILA][COL]={"NFVMCS","MENU DE NUMEROS","MENU DE DE FECHA","MENU DE VECTORES","MENU DE MATRICES","MENU DE CADENAS","SALIR"};
    do
    {
        op = obtener_opcion(texto,FILA,COL);
        switch(op)
        {
            case 'N': menu_numeros();
                      break;
            case 'F': menu_fecha();
                      break;
            case 'V': menu_vectores();break;
            /**case 'M': menu_matrices;
                      break;
            case 'C': menu_cadena;
        */}
    }while(op!='S');

    return 0;
}

void menu_numeros()
{
  char op, menu[][40]={"ABCDEFS","EJERCICIO N 1", "EJERCICIO N 2",
                    "EJERCICIO N 3","EJERCICIO N 4","EJERCICIO N 5","EJERCICIO N 6","SALIR"};
    int cf=8;
    do
    {
        op=obtener_opcion(menu, cf, 40);
        switch (op)
        {
            case 'A': ejercicio1(); break;
            case 'B': ejercicio2(); break;
            case 'C': ejercicio3(); break;
            case 'D': ejercicio4(); break;
            case 'E': ejercicio5(); break;
            case 'F': ejercicio6(); break;
        }
    }while(op!='S');
}

void menu_fecha()
{
  char op, menu[][40]={"ABCDEFS","EJERCICIO N 14", "EJERCICIO N 15",
                    "EJERCICIO N 16","EJERCICIO N 17","EJERCICIO N 18","EJERCICIO N 19","SALIR"};
    int cf=8;
    do
    {
        op=obtener_opcion(menu, cf, 40);
        switch (op)
        {
            case 'A': ejercicio14(); break;
            case 'B': ejercicio15(); break;
            case 'C': ejercicio16(); break;
            case 'D': ejercicio17(); break;
            case 'E': ejercicio18(); break;
            case 'F': ejercicio19(); break;
        }
    }while(op!='S');
}

void menu_vectores()
{
  char op, menu[][40]={"ABCDEFGS","EJERCICIO N 22", "EJERCICIO N 23",
                    "EJERCICIO N 24","EJERCICIO N 25","EJERCICIO N 26","EJERCICIO N 27","EJERCICIO N 28","SALIR"};
    int cf=9;
    do
    {
        op=obtener_opcion(menu, cf, 40);
        switch (op)
        {
            case 'A': ejercicio22(); break;
           /** case 'B': ejercicio23(); break;
            case 'C': ejercicio24(); break;
            case 'D': ejercicio25(); break;
            case 'E': ejercicio26(); break;
            case 'F': ejercicio27(); break;
            case 'G': ejercicio28(); break;*/
        }
    }while(op!='S');
}
