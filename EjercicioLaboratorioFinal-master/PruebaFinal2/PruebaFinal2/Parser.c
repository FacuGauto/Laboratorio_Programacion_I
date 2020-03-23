#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Parser.h"
#include "Pedido.h"

int Parser_parserPedidos(ArrayList* listaPedidos,char* pathArchivo)
{
    int id,retorno = -1;
    char auxId[4096],producto[4096],direccion[4096],localidad[4096],recibe[4096];
    FILE* pFile = fopen(pathArchivo,"r");
    Pedido* auxPedido;

    if(pFile != NULL)
    {
        retorno = 0;
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,producto,direccion,localidad,recibe);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,producto,direccion,localidad,recibe);
            id = atoi(auxId);
            auxPedido = Pedido_newConParametros(id,producto,direccion,localidad,recibe);
            if (auxPedido!=NULL)
            {
                al_add(listaPedidos,auxPedido);
            }
        }
    }
    fclose(pFile);
    return retorno;
}
