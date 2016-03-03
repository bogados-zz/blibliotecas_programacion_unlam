#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED



typedef struct
{
    long clave; /// es el dni
    int codc; /// codigo de cliente

}t_dato;


typedef struct s_nodo
{
    struct s_nodo *nizq;
    t_dato dat;
    int reg;
    struct s_nodo *nder;
}t_nodo;


typedef t_nodo * t_arbol;


void crear_arbol(t_arbol*);
int cargar_arbol(t_arbol*, t_dato*);
int guardar_arbol_en_arch_in(t_arbol*,FILE*);
void guardar_arbol_en_arch_pre(t_arbol*, FILE *);
void recorrer_inorden(t_arbol*);
void recorrer_posorden(t_arbol*);
void recorrer_preorden(t_arbol*);
void recorrer_inorden_indice(t_arbol*);
int cargar_arbol_de_arch_bin_in(t_arbol*,FILE *,int, int);
void cargar_arbol_de_arch_bin_pre(t_arbol*,FILE *);


void mostrar_arbol(t_dato*);
int comparar_nodo(t_dato*, t_dato*);

int contar_nodos(t_arbol*);
int contar_claves_pares(t_arbol*);
int mostrar_los_nodos_con_hijos_por_izq(t_arbol *);
int mostrar_los_nodos_con_hijos_solo_izq(t_arbol *);

void mostrar_arbol_alt(t_dato*,int);

int altura_arbol(t_arbol*);
void podar_arbol(t_arbol*);


void preord_alt(t_arbol*, int);
int buscar_arbol(const t_arbol*,t_dato*);
t_nodo* buscar_arbol_dir(const t_arbol*,t_dato*);


void mostrar_arbol_in(t_dato*,int);

#endif // ARBOL_H_INCLUDED
