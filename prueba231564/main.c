#include <stdio.h>
#include <stdlib.h>
#define VALOR_ABSOLUTO(x) (x)<0? (x)*(-1):(x)
#define PARTE_ENTERA(x) (int)(x)
#define FACTORIAL(x)     sum=1;\
                        for((x);(x)>0;(x)--)\
                        {sum*=x;}\

long factrec(int);
int main()
{
    int a=-8,b=5;
    float s=3.2555;
    double sum;
    a=VALOR_ABSOLUTO(a);
    s=PARTE_ENTERA(s);
    sum=factrec(b);
    printf("%d", a);
    printf("\n\n%f", s);
    printf("\n\n\n%.0lf",sum);
    return 0;
}

long factrec(int a)
{
    if(a>0)
        return (factrec(a-1)*a);
    return 1;

}
