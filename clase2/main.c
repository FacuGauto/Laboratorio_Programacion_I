#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_NUMEROS 3


int main()
{
    int i;
    int numeroUsuario;
    int acumulador = 0;
    float resultado;
    int maximo;

    void imprimirMensaje(int n)
    {
        printf("Ingrese el numero %d: ", n+1);
    }

    for(i=0 ; i < CANTIDAD_NUMEROS ; i++)
    {
        //printf("Dame el Numero %d\n",i+1);
        imprimirMensaje(i);
        scanf("%d",&numeroUsuario);
        acumulador = acumulador + numeroUsuario;
//pepepeppeppepep
        if(i==0)
        {
            maximo = numeroUsuario;
        }
        else
        {
            if(maximo < numeroUsuario)
            {
                maximo = numeroUsuario;
            }
        }
    }

    resultado = (float)acumulador / CANTIDAD_NUMEROS;
    printf("Resultado %.2f\n",resultado);
    printf("Numero maximo: %d", maximo);
    return 0;
}
