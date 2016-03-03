#include <stdio.h>
#include <stdlib.h>


int main() /// acá se ingresan cadenas
{
    char c[20], cad[100];
    int i;
    FILE *pf;
    pf=fopen("/home/emanuel/Programacion/Programación C/archivito.txt","wt");
    if(!pf)
        exit(1);
    for(i=0;i<6;i++)
    {
        system("clear");
        printf("\n INGRESE CARACTER:\t");
        scanf("%s",c);
        fprintf(pf,"%s\t",c);
    }
    fclose(pf);
    pf=fopen("/home/emanuel/Programacion/Programación C/archivito.txt","rt");
    if(!pf)
        exit(1);

    fscanf(pf,"%s",cad);
    while(!feof(pf))
    {
        printf("\n%s",cad);      ///
        fscanf(pf,"%s",cad);
    }

    fclose(pf);
    return 0;
}



/** PARA LETRAS....
int main()
{
    char c,cad[20];
    int i;
    FILE *pf;
    pf=fopen("/home/emanuel/Programacion/Programación C/archivito.txt","wt");
    if(!pf)
        exit(1);
    for(i=0;i<6;i++)
    {
        system("clear");
        printf("\n INGRESE CARACTER:\t");
        scanf("%c",&c);
       /// fflush(stdin);
        scanf("%*c");
        fprintf(pf,"%c|",c);
    }
    fclose(pf);
    pf=fopen("/home/emanuel/Programacion/Programación C/archivito.txt","rt");
    if(!pf)
        exit(1);

    fscanf(pf,"%c|",&c);
    while(!feof(pf))
    {
        printf("\n%c",c);      ///
        fscanf(pf,"%c|",&c);
    }

    fclose(pf);
    return 0;
}
*/
