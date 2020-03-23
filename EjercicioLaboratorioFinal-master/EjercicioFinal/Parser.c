#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Parser.h"
#include "Pedido.h"

int parserPedidos(char* path,ArrayList* listaPedidos)
{
    int id;
    int retorno = -1;
    char auxiliarId[4096],producto[4096],direccion[4096],localidad[4096],recibe[4096];

    FILE* pFile;
    pFile = fopen(path,"r");
    Pedido* auxiliarPedido;

    if(pFile!=NULL)
    {
        retorno = 0;
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxiliarId,producto,direccion,localidad,recibe);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxiliarId,producto,direccion,localidad,recibe);
            id = atoi(auxiliarId);
            auxiliarPedido = Pedido_newConParametros(id,producto,direccion,localidad,recibe);
            if(auxiliarPedido!=NULL)
            {
                al_add(listaPedidos,auxiliarPedido);
            }
        }
    }
    fclose(pFile);
    return retorno;
}
