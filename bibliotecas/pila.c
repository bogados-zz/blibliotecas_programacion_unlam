#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define SIN_MEMORIA 0
#define TODO_OK 1
#define PILA_VACIA -1

void crear_pila(t_pila *p)
{
    *p==NULL;
    return;
}

int pila_vacia(const t_pila * p)
{
    return *p==NULL;
}

int apilar(t_pila* p, const t_dato* dat)
{
    t_nodo *nue = (t_nodo*)malloc(sizeof(t_nodo));


    if(!nue)
        return SIN_MEMORIA;
    nue -> dat= *dat;
    nue -> sig = *p;
    *p = nue;
    return TODO_OK;
}

int desapilar(t_pila *pp, t_dato* dat)
{
    t_nodo *aux;
    if(!*pp)
        return PILA_VACIA;
    aux=pp;
    *dat= aux->dat;
    pp=aux->sig;
    free(aux);
    return TODO_OK;
}

void vaciar_pila(t_pila *pp)     /// falta algo de poner el NULL
{
    t_nodo *aux;
    while(pp)
    {
        aux=pp;
        *pp= aux->sig;
        free(aux);
    }
}

int ver_tope(t_pila *p, t_dato *d)
{
    if(!(*p))
        return PILA_VACIA;
    *d= (*p)->dat;
    return TODO_OK;
}

int pila_llena(const t_pila *p)
{
    t_nodo *aux= (t_nodo*)malloc(sizeof(t_nodo));
    free(aux);
    return aux==NULL? 1:0;

}
