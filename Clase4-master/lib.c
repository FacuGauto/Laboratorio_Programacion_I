#include <stdio.h>
#include <stdlib.h>

int getInt(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno;
    long auxiliarLong;
    retorno = -1;

    do
    {
        reintentos --;
        printf("%s",mensaje);
        scanf("%ld",&auxiliarLong);

        if(auxiliarLong <= maximo && auxiliarLong >= minimo)
        {
            *resultado = (int)auxiliarLong;
            retorno = 0;
            break;
        }
        printf("%s",mensajeError);
    }while(reintentos >= 0);

    return retorno;

}

int getFloat(float* resultado , char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
    int retorno;
    double auxiliarDouble;
    retorno = -1;

    do
    {
        reintentos --;
        printf("%s",mensaje);
        scanf("%lf",&auxiliarDouble);

        if(auxiliarDouble <= maximo && auxiliarDouble >= minimo)
        {
            *resultado = (float)auxiliarDouble;
            retorno = 0;
            break;
        }
        printf("%s",mensajeError);
    }while(reintentos >= 0);

    return retorno;

}
