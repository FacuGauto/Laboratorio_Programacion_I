#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Publicacion.h"
#include "utn.h"
#include "cliente.h"


//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Publicacion* array,int limite);
static int buscarPorId(Publicacion* array,int limite, int id);
//__________________


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

int publicacion_mostrar(Publicacion* publicaciones,int limite,Cliente* clientes, int limiteClientes)
{
    int retorno = -1;
    int i;
    //int idCliente;
    //int indiceCliente;

    if((limite > 0 && publicaciones != NULL) && (limiteClientes > 0 && clientes != NULL))
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!publicaciones[i].isEmpty)
            {
                //idCliente = publicaciones[i].idCliente;
                //indiceCliente = cliente_buscarPorId(clientes,limiteClientes,idCliente);
                printf("%d - %d - %d - %s\n",publicaciones[i].idPublicacion, publicaciones[i].idCliente,publicaciones[i].numeroRubro,publicaciones[i].texto);
            }
        }
    }
    return retorno;
}

int publicacion_alta(Publicacion* publicaciones, int limitePublicaciones, int id, Cliente* clientes, int limiteClientes)
{
    int retorno = -1;
    int i;
    int idCliente;
    char texto[64];
    int numeroRubro;

    if((limitePublicaciones > 0 && publicaciones != NULL) && (limiteClientes > 0 && clientes != NULL))
    {
        i = buscarLugarLibre(publicaciones,limitePublicaciones);
        if(i >= 0)
        {
            idCliente = cliente_buscarPorId(clientes,limiteClientes,id);
            if (idCliente >=0)
            {
                // alta
                //TODO
                if(!getValidInt("\nIngrese el numero de rubro","\nNo es un numero de rubro",&numeroRubro,0,99,1))
                {
                    if(!getValidString("\nTexto? ","\nEso no es un texto valido","El maximo es 40",texto,40,2))
                    {
                        retorno = 0;
                        strcpy(publicaciones[i].texto,texto);
                        publicaciones[i].numeroRubro = numeroRubro;
                        //------------------------------
                        //------------------------------
                        publicaciones[i].estado = 0;
                        publicaciones[i].idCliente = idCliente;
                        publicaciones[i].idPublicacion = proximoId();
                        publicaciones[i].isEmpty = 0;
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

/*
int publicacion_modificacion(Publicacion* publicaciones,int limitePublicaciones, int id)
{
    int retorno = -1;
    int indiceAModificar;
    float precio;
    int stock;

    indiceAModificar = buscarPorId(publicaciones,limitePublicaciones,id);
    if(indiceAModificar>=0)
    {
        if(!getValidFloat("\nIngrese el precio: ","\n Eso no es un precio valido",&precio,0,99999,2))
        {
            if(!getValidInt("\nIngrese el stock: ","\n No es un stock valido",&stock,0,99999,2))
            {
                retorno = 0;
                publicaciones[indiceAModificar].precio = precio;
                publicaciones[indiceAModificar].stock = stock;
                //------------------------------
                //TODO
            }
            else
            {
                retorno = -3;
            }
        }
    }
    return retorno;
}


int publicacion_comprar(Publicacion* publicaciones,int limitePublicaciones, int id,Usuario* usuarios,int limiteUsuarios)
{
    int retorno = -1;
    int indiceAModificar;
    indiceAModificar = buscarPorId(publicaciones,limitePublicaciones,id);
    int idUsuario;
    int calificacion;
    int indiceUsuario;

    if(indiceAModificar>=0)
    {
        retorno = 0;
        if(publicaciones[indiceAModificar].stock > 0)
        {
            printf("Se puede comprar");
            retorno = 0;
            publicaciones[indiceAModificar].cantidadVendida ++;
            publicaciones[indiceAModificar].stock --;
            if(!getValidInt("\nIngrese una calificacion para el vendedor (1..10): ","\n No es una calificion valida",&calificacion,1,10,2))
            {
                idUsuario = publicaciones[indiceAModificar].idUsuario;
                indiceUsuario = usuario_buscarPorId(usuarios,limiteUsuarios,idUsuario);
                if(indiceUsuario>=0)
                {
                    usuarios[idUsuario].acumuladorCalificaciones += calificacion;
                    usuarios[idUsuario].cantidadCalificaciones ++;
                }
            }
        }
        else
        {
            printf("No hay stock");
        }
    }
    return retorno;
}

int publicacion_baja(Publicacion* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {publicaciones[i].idCliente = idCliente;
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}
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

static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

int publicacion_altaForzada(Publicacion* publicaciones, int limitePublicaciones, int id, Cliente* clientes, int limiteCliente, char* texto, int numeroRubro)
{
    int retorno = -1;
    int i;
    int idCliente;

    if((limitePublicaciones > 0 && publicaciones != NULL) && (limiteCliente > 0 && clientes != NULL))
    {
        i = buscarLugarLibre(publicaciones,limitePublicaciones);
        if(i >= 0)
        {
            publicaciones[i].idCliente = id;
            idCliente = cliente_buscarPorId(clientes,limiteCliente,id);
            if (idCliente >=0)
            {
                // alta
                //TODO

                retorno = 0;
                strcpy(publicaciones[i].texto,texto);
                publicaciones[i].numeroRubro = numeroRubro;
                //------------------------------
                //------------------------------
                publicaciones[i].estado = 0;
                publicaciones[i].idCliente = idCliente;
                publicaciones[i].idPublicacion = proximoId();
                publicaciones[i].isEmpty = 0;

            }
        }
    }
    else
    {
            retorno = -2;
    }
    return retorno;
}

static int buscarPorId(Publicacion* array,int limite, int id)
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

int cliente_por_publicacion(Publicacion* array,int limite, int id,Cliente* clientes, int limiteCliente)
{
    int retorno = -1;
    //int i;
    //char nombre[50];
    //char apellido[50];
    //int cuit;
    int indicePublicacion = buscarPorId(array,limite,id);

    printf("%d",indicePublicacion);
    //int indiceCliente;
    //int idCliente;
    for(i=0;i<limite;i++)
    {
        if(!array[i].isEmpty)
        {
            if(array[i].idCliente == id)
            {
                indiceCliente = cliente_buscarPorId(clientes,limiteCliente,idCliente);
                if(indiceCliente >= 0)
                {
                    strcmp(nombre,clientes[indiceCliente].nombre);
                    strcmp(apellido,clientes[indiceCliente].apellido);
                    cuit = clientes[indiceCliente].cuit;

                    printf("%s %s %d",nombre,apellido,cuit);
                }
            }
        }
    }
*/
    return retorno;
}

