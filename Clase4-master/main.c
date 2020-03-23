#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    float precio;
    //int edad;

    /*if(getInt(&edad,"Ingrese la edad","Edad invalidad",0,100,2)==0)
    {
        printf("Su edad es: %d",edad);
    }
    else
    {
        printf("No tengo la edad");
    }
    */

    if(getFloat(&precio,"Ingrese el precio","Precio invalido",0,100,2)==0)
    {
        printf("El precio es: %.2f",precio);
    }
    else
    {
        printf("No tengo el precio");
    }
    return 0;
}


