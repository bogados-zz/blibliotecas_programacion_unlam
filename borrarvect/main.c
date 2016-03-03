#include <stdio.h>
#include <stdlib.h>

int buscar_y_borrar(int*, int, int);
int buscar(int*, int, int, int*);
int borrar(int*, int,int);

int main()
{
    int vect[10]={1,2,3,4,6,9,8,18,98,87}, num, tam = 10,i;
    printf("Ingrese el numero: ");
    scanf("%d", &num);
    buscar_y_borrar(vect, num, tam);
    system("cls");
    printf("Este es el vector:  ");
    for(i=0;i<10;i++)
        printf("\t %d ", *(vect+i));
    return 0;
}

int buscar_y_borrar(int* v, int a, int tam)
{
    int pos;
    if(!buscar(v,a,tam, &pos))
        return 0;
    if (!borrar(v,pos,tam))
        return 0;
    return 1;
}

int buscar(int *v, int num, int tam, int *pos)
{
    int i=0;
    while(*(v+i) != num && tam>i)
        i++;
    if(i==tam)
        return 0;
    *pos = i;
    return 1;
}

int borrar(int *v, int pos,int tam)
{
    int i;
    while(pos<tam-1)
    {
        *(v+pos) = *(v+pos+1);
        pos++;
    }
    *(v+tam-1)= 0;
    return 1;
}
