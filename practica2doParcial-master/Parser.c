#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Empleado.h"

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    int retorno = -1;
    char bId[4096];
    char bNombre[4096];
    char bHorasTrabajadas[4096];
    int id,horasTrabajadas;

    FILE* pFile;
    pFile = fopen(fileName,"r");
    Empleado* auxiliarEmpleado;

    if(pFile != NULL)
    {
        retorno = 1;
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bId,bNombre,bHorasTrabajadas);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bId,bNombre,bHorasTrabajadas);
            auxiliarEmpleado = Empleado_new();
            id = atoi(bId);
            horasTrabajadas = atoi(bHorasTrabajadas);
            Empleado_setId(auxiliarEmpleado,id);
            Empleado_setNombre(auxiliarEmpleado,bNombre);
            Empleado_setHorasTrabajadas(auxiliarEmpleado,horasTrabajadas);
            al_add(listaEmpleados,auxiliarEmpleado);
            printf("%d,%s,%d\n",id,bNombre,horasTrabajadas);
        }
    }
    fclose(pFile);
    return retorno; // OK
}

