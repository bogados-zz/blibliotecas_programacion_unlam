#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/mi_utilitario.h"
#include "../bibliotecas/numero.h"
void ejerandom();
void ejecad();
void ejecadr();
void palabravert(char*);
void palabravertr(char *);
void ingresar_cadena(char*,int);
int main()
{
    char menu[][50]={"ABCDEFGHIJS","RANDOM","IMPRIMIR PALABRA EN VERTICAL AL DERECHO","IMPRIMIR PALABRA EN VERTICAL AL REVES","MOSTRAR PALABRA CRECIENTE","IMPRIMIR PALABRA DECRECIENTE",
                                    "SALIR"},op;

    do
    {
        op=obtener_opcion(menu,4,50);
        switch(op)
        {
            case 'A': ejerandom(); break;
            case 'B': ejecad();break;
            case 'C': ejecadr(); break;
        }
    }while(op!='S');
    return 0;

}


void ejerandom()
{
    int a,b,c,i;
    a=ingresar_int("INGRESE PRIMER NUMERO");
    b=ingresar_int("INGRESE SEGUNDO NUMERO ");
    c=abs(a)+abs(b)+1; ///se cual es la distancia entre ellos
    if(a<b)
        b=a; /// pregunto cual es menor para poder saber cual es el menor... se lo resto al valor abs de
    for(i=0;i<50;i++)
    {
        a=rand()%c;
        printf("\t%d",(a-abs(b))); /// lo resto para que me de entre los numeros pedidos
    }
    return;
}

void ejecad()
{
    char cad[50];
    ingresar_cadena(cad,50);
    system("clear");
    printf("\n*\n");
    palabravert(cad);
    printf("\n*");
    pausa();
    return;
}


void ejecadr()
{
    char cad[50];
    ingresar_cadena(cad,50);
    system("clear");
    printf("\n*\n");
    palabravertr(cad);
    printf("\n*");
    pausa();
    return;
}


void palabravert(char *cad)
{
    if(*cad)
    {
            printf("%c\n",*cad);
            palabravert((cad+1));
    }

    return;
}

void palabravertr(char *cad)
{
    if(*cad)
    {
            palabravertr((cad+1));
            printf("%c\n",*cad);
    }


    return;
}



void ingresar_cadena(char* cad, int cant)
{
    system("clear");
    printf("\n\n INGRESE LA CADENA: ");
    __fpurge(stdin);
    fgets(cad,cant,stdin);
    return;
}

/**
ejlista()
{
    for(i=0;i<5;i++)
    {
        ingresar_dato();
        cargar_en_lista(&lista, &dato);
    }
    system("clear");
    mostrar_lista_al_revés(&lista,&dato);
   return;
}

void mostrar_lista_al_revés(t_lista* pl,t_dato *d)
{
    if(*pl)
    {
        mostrar_lista_al_revés(pl,d);
        printf("",);
    }
}
*/
void ejpalabra_creciente()
{
    char cad[50];
    ingresar_cadena(cad,50);
    printf("\n *\n");
    palabra_creciente(cad,strlen(cad)/sizeof(char));
    printf("\n *\n");
}

void palabra_decreciente(const char * cad, int a)
{
    char *aux;
    if(*pa)
    {
        ()
    }
}
