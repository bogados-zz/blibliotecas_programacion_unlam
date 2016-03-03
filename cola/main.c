#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/cola.h"
#include "../bibliotecas/mi_utilitario.h"

int ingresar_dato(t_dato*);
void cargar_cola_desde_arch(t_cola*,FILE*);
void texto_a_bin(char*, t_dato*);
///void grabar_cola(t_cola*,FILE*);
int main()
{
    t_cola cola;
    t_dato dato;
    FILE *pf=fopen("/home/emanuel/Programacion/Programación C/archivos/pruebacola.txt","rt");
    if(!pf)
    {
        fin_anormal("ERROR AL CARGAR EL ARCHIVO");
    }

    crear_cola(&cola);
    cargar_cola_desde_arch(&cola,pf);

    while(ingresar_dato(&dato))
    {

        if(poner_en_cola(&cola,&dato))
            printf( " EL DATO FUE INGRESADO");
    }

    pf=fopen("/home/emanuel/Programacion/Programación C/archivos/pruebacola.txt","wt");
     while(!cola_vacia(&cola))
    {
        sacar_de_cola(&cola,&dato);
        system("clear");
        printf("ESTA ES LA COLA     %d\t%d\t%d\t%f\n", dato.art,dato.cant,dato.ped,dato.precio);
        pausa();
        fprintf(pf,"%d|%d|%d|%f\n", dato.art,dato.cant,dato.ped,dato.precio);
    }
    fclose(pf);
    return 0;
}




int ingresar_dato(t_dato*d)
{
    float aux;
    system("clear");
    printf("INGRESE EL PEDIDO:   ");
    scanf("%d", &d->ped);
    if(d->ped ==-1)
        return 0;
    printf("INGRESE EL PRECIO:   ");
    scanf("%f", &aux);
    d->precio=aux;
    printf("INGRESE EL ARTICULO:   ");
    scanf("%d", &d->art);
    printf("INGRESE LA CANTIDAD:   ");
    scanf("%d", &d->cant);
    return 1;
}

void cargar_cola_desde_arch(t_cola *pc,FILE *pf)
{
    t_dato dato;
    char aux[100];
    fgets(aux,sizeof(aux),pf);
    while(!feof(pf))
    {
        system("clear");
        printf("%s",aux);
        pausa();
        texto_a_bin(aux,&dato);
        if(poner_en_cola(pc,&dato))
            {
                system("clear");
                printf("SE HA CARGADO EL REGISTRO");
            }
        fgets(aux,sizeof(pf),pf);
    }

}

void texto_a_bin(char *cad, t_dato*d)
{
    double auxi;
    char *aux;
    system("clear");
    printf("\n\n%s",cad);
    pausa();
    aux=strrchr(cad,'|');
    auxi=atof(aux);
    d->precio=(float)auxi;
    *aux='\0';
    aux=strrchr(cad,'|');
    printf("\n%s",cad);
    printf("\n%s",aux);
    d->ped=atoi(aux);
    *aux='\0';
    aux=strrchr(cad,'|');
    d->cant=atoi(aux);
    *aux='\0';
    d->art=atoi(cad);
}
