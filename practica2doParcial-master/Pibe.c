
#include "Pibe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Pibe* Pibe_new()
{
    Pibe* this;
    this=malloc(sizeof(Pibe));
    return this;
}

void Pibe_delete(Pibe* this)
{
    free(this);
}

Pibe* Pibe_newConParametros(int id,char* nombre,int edad)
{
    Pibe* this;
    this=Pibe_new();

    if(
    !Pibe_setId(this,id)&&
    !Pibe_setNombre(this,nombre)&&
    !Pibe_setEdad(this,edad))
        return this;

    Pibe_delete(this);
    return NULL;
}

int Pibe_setId(Pibe* this,int id)
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

int Pibe_getId(Pibe* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Pibe_setNombre(Pibe* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Pibe_getNombre(Pibe* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Pibe_setEdad(Pibe* this,int edad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->edad=edad;
        retorno=0;
    }
    return retorno;
}

int Pibe_getEdad(Pibe* this,int* edad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *edad=this->edad;
        retorno=0;
    }
    return retorno;
}

