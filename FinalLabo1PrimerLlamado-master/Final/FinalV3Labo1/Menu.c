#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "utn.h"
#include "Menu.h"
#include "parser.h"
#include "Mercaderia.h"
#include "localidad.h"

void Menu_menu(ArrayList* listaMercaderia,ArrayList* listaLocalidades,ArrayList* listaLocalidadesUnicas)
{
    char seguir='s';
    int opcion=0;
    //int auxiliar;


    while(seguir=='s')
    {
        printf("\n");
        printf("1- Cargar archivo\n");
        printf("2- Imprimir entregas\n");
        printf("3- Imprimir localidades\n");
        printf("4- \n");
        printf("5- \n");
        printf("10- Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
            case 1:
                parser_parserMercaderia("DATA_FINAL_V3.csv",listaMercaderia);
                break;
            case 2:
                mostrarArrayListMercaderia(listaMercaderia);
                break;
            case 3:
                listaLocalidades = crearArrayLocalidades(listaMercaderia);
                //mostrarArrayListLocalidades(listaLocalidades);
                listaLocalidadesUnicas = creaListaLocalidadesUnicas(listaLocalidades);
                mostrarArrayListLocalidades(listaLocalidadesUnicas);
                break;
            case 4:
                /*if(!al_sort(listaLocalidades,Localidad_ordenarNombre,1))
                {
                    printf("Orden exitoso");
                }*/
                break;
            case 5:
                break;
            case 10:
                seguir = 'n';
                break;
        }
    }
}
