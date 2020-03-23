#ifndef DEPOSITO_H_INCLUDED
#define DEPOSITO_H_INCLUDED
#include "ArrayList.h"

typedef struct
{
    int id;
    char descripcion[128];
    int cantidad;
}Deposito;


Deposito* Deposito_new();
void Deposito_delete();
Deposito* Deposito_newConParametros(int id,char* descripcion,int cantidad);

int Deposito_setId(Deposito* this,int id);
int Deposito_getId(Deposito* this,int* id);

int Deposito_setDescripcion(Deposito* this,char* descripcion);
int Deposito_getDescripcion(Deposito* this,char* descripcion);

int Deposito_setCantidad(Deposito* this,int cantidad);
int Deposito_getCantidad(Deposito* this,int* cantidad);

void mostrarArrayListDeposito(ArrayList* this);
int Deposito_moverProducto(ArrayList* listaDeposito1,ArrayList* listaDeposito2);
int Deposito_descontarCantidad(ArrayList* listaDeposito1,ArrayList* listaDeposito2);
int Deposito_agregarCantidad(ArrayList* listaDeposito1,ArrayList* listaDeposito2);
int Deposito_ordenarId(void* id1,void*id2);

#endif // DEPOSITO_H_INCLUDED
