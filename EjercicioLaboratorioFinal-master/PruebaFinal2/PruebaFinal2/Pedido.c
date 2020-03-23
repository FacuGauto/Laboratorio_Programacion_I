#include "Pedido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

Pedido* Pedido_new()
{
    Pedido* this;
    this=malloc(sizeof(Pedido));
    return this;
}

void Pedido_delete(Pedido* this)
{
    free(this);
}

Pedido* Pedido_newConParametros(int id,char* producto,char* direccion,char* localidad,char* recibe)
{
    Pedido* this;
    this=Pedido_new();

    if(
    !Pedido_setId(this,id)&&
    !Pedido_setProducto(this,producto)&&
    !Pedido_setDireccion(this,direccion)&&
    !Pedido_setLocalidad(this,localidad)&&
    !Pedido_setRecibe(this,recibe))
        return this;

    Pedido_delete(this);
    return NULL;
}

int Pedido_setId(Pedido* this,int id)
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

int Pedido_getId(Pedido* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Pedido_setProducto(Pedido* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(this->producto,producto);
        retorno=0;
    }
    return retorno;
}

int Pedido_getProducto(Pedido* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(producto,this->producto);
        retorno=0;
    }
    return retorno;
}

int Pedido_setDireccion(Pedido* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(this->direccion,direccion);
        retorno=0;
    }
    return retorno;
}

int Pedido_getDireccion(Pedido* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(direccion,this->direccion);
        retorno=0;
    }
    return retorno;
}

int Pedido_setLocalidad(Pedido* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(this->localidad,localidad);
        retorno=0;
    }
    return retorno;
}

int Pedido_getLocalidad(Pedido* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(localidad,this->localidad);
        retorno=0;
    }
    return retorno;
}

int Pedido_setRecibe(Pedido* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(this->recibe,recibe);
        retorno=0;
    }
    return retorno;
}

int Pedido_getRecibe(Pedido* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(recibe,this->recibe);
        retorno=0;
    }
    return retorno;
}

void Pedido_mostrarArrayList(ArrayList* listaPedido)
{
    int i,id;
    char producto[4096],direccion[4096],localidad[4096],recibe[4096];
    Pedido* auxPedido;

    for(i=0;i<al_len(listaPedido);i++)
    {
        auxPedido = al_get(listaPedido,i);
        if(auxPedido!=NULL)
        {
            Pedido_getId(auxPedido,&id);
            Pedido_getProducto(auxPedido,producto);
            Pedido_getDireccion(auxPedido,direccion);
            Pedido_getLocalidad(auxPedido,localidad);
            Pedido_getRecibe(auxPedido,recibe);
            printf("%d %s %s %s %s\n",id,producto,direccion,localidad,recibe);
        }
    }
}
