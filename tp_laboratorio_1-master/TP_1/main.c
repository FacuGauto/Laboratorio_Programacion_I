#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int flagNumUno = 0;
    int flagNumDos = 0;

    int primerNumero;
    int segundoNumero;
    float resultado;

    while(seguir=='s')
    {

        printf("***********************************************\n");
        printf("Elegir un numero del menu:\n");
        if(flagNumUno == 1)
        {
            printf("1- Ingresar 1er operando (A=%d)\n",primerNumero);
        }
        else
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        if(flagNumDos == 1)
        {
            printf("2- Ingresar 2do operando (B=%d)\n",primerNumero);
        }
        else
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("***********************************************\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer numero: \n");
                scanf("%d",&primerNumero);
                flagNumUno = 1;
                break;
            case 2:
                printf("Ingrese el segundo numero: \n");
                scanf("%d",&segundoNumero);
                flagNumDos = 1;
                break;
            case 3:
                if(flagNumUno==1 && flagNumDos==1)
                {
                    if(suma(primerNumero,segundoNumero,&resultado) == 0)
                    {
                        printf("El resultado de la suma es: %.2f \n", resultado);
                    }
                    else
                    {
                        printf("No se pudo obtener el resultado de la suma \n");
                    }
                }
                else
                {
                    printf("Debe ingresar dos numeros primero\n");
                }

                break;
            case 4:
                if(flagNumUno==1 && flagNumDos==1)
                {
                    if(resta(primerNumero,segundoNumero,&resultado) == 0)
                    {
                        printf("El resultado de la resta es: %.2f \n", resultado);
                    }
                    else
                    {
                        printf("No se pudo obtener el resultado de la resta\n");
                    }
                }
                else
                {
                    printf("Debe ingresar dos numeros primero\n");
                }
                break;
            case 5:
                if(flagNumUno==1 && flagNumDos==1)
                {
                    if(division(primerNumero,segundoNumero,&resultado) == 0)
                    {
                        printf("El resultado de la division es: %.2f \n", resultado);
                    }
                    else
                    {
                        printf("No se pudo obtener el resultado de la division \n");
                    }
                }
                else
                {
                    printf("Debe ingresar dos numeros primero\n");
                }
                break;
            case 6:
                if(flagNumUno==1 && flagNumDos==1)
                {
                    if(multiplicacion(primerNumero,segundoNumero,&resultado) == 0)
                    {
                        printf("El resultado de la multiplicacion es: %.2f \n", resultado);
                    }
                    else
                    {
                        printf("No se pudo obtener el resultado de la multiplicacion \n");
                    }
                }
                else
                {
                    printf("Debe ingresar dos numeros primero\n");
                }
                break;
            case 7:
                if(flagNumUno==1)
                {
                    if(factorial(primerNumero,&resultado) == 0)
                    {
                        printf("El factorial de %d es: %.2f \n", primerNumero, resultado);
                    }
                    else
                    {
                        printf("No se pudo obtener el resultado del factorial \n");
                    }
                }
                else
                {
                    printf("Debe ingresar un umero primero\n");
                }
                break;
            case 8:
                if(flagNumUno==1)
                {
                    if(suma(primerNumero,segundoNumero,&resultado) == 0)
                    {
                        printf("El resultado de la suma es: %.2f \n", resultado);
                    }
                    else
                    {
                        printf("No se pudo obtener el resultado de la suma \n");
                    }

                    if(resta(primerNumero,segundoNumero,&resultado) == 0)
                    {
                        printf("El resultado de la resta es: %.2f \n", resultado);
                    }
                    else
                    {
                        printf("No se pudo obtener el resultado de la resta\n");
                    }

                    if(division(primerNumero,segundoNumero,&resultado) == 0)
                    {
                        printf("El resultado de la division es: %.2f \n", resultado);
                    }
                    else
                    {
                        printf("No se pudo obtener el resultado de la division \n");
                    }

                    if(multiplicacion(primerNumero,segundoNumero,&resultado) == 0)
                    {
                        printf("El resultado de la multiplicacion es: %.2f \n", resultado);
                    }
                    else
                    {
                        printf("No se pudo obtener el resultado de la multiplicacion \n");
                    }

                    if(factorial(primerNumero,&resultado) == 0)
                    {
                        printf("El factorial de %d es: %.2f \n", primerNumero, resultado);
                    }
                    else
                    {
                        printf("No se pudo obtener el resultado del factorial \n");
                    }
                }
                else
                {
                    printf("Debe ingresar dos numeros primero\n");
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

