#include "ArrayList.h"
#include "Localidad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pedido.h"

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

int Localidad_crearListaLocalidades(ArrayList* listaPedidos, ArrayList* listalocalidades)
{
    int i,retorno = -1;
    Pedido* auxPedido;
    Localidad* auxLocalidad;
    char localidad[500];

    for(i=0;i<al_len(listaPedidos);i++)
    {
        auxPedido = al_get(listaPedidos,i);
        Pedido_getLocalidad(auxPedido,localidad);
        if(i==0)
        {
            retorno = 0;
            auxLocalidad = Localidad_newConParametros(i,localidad);
            al_add(listalocalidades,auxLocalidad);
        }
        else
        {
            if(Localidad_buscaLocalidad(listalocalidades,localidad))
            {
                auxLocalidad = Localidad_newConParametros(i,localidad);
                al_add(listalocalidades,auxLocalidad);
            }
        }
    }
    return retorno;
}

int Localidad_buscaLocalidad(ArrayList* listaLocalidades,char* localidad)
{
    int j,retorno = -1;
    Localidad* auxLocalidad;
    char nombre[200];

    for(j=0;j<al_len(listaLocalidades);j++)
    {
        auxLocalidad = al_get(listaLocalidades,j);
        Localidad_getNombre(auxLocalidad,nombre);
        if(!strcmp(nombre,localidad))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}


void Localidad_mostrarArrayList(ArrayList* listaLocalidades)
{
    int i;
    Localidad* auxLocalidad;
    char nombre[200];

    for(i=0;i<al_len(listaLocalidades);i++)
    {
        auxLocalidad = al_get(listaLocalidades,i);
        Localidad_getNombre(auxLocalidad,nombre);
        printf("%d %s\n",i,nombre);
    }
}
