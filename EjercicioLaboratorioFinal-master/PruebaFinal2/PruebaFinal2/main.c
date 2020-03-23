#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Parser.h"
#include "Pedido.h"
#include "Localidad.h"

int main()
{
    printf("Hello world!\n");
    ArrayList* listaPedidos = al_newArrayList();
    ArrayList* listaLocalidades = al_newArrayList();
    char pathArchivo[250] = "DATA_FINAL_V3.csv";

    Parser_parserPedidos(listaPedidos,pathArchivo);
    Pedido_mostrarArrayList(listaPedidos);

    Localidad_crearArrayList(listaPedidos,listaLocalidades);
    Localidad_mostrarArrayList(listaLocalidades);



    return 0;
}
