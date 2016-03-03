#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/mi_utilitario.h"
#define TAM 4
typedef struct
    {
        int clave;
        int monto;
    }t_dato;
typedef struct s_nodo
    {
    t_dato dato;
    struct s_nodo *sig;
    }t_nodo;
typedef t_nodo *t_lista;
/////////////////////////////
void mostrarArch (FILE *pf);
void crearLista (t_lista *);
int insertarEnLO (t_lista *,t_dato *);
void mostrarLista (t_lista *);
int elimSumarRepeLO (t_lista *);
void buscarEnMat (int [TAM][TAM],t_lista *,FILE *pf);
int comparar (t_dato *,t_dato *);
/////////////////////////////
int main ()
    {
        FILE *pf;
        int mat[TAM][TAM]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
        t_lista lista;
        t_dato dato;
        dato.clave=-1;
        pf=fopen("archivo.bin","rb+");
        if(!pf)
            {
            printf("No se pudo abrir el archivo.");
            exit(1);
            }
        printf("Los montos del arch. son: \n");
        mostrarArch(pf);
        pausa();
        system("cls");
        crearLista(&lista);
        printf("Ingrese clave y monto (clave=0 para salir): \n");
        scanf("%d %d",&dato.clave,&dato.monto);
        while(dato.clave!=0)
            {
            if(!insertarEnLO(&lista,&dato))
                printf("\nNo se pudo insertar.\n");
            printf("\nIngrese clave y monto (clave=0 para dejar de cargar): \n");
            scanf("%d %d",&dato.clave,&dato.monto);
            }
        system("cls");
        printf("La lista es: \n\n");
        mostrarLista(&lista);
        pausa();
        if(!elimSumarRepeLO(&lista))
            {
            printf("\nLista vacia. Cerrando Programa.");
            pausa();
            exit(1);
            }
        system("cls");
        printf("Tras eliminar repetidos, la lista es: \n\n");
        mostrarLista(&lista);
        pausa();
        buscarEnMat(mat,&lista,pf);
        system("cls");
        printf("Tras actualizar, el archivo queda: \n\n");
        mostrarArch(pf);
        fclose(pf);
        pausa();
        return 0;
    }
////////////////////////////////////////
void mostrarArch (FILE *pf)
    {
    int monto;
    fseek(pf,0,0);
    fread(&monto,sizeof(int),1,pf);
    while(!feof(pf))
        {
        printf("%d\n",monto);
        fread(&monto,sizeof(int),1,pf);
        }
    }
////////////////////////////////////////
void crearLista (t_lista *p)
    {
    *p=NULL;
    }
////////////////////////////////////////
int insertarEnLO (t_lista *p,t_dato *d)
    {
    t_nodo *nue;
    while(*p&&comparar(&(*p)->dato,d)<0)
        p=&(*p)->sig;
    nue=(t_nodo *)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->dato=*d;
    nue->sig=*p;
    *p=nue;
    return 1;
    }
////////////////////////////////////////
int comparar (t_dato *d1,t_dato *d2)
    {
    return d1->clave-d2->clave;
    }
////////////////////////////////////////
void mostrarLista (t_lista *p)
    {
    while(*p)
        {
        printf("\nClave: %d, Monto: %d",(*p)->dato.clave,(*p)->dato.monto);
        p=&(*p)->sig;
        }
    }
///////////////////////////////////////
int elimSumarRepeLO (t_lista *p)
    {
    t_nodo *aux;
    if(!*p)
        return 0;
    while(*p&&(*p)->sig)
        {
        if(comparar(&(*p)->dato,&(*p)->sig->dato)==0)
            while((*p)->sig&&comparar(&(*p)->dato,&(*p)->sig->dato)==0)
                {
                aux=*p;
                (*p)->sig->dato.monto+=(*p)->dato.monto;
                *p=aux->sig;
                free(aux);
                }
        else
            p=&(*p)->sig;
        }
    return 1;
    }
//////////////////////////////////////
void buscarEnMat (int mat[TAM][TAM],t_lista *p,FILE *pf)
    {
    int reg,num,i,j;
    while(*p)
        {
        for(i=0;i<TAM-1;i++)
            for(j=i+1;j<TAM;j++)
                if(mat[i][j]==(*p)->dato.clave)
                    {
                    num=i*TAM+j+1;
                    fseek(pf,sizeof(int)*(num-1),0);
                    fread(&reg,sizeof(int),1,pf);
                    fseek(pf,-1*sizeof(int),1);
                    reg+=(*p)->dato.monto;
                    fwrite(&reg,sizeof(int),1,pf);
                    fseek(pf,0,1);
                    reg+=(*p)->dato.monto;
                    }
        p=&(*p)->sig;
        }
    }
