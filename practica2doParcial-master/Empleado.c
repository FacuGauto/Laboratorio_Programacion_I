#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    return this;
}
/*
Employee* employee_newParametros(char* strId,char* nombre, char* horasTrabajadas, char* sueldo)
{
    int id;
    Employee* this;

    id = atoi(strId); //FALTA VALIDAR
    if(!strcmp(strIsEmpty,"true")) //FALTA VALIDAR
        isEmpty = 1;
    this = employee_new();
    if( !employee_setId(this,id) &&
        !employee_setName(this,name) &&
        !employee_setLastName(this,lastName) &&
        !employee_setIsEmpty(this,isEmpty)
       )
    {
        return this;
    }
    employee_delete(this);
    return NULL;
}
*/

void Empleado_delete(Empleado* this)
{
    free(this);
}

int Empleado_setId(Empleado* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
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

int Empleado_setSueldo(Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}
/*
Los valores de horas varkian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350
*/
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
