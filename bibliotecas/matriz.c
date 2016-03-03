void mostrar_tri_sup(const int * mat, int tam)
{
    int i=1,j=0;
    while(i+j<tam-j-1)
    {
        while(i+j<tam-j-1)
        {
            printf("%d", *(mat+tam*j+(i+j)));
            i++;
        }
        printf("\n");
        i=1;
        j++;

    }
}
