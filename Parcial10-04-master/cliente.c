#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"


//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Cliente* array,int limite);
//__________________

/** \brief
 * \param array Cliente*
 * \param limite int
 * \return int
 *
 */
int cliente_init(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief Muestra todas las pantallas que no esten vacias
 * \param array Pantalla* array de pantallas
 * \param limite int cantidad de elementos del array de pantallas
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int cliente_mostrar(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %s - %d - %d\n",array[i].idCliente, array[i].nombre, array[i].apellido, array[i].cuit, array[i].isEmpty);
        }
    }
    return retorno;
}


int cliente_alta(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    int cuit;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidString("\nApellido? ","\nEso no es un apellido valido","El maximo es 40",apellido,40,2))
                {
                    if(!getValidInt("\nCuit?","\nEso no es un cuit valido",&cuit,0,99,1))
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        strcpy(array[i].apellido,apellido);
                        array[i].cuit = cuit;
                        //------------------------------
                        //------------------------------
                        array[i].idCliente = proximoId();
                        array[i].isEmpty = 0;
                    }
                }
            }
        }
        else
        {
           retorno = -3;
        }
    }
    return retorno;
}

int cliente_baja(Cliente* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = cliente_buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

int cliente_modificacion(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char apellido[50];
    int cuit;

    indiceAModificar = cliente_buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
        {
            if(!getValidString("\nApellido? ","\nEso no es un apellido valido","El maximo es 40",apellido,40,2))
            {
                if(!getValidInt("\nCuit?","\nEso no es un cuit valido",&cuit,0,99,1))
                {
                    retorno = 0;
                    strcpy(array[indiceAModificar].nombre,nombre);
                    strcpy(array[indiceAModificar].apellido,apellido);
                    array[indiceAModificar].cuit = cuit;
                    //------------------------------
                    //TODO
                }
                else
                {
                    retorno = -3;
                }
            }
        }
    }
    return retorno;
}

/*
int cliente_ordenar(Cliente* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden))
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
*/
static int buscarLugarLibre(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


int cliente_buscarPorId(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int cliente_altaForzada(Cliente* array,int limite,char* nombre,char* apellido,int cuit)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].apellido,apellido);
            array[i].cuit = cuit;
            //------------------------------
            //------------------------------
            array[i].idCliente = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

