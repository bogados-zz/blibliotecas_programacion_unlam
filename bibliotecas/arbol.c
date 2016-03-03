#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "mi_utilitario.h"
#define TODO_OK 1
#define FIN_DE_ARCHIVO 2
#define SIN_MEMORIA 0
#define SIN_ELEMENTOS 0


int altura_arbol(t_arbol *pa)
{
    if(!*pa)
        return 0;
    return altura_arbol(&(*pa)->nder) > altura_arbol(&(*pa)->nizq) ? altura_arbol(&(*pa)->nder)+1 : altura_arbol(&(*pa)->nizq)+1 ;
}

void crear_arbol(t_arbol *pa)
{
    *pa=NULL;
}

int contar_nodos(t_arbol *p)
{
    if(*p)
        return 1+contar_nodos(&(*p)->nder)+contar_nodos(&(*p)->nizq);
    return 0;
}



int comparar_nodo(t_dato *darb, t_dato *d)
{
    return darb ->clave < d-> clave? 1: darb ->clave > d-> clave? -1: 0;
}


int cargar_arbol(t_arbol *pa, t_dato *d)
{
    if(!*pa)
    {
        *pa=(t_nodo*) malloc(sizeof(t_nodo));
        if(!*pa)
            return SIN_MEMORIA;
        (*pa )-> dat=*d;
        (*pa)-> nder=(*pa)-> nizq=NULL;
        return TODO_OK;
    }
    return comparar_nodo(&(*pa)->dat, d) > 0 ? cargar_arbol(&(*pa)-> nder,d) : comparar_nodo(&(*pa)->dat, d) < 0 ? cargar_arbol(&(*pa) -> nizq,d) :2;
}


void recorrer_inorden(t_arbol *pa)
{
    if(*pa)
    {
        recorrer_inorden( &(*pa)->nizq);
        mostrar_arbol(&(*pa)->dat);
        recorrer_inorden( &(*pa)->nder);
    }
    return;
}


void recorrer_inorden_indice(t_arbol *pa)
{
    if(*pa)
    {
        recorrer_inorden_indice( &(*pa)->nizq);
        mostrar_arbol_in(&(*pa)->dat, (*pa)->reg);
        recorrer_inorden_indice( &(*pa)->nder);
    }
    return;
}



void recorrer_posorden(t_arbol *pa)
{
    if(*pa)
    {
        recorrer_posorden( &(*pa) -> nizq);
        recorrer_posorden( &(*pa) -> nder);
        mostrar_arbol(&(*pa)->dat);
    }
    return;
}


void recorrer_preorden(t_arbol *pa)
{
    if(*pa)
    {
        mostrar_arbol(&(*pa)-> dat);
        recorrer_preorden(&(*pa)-> nizq);
        recorrer_preorden(&(*pa)-> nder);
    }
}


void guardar_arbol_en_arch_pre(t_arbol *pa,FILE* pf)
{
    if(*pa)
    {
        fwrite(&(*pa)->dat,sizeof(t_dato),1,pf);
        guardar_arbol_en_arch_pre(&(*pa) -> nizq,pf);
        guardar_arbol_en_arch_pre(&(*pa) -> nder,pf);
    }
}


void cargar_arbol_de_arch_bin_pre(t_arbol *pa, FILE *pf)
{
    t_dato reg;
    fread(&reg,sizeof(t_dato),1,pf);
    while(!feof(pf))
    {
        cargar_arbol(pa,&reg);
        fread(&reg,sizeof(t_dato),1,pf);
    }
}


int guardar_arbol_en_arch_in(t_arbol *pa, FILE * pf)
{
    int a,b;
    if(!*pa)
        return SIN_ELEMENTOS;
    if((*pa)->nizq)
        a=guardar_arbol_en_arch_in(&(*pa)->nizq,pf);
    fwrite(&(*pa) -> dat,sizeof(t_dato),1,pf);
    if((*pa)->nder)
        b=guardar_arbol_en_arch_in(&(*pa)->nder,pf);
    return (a&&b);
}


int cargar_arbol_de_arch_bin_in(t_arbol*pa,FILE *pf,int li, int ls)
{
    int aux;
    t_dato reg;
    if(ls>=li)
    {
        aux=(li+ls)/2;
        fseek(pf,aux*sizeof(t_dato),SEEK_SET);
        fread(&reg, sizeof(t_dato),1,pf); ///el nodo de la mitad del archivo lo pone como raiz del subarbol
        fseek(pf,0,SEEK_SET);
        if(cargar_arbol(pa,&reg))
        {
            (*pa)->reg=aux;
            return (cargar_arbol_de_arch_bin_in(&(*pa)-> nder,pf,aux+1,ls)&&cargar_arbol_de_arch_bin_in(&(*pa)-> nizq,pf,li,aux-1)); ///manda la pos-1 manda la pos +1
        }

                                                                                                                                /// para el menor ..........para la mayor
    }
     return 2;/// para que no me invalide el otro return devuelvo un dos.... diciendo 1&&2 no me da 0.... creo
}

/**
void recorrer_preordeni(t_arbol* pa)
{
    t_nodo *aux= *pa; /// es un puntero a nodo
    t_pila= pila;
    while (aux)/// trato todos por izq
    {

        cargar_pila(&pila,&aux)
        mostrar_dato(&(*aux)->dat);
        aux= aux-> nizq;
    }

    while(sacar_de_pila(&pila,&aux)) /// muestro de los nodos y la raiz la rama der
        if( *aux->nder)
            mostrar_dato( &aux->nder->dat);
    while(aux->izq)
    {
        aux= aux-> nizq;
        cargar_pila(&pila,&aux)
        mostrar_dato(&(*aux)->dat);
    }
}*/

void mostrar_arbol(t_dato *d)
{
    printf("\n\nDNI: %ld", d->clave);
    printf("\nCODIGO DE CLIENTE: %d", d->codc);
}

void mostrar_arbol_in(t_dato *d, int reg)
{
    printf("\n\nDNI: %ld", d->clave);
    printf("\nCODIGO DE CLIENTE: %d", d->codc);
    printf("EL NUMERO DE REGISTRO ES: %d", reg);
}

int contar_hojas(t_arbol *p)
{
    if(*p)
    {
        if((*p)->nizq==NULL&&(*p)->nder==NULL)
            return 1;
        return contar_hojas(&(*p)->nder)+contar_hojas(&(*p)->nizq);
    }
    return 0;
}

int contar_no_hojas(t_arbol *p)
{
    if(*p)
    {
        if((*p)->nizq||(*p)->nder)
            return contar_no_hojas(&(*p)->nizq) + contar_no_hojas(&(*p)->nder)+1;
        return 0;
    }
    return 0;
}

int mostrar_los_nodos_con_hijos_por_izq(t_arbol *pa)
{
    if(*pa)
    {
        if((*pa)->nizq)
        {
            mostrar_arbol(&(*pa) -> dat );
            return 1+ mostrar_los_nodos_con_hijos_por_izq(&(*pa)->nizq) +mostrar_los_nodos_con_hijos_por_izq(&(*pa)->nder);
        }
        return mostrar_los_nodos_con_hijos_por_izq(&(*pa)->nder);
    }
    return 0;
}

int mostrar_los_nodos_con_hijos_solo_izq(t_arbol *pa)
{
    if(*pa)
    {
        if((*pa)->nizq && !(*pa)->nder)
        {
            mostrar_arbol(&(*pa) -> dat );
            return 1 + mostrar_los_nodos_con_hijos_solo_izq(&(*pa)->nizq);
        }
        return mostrar_los_nodos_con_hijos_solo_izq(&(*pa)->nder);
    }
    return 0;
}



int contar_claves_pares(t_arbol *pa)
{
    if(*pa)
    {
        if((*pa)->dat.clave%2 == 0)
            return contar_claves_pares(&(*pa)->nizq)+ contar_claves_pares(&(*pa)->nder)+ 1;
        return contar_claves_pares(&(*pa)->nizq)+ contar_claves_pares(&(*pa)->nder);
    }
    return 0;
}

void podar_arbol(t_arbol* pa)
{

    if(!*pa)
        return;
    if(!(*pa) -> nder && !(*pa) -> nizq)
    {
        free(*pa);
        *pa=NULL;
        return;
    }
    podar_arbol(&(*pa) -> nder);
    podar_arbol(&(*pa) -> nizq);
}

void preord_alt(t_arbol *pa, int alt)
{
    if(*pa)
    {
        mostrar_arbol_alt(&(*pa) -> dat,alt);
        alt++;
        preord_alt(&(*pa) -> nizq,alt);
        preord_alt(&(*pa) -> nder,alt);
    }
}

int buscar_arbol(const t_arbol*pa, t_dato*d)
{
    if(!*pa)
        return 0;
    if(!comparar_nodo(&(*pa) -> dat,d))
    {
        *d= (*pa) -> dat;
        return 1;
    }
    return comparar_nodo(&(*pa) -> dat,d) > 0 ? buscar_arbol(& (*pa)-> nder, d) : buscar_arbol(& (*pa)-> nizq, d);
}

t_nodo* buscar_arbol_dir(const t_arbol* pa, t_dato* d)
{
    if(!*pa)
        return NULL;
    if(!comparar_nodo(&(*pa)-> dat, d))
        return (*pa);
    return comparar_nodo(&(*pa)-> dat, d) >0? buscar_arbol_dir(&(*pa)->nder,d) : buscar_arbol_dir(&(*pa)->nizq,d);
}


void mostrar_arbol_alt(t_dato *d , int alt)
{
    printf("EL DNI ES: %ld", d-> clave);
    printf("EL CODIGO DE CLIENTE ES: %d", d -> codc);
    printf("LA ALTURA ES: %d",alt);
}
