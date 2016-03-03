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
    int aux;
    FILE *pf;
    float auxf;
    pf=fopen("/home/emanuel/Programacion/Programación C/tarea1702/archivo.bin","rb+");
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
    system("clear");

    printf("\n\n Ingrese el registro a modificar");
    scanf("%d",&aux);
    system("clear");
    printf("\n\n Ingrese el precio a sumar");
    scanf("%f",&auxf);
    fseek(pf,sizeof(t_dato)*aux,SEEK_SET);
    fread(&reg,sizeof(t_dato),1,pf);
    reg.precio+=auxf;
    fseek(pf,-sizeof(t_dato),SEEK_CUR);/// VUELVO HACIA ATRÁS
    fseek(pf,0,1);/// apunta hacia adelante
    fwrite(&reg,sizeof(t_dato),1,pf);
    fseek(pf,0,SEEK_SET);
    fseek(pf,aux*sizeof(t_dato),SEEK_SET);
    fread(&reg,sizeof(t_dato),1,pf);
    system("clear");
    printf(" \n\n\n\n NRO REG: %d\t", reg.nro_reg);
    printf(" \n PRECIO: %f\t", reg.precio);
    fclose(pf);
    return 0;
}
