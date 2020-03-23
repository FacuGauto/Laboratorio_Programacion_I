#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED
#include "ArrayList.h"

typedef struct
{
    int id;
    char producto[4096];
    char direccion[4096];
    char localidad[4096];
    char recibe[4096];
}Pedido;

Pedido* Pedido_new();
void Pedido_delete();
Pedido* Pedido_newConParametros(int id,char* producto,char* direccion,char* localidad,char* recibe);

int Pedido_setId(Pedido* this,int id);
int Pedido_getId(Pedido* this,int* id);

int Pedido_setProducto(Pedido* this,char* producto);
int Pedido_getProducto(Pedido* this,char* producto);

int Pedido_setDireccion(Pedido* this,char* direccion);
int Pedido_getDireccion(Pedido* this,char* direccion);

int Pedido_setLocalidad(Pedido* this,char* localidad);
int Pedido_getLocalidad(Pedido* this,char* localidad);

int Pedido_setRecibe(Pedido* this,char* recibe);
int Pedido_getRecibe(Pedido* this,char* recibe);

void Pedido_mostrarArrayList(ArrayList* listaPedido);
int Pedido_crearArrayListPorLocalidad(ArrayList*listaPedidos,ArrayList* listaPedidosPorLocalidad,char* nombrelocalidad);
#endif // PEDIDO_H_INCLUDED
