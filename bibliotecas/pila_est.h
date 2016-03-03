#ifndef PILA_EST_H_INCLUDED
#define PILA_EST_H_INCLUDED
#define TAM 20

typedef struct
{
    long dni;

}t_dato;

typedef struct
{
    t_dato pila[TAM];
    int tope;
}

void crear_pila(t_pila*);
int pila_vacia(const t_pila *);
int pila_llena(const t_pila*);
int ver_tope(const t_pila*, t_dato*);
int apilar(t_pila*, const t_dato*);
int desapilar(t_pila*, t_dato *);
int vaciar_pila(t_pila*);

#endif // PILA_EST_H_INCLUDED
