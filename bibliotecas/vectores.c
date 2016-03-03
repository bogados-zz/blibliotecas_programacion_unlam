#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#include "mi_utilitario.h"
#define TAM 20
void ejercicio22()
{
    int v[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}, elem, pos;
    system("clear");
    printf("\n INGRESE EL ELEMENTO QUE QUIERE INGRESAR:   ");
    scanf("%d", &elem);
    do
    {
        printf("\n INGRESE LA POSICION QUE DESEE QUE TOME EN EL VECTOR ENTRE 0 Y %d :     " ,TAM-1);
        scanf("%d",&pos);

    }while(pos<0||pos>TAM-1);
    insertar_vect_en_pos(v,elem,pos);
    system("clear");
    printf("LOS ELEMENTOS DEL VECTOR SON");
    for(pos=0; pos<TAM;pos++)
        printf("%d\t", *(v+pos));
    pausa();
    return;

}


void insertar_vect_en_pos(int * v, int el, int pos)
{
    *(v+pos)= el;
    return;
}
