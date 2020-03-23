#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "utn.h"
#include "View.h"
#include "Parser.h"
#include "Deposito.h"

void View_menu(ArrayList* listaDeposito1,ArrayList* listaDeposito2)
{
    char seguir='s';
    int opcion=0;
    int auxiliar;

    while(seguir=='s')
    {
        printf("\n");
        printf("1- Cargar depositos\n");
        printf("2- Listar productos\n");
        printf("3- Mover productos\n");
        printf("4- Descontar productos\n");
        printf("5- Agregar productos\n");
        printf("6- Crear nuevo archivo\n");
        printf("7- Ordenar lista\n");
        printf("10- Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
            case 1:
                parser_parserDeposito("dep0.csv",listaDeposito1);
                parser_parserDeposito("dep1.csv",listaDeposito2);
                break;
            case 2:
                getValidInt("Numero de deposito(1 o 2)","\nNumero invalido\n",&auxiliar,1,2,1);
                if(auxiliar == 1)
                {
                    mostrarArrayListDeposito(listaDeposito1);
                }
                if(auxiliar == 2)
                {
                    mostrarArrayListDeposito(listaDeposito2);
                }
                break;
            case 3:
                if(Deposito_moverProducto(listaDeposito1,listaDeposito2))
                {
                    printf("Error al mover el producto\n");
                }
                break;
            case 4:
                if(Deposito_descontarCantidad(listaDeposito1,listaDeposito2))
                {
                    printf("Error al descontar la cantidad");
                }
                break;
            case 5:
                if(Deposito_agregarCantidad(listaDeposito1,listaDeposito2))
                {
                    printf("Error al agregar la cantidad");
                }
                break;
            case 6:
                if(!parser_generarArchivoDeposito("nuevo.csv",listaDeposito1))
                {
                    printf("Archivo generado con exito");
                }
                else
                {
                    printf("Error al generar el archivo");
                }
                break;
            case 7:
                if(!al_sort(listaDeposito2,Deposito_ordenarId,1))
                {
                    printf("Orden exitoso");
                }
                break;
            case 10:
                seguir = 'n';
                break;
        }
    }
}
