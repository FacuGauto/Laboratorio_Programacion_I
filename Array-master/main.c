#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define SIZE_ARRAY 5

float calcularPromedio(int valores[],int cantidad);
int calcularPromedioV2(int valores[],int cantidad,float *pResultado);

int main()
{
    int num[SIZE_ARRAY];
    int i;
    int suma;
    float promedio;
    //int maximo;
    //int minimo;

    suma = 0;

    for(i=0;i<SIZE_ARRAY;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&num[i]);
    }

    promedio = calcularPromedio(num,SIZE_ARRAY);
    if(promedio = calcularPromedioV2(num,SIZE_ARRAY,&promedio)==0)
    {
        printf("El promedio es: %.2f",promedio);
    }
    else
    {
        printf("Error");
    }
  /*
    for(i=0;i<5;i++)
    {
        suma = suma + num[i];
        if(i==0)
        {
            maximo = num[i];
            minimo = num[i];
        }
        else
        {
            if(maximo<num[i])
            {
                maximo = num[i];
            }
            if(minimo>num[i])
            {
                minimo = num[i];
            }
        }
    }
*/

    printf("La suma es: %d \n",suma);
    printf("El promedio es: %.2f",promedio);
  //  printf("\nEl tamaño del array es: %d",SIZE_ARRAY);
  //  printf("\nEl numero maximo ingresado es: %d \n",maximo);
   // printf("El numero minimo ingresado es: %d \n",minimo);




    return 0;
}

float calcularPromedio(int valores[],int cantidad)
{
    float prom;
    int i;
    int sumador;
    sumador = 0;
    for(i=0;i<cantidad;i++)
    {
        sumador = sumador + valores[i];
    }
    prom = (float)sumador / cantidad;
    return prom;
}

int calcularPromedioV2(int valores[],int cantidad,float *pResultado)
{
    int i;
    int sumador;
    int retorno;
    sumador = 0;

    if(cantidad <= 0)
    {
        retorno= -1;
    }
    else
    {
        retorno =0;
    }
    for(i=0;i<cantidad;i++)
    {
        sumador = sumador + valores[i];
    }
     *pResultado = (float)sumador / cantidad;
    return retorno;
}
