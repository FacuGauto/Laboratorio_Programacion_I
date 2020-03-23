#include "localidad.h"
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

