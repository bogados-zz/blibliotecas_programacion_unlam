#include <stdio.h>
#include <stdlib.h>
#include "listaD.h"
#define CLAVE_DUPLICADA 0
#define NO_SE_HA_ENCONTRADO_ELEMENTO 0
#define SIN_MEMORIA 0
#define TODO_OK 1
#define SIN_ELEMENTOS 0

int comparar(t_dato* d1, t_dato* d2)
{
    return d1-> clave > d2 -> clave? 1: d1-> clave < d2 ->clave? -1:0;
}

void crear_listaD(t_listaD* pl)
{
    *pl= NULL;
}

int poner_en_listaD_ord (t_listaD *pl, t_dato *d)
{
    t_nodo *ante, *act, *aux;
      act = *(pl);
    if(act)
        ante = act-> ant;
    else
        ante = NULL;
    while(act && comparar(d, &act ->dat)>0) /// D mayor QUE DAT
        {
            ante = act;
            act = act->sig;
        }
    while(ante && comparar(d, &ante ->dat)<0) /// DATO MAYOR QUE D
        {
            act=ante;
            ante = ante -> ant;
        }
    aux = (t_nodo*)malloc (sizeof(t_nodo));
    if(!aux)
        return SIN_MEMORIA;
    if(comparar(d, &ante ->dat) == 0 || comparar(d, &act ->dat) == 0)
    {
        return CLAVE_DUPLICADA;
    }
    aux -> dat = *d;
    aux -> sig = act; /// hago que el siguiente apunte al sig del ant
    aux -> ant = ante;  /// hago que el ant apunte al anterior del sig
    if(ante)
        ante-> sig= aux;
    if(act)
        act -> ant = aux;
    return TODO_OK;
}

int eliminar_en_listaD_ord(t_listaD *pl, t_dato *d)
{
    t_nodo *act, *ante,*aux;

    if(!(*pl))
        return SIN_ELEMENTOS;

    act=*pl;
    ante= act->ant;

    while (act && comparar(d, &act->dat)>0) /// que d sea may
        act = act-> sig;

    while ( act && comparar(d, &ante -> dat) < 0) ///
        act = act-> ant;

    if(!act || comparar(d, &act ->dat)!=0)
        return NO_SE_HA_ENCONTRADO_ELEMENTO;

    *d = act-> dat;
    ante= act-> ant;
    aux=act;
    act= act-> sig;
    act -> ant = ante;
    (*pl) = act;
    free(aux);
    if(ante)
        ante-> sig = act;

    return TODO_OK;
}

void vaciar_listaD(t_listaD *pl)
{
    t_nodo *aux;
    if(!(*pl))
        return;
    aux=(*pl)->sig;
    while(aux&&aux->sig)
    {
        (*pl)=aux->sig;
        aux->sig->ant=(*pl);
        free(aux);
        aux=(*pl)->sig;
    }
    if(aux)
        free(aux);
    aux=(*pl)->ant;
    while(aux&&aux->ant)
    {
        (*pl)->ant=aux->ant;
        aux->ant->sig=(*pl);
        free(aux);
        aux=(*pl);
    }
    if(aux)
        free(aux);
    free((*pl));
    (*pl)=NULL;
}


int buscar_listaD(const t_listaD *pl,t_dato *d)
{

    t_nodo *aux=(*pl);
    if(!aux)
        return SIN_ELEMENTOS;
    while(comparar(&aux->dat,d)>0&&aux)
    {
        aux=aux->sig;
    }
    if(!aux)
        return 0;
    if(comparar(&aux->dat,d)==0)
        {
            *d=aux->dat;
            return TODO_OK;
        }

    while(comparar(&aux->dat,d)<0&&aux)
        aux=aux->ant;
    if(!aux)
        return 0;
    *d=aux->dat;
    return TODO_OK;
}

int listaDllena(const t_listaD *pl)
{

    t_nodo *aux=(t_nodo*)malloc(sizeof(t_nodo));
    free(aux);
    return aux==NULL;
}

int listaDvacia(const t_listaD *pl)
{
    return (*pl)==NULL;
}
