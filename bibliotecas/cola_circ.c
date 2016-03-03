#include <stdio.h>
#include <stdlib.h>
#include "cola_circ.h"
#define SIN_MEMORIA 0
#define SIN_ELEMENTOS 0
#define TODO_OK 1

void crear_colac(t_colac* p)
{
    *p=NULL;
}

int encolarc (t_colac *p, const t_dato*d)
{
    t_nodo *nue;
    nue= (t_nodo*) malloc(sizeof(t_nodo));
    if(!nue)
        return SIN_MEMORIA;
    nue->dat= *d;
    if(!(*p))
        nue->sig= nue;
    else
    {
        nue->sig= (*p)->sig;
        (*p)->sig= nue;
    }
    *p=nue;
    return TODO_OK;
}

int desencolarc(t_colac *p, t_dato *d)
{
    t_nodo *aux;
    if(!*p)
        return SIN_ELEMENTOS;
    aux= (*p) -> sig;
    *d= aux -> dat;
    (*p)-> sig= aux-> sig;
    if(aux->sig== aux)
        *p=NULL;
    free (aux);
    return TODO_OK;
}

void vaciar_colac(t_colac *p)
{
    t_nodo *aux;
    if(!*p)
        return;
    while((*p)-> sig != (*p))
    {
        aux= (*p)->sig;
        (*p) -> sig= aux->sig;
        free(aux);
    }
    aux=(*p)-> sig;
    (*p)=NULL;
    free(aux);
    return;
}

int colacllena(const t_colac *pc)
{
    t_nodo *aux=(t_nodo*)malloc(sizeof(t_nodo));
    free(aux);
    if(!aux)
        return 1;
    return 0;
}

int colacvacia(const t_colac *pc)
{

    if(!(*pc))
        return 1;
    return 0;
}

int mostar_topec(const t_colac*pc,t_dato *d)
{

    if(!*pc)
        return SIN_ELEMENTOS;
    *d=(*pc)->sig-> dat;
    return TODO_OK;
}
