#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "persona.h"

int parserEmployee(char* fileName, ArrayList* pArrayList);

int main()
{
    //char pathDestinatarios[]="destinatarios.csv";
    //printf("Ingrese el nombre del archivo con los destinatarios:");

    ArrayList* pArrayList = al_newArrayList();
    parserEmployee("destinatarios.csv",pArrayList);

    ArrayList* pBlackList = al_newArrayList();
    parserEmployee("black_list.csv",pBlackList);






    return 0;
}

int parserEmployee(char* fileName, ArrayList* pArrayList)
{
    char name[128];
    char email[128];
    FILE* fp = fopen(fileName, "r");
    if(fp!=NULL)
    {
        printf("Abrir el archivo!\n");
        do{
            int parts = fscanf(fp,"%[^,],%[^\n]",name,email);
            if(parts==2)
            {
                EPersona* aux = persona_new();
                persona_setNombre(aux,name);
                persona_setEmail(aux,email);
                al_add(pArrayList,aux);
                printf("%s %s\n",name,email);
            }
        }while(!feof(fp));
        return 1;
    }
    return 0;
}

int ordenarArrayList(ArrayList* pArrayList)
{
    int returnAux = -1;
    int i;

    for(i=0;i<(al_len(this));i++)
    {

    }

    return returnAux;
}



