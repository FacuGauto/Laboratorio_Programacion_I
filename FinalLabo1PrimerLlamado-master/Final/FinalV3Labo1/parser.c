#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#include "utn.h"
#include "Mercaderia.h"



int parser_parserMercaderia(char* filename,ArrayList* listaMercaderia)
{
    int retorno = -1;
    char auxId[4096];
    char producto[4096];
    char direccion[4096];
    char localidad[4096];
    char recibe[4096];
    int id;

    FILE* pFile;
    pFile = fopen(filename,"r");
    Mercaderia* auxiliarMercaderia;

    if(pFile!=NULL)
    {

        retorno = 0;
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,producto,direccion,localidad,recibe);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,producto,direccion,localidad,recibe);
            id = atoi(auxId);
            auxiliarMercaderia = Mercaderia_newConParametros(id,producto,direccion,localidad,recibe);
            if (auxiliarMercaderia != NULL)
            {
                al_add(listaMercaderia,auxiliarMercaderia);
                //printf("%d %s %s %s %s\n",id,producto,direccion,localidad,recibe);
            }
        }
        fclose(pFile);
    }

    return retorno;
}
