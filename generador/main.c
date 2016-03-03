#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/mi_utilitario.h"


typedef struct
{
    int nro_reg;
    float precio;
}
t_dato;

int main()
{
    t_dato reg[16];
    FILE *pf;
    float aux;
    int i;
    pf=fopen("archivo.bin","rb");
    fseek(pf,0,SEEK_END);
    printf("LA CANTIDAD DE REGISTROS ES:  %ld", ftell(pf)/sizeof(t_dato));
    system("pause");
    pf=fopen("archivo.bin","wb");
    if(!pf)
    {
        system("cls");
        printf("ERROR AL CARGAR EL ARCHIVO...");
        system("pause");
        exit(1);
    }
    for(i=0;i<16;i++)
    {
        reg[i].nro_reg=i;
        system("cls");
        printf(" INGRESE PRECIO: \t");
        scanf("%f",&aux);
        reg[i].precio=aux;
        printf("\n\n\nEl precio es %f:",reg[i].precio);
        system("pause");
        /*system("clear");
        printf(" INGRESE PEDIDO: \t");
        scanf("%d",&reg[i].ped);
        system("clear");
        printf(" INGRESE ARTICULO: \t");
        scanf("%d",&reg[i].art);
        system("clear");
        printf(" INGRESE CANTIDAD: \t");
        scanf("%d",&reg[i].cant);
        system("clear");
        printf(" INGRESE PRECIO: \t");
        scanf("%f",&aux);
        reg[i].precio=aux;*/

    }
    for(i=0;i<16;i++)
        fwrite(&reg[i],sizeof(t_dato),1,pf);
    return 0;
}
