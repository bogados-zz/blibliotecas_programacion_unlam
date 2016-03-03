#ifndef COLA_CIRC_H_INCLUDED
#define COLA_CIRC_H_INCLUDED

typedef struct
{
    int clave;
    float importe;
} t_dato;

typedef struct s_nodo
{
    t_dato dat;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo* t_colac;

void crear_colac(t_colac*);
int encolarc(t_colac*, const t_dato*);
int desencolarc(t_colac*,t_dato*);
int colacllena(const t_colac*);
int colacvacia(const t_colac*);
int mostar_topec(const t_colac*,t_dato*);
void vaciar_colac(t_colac*);

#endif // COLA_CIRC_H_INCLUDED
