#ifndef PILAC_H_INCLUDED
#define PILAC_H_INCLUDED
typedef struct
{
    long dni;
    char nomya[51];
}t_dato;

typedef struct s_nodo
{
    t_dato dat;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo* t_pilac;

void crear_pilac (t_pilac *);
int poner_en_pilac (t_pilac *, const t_dato*);
int sacar_de_pilac(t_pilac*, t_dato *);
void vaciar_pilac (t_pilac*);
int mostar_tope(const t_pilac*, t_dato*);
int pila_vacia(const t_pilac*);
int pila_llena(const t_pilac*);



#endif // PILAC_H_INCLUDED
