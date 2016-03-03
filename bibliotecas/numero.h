#ifndef NUMERO_H_INCLUDED
#define NUMERO_H_INCLUDED


int ingresar_int(const char*);
long ingresar_long(const char*);
float ingresar_float(const char*);
double ingresar_double(const char*);
char validar_int1(int,int);
char validar_int2(int, int, int);
char validar_long1(long, long);
char validar_long2(long, long, long);
char validar_float1(float,float);
char validar_float2(float, float,float);
char validar_double1(double,double);
char validar_double2 (double, double,double);

void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
long factorial(int);
long combinatoria(int,int);
double exponencial(int);
double raiz_cuad(int);
int fibonacci(int);
double seno(int);

#endif // NUMERO_H_INCLUDED
