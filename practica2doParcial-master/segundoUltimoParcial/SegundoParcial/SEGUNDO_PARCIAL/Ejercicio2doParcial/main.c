#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera filtrar los empleados leidos, segun la horas que trabajaron, y generar una lista nueva en donde solo se encuentren
    los que trabajaron mas de 120 horas.

    Para hacer esta operacion, se debera desarrollar la funcion "filter" en la biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion filter ejecutara la funcion recibida como parametro por cada item de la lista, y le pasara en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra analizar el item recibido y devolver un "1" en el caso de que el item deba permanacer
    en la lista generada y un "0" si se debe sacar de la lista. La funcion filter debera devolver un nuevo arraylist con los items que la funcion
    pasada como argumento determino que se incluyan.

    Una vez generada la nueva lista filtrada, se debera generar un archivo de salida "jornada_completa.csv" con las mismas columnas que el original.
*/

int generarArchivoFiltrado(char* fileName,ArrayList* listaEmpleados);

int main()
{
    // Definir lista de empleados
    ArrayList* listaEmpleados = NULL;
    ArrayList* listaNueva = NULL;
    // Crear lista empledos
    //...
    listaEmpleados = al_newArrayList();
    listaNueva = al_newArrayList();
    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados("data.csv",listaEmpleados)==1)
    {
        mostrarArrayListEmpleado(listaEmpleados);
        // Filtrar empleados
        printf("Filtrando empleados\n");
        listaNueva = al_filter(listaEmpleados,em_trabajaMasDe120Horas);

        if(listaNueva!=NULL)
        {
            mostrarArrayListEmpleado(listaNueva);
        }
        else
        {
            printf("Error al generar la lista con empleados que trabajaron mas de 120 horas");
        }
        // Generar archivo de salida
        if(generarArchivoFiltrado("jornada_completa.csv",listaNueva)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo empleados\n");


    return 0;
}

int generarArchivoFiltrado(char* fileName,ArrayList* listaEmpleados)
{
    int retorno = -1;
    int i,id,horastrabajadas;
    char nombre[64];
    Empleado* auxiliarEmpleado;

    if(listaEmpleados!=NULL && fileName!=NULL)
    {
        FILE* pFile;
        pFile = fopen(fileName,"w");
        if(pFile != NULL)
        {
            retorno = 1;
            fprintf(pFile,"id,nombre,horas_trabajadas\n");
            for(i=0;i<al_len(listaEmpleados);i++)
            {
                auxiliarEmpleado = al_get(listaEmpleados,i);
                Empleado_getId(auxiliarEmpleado,&id);
                Empleado_getNombre(auxiliarEmpleado,nombre);
                Empleado_getHorasTrabajadas(auxiliarEmpleado,&horastrabajadas);
                fprintf(pFile,"%d,%s,%d\n",id,nombre,horastrabajadas);
            }
        }
        fclose(pFile);
    }
    return retorno;
}



















/*for(i=0;i<al_len(listaNueva);i++)
            {
                auxiliarEmpleado = al_get(listaNueva,i);
                Empleado_getId(auxiliarEmpleado,&id);
                Empleado_getNombre(auxiliarEmpleado,nombre);
                Empleado_getHorasTrabajadas(auxiliarEmpleado,&horasTrabajadas);
                printf("%d,%s,%d\n\n",id,nombre,horasTrabajadas);
            }*/


/* for(i=0;i<al_len(listaEmpleados);i++)
        {
            auxiliarEmpleado = al_get(listaEmpleados,i);
            Empleado_getId(auxiliarEmpleado,&id);
            Empleado_getNombre(auxiliarEmpleado,nombre);
            Empleado_getHorasTrabajadas(auxiliarEmpleado,&horasTrabajadas);
            //Empleado_getSueldo(auxiliarEmpleado,&sueldo);
            printf("%d,%s,%d\n\n",id,nombre,horasTrabajadas);
        }*/
