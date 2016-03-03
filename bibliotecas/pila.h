#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "tipos.h"

typedef struct s_nodo
{
    t_dato dat;
    struct s_nodo *sig;
}t_nodo;

typedef struct   t_nodo * t_pila;

void crear_pila (t_pila *);
int pila_vacia(const t_pila* );
int pila_llena(const t_pila* );
int apilar(t_pila*, const t_dato*);
int desapilar(t_pila*, t_dato*);
void vaciar_pila(t_pila*);
int ver_tope(t_pila*, t_dato*);



#endif // PILA_H_INCLUDED
