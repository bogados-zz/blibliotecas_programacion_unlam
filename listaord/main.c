#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\Sebastian Note\Desktop\Programación C\bibliotecas\lista.h"
#include <string.h>
void pasar_a_bin(char*,t_dato*);
int main()
{
    FILE *pf=fopen("0hclinicas.in","rt");
    FILE *wpf=fopen("salida_esperada.txt","wt");
    t_dato persona;
    t_lista lista;
    crear_lista(&lista);
    char aux[400];
    if(!pf || !wpf)
    {
        printf("Te mandaste una cagada en los archivos");
        exit(0);
    }
    fgets(aux,sizeof(char)*400,pf);
    printf("%s",aux);
    while(!feof(pf))
    {
        pasar_a_bin(aux, &persona);
        poner_en_lista_sin_rep(&lista,&persona);
    }
    while(sacar_de_lista_ord(&lista,&persona))
    {
        fprintf(wpf,"%ld %s %s", persona.dni,persona.nombre,persona.apellido);
    }
    return 0;
}


void pasar_a_bin( char * cadena, t_dato* persona)
{
    char * aux=strrchr(cadena,' ');
    strcpy(persona->apellido,aux+1);
    *aux='\n';
    aux=strrchr(cadena,' ');
    strcpy(persona->nombre,aux+1);
    *aux='\n';
    persona->dni=atol(aux);
}
