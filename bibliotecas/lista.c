#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define SIN_ELEMENTOS 0
#define TODO_OK 1
#define SIN_MEMORIA 0
#define ELEMENTO_REPETIDO 0
#define NO_EXISTE_REGISTRO 0

void crear_lista(t_lista* pl)
{
    (*pl)=NULL;
}

int comparar(const t_dato* d1, const t_dato* d2)
{
    return d1 -> dni < d2 -> dni? -1: d1 -> dni > d2 -> dni? 1:0;
}


int poner_en_lista_sin_rep(t_lista *p, const t_dato *d)
{
    t_nodo *nue;
    if((*p))
    {
        while((*p) && comparar(&(*p)->dat, d)== -1)
        p= &(*p)->sig;
        if(!comparar(&(*p)->dat, d))
            return ELEMENTO_REPETIDO;
    }

    nue= (t_nodo*) malloc(sizeof(t_nodo));
    if(!nue)
        return SIN_MEMORIA;
    nue->dat = *d; /// asignacion del dato
    nue->sig= (*p) -> sig; /// enganche
    (*p) -> sig = nue;
    return  TODO_OK;
}

/*
int poner_en_lista_sum_rep(t_lista *p, const t_dato *d)
{
    t_nodo *nue;
    while((*p) && comparar(&(*p)->dat, d)== -1)
        p = &(*p)->sig;
    if(!comparar(&(*p)->dat, d))
    {
        (*p)->dat.importe = d->importe;
        return TODO_OK;
    }
    nue= (t_nodo*) malloc(sizeof(t_nodo));
    if(!nue)
        return SIN_MEMORIA;
    nue->dat = *d; /// asignacion del dato
    nue->sig= (*p) -> sig; /// enganche
    (*p) -> sig = nue;
    return  TODO_OK;
}*/

int eliminar_por_clave_ord(t_lista *p, t_dato *d)
{
    t_nodo* aux;
    while((*p) && comparar(&(*p)->dat, d)== -1)
        p=&(*p)-> sig;
    if( !(*p) ||(*p)->dat.dni > d->dni)
        return NO_EXISTE_REGISTRO;
    aux=(*p);
    (*p)= aux -> sig;
    *d= aux->dat;
    free(aux);
    return TODO_OK;
}

/*
int eliminar_repetidos_ord_sum(t_lista *p, t_dato *d)
{
    t_nodo *aux;
    while( (*p) && comparar(&(*p)->dat, d)== -1)
        p=&(*p)-> sig;

    if((*p)==NULL|| comparar(&(*p)->dat, d)== 1)
        return SIN_ELEMENTOS;

    while((*p)->sig   &&  comparar(&(*p)->dat, d)==0)
        {
            aux = (*p)-> sig;
            (*p)->dat.importe+= aux->dat.importe;
            (*p)->sig = aux->sig;
            free(aux);
        }
    return TODO_OK;
}*/

int eliminar_todos_repetidos_ord(t_lista *p)
{
    t_nodo *aux;
    if(!(*p))
        return SIN_ELEMENTOS;
    while((*p) && (*p) -> sig)
    {
        if(!comparar(&(*p) -> dat, &(*p) -> sig -> dat))
        {
            while((*p) -> sig && !comparar(&(*p) -> dat, &(*p) -> sig -> dat))
            {
                aux = (*p);
                (*p) = (*p)->sig;
                free(aux);
            }
                aux = (*p);
                (*p) = (*p)->sig;
                free(aux);
        }
        else
            p= &(*p) -> sig;

    }
    return TODO_OK;
}

/*
int eliminar_todos_repetidos_dejando_ord(t_lista *p)
{
    t_nodo *aux;
    if(!(*p))
        return (t_lista*, t_dato*);SIN_ELEMENTOS;
    while((*p) && (*p) -> sig)
    {

        while((*p) -> sig && !comparar(&(*p) -> dat, &(*p) -> sig -> dat))
        {
            aux = (*p);
            (*p) ->  sig -> dat.importe += (*p) ->  dat.importe;
            (*p) = (*p)->sig;
            free(aux);
        }
        p= &(*p) -> sig;

    }
    return TODO_OK;
}
*/

int eliminar_por_clave_des(t_lista*p, t_dato *d)
{
    t_nodo *aux;
    while( *p && comparar(&(*p)-> dat, d)!=0)
       p= &(*p)->sig;
    if(!(*p))
        return NO_EXISTE_REGISTRO;
    *d= (*p)->dat;
    aux = (*p);
    (*p)=aux->sig;
    free(aux);
    return TODO_OK;
}

int eliminar_repetidos_des(t_lista *p, t_dato *d)
{
    int cont=0;
    t_nodo *aux;
    while(*p)
        {
            if (comparar(&(*p)-> dat, d)== 0)
                {
                    cont++;
                    aux = (*p);
                    (*p)=aux->sig;
                    free(aux);
                }
            else
                p= &(*p) -> sig;
        }
    return cont==0? 0:1;
}

int sacar_de_lista_ord(t_lista * pl, t_dato *d)
{
    if(!(*pl))
        return 0;
    t_nodo * aux = (*pl);
    (*pl)=(*pl)->sig;
    free(aux);
    return 1;
}
