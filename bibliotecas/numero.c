#include <stdio.h>
#include <stdlib.h>
#include "mi_utilitario.h"
#include <math.h>
#include "numero.h"
#define TOL 0.000000000000000000001

/**  ////////////////     FUNCIONES DE INGRESO DE NUMEROS   /////////////////////*********************
*********************                                       *****************************************/
int ingresar_int(const char* texto)
{
    int num;
    system("clear");
    printf("\n %s", texto);
    scanf("%d",&num);
    return num;
}

long ingresar_long (const char* texto)
{
    long num;
    system("clear");
    printf("\n %s", texto);
    scanf("%ld",&num);
    return num;
}

float ingresar_float (const char* texto)
{
    float num;
    system("clear");
    printf("\n %s", texto);
    scanf("%f",&num);
    return num;
}

double ingresar_double (const char* texto)
{
    double num;
    system("clear");
    printf("\n %s", texto);
    scanf("%lf",&num);
    return num;
}
/**  ////////////////     FUNCIONES DE VALIDACION DE NUMEROS   /////////////////////*********************
*********************               1 PARAMETRO                *****************************************/
char validar_double1(double num, double par) /// en caso de ambas validaciones el dos es para el caso de si es igual a uno de los paramentros
{
    return num==par? 2:num<par? 0 : 1;
}

char validar_float1(float num, float par)
{
    return num==par? 2:num<par? 0 : 1;
}

char validar_long1(long num, long par)
{
    return num==par? 2:num<par? 0 : 1;
}

char validar_int1(int num, int par)
{
    return num==par? 2:num>par? 1 : 0;
}

/**  ////////////////     FUNCIONES DE VALIDACION DE NUMEROS   /////////////////////*********************
*********************               2 PARAMETROS               *****************************************/

char validar_int2(int num, int men, int may)
{
    if(num>men&&num<may)
        return 1;
    else
        return (num==men||num==may)? 2:0;
}

char validar_float2(float num, float men, float may)
{
    if(num>men&&num<may)
        return 1;
    else
        return (num==men||num==may)? 2:0;
}

char validar_double2(double num, double men, double may)
{
    if(num>men&&num<may)
        return 1;
    else
        return (num==men||num==may)? 2:0;
}

char validar_long2(long num, long men, long may)
{
    if(num>men&&num<may)
        return 1;
    else
        return (num==men||num==may)? 2:0;
}

/**  ////////////////     FUNCIONES DE LA GUIA DE NUMEROS   /////////////////////*********************
*********************                                       *****************************************/
void ejercicio1()
{
    int num;
    long fact;
    num= ingresar_int("INGRESE NUMERO MAYOR A 0");
    while(validar_int1(num,0)!=1)
        num= ingresar_int("NUMERO INCORRECTO. INGRESE NUMERO MAYOR A 0:");
    fact=factorial(num);
    system("clear");
    printf("El factorial del numero %d es:\t %ld",num, fact);
    pausa();
    return;
}

void ejercicio2()
{
    int num1, num2;
    long comb;
    do
        num1=ingresar_int("INGRESE NUMERO MAYOR A 0:");
    while(validar_int1(num1,0)!=1);

    do
    {
        system("clear");
        printf("INGRESE NUMERO MENOR A %d :", num1);
        scanf("%d", &num2);
    }
    while(validar_int1(num2,num1)!=0);
    comb= combinatoria(num1, num2);
    system("clear");
    printf("\n La combinatoria entre los numeros   %d  y %d  es: %ld",num1,num2,comb);
    pausa();
}

void ejercicio3()
{
    int num;
    double res;
    do
       {
         system("clear");
         num = ingresar_int("INGRESE UN NUMERO MAYOR O IGUAL QUE 0");
       }
    while(validar_int1(num,0)==0);
    res=exponencial(num);
    system("clear");
    printf("EL EXPONENCIAL DEL NUMERO %d ES: %lf \n", num, res);
    pausa();
}

void ejercicio4()
{
    int num;
    double res;
    do
        num = ingresar_int("INGRESE NUMERO MAYOR O IGUAL QUE 0");
    while(!validar_int1(num,0));
    res= raiz_cuad(num);
    printf("LA RAIZ CUADRADA DE %d, ES:\t %lf \n", num, res);
    pausa();
    return;
}

void ejercicio5()
{
    int num;
    do
    {
        num=ingresar_int("INGRESE NUMERO MAYOR QUE 0");
    }while(validar_int1(num, 0)!=1);
    if(!fibonacci(num))
        printf("EL NUMERO %d NO PERTENECE A LA SERIE FIBBONACCI",num);
    printf("EL NUMERO %d PERTENECE A LA SERIE FIBBONACCI",num);
    pausa();
    return;
}

void ejercicio6()
{
    int num;
    double res;
    system("clear");
    printf("INGRESE NUMERO");
    setbuf(stdin,NULL);
    scanf("%d",&num);
    res= seno(num);
    printf("EL SENO DEL NUMERO %d ES: %lf\n", num, res);
    pausa();
    return;
}


/**  ////////////////     FUNCIONES DE MATEMATICAS DE NUMEROS   /////////////////////*********************
*********************                                           *****************************************/
long factorial(int num)
{
    long fact=1;
    while(num>0)
    {
       fact*=num;
       num--;
    }
    return fact;
}

long combinatoria (int m, int n)
{
    return(factorial(m)/(factorial(n)*factorial(m-n)));
}

double exponencial(int num)
{
    int i=1;
    double res=1, aux=1;
    while(aux>=TOL)
    {
        aux*=(double)num/i;
        res+=aux;
        i++;
    }
    return res;
}

double raiz_cuad (int num)
{
    double res=1, aux=0;
    if(num==0)
        return 0;
    while(fabs(res-aux) >= TOL)
    {
        aux=res;
        res=(aux+num/aux)/2;
    }
    return res;
}

int fibonacci(int num)
{
    int aux1=1, aux2, res=1;
    while(res<num)
    {
        aux2=aux1;
        aux1=res;
        res+=aux2;
    }
    if(res==num)
        return 1;
    return 0;
}
 double seno(int num)    /// CON UNO CICLO INFINITO, CON RESTO DE
 {
     double res=0, aux=num;
     int i=1;
     while(fabs(aux)> TOL)
     {
        printf(" \n %lf,     %lf",aux,res);
        i+=2;
        res+= aux;
        aux*= -(double)(num*num)/(double)(i*(i-1));
     }
     pausa();
     return res;
 }
