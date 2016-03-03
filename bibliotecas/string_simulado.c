#include <stdio.h>
#include <stdlib.h>


char* strcat_simulada(char* destino, const char* origen)
{
    char *aux = destino;
    while(destino!= '\0')
        destino++;
    *destino=' ';
    while (*origen != 0)
    {
        *destino= *origen;
        destino++;
        origen++;
    }
    *origen= 0;
    return aux;
}

int strlen_simulada(const char * palabra)
{
    int desp=0;
    while(*(palabra+desp))
        desp++;
    return desp;
}

/** void strcpy_simulada(char *destino, const char *origen)       porque no puedo utilizarlo en otra funcion
{
    int desp=0;
    char* aux= destino;
    while(*(origen+desp)!= 0 && *(destino+desp)!= 0)   ///
    {
        *(destino+desp) = *(origen+desp);
        desp++;
    }
    return;
}*/

char* strchr_simulada (const char* s, int c)
{
    int desp=0;
    while(*(s+desp)!= 0 && *(s+desp)!=c)
        desp++;
    if(*(s+desp)=0)
        return 0;
    return 1;
}

char* strrchr_simulada (const char* s, int c)
{

}
