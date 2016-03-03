#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct
{
    int dd,
        mm,
        aa;
}t_fecha;

typedef struct
{
    char nom[20],
         ape[20];
    float prom;
    int edad;
    t_fecha fnac;

}t_alu;

void grabaralu(FILE *);
void ingresaralu(t_alu*);

int main()
{
    char op;
    FILE * pf;
    pf=fopen("/home/emanuel/Programacion/Programación C/alumnito.txt","wb");
    if(!pf)
        {
            printf("ERROR AL CARGAR ARCHIVO");
            scanf("%*c");
            exit(1);
        }
    system("clear");
    printf("DESEA AGREGAR UN ALUMNO? Y/N");
    scanf("%c",&op);
    while(toupper(op)=='Y')
    {
        grabaralu(pf);
        system("clear");
        scanf("%*c");
        printf("DESEA AGREGAR UN ALUMNO? Y/N");
        scanf("%c",&op);
    }
    return 0;
}

void grabaralu( FILE *pf)
{
    t_alu alum;
    ingresaralu(&alum);
    fprintf(pf,"%s\t%s\t%f\t%i\t%d/%d/%d\n",alum.nom, alum.ape, alum.prom, alum.edad, alum.fnac.dd, alum.fnac.mm, alum.fnac.aa);
    return;
}

void ingresaralu(t_alu* al)
{
    system("clear");
    printf("INGRESE EL NOMBRE");
    scanf("%s",al->nom);
    scanf("%*c");
    system("clear");
    printf("INGRESE EL APELLIDO");
    scanf("%s",al->ape);
    scanf("%*c");
    system("clear");
    printf("INGRESE EL PROMEDIO");
    scanf("%f", &al->prom);
    system("clear");
    printf("INGRESE LA EDAD");
    scanf("%d", &al->edad);
    system("clear");
    printf("INGRESE EL FECHA DE NAC DD/MM/AAAA");
    scanf("%d/%d/%d", &al->fnac.dd,&al->fnac.mm,&al->fnac.aa);
    return;
}
