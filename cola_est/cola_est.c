#include <stdio.h>
#include <stdlib.h>
#include "cola_est.h"
#define COLA_LLENA 0
#define TODO_OK 1
#define SIN_ELEMENTOS 0

void crear_cola(t_cola *pc)
{
    pc-> pri=0;
    pc-> ult=-1;
}

int desencolar(t_cola *pc, t_dato *d)
{
    if(pc -> ult==-1)
        return SIN_ELEMENTOS;
    *d = pc-> dat[pc -> pri];
    pc -> pri++;
    return TODO_OK;
}

int encolar(t_cola *cola,const t_dato* d)
{
        if((cola->pri ==0&& cola -> ult == TAM-1) || cola -> pri%TAM == cola -> ult%TAM)
            return COLA_LLENA;
        cola -> ult++;
        cola->dat[cola -> ult%TAM]=*d;
        return TODO_OK;
}


void vaciar_cola(t_cola *pc)
{
    pc -> pri=0;
    pc -> ult=-1;
}

int mostrar_tope(const t_cola *pc, t_dato *d) /// muestra el primero
{
    if ((pc->pri ==0&& pc -> ult == TAM-1) || pc -> pri%TAM == pc -> ult%TAM)
        return SIN_ELEMENTOS;
    *d= pc->dat[pc->pri];
    return TODO_OK;
}

int cola_vacia(const t_cola* pc)
{
    return pc-> pri == 0&& pc-> ult==-1? 1:0;
}
int cola_llena(const t_cola* pc)
{
    return ((pc->pri ==0&& pc -> ult == TAM-1) || pc -> pri%TAM == pc -> ult%TAM) ? 1:0;
}
