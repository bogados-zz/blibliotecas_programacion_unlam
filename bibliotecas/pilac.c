#include <stdio.h>
#include <stdlib.h>
#include "pilac.h"
#include "mi_utilitario.h"
#define SIN_MEMORIA 0
#define TODO_OK 1
#define SIN_ELEMENTOS 0

void crear_pilac (t_pilac * pp)
{
    *pp=NULL;
}

int poner_en_pilac (t_pilac *pp, const t_dato* d)
{
    t_nodo *nue= (t_nodo*)malloc( sizeof(t_nodo));
    if(!nue)
        return SIN_MEMORIA;
    nue->dat= *d;
    if(!*pp)
    {
        nue->sig=nue;
        *pp=nue;
    }

    else
    {
        nue->sig= (*pp)->sig;
        (*pp)->sig=nue;
    }
    return TODO_OK;

}

int sacar_de_pilac(t_pilac* pp, t_dato *d)
{
    t_nodo *aux;
    if(!*pp)
        return SIN_ELEMENTOS;
    aux= (*pp)->sig;
    *d= aux->dat;
    (*pp)->sig= aux-> sig;
    if((*pp)== (*pp)-> sig)
        (*pp)= NULL;
    free(aux);
    return TODO_OK;
}

void vaciar_pilac (t_pilac *pp)
{
    t_nodo *aux;
    if(!(*pp))
        return;
    while((*pp)!= (*pp)-> sig)
    {
        aux= (*pp);
        (*pp)= (*pp)->sig;
        free(aux);
    }
    aux= (*pp);
    free(aux);
    (*pp)=NULL;
}

int mostar_tope(const t_pilac *pp, t_dato* d)
{
    if(!(*pp))
        return SIN_ELEMENTOS;
    *d=(*pp)->dat;
    return TODO_OK;
}

int pila_llena(const t_pilac* pp)
{
    t_nodo *aux=(t_nodo*)malloc(sizeof(t_nodo));
    free(aux);
    if(!aux)
        return 1;
    return 0;
}

int pila_vacia(const t_pilac*pp)
{
    return (*pp)==NULL;
}

void grabar_arch(t_pilac *pp, FILE *pf)
{
    t_dato aux;
    while(sacar_de_pilac(pp,&aux))
    {
        fwrite(&aux,sizeof(t_dato),1,pf);
    }
}

void cargar_desde_arch(t_pilac *pp, FILE *pf)
{
    t_dato aux;
    FILE *faux=pf;
    int reg;
    fseek(faux,0,SEEK_END);
    reg=ftell(faux)/sizeof(t_dato);
    for(reg-=1;reg>=0;reg--)
    {
        fseek(faux,sizeof(t_dato)*reg,SEEK_SET);
        fread(&aux,sizeof(t_dato),1,pf);
        if(poner_en_pilac(pp,&aux))
        {
            printf("REGISTRO CARGADO CON EXITO");
            pausa();
        }
    }
}
