#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EPersona* persona_new()
{
    EPersona* this;
    this=malloc(sizeof(EPersona));
    return this;
}

void persona_delete(EPersona* this)
{
    free(this);
}

int persona_setNombre(EPersona* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int persona_getNombre(EPersona* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int persona_setEmail(EPersona* this,char* email)
{
    int retorno=-1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(this->email,email);
        retorno=0;
    }
    return retorno;
}

int persona_getEmail(EPersona* this,char* email)
{
    int retorno=-1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(email,this->email);
        retorno=0;
    }
    return retorno;
}

