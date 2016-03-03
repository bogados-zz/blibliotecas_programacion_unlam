#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "mi_utilitario.h"

#define SIN_MEMORIA 0
#define TODO_OK 1
#define COLA_VACIA 0
#define SIN_ELEMENTOS 0



void crear_cola(t_cola * pc)
{
    pc->pri= pc-> ult=NULL;
}

int poner_en_cola(t_cola *pc, const t_dato *dat)
{
    t_nodo *nue= (t_nodo*) malloc(sizeof(t_nodo));
    if(!nue)
        return SIN_MEMORIA;
    nue-> dat= *dat;
    nue -> sig= NULL;
    if(pc-> pri==NULL)
        pc->pri= nue;
    else
        pc -> ult -> sig=nue;
    pc->ult= nue;
    return 1;
}

int sacar_de_cola(t_cola *pc,t_dato *dat)
{
    t_nodo *aux;
    if(pc->pri==NULL)
        return SIN_ELEMENTOS;
    *dat = pc -> pri -> dat;
    aux = pc -> pri;
    pc -> pri = pc -> pri -> sig;
    if(pc -> pri == pc -> ult)
        pc-> ult = pc -> pri;
    free(aux);
    return TODO_OK;
}

int mostrar_tope(const t_cola* pc,t_dato *d)
{
    if(!pc->pri)
        return SIN_ELEMENTOS;
    *d= pc-> pri->dat;
    return TODO_OK;
}

void vaciar_cola(t_cola *pc)
{
    t_nodo *aux;
    while(pc->pri)
    {
        aux= pc->pri;
        pc -> pri= pc->pri->sig;
        free(aux);
    }
    pc->ult=pc->pri; /// como pri es NULL ult toma NULL....
}


int cola_vacia(const t_cola *pc)
{
    return pc->pri==NULL? 1:0;
}

int cola_llena(const t_cola *pc)
{
    t_nodo *aux=(t_nodo*) malloc(sizeof (t_nodo));
    free(aux);
    return aux!=NULL?0:1;
}


void cargar_cola_archb(t_cola*pc,FILE *pf)
{
    t_dato aux;
    fread(&aux,sizeof(t_dato),1,pf);
    while(!feof(pf)&&poner_en_cola(pc,&aux))
        fread(&aux,sizeof(t_dato),1,pf);
    if(!feof(pf))
        fin_anormal("ERROR AL CARGAR EN LA COLA");
}
