#include <stdio.h>
#include <stdlib.h>


void crear_pila(t_pila *pp)
{
    pp->tope=0;
}

int pila_vacia(const t_pila *pp)
{
    return pp-> tope==0;
}

int pila_llena(const t_pila*)
{
    return pp->tope==TAM;
}

int ver_tope(const t_pila *pp , t_dato *d)
{
    if(!pp->tope)
        return COLA_VACIA;
    *d = pp-> *(pila + pp->tope);
}
int apilar(t_pila*pp, const t_dato* dat)
{
    if(pp->tope== TAM)
        return PILA_LLENA;
    pp->*(pila+ pp -> tope) = dat;
    tope++;
    return TODO_OK;
}

int desapilar(t_pila*, t_dato *)
{
    if(!pp->tope)
        return PILA_LLENA;
    tope--;
    dat= pp->*(pila+ pp -> tope);
    return TODO_OK;
}


int vaciar_pila(t_pila*pp);
{
    pp->tope=0;
}
