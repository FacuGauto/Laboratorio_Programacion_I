#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"

#define LEN_PERSONAS 20

int main()
{
    char seguir='s';
    int opcion=0;
    int auxiliar;
    EPersona personas[LEN_PERSONAS];

    persona_init(personas,LEN_PERSONAS);

    persona_altaForzada(personas,LEN_PERSONAS,"Facundo",26,36587984);
    persona_altaForzada(personas,LEN_PERSONAS,"Damian",16,38545754);
    persona_altaForzada(personas,LEN_PERSONAS,"Martin",43,34568741);
    persona_altaForzada(personas,LEN_PERSONAS,"Pablo",30,30124875);
    persona_altaForzada(personas,LEN_PERSONAS,"Juan",29,31548962);

    while(seguir=='s')
    {
        printf("\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                persona_alta(personas,LEN_PERSONAS);
                break;
            case 2:
                getValidInt("DNI?","\nNumero invalido\n",&auxiliar,0,99999999,1);
                persona_baja(personas,LEN_PERSONAS,auxiliar);
                break;
            case 3:
                persona_ordenar(personas,LEN_PERSONAS);
                persona_mostrar(personas,LEN_PERSONAS);
                break;
            case 4:
                persona_edades(personas,LEN_PERSONAS);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
