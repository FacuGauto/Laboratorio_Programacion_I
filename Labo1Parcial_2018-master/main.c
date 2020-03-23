#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"
#include "informar.h"
#define LEN_CLIENTES 100
#define LEN_PUBLICACIONES 1000

int main()
{
    Cliente clientes[LEN_CLIENTES];
    Publicacion publicaciones[LEN_PUBLICACIONES];
    int menu, auxiliarId, respuesta;

    cliente_init(clientes,LEN_CLIENTES);
    publicacion_init(publicaciones,LEN_PUBLICACIONES);

    cliente_altaForzada(clientes,LEN_CLIENTES,"Facundo","Gauto","20254569875");
    cliente_altaForzada(clientes,LEN_CLIENTES,"Juan","Dominguez","20354598765");
    cliente_altaForzada(clientes,LEN_CLIENTES,"Martin","Vazquez","20298744535");
    cliente_altaForzada(clientes,LEN_CLIENTES,"Pablo","Vera","20401547895");
    cliente_altaForzada(clientes,LEN_CLIENTES,"Damian","Cascino","20378965425");
    cliente_altaForzada(clientes,LEN_CLIENTES,"Bruno","Lopez","20396874585");
    cliente_altaForzada(clientes,LEN_CLIENTES,"Melina","Miranda","27304569825");

    publicacion_altaForzada(publicaciones,LEN_PUBLICACIONES,2,3,"Ford Ranger 0km");
    publicacion_altaForzada(publicaciones,LEN_PUBLICACIONES,2,3,"Chevrolet s10 0km");
    publicacion_altaForzada(publicaciones,LEN_PUBLICACIONES,4,4,"Banfield monoambiente");
    publicacion_altaForzada(publicaciones,LEN_PUBLICACIONES,1,7,"Banfield 4 ambientes");
    publicacion_altaForzada(publicaciones,LEN_PUBLICACIONES,1,7,"Adrogue 2 ambientes");
    publicacion_altaForzada(publicaciones,LEN_PUBLICACIONES,1,7,"Heladera usada");
    publicacion_altaForzada(publicaciones,LEN_PUBLICACIONES,3,5,"Licitacion Belgrano Cargas");
    publicacion_altaForzada(publicaciones,LEN_PUBLICACIONES,2,7,"Flete mudanza");


    do
    {
        getValidInt("\n1.Alta cliente\n2.Modificar datos de cliente\n3.Baja cliente\n4.Publicar\n5.Pausar publicaciones\n6.Reanudar publicacion\n7.Imprimir clientes\n8.Imprimir publicaciones activas\n9.Cliente/s con mas publicaciones activas\n10.Cliente/s con mas publicaciones pausadas\n11.Cliente/s con mas publicaciones\n12.Cantidad de publicaciones de un rubro\n13.Rubro/s con mas publicaciones activas\n14.Rubro/s con menos publicaciones activas\n30.Salir\n","\nNo valida\n",&menu,1,30,1);
        switch(menu)
        {
            case 1:
                cliente_alta(clientes,LEN_CLIENTES);
                break;
            case 2:
                getValidInt("ID? ","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_modificacion(clientes,LEN_CLIENTES,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                publicaciones_listar_por_idCliente(publicaciones,LEN_PUBLICACIONES,auxiliarId);
                if(!getValidInt("\nIngrese el numero de la opcion que desea realizar?\n\n1.Eliminar.\n2.No eliminar.\n","No es una opcion correcta\n",&respuesta,0,2,1))
                {
                    if(respuesta == 1)
                    {
                        cliente_baja(clientes,LEN_CLIENTES,auxiliarId);
                        publicacion_baja_por_idCliente(publicaciones,LEN_PUBLICACIONES,auxiliarId);
                    }
                }
                break;
            case 4:
                publicacion_alta(publicaciones,LEN_PUBLICACIONES,clientes,LEN_CLIENTES);
                break;
            case 5:
                publicacion_pausar(publicaciones,LEN_PUBLICACIONES,clientes,LEN_CLIENTES);
                break;
            case 6:
                publicacion_reanudar(publicaciones,LEN_PUBLICACIONES,clientes,LEN_CLIENTES);
                break;
            case 7:
                cliente_mostrar_con_publicaciones_activas(clientes,LEN_CLIENTES,publicaciones,LEN_PUBLICACIONES);
                break;
            case 8:
                imprimir_publicaciones(publicaciones,LEN_PUBLICACIONES,clientes,LEN_CLIENTES);
                break;
            case 9:
                clientes_con_mas_publicaciones_activas(clientes,LEN_CLIENTES,publicaciones,LEN_PUBLICACIONES);
                break;
            case 10:
                clientes_con_mas_publicaciones_pausadas(clientes,LEN_CLIENTES,publicaciones,LEN_PUBLICACIONES);
                break;
            case 11:
                clientes_con_mas_publicaciones(clientes,LEN_CLIENTES,publicaciones,LEN_PUBLICACIONES);
                break;
            case 12:
                cantidad_publicaciones_por_rubro(publicaciones,LEN_PUBLICACIONES);
                break;
            case 13:
                publicacion_ordenar_por_numeroDeRubro(publicaciones,LEN_PUBLICACIONES);
                rubro_mas_publicaciones(publicaciones,LEN_PUBLICACIONES);
                break;
            case 14:
                rubro_menos_publicaciones(publicaciones,LEN_PUBLICACIONES);
                break;
            case 20:
                cliente_mostrar(clientes,LEN_CLIENTES);
                break;
            case 21:
                cliente_ordenar(clientes,LEN_CLIENTES,0);
                break;
            case 22:
                publicacion_mostrar(publicaciones,LEN_PUBLICACIONES);
                break;
        }

    }while(menu != 30);

    return 0;
}
