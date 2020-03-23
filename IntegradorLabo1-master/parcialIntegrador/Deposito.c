#include "Deposito.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "utn.h"

Deposito* Deposito_new()
{
    Deposito* this;
    this=malloc(sizeof(Deposito));
    return this;
}

void Deposito_delete(Deposito* this)
{
    free(this);
}

Deposito* Deposito_newConParametros(int id,char* descripcion,int cantidad)
{
    Deposito* this;
    this=Deposito_new();

    if(
    !Deposito_setId(this,id)&&
    !Deposito_setDescripcion(this,descripcion)&&
    !Deposito_setCantidad(this,cantidad))
        return this;

    Deposito_delete(this);
    return NULL;
}

int Deposito_setId(Deposito* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Deposito_getId(Deposito* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Deposito_setDescripcion(Deposito* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL && validarNombreConEspacios(descripcion))
    {
        strcpy(this->descripcion,descripcion);
        retorno=0;
    }
    return retorno;
}

int Deposito_getDescripcion(Deposito* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(descripcion,this->descripcion);
        retorno=0;
    }
    return retorno;
}

int Deposito_setCantidad(Deposito* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Deposito_getCantidad(Deposito* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

void mostrarArrayListDeposito(ArrayList* this)
{
    int i,id, cantidad;
    char descripcion[128];
    Deposito* auxiliarDeposito = Deposito_new();
    for(i=0;i<al_len(this);i++)
    {
        auxiliarDeposito = al_get(this,i);
        Deposito_getId(auxiliarDeposito,&id);
        Deposito_getDescripcion(auxiliarDeposito,descripcion);
        Deposito_getCantidad(auxiliarDeposito,&cantidad);
        printf("\t%d,%s,%d\n",id,descripcion,cantidad);
    }
}

void* buscarProducto(ArrayList* this, int codigoProducto)
{
    void* returnAux = NULL;
    Deposito* auxiliarDeposito = Deposito_new();
    int i,producto;
    if(this!=NULL)
    {
        for(i=0;i<al_len(this);i++)
        {
            auxiliarDeposito = al_get(this,i);
            Deposito_getId(auxiliarDeposito,&producto);
            if(producto == codigoProducto)
            {
                returnAux = auxiliarDeposito;
                break;
            }
        }
    }
    return returnAux;
}

int Deposito_moverProducto(ArrayList* listaDeposito1,ArrayList* listaDeposito2)
{
    int depoOrigen, depoDestino, codigoProducto, indice;
    int retorno = -1;
    ArrayList* origen;
    ArrayList* destino;
    Deposito* auxiliarDeposito = NULL;

    if(listaDeposito1!=NULL && listaDeposito2!=NULL)
    {
        if(!getValidInt("Numero de deposito origen(1 o 2) ","\nNumero invalido\n",&depoOrigen,1,2,1))
        {
            if(!getValidInt("Numero de deposito destino(1 o 2) ","\nNumero invalido\n",&depoDestino,1,2,1))
            {
                if(depoOrigen != depoDestino)
                {
                    if(!getValidInt("Codigo de producto a mover: ","\nNumero invalido\n",&codigoProducto,1,15,1))
                    {
                        if(depoOrigen == 1)
                        {
                            origen = listaDeposito1;
                            destino = listaDeposito2;
                        }
                        if(depoOrigen == 2)
                        {
                            origen = listaDeposito2;
                            destino = listaDeposito1;
                        }
                        auxiliarDeposito = buscarProducto(origen,codigoProducto);
                        if(auxiliarDeposito != NULL)
                        {
                            printf("El producto existe en el deposito origen\n");
                            indice = al_indexOf(origen,auxiliarDeposito);

                            if(indice>=0)
                            {
                                auxiliarDeposito = al_pop(origen,indice);
                                if(auxiliarDeposito!=NULL)
                                {
                                    if(!al_add(destino,auxiliarDeposito))
                                    {
                                        printf("Operacion realizada con exito\n");
                                        retorno = 0;
                                    }
                                }
                            }
                        }
                        else
                        {
                            printf("El producto no existe en este deposito\n");
                        }
                    }
                }
                else
                {
                    retorno = -2;
                    printf("Deposito origen y deposito destino no pueden ser el mismo.\n");
                }
            }
        }
    }
    return retorno;
}

int Deposito_descontarCantidad(ArrayList* listaDeposito1,ArrayList* listaDeposito2)
{
    int retorno = -1;
    int auxiliar, cantidadProductos, cantidadADescontar;
    ArrayList* listaDepositoAuxiliar;
    Deposito* auxiliarDeposito;

    if(!getValidInt("Codigo de producto a descontar la cantidad: ","\nNumero invalido\n",&auxiliar,1,15,1))
    {
        auxiliarDeposito = buscarProducto(listaDeposito1,auxiliar);
        if(auxiliarDeposito!=NULL)
        {
            listaDepositoAuxiliar = listaDeposito1;
        }
        else
        {
            auxiliarDeposito = buscarProducto(listaDeposito2,auxiliar);
            if(auxiliarDeposito!=NULL)
            {
                listaDepositoAuxiliar = listaDeposito2;
            }
        }
        if(listaDepositoAuxiliar!= NULL)
        {
            printf("Producto encontrado\n");
            Deposito_getCantidad(auxiliarDeposito,&cantidadProductos);
            printf("Cantidad disponible: %d\n",cantidadProductos);
            if((!getValidInt("Cantidad a descontar: ","\nNumero invalido\n",&cantidadADescontar,1,cantidadProductos,1)) && (cantidadProductos>0))
            {
                Deposito_setCantidad(auxiliarDeposito,cantidadProductos-cantidadADescontar);
                printf("Cantidad descontada con exito\n");
                retorno = 0;
            }
            else
            {
                printf("Cantidad invalida para descontar\n");
            }
        }
    }
    return retorno;
}


int Deposito_agregarCantidad(ArrayList* listaDeposito1,ArrayList* listaDeposito2)
{
    int retorno = -1;
    int auxiliar, cantidadProductos, cantidadAAgregar;
    ArrayList* listaDepositoAuxiliar;
    Deposito* auxiliarDeposito;

    if(!getValidInt("Codigo de producto a agregar la cantidad: ","\nNumero invalido\n",&auxiliar,1,15,1))
    {
        auxiliarDeposito = buscarProducto(listaDeposito1,auxiliar);
        if(auxiliarDeposito!=NULL)
        {
            listaDepositoAuxiliar = listaDeposito1;
        }
        else
        {
            auxiliarDeposito = buscarProducto(listaDeposito2,auxiliar);
            if(auxiliarDeposito!=NULL)
            {
                listaDepositoAuxiliar = listaDeposito2;
            }
        }
        if(listaDepositoAuxiliar!= NULL)
        {
            printf("Producto encontrado\n");
            Deposito_getCantidad(auxiliarDeposito,&cantidadProductos);
            printf("Cantidad disponible: %d\n",cantidadProductos);
            if(!getValidInt("Cantidad a agregar: ","\nNumero invalido\n",&cantidadAAgregar,1,100,1))
            {
                Deposito_setCantidad(auxiliarDeposito,cantidadProductos+cantidadAAgregar);
                printf("Cantidad agregada con exito\n");
                retorno = 0;
            }
            else
            {
                printf("Cantidad invalida para agregar\n");
            }
        }
    }
    return retorno;
}

int Deposito_ordenarId(void* id1,void*id2)
{
    int retorno = 0;
    int* a = (int*) id1;
    int* b = (int*) id2;

    if(*(a)>*(b))
    {
        retorno = 1;
    }
    else if(*(a)<*(b))
    {
        retorno =-1;
    }
    return retorno;
}
