#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/mi_utilitario.h"


typedef struct
{
    int nro_reg;
    /*int ped, art,cant;
   */ float precio;
}
t_dato;

int main()
{
    t_dato reg;
    FILE *pf;
    pf=fopen("/home/emanuel/Programacion/Programación C/tarea1702/archivo.bin","rb");
    if(!pf)
        exit(0);
    system("clear");
    fread(&reg,sizeof(t_dato),1,pf);
    while(!feof(pf))
    {
        printf(" \n\n\n\n NRO REG: %d\t", reg.nro_reg);
        printf(" \n PRECIO: %f\t", reg.precio);
       /* printf(" \n\n\n\n PEDIDO: %d\t", reg.ped);
        printf(" \n ARTICULO: %d\t", reg.art);
        printf(" \n CANTIDAD: %d\t", reg.cant);
        printf(" \n PRECIO: %f \t", reg.precio);*/
        fread(&reg,sizeof(t_dato),1,pf);
    }
    pausa();
    return 0;
}
