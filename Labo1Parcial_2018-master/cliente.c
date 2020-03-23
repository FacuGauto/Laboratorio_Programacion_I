#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "publicacion.h"

//Funciones Privadas
static int proximoId();
static int buscarLugarLibre(Cliente* array,int limite);
////////////////////


/** \brief Inicia cada cliente como vacio
 * \param array Cliente* array de clientes
 * \param limite int cantidad de elementos del array de cliente
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
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


/** \brief Muestra todos las clientes que no esten vacios
 * \param array Cliente* array de clientes
 * \param limite int cantidad de elementos del array de clientes
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
                printf("Id: %d - Nombre: %s - Apellido: %s - Cuit: %s\n",array[i].idCliente,array[i].nombre,array[i].apellido,array[i].cuit);
        }
    }
    return retorno;
}


/** \brief Alta de un cliente
 * \param array Cliente* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int cliente_alta(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    char cuit[50];
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidString("\nApellido? ","\nEso no es un apellido","El maximo es 40",apellido,40,2))
                {
                    if(!getValidStringNumerico("\nCuit? ","\nEso no es un cuit","El maximo es 15",cuit,15,2))
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        strcpy(array[i].apellido,apellido);
                        strcpy(array[i].cuit,cuit);
                        //------------------------------
                        //------------------------------
                        array[i].idCliente = proximoId();
                        array[i].isEmpty = 0;

                        printf("\nEl ID del nuevo cliente es: %d\n",array[i].idCliente);
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


/** \brief Baja de un cliente
 * \param array Cliente* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \param id id del cliente a dar de baja
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
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


/** \brief Modificacion de un cliente
 * \param array Clientes* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \param id id del cliente a modificar
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int cliente_modificacion(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char apellido[50];
    char cuit[50];
    indiceAModificar = cliente_buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
        {
            if(!getValidString("\nApellido? ","\nEso no es un apellido","El maximo es 40",apellido,40,2))
            {
                if(!getValidStringNumerico("\nCuit? ","\nEso no es un cuit","El maximo es 15",cuit,15,2))
                {
                    retorno = 0;
                    strcpy(array[indiceAModificar].nombre,nombre);
                    strcpy(array[indiceAModificar].apellido,apellido);
                    strcpy(array[indiceAModificar].cuit,cuit);
                    //------------------------------
                    //------------------------------
                }
                else
                {
                    retorno = -2;
                }
            }
        }
    }
    return retorno;
}


/** \brief Ordena por nombre las clientes que no esten vacios
 * \param array Clientes* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \param orden orden para array(ascendente/descendente)
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
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


/** \brief Busca un lugar libre en el array clientes
 * \param array Cliente* array de clientes
 * \param limite int cantidad de elementos del array de cliente
 * \return Si devuelve un numero negativo no hay lugar libre sino devuelve el indice libre del array
 *
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


/** \brief Genera un proximo id
 * \return Devuelve el numero para el proximo id
 *
 */
static int proximoId()
{
    static int proximoId = 0;
    proximoId++;
    return proximoId;
}


/** \brief Busca por id un elemento en el array
 * \param array Cliente* array de cliente
 * \param limite int cantidad de elementos del array de cliente
 * \param id id del cliente a buscar
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el array
 *
 */
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


/** \brief Da de alta clientes sin necesidad del ingreso del usuario
 * \param array Cliente* array de cliente
 * \param limite int cantidad de elementos del array de clientes
 * \param char* nombre nombre de la cliente
 * \param char* apellido apellido del cliente
 * \param char* cuit cuit del cliente
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el array
 *
 */
int cliente_altaForzada(Cliente* array,int limite,char* nombre,char* apellido,char* cuit)
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
            strcpy(array[i].cuit,cuit);
            //------------------------------
            //------------------------------
            array[i].idCliente = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}



