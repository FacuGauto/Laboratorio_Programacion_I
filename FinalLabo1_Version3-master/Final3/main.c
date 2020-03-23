#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Parser.h"
#include "Pedido.h"
#include "Localidad.h"
#include "utn.h"
#include <ctype.h>

int main()
{
    char pathArchivo[4096] = "DATA_FINAL_V3.csv";
    char localidades[3][4096];
    int i;
    ArrayList* listaPedidos = al_newArrayList();
    ArrayList* listaLocalidades = al_newArrayList();
    ArrayList* listaPedidosPorLocalidad = al_newArrayList();

    Parser_parserPedidos(listaPedidos,pathArchivo);
    Pedido_mostrarArrayList(listaPedidos);

    Localidad_crearArrayList(listaPedidos,listaLocalidades);
    Localidad_mostarArrayList(listaLocalidades);

    for(i=0;i<3;i++)
    {
        getValidString("Ingrese localidad: ","No es una localidad","Error",localidades[i],4096,1);
        localidades[i][0] = toupper(localidades[i][0]);
    }

    for(i=0;i<3;i++)
    {
        //printf("%s\n",localidades[i]);
        Pedido_crearArrayListPorLocalidad(listaPedidos,listaPedidosPorLocalidad,localidades[i]);
    }

    Pedido_mostrarArrayList(listaPedidosPorLocalidad);





    return 0;
}
