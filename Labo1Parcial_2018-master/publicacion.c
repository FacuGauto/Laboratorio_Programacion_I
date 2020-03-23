#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "utn.h"
#include "cliente.h"

//Funciones privadas
static int proximoId();
static int buscarLugarLibre(Publicacion* array,int limite);
//////////////////////////


/** \brief Inicia cada publicacion como vacia
 * \param array Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicacion_init(Publicacion* array,int limite)
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


/** \brief Muestra todos las publicaciones que no esten vacias
 * \param array Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicacion_mostrar(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("Id: %d - IdCliente: %d - Numero de rubro: %d - Texto: %s - Estado: %d\n",array[i].idPublicacion,array[i].idCliente,array[i].numeroDeRubro,array[i].texto,array[i].estado);
        }
    }
    return retorno;
}



/** \brief Alta de una publicacion
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \param Cliente* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicacion_alta(Publicacion* publicaciones,int limitePublicaciones,Cliente* clientes,int limiteClientes)
{
    int retorno = -1;
    int i, idCliente, numeroDeRubro;
    char texto[64];

    if(limitePublicaciones > 0 && publicaciones != NULL)
    {
        i = buscarLugarLibre(publicaciones,limitePublicaciones);
        if(i >= 0)
        {
            if(!getValidInt("\nId Cliente? ","\nEso no es un id de cliente valido",&idCliente,0,999,2))
            {
                if(cliente_buscarPorId(clientes,limiteClientes,idCliente)>=0)
                {
                    if(!getValidInt("\nNumero de Rubro: ","\n Eso no es un numero de rubro valido",&numeroDeRubro,0,99,1))
                    {
                        if(!getValidStringAlfanumerico("\nTexto de la publicacion? ","\nEso no es una publicacion valida","Excede el numero de caracteres maximo",texto,64,2))
                        {
                            retorno = 0;
                            publicaciones[i].idCliente = idCliente;
                            publicaciones[i].numeroDeRubro = numeroDeRubro;
                            strcpy(publicaciones[i].texto,texto);
                            //------------------------------
                            //------------------------------
                            publicaciones[i].estado = 0;
                            publicaciones[i].idPublicacion = proximoId();
                            publicaciones[i].isEmpty = 0;

                            printf("\nEl ID de la nueva publicacion es: %d\n",publicaciones[i].idPublicacion);
                        }
                        else
                        {
                            retorno = -3;
                        }
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


/** \brief Baja de una publicacion
 * \param array Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \param id id de la publicacion a dar de baja
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicacion_baja(Publicacion* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = publicacion_buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}


/** \brief Modificacion de una publicacion
 * \param Publicaciones* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \param id id de la publicacion a modificar
 * \param Cliente* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicacion_modificacion(Publicacion* publicaciones,int limite, int id,Cliente* clientes,int limiteClientes)
{
    int retorno = -1;
    int indiceAModificar,idCliente,numeroDeRubro;
    char texto[64];
    indiceAModificar = publicacion_buscarPorId(publicaciones,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidInt("\nId Cliente? ","\nEso no es un id de cliente valido",&idCliente,0,999,2))
        {
            if(cliente_buscarPorId(clientes,limiteClientes,idCliente)>=0)
            {
                if(!getValidInt("\nNumero de Rubro: ","\n Eso no es un numero de rubro valido",&numeroDeRubro,0,99,1))
                {
                    if(!getValidStringAlfanumerico("\nTexto de la publicacion? ","\nEso no es una publicacion valida","Excede el numero de caracteres maximo",texto,64,2))
                    {
                        retorno = 0;
                        publicaciones[indiceAModificar].idCliente = idCliente;
                        publicaciones[indiceAModificar].numeroDeRubro = numeroDeRubro;
                        strcpy(publicaciones[indiceAModificar].texto,texto);
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
    }
    return retorno;
}


/** \brief Ordena por idCliente las publicaciones que no esten vacios
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicacion_ordenar_por_idCliente(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if(array[i].idCliente > array[i+1].idCliente)
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


/** \brief Ordena por numero de rubro las publicaciones que no esten vacios
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicacion_ordenar_por_numeroDeRubro(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if(array[i].numeroDeRubro > array[i+1].numeroDeRubro)
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                        retorno = 0;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}


/** \brief Busca por id un elemento en el array de Publicaciones
 * \param Publicacion* array de publicacion
 * \param limite int cantidad de elementos del array de publicaciones
 * \param id id de la publicacion a buscar
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el array
 *
 */
int publicacion_buscarPorId(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicacion==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un lugar libre en el array de publicaciones
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \return Si devuelve un numero negativo no hay lugar libre sino devuelve el indice libre del array
 *
 */
static int buscarLugarLibre(Publicacion* array,int limite)
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


/** \brief Da de alta publicaciones sin necesidad del ingreso del usuario
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \param int idCliente id del cliente
 * \param int numeroDeRubro numero de rubro de la publicacion
 * \param char* texto texto que lleva la publicacion
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicacion_altaForzada(Publicacion* array,int limite,int idCliente,int numeroDeRubro,char* texto)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            array[i].idCliente = idCliente;
            array[i].numeroDeRubro = numeroDeRubro;
            strcpy(array[i].texto,texto);
            //------------------------------
            //------------------------------
            array[i].estado = 0;
            array[i].idPublicacion = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Muestra los datos del cliente correspondiente a la publicacion
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \param Cliente* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el array
 *
 */
int publicacion_mostrar_cliente_por_publicacion(Publicacion* publicaciones,int limitePublicaciones,Cliente* clientes,int limiteClientes)
{
    int retorno = -1;
    int idPublicacion,indicePublicacion, indiceCliente, idCliente;

    if(limitePublicaciones > 0 && publicaciones != NULL)
    {
        if(!getValidInt("\nId Publicacion? ","\nEso no es un id de publicacion valido\n",&idPublicacion,0,999,1))
        {
            indicePublicacion = publicacion_buscarPorId(publicaciones,limitePublicaciones,idPublicacion);
            if((indicePublicacion)>=0)
            {
                idCliente = publicaciones[indicePublicacion].idCliente;
                indiceCliente = cliente_buscarPorId(clientes,limiteClientes,idCliente);
                if(indiceCliente>=0)
                {
                    printf("\nEsta publicacion pertenece a: %s %s, con cuit: %s\n",clientes[indiceCliente].apellido,clientes[indiceCliente].nombre,clientes[indiceCliente].cuit);
                    retorno = indicePublicacion;
                }
            }
        }
    }
    return retorno;
}


/** \brief Pausa una publicacion
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \param Cliente* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicacion_pausar(Publicacion* publicaciones,int limitePublicaciones,Cliente* clientes,int limiteClientes)
{
    int retorno = -1;
    int respuesta;
    int indicePublicacion;

    indicePublicacion = publicacion_mostrar_cliente_por_publicacion(publicaciones,limitePublicaciones,clientes,limiteClientes);

    if(indicePublicacion>=0)
    {
        if(!getValidInt("\nIngrese el numero de la opcion que desea realizar?\n\n1.Pausar.\n2.No pausar.\n","No es una opcion correcta\n",&respuesta,0,2,1))
        {
            retorno = 0;
            if(respuesta == 1)
            {
                publicaciones[indicePublicacion].estado = 1;
            }
        }
    }
    return retorno;
}


/** \brief Reanuda una publicacion
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \param Cliente* array de clientes
 * \param limite int cantidad de elementos del array de clientes
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicacion_reanudar(Publicacion* publicaciones,int limitePublicaciones,Cliente* clientes,int limiteClientes)
{
    int retorno = -1;
    int respuesta;
    int indicePublicacion;

    indicePublicacion = publicacion_mostrar_cliente_por_publicacion(publicaciones,limitePublicaciones,clientes,limiteClientes);

    if(indicePublicacion>=0)
    {
        if(!getValidInt("\nIngrese el numero de la opcion que desea realizar?\n\n1.Reanudar.\n2.No reanudar.\n","No es una opcion correcta\n",&respuesta,0,2,1))
        {
            retorno = 0;
            if(respuesta == 1)
            {
                publicaciones[indicePublicacion].estado = 0;
            }
        }
    }
    return retorno;
}


/** \brief Da de baja una publicacion por su id cliente
 * \param Publicacion* array de publicaciones
 * \param limite int cantidad de elementos del array de publicaciones
 * \param id id del cliente
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicacion_baja_por_idCliente(Publicacion* array,int limite, int id)
{
    int retorno=-1;
    int i;

    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].idCliente == id)
            {
                array[i].isEmpty = 1;
                retorno=0;
            }
        }
    }
    return retorno;
}
