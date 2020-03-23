#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "publicacion.h"
#include "informar.h"


/** \brief Muestra los datos del cliente con la cantidad de publicaciones activas que tiene
 * \param Cliente* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el array
 *
 */
int cliente_mostrar_con_publicaciones_activas(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones)
{
    int retorno = -1;
    int i,activas;

    if((limiteClientes > 0 && clientes != NULL) && (limitePublicaciones > 0 && publicaciones != NULL))
    {
        retorno = 0;
        for(i=0;i<limiteClientes;i++)
        {
            if(!clientes[i].isEmpty)
            {
                activas = cliente_cant_publicaciones_activas(clientes[i].idCliente,publicaciones,limitePublicaciones);
                printf("Id: %d - Nombre: %s - Apellido: %s - Cuit: %s - Avisos activos: %d\n",clientes[i].idCliente,clientes[i].nombre,clientes[i].apellido,clientes[i].cuit,activas);
                printf("\n");
            }
        }
    }
    return retorno;
}


/** \brief Calcula la cantidad de publicaciones activas que tiene un cliente
 * \param idCliente id del cliente
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return cantidad de publicaciones activas para ese cliente
 *
 */
int cliente_cant_publicaciones_activas(int idCliente,Publicacion* publicaciones,int limitePublicaciones)
{
    int i;
    int activas = 0;
    for(i=0;i<limitePublicaciones;i++)
    {
        publicacion_ordenar_por_idCliente(publicaciones,limitePublicaciones);
        if(!publicaciones[i].isEmpty)
        {
            if(publicaciones[i].idCliente == idCliente)
            {
                if(publicaciones[i].estado == 0)
                {
                    activas ++;
                }
            }
        }
    }
    return activas;
}


/** \brief Calcula la cantidad de publicaciones pausadas que tiene un cliente
 * \param idCliente id del cliente
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return cantidad de publicaciones pausadas para ese cliente
 *
 */
int cliente_cant_publicaciones_pausadas(int idCliente,Publicacion* publicaciones,int limitePublicaciones)
{
    int i;
    int pausadas = 0;
    for(i=0;i<limitePublicaciones;i++)
    {
        publicacion_ordenar_por_idCliente(publicaciones,limitePublicaciones);
        if(!publicaciones[i].isEmpty)
        {
            if(publicaciones[i].idCliente == idCliente)
            {
                if(publicaciones[i].estado == 1)
                {
                    pausadas ++;
                }
            }
        }
    }
    return pausadas;
}


/** \brief Calcula la cantidad de publicaciones que tiene un cliente
 * \param idCliente id del cliente
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return cantidad de publicaciones para ese cliente
 *
 */
int cliente_cant_publicaciones(int idCliente,Publicacion* publicaciones,int limitePublicaciones)
{
    int i;
    int cantPublicaciones = 0;
    for(i=0;i<limitePublicaciones;i++)
    {
        publicacion_ordenar_por_idCliente(publicaciones,limitePublicaciones);
        if(!publicaciones[i].isEmpty)
        {
            if(publicaciones[i].idCliente == idCliente)
            {
                cantPublicaciones ++;
            }
        }
    }
    return cantPublicaciones;
}


/** \brief Imprime los datos de cada publicacion junto con el cuit del cliente
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
  * \param Cliente* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int imprimir_publicaciones(Publicacion* publicaciones,int limitePublicaciones,Cliente* clientes,int limiteClientes)
{
    int retorno = -1;
    int i,indiceCliente,idCliente;

    if(limitePublicaciones > 0 && publicaciones != NULL)
    {
        for(i=0;i<limitePublicaciones;i++)
        {
            if(!publicaciones[i].isEmpty)
            {
                if(!publicaciones[i].estado)
                {
                    idCliente = publicaciones[i].idCliente;
                    indiceCliente = cliente_buscarPorId(clientes,limiteClientes,idCliente);
                    if(indiceCliente>=0)
                    {
                        printf("\nId publicacion: %d - idCliente: %d - Numero de rubro: %d - Texto: %s - Cuit del cliente: %s \n",publicaciones[i].idPublicacion,publicaciones[i].idCliente,publicaciones[i].numeroDeRubro,publicaciones[i].texto,clientes[indiceCliente].cuit);
                        retorno = 0;
                    }
                }
            }
        }
    }
    return retorno;
}


/** \brief Muestra el o los clientes con mas publicaciones activas
 * \param Cliente* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int clientes_con_mas_publicaciones_activas(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones)
{
    int i,activas;
    int retorno = -1;
    int maximoPublicaciones = -1;

    if((limiteClientes > 0 && clientes != NULL) && (limitePublicaciones > 0 && publicaciones != NULL))
    {
        for(i=0;i<limiteClientes;i++)
        {
            if(!clientes[i].isEmpty)
            {
                activas = cliente_cant_publicaciones_activas(clientes[i].idCliente,publicaciones,limitePublicaciones);
                if(maximoPublicaciones < activas)
                {
                    maximoPublicaciones = activas;
                    retorno = 0;
                }
            }
        }
        for(i=0;i<limiteClientes;i++)
        {
            if(!clientes[i].isEmpty)
            {
                activas = cliente_cant_publicaciones_activas(clientes[i].idCliente,publicaciones,limitePublicaciones);
                if(maximoPublicaciones == activas)
                {
                    printf("El cliente %s %s tiene la mayor cantidad de publicaciones activas: %d\n",clientes[i].apellido,clientes[i].nombre,maximoPublicaciones);
                }
            }
        }
    }
    return retorno;
}


/** \brief Muestra el o los clientes con mas publicaciones pausadas
 * \param Cliente* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int clientes_con_mas_publicaciones_pausadas(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones)
{
    int i,pausadas;
    int maximoPublicaciones = -1;
    int retorno = -1;

    if((limiteClientes > 0 && clientes != NULL) && (limitePublicaciones > 0 && publicaciones != NULL))
    {
        for(i=0;i<limiteClientes;i++)
        {
            if(!clientes[i].isEmpty)
            {
                pausadas = cliente_cant_publicaciones_pausadas(clientes[i].idCliente,publicaciones,limitePublicaciones);
                if(maximoPublicaciones < pausadas)
                {
                    maximoPublicaciones = pausadas;
                    retorno = 0;
                }
            }
        }
        if(maximoPublicaciones > 0)
        {
            for(i=0;i<limiteClientes;i++)
            {
                if(!clientes[i].isEmpty)
                {
                    pausadas = cliente_cant_publicaciones_pausadas(clientes[i].idCliente,publicaciones,limitePublicaciones);
                    if(maximoPublicaciones == pausadas)
                    {
                        printf("El cliente %s %s tiene la mayor cantidad de publicaciones pausadas: %d\n",clientes[i].apellido,clientes[i].nombre,maximoPublicaciones);
                    }
                }
            }
        }
        else
        {
            printf("No hay publicaciones pausadas\n");
        }
    }
    return retorno;
}


/** \brief Muestra el o los clientes con mas publicaciones
 * \param Cliente* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int clientes_con_mas_publicaciones(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones)
{
    int i,cantPublicaciones;
    int maximoPublicaciones = -1;
    int retorno = -1;

    if((limiteClientes > 0 && clientes != NULL) && (limitePublicaciones > 0 && publicaciones != NULL))
    {
        for(i=0;i<limiteClientes;i++)
        {
            if(!clientes[i].isEmpty)
            {
                cantPublicaciones = cliente_cant_publicaciones(clientes[i].idCliente,publicaciones,limitePublicaciones);
                if(maximoPublicaciones < cantPublicaciones)
                {
                    maximoPublicaciones = cantPublicaciones;
                    retorno = 0;
                }
            }
        }
        if(maximoPublicaciones > 0)
        {
            for(i=0;i<limiteClientes;i++)
            {
                if(!clientes[i].isEmpty)
                {
                    cantPublicaciones = cliente_cant_publicaciones(clientes[i].idCliente,publicaciones,limitePublicaciones);
                    if(maximoPublicaciones == cantPublicaciones)
                    {
                        printf("El cliente %s %s tiene la mayor cantidad de publicaciones: %d\n",clientes[i].apellido,clientes[i].nombre,maximoPublicaciones);
                    }
                }
            }
        }
        else
        {
            printf("No hay publicaciones\n");
        }
    }
    return retorno;
}


/** \brief Muestra la cantidad de publicaciones que tiene el rubro ingresado
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int cantidad_publicaciones_por_rubro(Publicacion* publicaciones, int limitePublicaciones)
{
    int retorno = -1;
    int numeroDeRubro, i;
    int activas = 0;

    if(limitePublicaciones > 0 && publicaciones != NULL)
    {
        if(!getValidInt("\nNumero de rubro? ","\nEso no es un rubro valido\n",&numeroDeRubro,0,99,1))
        {
            for(i=0;i<limitePublicaciones;i++)
            {
                if(publicaciones[i].numeroDeRubro == numeroDeRubro)
                {
                    if(publicaciones[i].estado == 0)
                    {
                        activas ++;
                    }
                }
            }
            retorno = 0;
            printf("El numero de rubro %d tiene %d publicaciones activas.\n",numeroDeRubro,activas);
        }
    }
    return retorno;
}

/** \brief Muestra el o los rubros con mas publicaciones
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int rubro_mas_publicaciones(Publicacion* publicaciones, int limitePublicaciones)
{
    int retorno = -1;
    int activas, i, numeroRubro;
    int numeroDeRubroMayor = -1;
    activas = 0;
    int maximoActivas = 0;

    if(limitePublicaciones > 0 && publicaciones != NULL)
    {
        maximoActivas = publicaciones_maximo_activas(publicaciones,limitePublicaciones);
        if(maximoActivas > 0)
        {
            for(i=0;i<limitePublicaciones;i++)
            {
                if(!publicaciones[i].isEmpty)
                {
                    if(publicaciones[i].estado == 0)
                    {
                        numeroRubro = publicaciones[i].numeroDeRubro;
                        activas = publicaciones_rubro_cant_publicaciones_activas(numeroRubro,publicaciones,limitePublicaciones);
                        if(maximoActivas == activas && numeroDeRubroMayor != numeroRubro)
                        {
                            numeroDeRubroMayor = numeroRubro;
                            printf("\nEl numero de rubro: %d, tiene la mayor cantidad de publicaciones activas: %d.\n",numeroRubro,activas);
                        }
                    }
                }
            }
        }
        else
        {
            printf("No hay publicaciones activas\n");
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el maximo de publicaciones activas
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Devuelve el numero maximo de publicaciones activas
 *
 */
int publicaciones_maximo_activas(Publicacion* publicaciones, int limitePublicaciones)
{
    int activas, i, numeroRubro;
    activas = 0;
    int maximoActivas = 0;
    int flag = 0;

    if(limitePublicaciones > 0 && publicaciones != NULL)
    {
        for(i=0;i<limitePublicaciones;i++)
        {
            if(!publicaciones[i].isEmpty)
            {
                if(publicaciones[i].estado == 0)
                {
                    numeroRubro = publicaciones[i].numeroDeRubro;
                    activas = publicaciones_rubro_cant_publicaciones_activas(numeroRubro,publicaciones,limitePublicaciones);
                    if(flag == 0)
                    {
                        maximoActivas = activas;
                        flag = 1;
                    }
                    else
                    {
                        if(maximoActivas < activas)
                        {
                            maximoActivas = activas;
                        }
                    }
                }
            }
        }
    }
    return maximoActivas;
}



/** \brief calcula la cantidad de publicaciones activas que tiene un rubro
 * \param numeroDeRubro int numero de rubro a ser analizado
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Cantidad de publicaciones activas de cierto rubro
 *
 */
int publicaciones_rubro_cant_publicaciones_activas(int numeroDeRubro,Publicacion* publicaciones,int limitePublicaciones)
{
    int i;
    int activas = 0;
    for(i=0;i<limitePublicaciones;i++)
    {
        publicacion_ordenar_por_numeroDeRubro(publicaciones,limitePublicaciones);
        if(!publicaciones[i].isEmpty)
        {
            if(publicaciones[i].numeroDeRubro == numeroDeRubro)
            {
                if(publicaciones[i].estado == 0)
                {
                    activas ++;
                }
            }
        }
    }
    return activas;
}


/** \brief Muestra el o los rubros con menos publicaciones
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int rubro_menos_publicaciones(Publicacion* publicaciones, int limitePublicaciones)
{
    int retorno = -1;
    int activas, i, numeroRubro;
    int numeroDeRubroMenor = -1;
    activas = 0;
    int minimoActivas = 0;

    if(limitePublicaciones > 0 && publicaciones != NULL)
    {
        minimoActivas = publicaciones_minimo_activas(publicaciones,limitePublicaciones);
        if(minimoActivas > 0)
        {
            for(i=0;i<limitePublicaciones;i++)
            {
                if(!publicaciones[i].isEmpty)
                {
                    if(publicaciones[i].estado == 0)
                    {
                        numeroRubro = publicaciones[i].numeroDeRubro;
                        activas = publicaciones_rubro_cant_publicaciones_activas(numeroRubro,publicaciones,limitePublicaciones);
                        if(minimoActivas == activas && numeroDeRubroMenor != numeroRubro)
                        {
                            numeroDeRubroMenor = numeroRubro;
                            printf("\nEl numero de rubro: %d, tiene la menor cantidad de publicaciones activas: %d.\n",numeroRubro,activas);
                        }
                    }
                }
            }
        }
        else
        {
            printf("No hay publicaciones activas\n");
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Obtiene el minimo de publicaciones activas
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Devuelve el numero de publicaciones minimas  activas
 *
 */
int publicaciones_minimo_activas(Publicacion* publicaciones, int limitePublicaciones)
{
    int activas, i, numeroRubro;
    activas = 0;
    int minimoActivas = 0;
    int flag = 0;

    if(limitePublicaciones > 0 && publicaciones != NULL)
    {
        for(i=0;i<limitePublicaciones;i++)
        {
            if(!publicaciones[i].isEmpty)
            {
                if(publicaciones[i].estado == 0)
                {
                    numeroRubro = publicaciones[i].numeroDeRubro;
                    activas = publicaciones_rubro_cant_publicaciones_activas(numeroRubro,publicaciones,limitePublicaciones);
                    if(flag == 0)
                    {
                        minimoActivas = activas;
                        flag = 1;
                    }
                    else
                    {
                        if(minimoActivas > activas)
                        {
                            minimoActivas = activas;
                        }
                    }
                }
            }
        }
    }
    return minimoActivas;
}


/** \brief Muestra las publicaciones de un cliente
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \param idCliente int id del cliente a mostrar
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicaciones_listar_por_idCliente(Publicacion* publicaciones, int limitePublicaciones, int idCliente)
{
    int retorno = -1;
    int i;
    if(limitePublicaciones > 0 && publicaciones != NULL)
    {
        for(i=0;i<limitePublicaciones;i++)
        {
            if(!publicaciones[i].isEmpty && publicaciones[i].idCliente==idCliente)
            {
                retorno = 0;
                printf("\n    IdPublicacion: %d - Numero de rubro: %d - Texto: %s - Estado: %d \n",publicaciones[i].idPublicacion,publicaciones[i].numeroDeRubro,publicaciones[i].texto,publicaciones[i].estado);
            }
        }
    }
    return retorno;
}


/*
int cliente_con_mas_publicaciones_activas(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones)
{
    int i,activas;
    int maximoPublicaciones = -1;
    int indiceClienteMaximo = -1;

    if((limiteClientes > 0 && clientes != NULL) && (limitePublicaciones > 0 && publicaciones != NULL))
    {
        for(i=0;i<limiteClientes;i++)
        {
            if(!clientes[i].isEmpty)
            {
                activas = cliente_cant_publicaciones_activas(clientes[i].idCliente,publicaciones,limitePublicaciones);
                if(maximoPublicaciones < activas)
                {
                    maximoPublicaciones = activas;
                    indiceClienteMaximo = i;
                }
            }
        }
        if(maximoPublicaciones > 0)
        {
            printf("El cliente %s %s tiene la mayor cantidad de publicaciones activas: %d\n",clientes[indiceClienteMaximo].apellido,clientes[indiceClienteMaximo].nombre,maximoPublicaciones);
        }
        else
        {
            printf("No hay publicaciones activas");
        }

    }
    return indiceClienteMaximo;
}

int cliente_con_mas_publicaciones_pausadas(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones)
{
    int i,pausadas;
    int maximoPublicaciones = -1;
    int indiceClienteMaximo = -1;

    if((limiteClientes > 0 && clientes != NULL) && (limitePublicaciones > 0 && publicaciones != NULL))
    {
        for(i=0;i<limiteClientes;i++)
        {
            if(!clientes[i].isEmpty)
            {
                pausadas = cliente_cant_publicaciones_pausadas(clientes[i].idCliente,publicaciones,limitePublicaciones);
                if(maximoPublicaciones < pausadas)
                {
                    maximoPublicaciones = pausadas;
                    indiceClienteMaximo = i;
                }
            }
        }
        if(maximoPublicaciones > 0)
        {
            printf("El cliente %s %s tiene la mayor cantidad de publicaciones pausadas: %d\n",clientes[indiceClienteMaximo].apellido,clientes[indiceClienteMaximo].nombre,maximoPublicaciones);
        }
        else
        {
            printf("No hay publicaciones pausadas\n");
        }


    }
    return indiceClienteMaximo;
}


int cliente_con_mas_publicaciones(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones)
{
    int i,cantPublicaciones;
    int maximoPublicaciones = -1;
    int indiceClienteMaximo = -1;

    if((limiteClientes > 0 && clientes != NULL) && (limitePublicaciones > 0 && publicaciones != NULL))
    {
        for(i=0;i<limiteClientes;i++)
        {
            if(!clientes[i].isEmpty)
            {
                cantPublicaciones = cliente_cant_publicaciones(clientes[i].idCliente,publicaciones,limitePublicaciones);
                if(maximoPublicaciones < cantPublicaciones)
                {
                    maximoPublicaciones = cantPublicaciones;
                    indiceClienteMaximo = i;
                }
            }
        }
        if(maximoPublicaciones > 0)
        {
            printf("El cliente %s %s tiene la mayor cantidad de publicaciones: %d\n",clientes[indiceClienteMaximo].apellido,clientes[indiceClienteMaximo].nombre,maximoPublicaciones);
        }
        else
        {
            printf("No hay publicaciones\n");
        }
    }
    return indiceClienteMaximo;
}
*/
