#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "Publicacion.h"
#include "utn.h"


#define LEN_CLIENTES 10
#define LEN_PUBLICACIONES 100

int main()
{
    Cliente clientes[LEN_CLIENTES];
    Publicacion publicaciones[LEN_PUBLICACIONES];
    int menu;
    int auxiliarId;

    cliente_init(clientes,LEN_CLIENTES);
    publicacion_init(publicaciones,LEN_PUBLICACIONES);

    cliente_altaForzada(clientes,LEN_CLIENTES,"Facundo","Gauto",10);
    cliente_altaForzada(clientes,LEN_CLIENTES,"Federico","Gomez",11);
    cliente_altaForzada(clientes,LEN_CLIENTES,"Alicia","Vazquez",12);
    cliente_altaForzada(clientes,LEN_CLIENTES,"Juan","Lopez",13);
    cliente_altaForzada(clientes,LEN_CLIENTES,"Melina","Alvares",14);


    publicacion_altaForzada(publicaciones,LEN_PUBLICACIONES,1,clientes,LEN_CLIENTES,"sfsfsf",2);
    publicacion_altaForzada(publicaciones,LEN_PUBLICACIONES,1,clientes,LEN_CLIENTES,"arbol de",2);
    publicacion_altaForzada(publicaciones,LEN_PUBLICACIONES,1,clientes,LEN_CLIENTES,"arbdsdsol de",2);

    do
    {
        getValidInt("\n1.Alta de cliente\n2.Modificar datos del cliente\n3.Baja del cliente\n4.Publicar\n5.Modificar producto\n6.Cancelar publicacion\n7.Comprar producto\n8.Listar publicaciones de cliente\n9.Listar publicaciones\n10.Listar clientes\n15.Salir\n\n","\nNo valida\n",&menu,1,15,1);
        switch(menu)
        {
            case 1:
                cliente_alta(clientes,LEN_CLIENTES);
                break;
            case 2:
                getValidInt("ID del cliente?","\nNumero invalido\n",&auxiliarId,0,200,2);
                cliente_modificacion(clientes,LEN_CLIENTES,auxiliarId);
                break;
            case 3:
                getValidInt("ID del cliente?","\nNumero invalido\n",&auxiliarId,0,200,2);
                cliente_baja(clientes,LEN_CLIENTES,auxiliarId);
                break;
            case 4:
                getValidInt("ID del cliente?","\nNumero invalido\n",&auxiliarId,0,200,2);
                publicacion_alta(publicaciones,LEN_PUBLICACIONES,auxiliarId,clientes,LEN_CLIENTES);
                break;
            case 5:
                if(getValidInt("ID de la publicacion?","\nNumero invalido\n",&auxiliarId,0,200,2)==0)
                {
                   cliente_por_publicacion(publicaciones,LEN_PUBLICACIONES,auxiliarId,clientes,LEN_CLIENTES);
                }
                break;
            case 9:
                cliente_mostrar(clientes,LEN_CLIENTES);
                break;
            case 10:
                publicacion_mostrar(publicaciones,LEN_PUBLICACIONES,clientes,LEN_CLIENTES);

        }

    }while(menu != 15);

    return 0;
}
