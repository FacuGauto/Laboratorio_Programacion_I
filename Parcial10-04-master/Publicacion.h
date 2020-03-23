#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
#include "cliente.h"
typedef struct
{
    int idCliente;
    int numeroRubro;
    char texto[64];
    int estado;
    //------------
    int idPublicacion;
    int isEmpty;
}Publicacion;

int publicacion_alta(Publicacion* publicaciones, int limitePublicaciones, int id, Cliente* clientes, int limiteClientes);

int publicacion_init(Publicacion* array,int limite);
int publicacion_altaForzada(Publicacion* publicaciones, int limitePublicaciones, int id, Cliente* clientes, int limiteCliente, char* texto, int numeroRubro);
int cliente_por_publicacion(Publicacion* array,int limite, int id,Cliente* clientes, int limiteCliente);
int publicacion_mostrar(Publicacion* publicaciones,int limite,Cliente* clientes, int limiteClientes);
/*

int publicacion_modificacion(Publicacion* publicaciones,int limitePublicaciones, int id);
int publicacion_baja(Publicacion* array,int limite, int id);
int publicacion_comprar(Publicacion* publicaciones,int limitePublicaciones, int id,Usuario* usuarios,int limiteUsuarios);


*/


#endif // PANTALLA_H_INCLUDED

