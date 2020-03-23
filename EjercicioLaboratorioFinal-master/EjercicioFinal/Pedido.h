#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED
#include "ArrayList.h"

typedef struct
{
    int id;
    char producto[200];
    char direccion[200];
    char localidad[200];
    char recibe[200];
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

void Pedido_mostrarArrayList(ArrayList* listaPedidos);

#endif // PEDIDO_H_INCLUDED
