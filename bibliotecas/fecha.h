#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#define ES_BISIESTO(A) (A) % 400 == 0 ? 1: ((A) % 4 == 0 && (A) % 100 != 0) ? 1:0

typedef struct
{
    int dia;
    int mes;
    int anio;
}t_fecha;

void restardias(t_fecha*,int);
void sumardias(t_fecha*,int);
long restarfechas(const t_fecha*, const t_fecha*);
long adiarel(const t_fecha*);
int saberdia(const t_fecha*, const t_fecha* );


void ejercicio14();
void ejercicio15();
void ejercicio16();
void ejercicio17();
void ejercicio18();
void ejercicio19();


#endif // FECHA_H_INCLUDED
