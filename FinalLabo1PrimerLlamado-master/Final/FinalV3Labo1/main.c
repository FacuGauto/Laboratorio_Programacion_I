#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Menu.h"

int main()
{
    printf("Hello world!\n");

    ArrayList* listaMercaderia = al_newArrayList();
    ArrayList* listaLocalidades = al_newArrayList();
    ArrayList* listaLocalidadesUnicas = al_newArrayList();

    Menu_menu(listaMercaderia,listaLocalidades,listaLocalidadesUnicas);

    return 0;
}
