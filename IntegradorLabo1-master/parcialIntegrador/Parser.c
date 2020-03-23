#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Parser.h"
#include "utn.h"
#include "Deposito.h"


int parser_parserDeposito(char* filename,ArrayList* listaDeposito)
{
    int retorno = -1;
    char auxId[4096];
    char descripcion[4096];
    char auxCantidad[4096];
    int id,cantidad;

    FILE* pFile;
    pFile = fopen(filename,"r");
    Deposito* auxiliarDeposito;

    if(pFile!=NULL)
    {
        retorno = 1;
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",auxId,descripcion,auxCantidad);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",auxId,descripcion,auxCantidad);
            id = atoi(auxId);
            if(!esNumerico(auxCantidad))
            {
                continue;
            }
            cantidad = atoi(auxCantidad);
            auxiliarDeposito = Deposito_newConParametros(id,descripcion,cantidad);
            if (auxiliarDeposito != NULL)
            {
                al_add(listaDeposito,auxiliarDeposito);
                //printf("%d %s %d\n",id,descripcion,cantidad);
            }
        }
        fclose(pFile);
    }
    return retorno;
}

int parser_generarArchivoDeposito(char* path,ArrayList* listaDeposito)
{
    int i,producto,cantidad,retorno = -1;
    char descripcion[50];
    Deposito* auxiliarDeposito;

    if(path!=NULL && listaDeposito!=NULL)
    {
        FILE* pFile;
        pFile = fopen(path,"r");
        if(pFile ==NULL)
        {
            pFile = fopen(path,"w");
            fprintf(pFile,"producto,descripcion,cantidad\n");
        }
        fclose(pFile);
        pFile = fopen(path,"a");
        if(pFile!=NULL)
        {
            retorno = 0;
            //fprintf(pFile,"producto,descripcion,cantidad\n");
            for(i=0;i<al_len(listaDeposito);i++)
            {
                auxiliarDeposito = al_get(listaDeposito,i);
                Deposito_getId(auxiliarDeposito,&producto);
                Deposito_getDescripcion(auxiliarDeposito,descripcion);
                Deposito_getCantidad(auxiliarDeposito,&cantidad);
                fprintf(pFile,"%d,%s,%d\n",producto,descripcion,cantidad);
            }
        }
        fclose(pFile);
    }
    return retorno;
}
