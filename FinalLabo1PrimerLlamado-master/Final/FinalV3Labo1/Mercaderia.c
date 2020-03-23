#include "Mercaderia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "localidad.h"

Mercaderia* Mercaderia_new()
{
    Mercaderia* this;
    this=malloc(sizeof(Mercaderia));
    return this;
}

void Mercaderia_delete(Mercaderia* this)
{
    free(this);
}

Mercaderia* Mercaderia_newConParametros(int id,char* producto,char* direccion,char* localidad,char* recibe)
{
    Mercaderia* this;
    this=Mercaderia_new();

    if(
    !Mercaderia_setId(this,id)&&
    !Mercaderia_setProducto(this,producto)&&
    !Mercaderia_setDireccion(this,direccion)&&
    !Mercaderia_setLocalidad(this,localidad)&&
    !Mercaderia_setRecibe(this,recibe))
        return this;

    Mercaderia_delete(this);
    return NULL;
}

int Mercaderia_setId(Mercaderia* this,int id)
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

int Mercaderia_getId(Mercaderia* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Mercaderia_setProducto(Mercaderia* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(this->producto,producto);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_getProducto(Mercaderia* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(producto,this->producto);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_setDireccion(Mercaderia* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(this->direccion,direccion);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_getDireccion(Mercaderia* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(direccion,this->direccion);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_setLocalidad(Mercaderia* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(this->localidad,localidad);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_getLocalidad(Mercaderia* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(localidad,this->localidad);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_setRecibe(Mercaderia* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(this->recibe,recibe);
        retorno=0;
    }
    return retorno;
}

int Mercaderia_getRecibe(Mercaderia* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(recibe,this->recibe);
        retorno=0;
    }
    return retorno;
}


void mostrarArrayListMercaderia(ArrayList* this)
{
    int i,id;
    char producto[4096];
    char direccion[4096];
    char localidad[4096];
    char recibe[4096];
    Mercaderia* auxiliarmercaderia = Mercaderia_new();
    for(i=0;i<al_len(this);i++)
    {
        auxiliarmercaderia = al_get(this,i);
        Mercaderia_getId(auxiliarmercaderia,&id);
        Mercaderia_getProducto(auxiliarmercaderia,producto);
        Mercaderia_getDireccion(auxiliarmercaderia,direccion);
        Mercaderia_getLocalidad(auxiliarmercaderia,localidad);
        Mercaderia_getRecibe(auxiliarmercaderia,recibe);
        printf("%d %s %s %s %s\n",id,producto,direccion,localidad,recibe);
    }
}

ArrayList* crearArrayLocalidades(ArrayList* listaMercaderia)
{
    int i;
    char localidad[4096];
    ArrayList* listaLocalidades = al_newArrayList();
    Mercaderia* auxiliarmercaderia = Mercaderia_new();
    Localidad* auxiliarLocalidad;
    for(i=0;i<al_len(listaMercaderia);i++)
    {
        auxiliarmercaderia = al_get(listaMercaderia,i);
        Mercaderia_getLocalidad(auxiliarmercaderia,localidad);
        auxiliarLocalidad = Localidad_newConParametros(i,localidad);
        if(auxiliarLocalidad!=NULL)
        {
            al_add(listaLocalidades,auxiliarLocalidad);
        }
    }
    return listaLocalidades;
}

void mostrarArrayListLocalidades(ArrayList* listaLocalidades)
{
    int i,id;
    char nombre[4096];
    Localidad* auxiliarlocalidad = Localidad_new();
    for(i=0;i<al_len(listaLocalidades);i++)
    {
        auxiliarlocalidad = al_get(listaLocalidades,i);
        Localidad_getId(auxiliarlocalidad,&id);
        Localidad_getNombre(auxiliarlocalidad,nombre);
        printf("%d %s\n",i,nombre);
    }
}

int Localidad_ordenarNombre(void* loc1,void* loc2)
{
    int retorno = 0;
    char nombre1[128];
    char nombre2[128];
    Localidad* localidad1 = loc1;
    Localidad* localidad2 = loc2;

    Localidad_getNombre(localidad1,nombre1);
    Localidad_getNombre(localidad2,nombre2);


    if(strcmp(nombre1,nombre2)>0)
    {
        retorno = 1;
    }
    else if (strcmp(nombre1,nombre2)<0)
    {
        retorno =-1;
    }
    return retorno;
}

ArrayList* creaListaLocalidadesUnicas(ArrayList* listaLocalidades)
{
    int i;
    char nombre[128];
    ArrayList* listaLocalidadesUnicas = al_newArrayList();
    Localidad* auxiliarLocalidad = Localidad_new();

    if(listaLocalidades!=NULL)
    {
        for(i=0;i<al_len(listaLocalidades);i++)
        {
            auxiliarLocalidad = al_get(listaLocalidades,i);
            Localidad_getNombre(auxiliarLocalidad,nombre);
            if(i==0)
            {
                al_add(listaLocalidadesUnicas,auxiliarLocalidad);
            }
            else
            {
                if(buscarLocalidad(listaLocalidadesUnicas,nombre))
                {
                    al_add(listaLocalidadesUnicas,auxiliarLocalidad);
                }
            }
        }
    }
    return listaLocalidadesUnicas;
}

int buscarLocalidad(ArrayList* listaLocalidades, char* localidad)
{
    int retorno= -1;
    Localidad* auxiliarlocalidad = Localidad_new();
    int i;
    char nombre[4096];
    if(listaLocalidades!=NULL)
    {
        for(i=0;i<al_len(listaLocalidades);i++)
        {
            auxiliarlocalidad = al_get(listaLocalidades,i);
            Localidad_getNombre(auxiliarlocalidad,nombre);
            if(strcmp(nombre,localidad)==0)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
