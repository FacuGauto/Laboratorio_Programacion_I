#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "utn.h"

Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    return this;
}

void Empleado_delete(Empleado* this)
{
    free(this);
}

Empleado* Empleado_newConParametros(int id,char* nombre,int horasTrabajadas)
{
    Empleado* this;
    this=Empleado_new();

    if(
    !Empleado_setId(this,id)&&
    !Empleado_setNombre(this,nombre)&&
    !Empleado_setHorasTrabajadas(this,horasTrabajadas))
        return this;

    Empleado_delete(this);
    return NULL;
}

int Empleado_setId(Empleado* this,int id)
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

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int em_trabajaMasDe120Horas(void* item)
{
    int horasTrabajadas;
    int retorno = -1;

    if(item!=NULL)
    {
        Empleado_getHorasTrabajadas(item,&horasTrabajadas);

        if(horasTrabajadas>120)
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

void mostrarArrayListEmpleado(ArrayList* this)
{
    int i,id, horasTrabajadas;
    char nombre[128];
    Empleado* auxiliarEmpleado;

    for(i=0;i<al_len(this);i++)
    {
        auxiliarEmpleado = al_get(this,i);
        Empleado_getId(auxiliarEmpleado,&id);
        Empleado_getNombre(auxiliarEmpleado,nombre);
        Empleado_getHorasTrabajadas(auxiliarEmpleado,&horasTrabajadas);
        printf("%d,%s,%d\n\n",id,nombre,horasTrabajadas);
    }
}


/*
void em_calcularSueldo(void* p)
{
    int horasTrabajadas,horasTotal;

    Empleado_getHorasTrabajadas(p,&horasTrabajadas);

    if(horasTrabajadas>120)
    {
        horasTotal = 120 * 180;
        if(horasTrabajadas>160)
        {
            horasTotal = horasTotal + 40*240 +(horasTrabajadas-160)*350;

        }
        else
        {
            horasTotal = horasTotal + (horasTrabajadas-120)*240;
        }
    }
    else
    {
        horasTotal = horasTrabajadas * 180;
    }
    Empleado_setSueldo(p,horasTotal);
}

*/
