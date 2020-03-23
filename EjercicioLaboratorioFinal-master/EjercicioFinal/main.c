#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Parser.h"
#include "Pedido.h"
#include "Localidad.h"

int main()
{
    char pathArchivo[4096] = "DATA_FINAL_V3.csv";
    ArrayList* listaPedidos = al_newArrayList();
    ArrayList* listaLocalidades = al_newArrayList();

    if(!parserPedidos(pathArchivo,listaPedidos))
    {
       Pedido_mostrarArrayList(listaPedidos);
    }

    if(!Localidad_crearListaLocalidades(listaPedidos,listaLocalidades))
    {
        Localidad_mostrarArrayList(listaLocalidades);
    }

    return 0;
}
