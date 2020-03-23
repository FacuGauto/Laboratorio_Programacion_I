#include "ArrayList.h"
#include "Pedido.h"
#include "Localidad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Localidad* Localidad_new()
{
    Localidad* this;
    this=malloc(sizeof(Localidad));
    return this;
}

void Localidad_delete(Localidad* this)
{
    free(this);
}

Localidad* Localidad_newConParametros(int id,char* nombre)
{
    Localidad* this;
    this=Localidad_new();

    if(
    !Localidad_setId(this,id)&&
    !Localidad_setNombre(this,nombre))
        return this;

    Localidad_delete(this);
    return NULL;
}

int Localidad_setId(Localidad* this,int id)
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

int Localidad_getId(Localidad* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Localidad_setNombre(Localidad* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Localidad_getNombre(Localidad* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Localidad_crearArrayList(ArrayList* listaPedido,ArrayList* listaLocalidades)
{
    int i,retorno = -1;
    char auxNombreLocalidad[4096];
    Pedido* auxPedido;
    Localidad* auxLocalidad;

    if(listaLocalidades!=NULL && listaPedido!=NULL)
    {
        retorno = 0;
        for(i=0;i<al_len(listaPedido);i++)
        {
            auxPedido = al_get(listaPedido,i);
            Pedido_getLocalidad(auxPedido,auxNombreLocalidad);
            auxLocalidad = Localidad_newConParametros(i,auxNombreLocalidad);
            if(!al_len(listaLocalidades))
            {
                al_add(listaLocalidades,auxLocalidad);
            }
            else
            {
                if(Localidad_buscarLocalidad(listaLocalidades,auxNombreLocalidad))
                {
                    al_add(listaLocalidades,auxLocalidad);
                }
            }
        }
    }
    return retorno;
}

int Localidad_buscarLocalidad(ArrayList* listaLocalidades,char* nombreLocalidad)
{
    int i,retorno = -1;
    Localidad* auxLocalidad;
    char auxNombre[4096];

    if(listaLocalidades!=NULL && nombreLocalidad!=NULL)
    {
        if(al_len(listaLocalidades)>0)
        {
            for(i=0;i<al_len(listaLocalidades);i++)
            {
                auxLocalidad = al_get(listaLocalidades,i);
                Localidad_getNombre(auxLocalidad,auxNombre);
                if(!strcmp(auxNombre,nombreLocalidad))
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

void Localidad_mostrarArrayList(ArrayList* listaLocalidades)
{
    int i;
    char nombre[4096];
    Localidad* auxLocalidad;

    for(i=0;i<al_len(listaLocalidades);i++)
    {
        auxLocalidad = al_get(listaLocalidades,i);
        if(auxLocalidad!=NULL)
        {
            Localidad_getNombre(auxLocalidad,nombre);
            printf("%d %s\n",i,nombre);
        }
    }
}

