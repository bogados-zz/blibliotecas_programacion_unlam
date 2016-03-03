#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/cola.h"
#include "../bibliotecas/lista.h"
#include "../bibliotecas/pila.h"
#include "../bibliotecas/mi_utilitario.h"
#include "../bibliotecas/tipos.h"

#define NO_HAY_PRODUCTO 2
#define TODO_OK 1
#define SIN_SSEG 0

void texto_a_bin(char * cad, t_dato*);
void ingresar_info(t_dato*);

int main()
{
    t_cola cola; /// carga en la cola
    t_cliente cliente;
    FILE *pf,*pf2; ///pf2 si el producto no se encuentra el archivo se guarda en txt
    t_pila pila; /// productos que la cantidad de stock sea menor que la de seguridad
    t_listaD lista; /// el pedido se pone en una lista si no alcanza el stock
    t_dato info;
    char path[100]="/home/emanuel/Programacion/Programación C/archivos/", aux[104], auxc[50];

    /** declaraciones realizadas******/
    crear_pila(&pila);
    crear_cola(&cola);
    crear_listaD(&lista);
    strcpy(aux, path);
    strcat(aux,"pedidios.txt");
    pf=fopen(aux,"rt");
    strcpy(aux,path);
    strcat(aux,"no_existentes.txt");
    pf2=fopen(aux,"wt");
    if(!pf||!pf2)
        fin_anormal("ERROR AL CARGAR ARCHIVO");
    ingresar_info(&cliente);
    do
    {
        char op;
        system("clear");
        printf("DESEA AGREGAR ELEMENTO A LA COLA Y/N");
        scanf("%c",op)
        ingresar_info(&cliente);
    }while(poner_en_cola(&cola,&cliente)&&op!=0);
    /// ya tenemos los elementos en cola

    /**fgets(auxc,50,pf);

    texto_a_bin(auxc,info);
    while(!feof(pf)||poner_en_cola(&cola,info))
    {
        fgets(auxc,50,pf);
        texto_a_bin(auxc,info);
    }*/

    while(sacar_de_cola(&cola,&cliente))
    {
        switch(buscar_en_arch(pf,&info,&cliente))
        {
            case 1: actualizar_arch();break
            case 2: grabar_pedido(pf2,&cliente); break;
            case 3: poner_en_listaD_ord(&lista,&info); break;
        }

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

void ingresar_info(t_dato *d)
{
    system("clear");
    printf("\n\nINGRESE NUMERO DE CLIENTE\t");
    scanf("%d",&d->cliente);
    printf("\n\nINGRESE CODIGO DE PRODUCTO \t");
    scanf("%d",&d->prod);
    printf("\n\nINGRESE CANTIDAD \t");
    scanf("%d",&d->cant);
}


int buscar_en_arch(FILE * pf, t_dato *d,const t_cliente* ped)
{
    char aux [50];
    fgets(aux,50,pf);
    while(!feof(pf)||d ->prod!=ped->prod)
    {
        texto_a_bin(aux,d);
        fgets(aux,50,pf);
    }
    if (feof(pf))
        return NO_HAY_PRODUCTO;
    if (d->cant < d->sseg)
        return SIN_SSEG;
}

void grabar_pedido(FILE* pf, t_cliente * cliente)
{
    fprintf(pf,"%d\t%d\t%d",cliente -> cliente, cliente ->prod, cliente -> cant);
}
