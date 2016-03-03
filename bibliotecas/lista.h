#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


typedef struct
{
    long dni;
    char nombre[60];
    char apellido[60];
}t_dato;

typedef struct s_nodo
{
    t_dato dat;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo* t_lista;

void crear_lista(t_lista*);
int poner_en_lista_sin_rep(t_lista*, const t_dato*);
int sacar_de_lista_ord(t_lista*, t_dato*);


#endif // LISTA_H_INCLUDED
