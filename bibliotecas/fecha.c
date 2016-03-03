#include <stdio.h>
#include <stdlib.h>
#include "mi_utilitario.h"
#include "fecha.h"

///#define BIS [2][12] {{31,28,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31}}

void ingresar_fecha(t_fecha * fech,const char *texto)
{
   system("clear");
   printf("%s",texto);
   scanf("%d/%d/%d", &fech->dia, &fech->mes, &fech->anio);
   __fpurge(stdin);
   return;

}

char validar_fecha(t_fecha * fech, t_fecha * par)
{
   return fech -> anio < par -> anio? 0: fech -> anio > par -> anio? 1: fech -> mes < par -> mes? 0: fech -> mes > par -> mes? 1: fech -> dia < par -> dia? 0: fech -> dia > par -> dia? 1 : 2 ;
    /** lo que deberia hacer es que pregunte primero si año que se ingresa es menor, sino, pregunta si es mayor, caso contrario
    pasa al mes y de ultima lo que hace es preguntar por dia
    */
}

char fecha_valida(const t_fecha * f1)
{
    int bis [2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    if(f1 -> anio<1600)
        return 0;
    if(f1 -> mes < 1 || f1 -> mes >12)
        return 0;
    if(f1 -> dia <1|| f1 -> dia > bis[ES_BISIESTO(f1->anio)][f1 -> mes])
        return 0;
    return 1;
}


void ejercicio14()
{
    t_fecha f1;

    ingresar_fecha(&f1,"INGRESE FECHA MAYOR A 1/1/1600");
    while(!fecha_valida(&f1))
    {
        ingresar_fecha(&f1,"FECHA ERRONEA\nINGRESE FECHA MAYOR A 1/1/1600");
    }
    restardias(&f1,1);
    system("clear");
    printf("El dia anterior es: %d/%d/%d",f1.dia, f1.mes, f1.anio);
    pausa();
    return;

}


void ejercicio15()
{
    t_fecha f1;
    ingresar_fecha(&f1,"\nINGRESE FECHA MAYOR A 1/1/1600\t");
    sumardias(&f1,1);
    system("clear");
    printf("\nEl dia siguiente es: %d/%d/%d",f1.dia, f1.mes, f1.anio);
    pausa();
    return;

}

void ejercicio16()
{
    t_fecha f1;
    int cant;
    ingresar_fecha(&f1,"\nINGRESE FECHA MAYOR A 1/1/1600\t");
    do
    {
        system("clear");
        printf("INGRESE NUMERO MAYOR O IGUAL A 0 PARA REALIZAR LA SUMA");
        scanf("%d",&cant);
    }while(cant<0);
    sumardias(&f1,cant);
    system("clear");
    printf("\nDentro de %d dias sera: %d/%d/%d", cant,f1.dia, f1.mes, f1.anio);
    pausa();
    return;

}

void ejercicio17()
{
    t_fecha f1;
    int cant;
    ingresar_fecha(&f1,"\nINGRESE FECHA MAYOR A 1/1/1600\t");
    do
    {
        system("clear");
        printf("INGRESE NUMERO MAYOR O IGUAL A 0 PARA REALIZAR LA RESTA");
        scanf("%d",&cant);
    }while(cant < 0);
    restardias(&f1,cant);
    system("clear");
    printf("\nHace %d dias fue: %d/%d/%d", cant,f1.dia, f1.mes, f1.anio);
    pausa();
    return;

}

void ejercicio18()
{
    t_fecha f1,f2;
    long res;
    ingresar_fecha(&f1,"INGRESE FECHA MAYOR A 01/01/1600");
    ingresar_fecha(&f2,"INGRESE FECHA MAYOR A 01/01/1600");
    res=restarfechas(&f1,&f2);
    system("clear");
    printf("LA CANTIDAD DE DIAS ENTRE %02d/%02d/%02d  y  %02d/%02d/%02d es %ld", f1.dia, f1.mes, f1.anio,f2.dia, f2.mes, f2.anio, res);
    pausa();
    return;
}

void ejercicio19()
{
    t_fecha f1,f2;
    int res;
    f1 . dia = 16; /// F1 ES DOMINGO
    f1 . mes = 02;
    f1 . anio= 2014;
    ingresar_fecha(&f2,"INGRESE FECHA MAYOR A 1/1/1600");
    res= saberdia(&f1,&f2);
    system("clear");
    switch (res)
    {
        case 0: printf("\n %d/%d/%d ES DOMINGO",f2.dia, f2.mes, f2.anio); break;
        case 1: printf("\n %d/%d/%d ES LUNES",f2.dia, f2.mes, f2.anio); break;
        case 2: printf("\n %d/%d/%d ES MARTES",f2.dia, f2.mes, f2.anio); break;
        case 3: printf("\n %d/%d/%d ES MIERCOLES",f2.dia, f2.mes, f2.anio); break;
        case 4: printf("\n %d/%d/%d ES JUEVES",f2.dia, f2.mes, f2.anio); break;
        case 5: printf("\n %d/%d/%d ES VIERNES",f2.dia, f2.mes, f2.anio); break;
        case 6: printf("\n %d/%d/%d ES SABADO",f2.dia, f2.mes, f2.anio); break;
    }
    pausa();
    return;
}


void restardias(t_fecha * f1, int cant)
{
    int bis [2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    f1->dia-=cant;
    while(f1->dia < 1 )
    {
        f1->mes--;
        while( f1 -> mes < 1)
        {
            f1 ->mes+=12;
            f1-> anio--;
        }
        f1->dia+= bis[ES_BISIESTO(f1->anio)][f1->mes-1];
    }
    return;
}

void sumardias(t_fecha *f1, int cant)
{
    int bis [2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    f1->dia+=cant;
    while (f1-> dia > bis[ES_BISIESTO(f1->anio)][f1->mes-1]) /// a f1->mes le resto uno por la pos de la matriz
    {
        f1->dia-= bis[ES_BISIESTO(f1->anio)][f1->mes-1]; /// Se le resta el mes. No es lo mismo feb que marzo...
        f1->mes++;
        while(f1-> mes > 12)
        {
            f1->mes-=12;
            f1->anio++;
        }

    }
    return;
}


long restarfechas(const t_fecha* f1, const t_fecha* f2)
{
    long cant1 = adiarel(f1), cant2=adiarel(f2);
    return abs(cant1-cant2);

}

long adiarel(const t_fecha *fch) /// dada la fecha busca saber cuantos dias pasaron desde el 1/1/1600
{
    long diarel=(fch->anio-1601)*365+ ((fch->anio-1601)/4) - ((fch->anio-1601)/100) + ((fch->anio-1601)/400); /// se resta uno por el año que está en curso
    int bis [2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}}, i;
    for(i=0;i<(fch->mes-1);i++)
        diarel+=bis[ES_BISIESTO(fch -> anio)][i];
    diarel += fch -> dia;
    return diarel;
}


int saberdia(const t_fecha *f1, const t_fecha* f2) /// resta los dias relativos y a ese dia se lo divide por 7 para buscar cual es el resto
{
    long res=restarfechas(f1,f2);
    return res%7;

}
