#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/mi_utilitario.h"
#include "../bibliotecas/arbol.h"

void ejcarga(t_arbol*);
void ejarch_pre(t_arbol*);
void ejarch_in(t_arbol*);
void guardar_inord(t_arbol*);
void guardar_preord(t_arbol*);
void buscar_dato(t_arbol*);
void buscar_dato_dir(t_arbol*);

int main()
{
    t_arbol arbol;
    char op,menu[][50]= {"ABCDEFGHIJKLMNOPQRS",
                    "CARGAR ARBOL",
                    "CARGAR ARBOL DESDE ARCHIVO PRE ORDEN",
                    "CARGAR ARBOL DESDE ARCHIVO IN ORDEN",
                    "RECORRER PRE ORDEN",
                    "RECORRER IN ORDEN",
                    "RECORRER POS ORDEN",
                    "GUARDAR ARCHIVO PRE ORDEN",
                    "GUARDAR ARCHIVO IN ORDEN",
                    "MOSTRAR NODOS CON HIJOS POR IZQUIERDA",
                    "MOSTRAR NODOS SOLO CON HIJOS POR IZQUIERDA",
                    "MOSTRAR LA ALTURA DEL ARBOL",
                    "PODAR ARBOL",
                    "BUSCAR NODO DEVOLVER DATO",
                    "BUSCAR EN NODO DEVOLVER DIRECCION",
                    "ELIMINAR NODO",
                    "VACIAR ARBOL",
                    "SALIR"};

    crear_arbol(&arbol);
    do
    {
        op=obtener_opcion(menu,18,50);
        switch(op)
        {
            case 'A': ejcarga(&arbol); break;
            case 'B': ejarch_pre(&arbol); break;
            case 'C': ejarch_in(&arbol); break;
            case 'D':   system("clear");
                        recorrer_preorden(&arbol);
                        pausa();
                        break;

            case 'E':   system("clear");
                        recorrer_inorden(&arbol);
                        pausa();
                        break;

            case 'F':   system("clear");
                        recorrer_posorden(&arbol);
                        pausa();
                        break;
            case 'G': guardar_preord(&arbol); break;
            case 'H': guardar_inord(&arbol); break;

            case 'I':   system("clear");
                        printf("\nLA CANTIDAD DE NODOS CON HIJOS SOLAMENTE POR IZQUIERDA ES: %d",mostrar_los_nodos_con_hijos_por_izq(&arbol));
                        pausa();
                        break;

            case 'J':
                        system("clear");
                        printf("\nLA CANTIDAD DE NODOS CON HIJOS SOLAMENTE POR IZQUIERDA ES: %d",mostrar_los_nodos_con_hijos_solo_izq(&arbol));
                        pausa();
                        break;
            case 'K':   system("clear");
                        printf("LA ALTURA DEL ARBOL ES: \t %d", altura_arbol(&arbol)); break;
            case 'L': podar_arbol(&arbol); break;
            case 'M': buscar_dato(&arbol); break;
            case 'N': buscar_dato_dir(&arbol);break;

        }


    } while(op!='S');
    return 0;
}


void ejcarga(t_arbol*pa)
{
    t_dato reg;
    char op;
    do
    {
        system("clear");
        printf("\n INGRESE LA CLAVE (D.N.I.): \t");
        scanf("%ld", &reg.clave);
        system("clear");
        printf("\n INGRESE EL CODIGO DE CLIENTE: \t");
        scanf("%d", &reg.codc);
        if(cargar_arbol(pa,&reg))
        {
            if(cargar_arbol(pa,&reg)==2)
                printf("REGISTRO REPETIDO");
            else
                printf("REGISTRO CARGADO CON EXITO");
        }
        else
            printf("NO HAY MEMORIA");
        pausa();
        system("clear");
        printf("INGRESE SI DESEA INGRESAR OTRO REGISTRO Y/N:    ");
        scanf("%c",&op);

    }while(op == 'Y');
}


void ejarch_pre(t_arbol* pa)
{
    FILE *pf;
    char path[101];
    obtener_path(path);
    pf=fopen(path,"rb");
    if(!pf)
        fin_anormal("ERROR AL CARGAR EL ARCHIVO");
    cargar_arbol_de_arch_bin_pre(pa,pf);
    fclose(pf);
}

void ejarch_in(t_arbol* pa)
{
    FILE *pf;
    int aux;
    char path[101];//"home/emanuel/Programacion/Programación C/archivos/inord.bin";
    obtener_path(path);
    pf=fopen(path,"rb");
    if(!pf)
        fin_anormal("ERROR AL CARGAR EL ARCHIVO");
    fseek(pf,0,SEEK_END);
    aux=ftell(pf)/sizeof(t_dato);
    pausa();
    ///fseek(pf,0,SEEK_SET);
    if(cargar_arbol_de_arch_bin_in(pa,pf,0,aux-1))
        printf("ARCHIVO CARGADO CON EXITO");
    pausa();
    fclose(pf);
    recorrer_inorden_indice(pa);
    pausa();
}

void guardar_inord(t_arbol * pa)
{
    FILE *pf;
    char path[101];
    obtener_path(path);
    pf=fopen(path,"wb");
    if(!pf)
        fin_anormal("ERROR AL CREAR EL ARCHIVO, DIRECTORIO NO ENCONTRADO");
    guardar_arbol_en_arch_in(pa,pf);
    fclose(pf);

}


void guardar_preord(t_arbol * pa)
{
    FILE *pf;
    char path[101];
    obtener_path(path);
    pf=fopen(path,"wb");
    if(!pf)
        fin_anormal("ERROR AL CREAR EL ARCHIVO, DIRECTORIO NO ENCONTRADO");
    guardar_arbol_en_arch_pre(pa,pf);
    system("clear");
    printf("SE HA GUARDADO EXITOSAMENTE");
    pausa();
}

void buscar_dato(t_arbol* pa)
{

    t_dato reg;
    int aux;
    printf("INGRESE CLAVE QUE DESEA BUSCAR");
    scanf("%ld",&reg.clave);
    aux=buscar_arbol(pa,&reg);
    system("clear");
    if(aux>0)
    {

        printf("LOS DATOS DEL NODO SON:   \n\n");
        printf("EL DNI ES:   %ld",reg.clave);
        printf("EL CODIGO DE CLIENTE ES:   %d",reg.codc);
    }
    else
        printf("LA BUSQUEDA FRACASO \n");
    pausa();
}


void buscar_dato_dir(t_arbol* pa)
{

    t_dato reg;
    t_nodo* aux;
    printf("INGRESE CLAVE QUE DESEA BUSCAR");
    scanf("%ld",&reg.clave);
    aux=buscar_arbol_dir(pa,&reg);
    system("clear");
    if(aux)
    {

        printf("LOS DATOS DEL NODO SON:   \n\n");
        printf("EL DNI ES:   %ld",aux->dat.clave);
        printf("EL CODIGO DE CLIENTE ES:   %d",aux->dat.codc);
    }
    else
        printf("LA BUSQUEDA FRACASO \n");
    pausa();
}
