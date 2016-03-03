#include <stdio.h>
#include <stdlib.h>
#include "mi_utilitario.h"
#include <string.h>
#include <ctype.h>
/**
void pausa()
{
    printf("\n PRESIONE UNA TECLA PARA CONTINUAR...");
    __fpurge(stdin);
    getchar();
}*/

void fin_anormal(const char*cad)
{
    system("clear");
    printf("%s",cad);
    system("pause");
    exit(1);
}

char obtener_opcion(const char* menu, int cf, int cc)
{
    char op;
    imprimir_menu(menu,cf,cc);
    op=ingresar_opc("INGRESE OPCION: \t");
    while(!strchr(menu,op))
        {
          imprimir_menu(menu,cf,cc);
          op=ingresar_opc("OPCION ERRONEA. INGRESE OPCION NUEVAMENTE: \t");
        }
    return op;
}

void imprimir_menu(const char* menu, int cf, int cc)
{
    int i=0;
    system("clear");
    while(cf-1 > i)
    {
        printf("\n %c", *(menu+i));
        printf(":\t %s \n", (menu+(i+1)*cc));
        i++;
    }
}
char ingresar_opc(const char* texto)
{
  char op;
  printf("\n %s", texto);
  fflush(stdin);
  scanf("%c", &op);
  return toupper(op);
}

void obtener_path(char *path)
{
    system("cls");
    printf("INGRESE PATH:\n");
    fflush(stdin);
    fgets(path,100,stdin);
}


void pausa()
{
    system("pause");
}
