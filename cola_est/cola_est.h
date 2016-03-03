#ifndef COLA_EST_H_INCLUDED
#define COLA_EST_H_INCLUDED
#define TAM 10

typedef struct
{
    long dni;
}
t_dato;

///typedef struct t_dato t_nodo;

typedef struct
{
    t_dato dat[10];
    int pri, ult;
}t_cola;


void crear_cola(t_cola *);
int desencolar(t_cola *, t_dato*);
int encolar(t_cola*,const t_dato*);
void vaciar_cola(t_cola*);
int mostrar_tope(const t_cola*, t_dato*); /// muestra el primero
int cola_vacia(const t_cola*);
int cola_llena(const t_cola*);

#endif // COLA_EST_H_INCLUDED
