#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"

static int obtenerEspacioLibre(EPersona* array,int limite);


/**
 * \brief Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param limite el tamaño del array se pasa como parametro.
 * @return el primer indice disponible
 */
static int obtenerEspacioLibre(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].estado==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/**
 * \brief Inicializa todos los elementos del array con estado 1.
 * @param array el array se pasa como parametro.
 * @param limite el tamaño del array se pasa como parametro.
 * @return 0 si salio bien -1 si hubo error.
 */
int persona_init(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].estado=1;
        }
    }
    return retorno;
}


/**
 * \brief Muestra los elementos del array con estado en 0.
 * @param array el array se pasa como parametro.
 * @param limite el tamaño del array se pasa como parametro.
 * @return 0 si salio bien -1 si hubo error.
 */
int persona_mostrar(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado)
                printf(" %s  - %d  - %d  - %d\n",array[i].nombre, array[i].edad, array[i].dni, array[i].estado);
        }
    }
    return retorno;
}


/**
 * \brief Ordena por nombre los elementos del array que esten estado 0.
 * @param array el array se pasa como parametro.
 * @param limite el tamaño del array se pasa como parametro.
 * @return 0 si salio bien -1 si hubo error.
 */
int persona_ordenar(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    int flagSwap;
    EPersona auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].estado && !array[i+1].estado)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0))
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}


/**
 * \brief Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param limite tamaño del array.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni.
 */
int persona_buscarPorDni(EPersona* array,int limite, int dni)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado && array[i].dni==dni)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/**
 * \brief Alta de persona.
 * @param array el array se pasa como parametro.
 * @param limite el tamaño del array se pasa como parametro.
 * @return 0 si salio bien -1 si hubo error.
 */
int persona_alta(EPersona* array,int limite)
{
    int retorno = -1;
    int i,edad,dni;
    char nombre[50];

    if(limite > 0 && array != NULL)
    {
        i = obtenerEspacioLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidInt("\nEdad?","\nEso no es una edad valida",&edad,0,99,1))
                {
                    if(!getValidInt("\nDNI?","\nEso no es un dni valido",&dni,0,99999999,1))
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        array[i].edad = edad;
                        array[i].dni = dni;
                        array[i].estado = 0;
                    }
                    else
                    {
                        retorno = -3;
                    }
                }
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


/**
 * \brief Baja de persona(se pone el estado en 1).
 * @param array el array se pasa como parametro.
 * @param limite el tamaño del array se pasa como parametro.
 * @param dni dni de la persona que se va a dar de baja.
 * @return 0 si salio bien -1 si hubo error.
 */
int persona_baja(EPersona* array,int limite, int dni)
{
    int retorno = -1;
    int indiceAEliminar;
    indiceAEliminar = persona_buscarPorDni(array,limite,dni);
    if(indiceAEliminar >=0)
    {
        array[indiceAEliminar].estado=1;
        retorno=0;
    }
    return retorno;
}


/**
 * \brief Imprime un grafico de edades.
 * @param array el array se pasa como parametro.
 * @param limite el tamaño del array se pasa como parametro.
 * @return 0 si salio bien -1 si hubo error.
 */
int persona_edades(EPersona* array,int limite)
{
    int retorno = -1;
    int i,max,j;
    int edadMenores = 0;
    int edadMedia = 0;
    int edadMayores = 0;
    int edades[3];
    max = 0;

    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite-1;i++)
        {
            if(!array[i].estado)
            {
                retorno = 0;
                if(array[i].edad <= 18)
                {
                    edadMenores ++;
                }
                else
                {
                    if(array[i].edad>=19 && array[i].edad<=35)
                    {
                        edadMedia ++;
                    }
                    else
                    {
                        if(array[i].edad>35)
                        {
                            edadMayores ++;
                        }
                    }
                }
            }
        }
    }
    edades[0] = edadMenores;
    edades[1] = edadMedia;
    edades[2] = edadMayores;

    for (i = 0; i < 3; i++)
    {
        if(edades[i] > max)
        {
            max = edades[i];
        }
    }

    for (i = max; i > 0; i--)
    {
        for (j = 0; j < 3; j++)
        {
            if(edades[j] >= i)
            {
                printf(" *      ");
            }
            else
            {
                printf("        ");
            }
        }
        printf("\n");
    }
    printf("<18    19-35    >35\n\n");
    return retorno;
}


/**
 * \brief Alta forzada de persona.
 * @param array el array se pasa como parametro.
 * @param limite el tamaño del array se pasa como parametro.
 * @param nombre nombre de la persona.
 * @param edad edad de la persona.
 * @param dni dni de la persona.
 * @return 0 si salio bien -1 si hubo error.
 */
int persona_altaForzada(EPersona* array,int limite,char* nombre,int edad, int dni)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = obtenerEspacioLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            array[i].edad = edad;
            array[i].dni = dni;
            array[i].estado = 0;
        }
        retorno = 0;
    }
    return retorno;
}
