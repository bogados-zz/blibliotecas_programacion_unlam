#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED


typedef struct
{
    int ped, art,cant;
    float precio;
}
t_dato;

typedef struct s_nodo
{
    t_dato dat;
    struct s_nodo *sig;
}t_nodo;

typedef struct
{
    t_nodo *pri, *ult;
}t_cola;



void crear_cola(t_cola *);
int sacar_de_cola(t_cola *, t_dato*);
int poner_en_cola(t_cola*,const t_dato*);
void vaciar_cola(t_cola*);
int mostrar_tope(const t_cola*, t_dato*); /// muestra el primero
int cola_vacia(const t_cola*);
int cola_llena(const t_cola*);

#endif // COLA_H_INCLUDED
