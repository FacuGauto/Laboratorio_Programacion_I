#ifndef MERCADERIA_H_INCLUDED
#define MERCADERIA_H_INCLUDED
#include "ArrayList.h"
typedef struct
{
    int id;
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
}Mercaderia;

Mercaderia* Mercaderia_new();
void Mercaderia_delete();
Mercaderia* Mercaderia_newConParametros(int id,char* producto,char* direccion,char* localidad,char* recibe);

int Mercaderia_setId(Mercaderia* this,int id);
int Mercaderia_getId(Mercaderia* this,int* id);

int Mercaderia_setProducto(Mercaderia* this,char* producto);
int Mercaderia_getProducto(Mercaderia* this,char* producto);

int Mercaderia_setDireccion(Mercaderia* this,char* direccion);
int Mercaderia_getDireccion(Mercaderia* this,char* direccion);

int Mercaderia_setLocalidad(Mercaderia* this,char* localidad);
int Mercaderia_getLocalidad(Mercaderia* this,char* localidad);

int Mercaderia_setRecibe(Mercaderia* this,char* recibe);
int Mercaderia_getRecibe(Mercaderia* this,char* recibe);

void mostrarArrayListMercaderia(ArrayList* this);
int buscarLocalidad(ArrayList* listaLocalidades, char* localidad);
ArrayList* crearArrayLocalidades(ArrayList* listaMercaderia);
void mostrarArrayListLocalidades(ArrayList* listaLocalidades);
int Localidad_ordenarNombre(void* loc1,void* loc2);
ArrayList* creaListaLocalidadesUnicas(ArrayList* listaLocalidades);
#endif // MERCADERIA_H_INCLUDED
