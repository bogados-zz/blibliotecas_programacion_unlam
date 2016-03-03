#ifndef LISTAD_H_INCLUDED
#define LISTAD_H_INCLUDED

typedef struct
{
    int clave;
    float importe;
} t_dato;

typedef struct s_nodo
{
    t_dato dat;
    struct s_nodo *ant, *sig;
}t_nodo;

typedef t_nodo* t_listaD;

void crear_listaD(t_listaD*);
int poner_en_listaD_ord(t_listaD*,t_dato*);
int eliminar_en_listaD_ord(t_listaD*,t_dato*);
int buscar_listaD(const t_listaD*,t_dato*);
int listaDllena(const t_listaD*);
int listaDvacia(const t_listaD*);
void vaciar_listaD(t_listaD*);



/// FUNCIONES*********************************

void crear_listaD(t_listaD*);
int poner_en_listaD_ord (t_listaD *, t_dato*);
int eliminar_en_listaD_ord(t_listaD *, t_dato *);

#endif // LISTAD_H_INCLUDED
