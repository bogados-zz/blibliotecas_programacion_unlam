#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/mi_utilitario.h"


typedef struct
{
    char prod[50];
    int cant,sseg;
}t_dato;

void tex_a_bin(char*, t_dato*);

int main()
{
    t_dato reg;

    char path[]="/home/emanuel/Programacion/Programación C/archivos/pedidos.txt", aux[100];
    FILE *pf;
    pf=fopen(path,"rt");
    if(!pf)
    {
        printf("PROBLEMA AL ABRIR EL ARCHIVO");
        exit(1);
    }
    __fpurge(stdin);
    fgets(aux,sizeof(aux),pf);
    while(!feof(pf))
    {
        tex_a_bin(aux,&reg);
        printf("\n\nPRODUCTO:   %s    ", reg.prod);
        printf("CANTIDAD EN STOCK:    %d   ",reg.cant );
        printf("STOCK DE SEGURIDAD:   %d   ", reg.sseg);
        fgets(aux,sizeof(aux),pf);
    }
    return 0;
}

void tex_a_bin(char* cad, t_dato* dat)
{
    char *aux=NULL;
    int aux1;
    aux=strrchr(cad,'|');
    aux++;
    aux1=atoi(aux);
    dat-> sseg= aux1;
    aux--;
    *aux= '\0';
    aux= strrchr(cad,'|');
    aux++;
    aux1=atoi(aux);
    dat -> cant= aux1;
    aux--;
    *aux='\0';
    aux=strrchr(cad,'|');
    aux++;
    strcpy(dat -> prod,aux);
}
