#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED

typedef struct
{
    int idCliente;
    int numeroDeRubro;
    char texto[64];
    int estado;
    //------------
    int idPublicacion;
    int isEmpty;
}Publicacion;
#endif // PUBLICACION_H_INCLUDED

#include "cliente.h"

int publicacion_init(Publicacion* array,int limite);
int publicacion_mostrar(Publicacion* array,int limite);
int publicacion_alta(Publicacion* publicaciones,int limitePublicaciones,Cliente* clientes,int limiteClientes);
int publicacion_mostrar_cliente_por_publicacion(Publicacion* publicaciones,int limitePublicaciones,Cliente* clientes,int limiteClientes);
int publicacion_pausar(Publicacion* publicaciones,int limitePublicaciones,Cliente* clientes,int limiteClientes);
int publicacion_reanudar(Publicacion* publicaciones,int limitePublicaciones,Cliente* clientes,int limiteClientes);
int publicacion_ordenar_por_idCliente(Publicacion* array,int limite);
int publicacion_ordenar_por_numeroDeRubro(Publicacion* array,int limite);
int publicaciones_listar_por_idCliente(Publicacion* publicaciones, int limitePublicaciones, int idCliente);
int publicacion_baja(Publicacion* array,int limite, int id);
int publicacion_baja_por_idCliente(Publicacion* array,int limite, int id);
int publicacion_buscarPorId(Publicacion* array,int limite, int id);
int publicacion_modificacion(Publicacion* publicaciones,int limite, int id,Cliente* clientes,int limiteClientes);
int publicacion_altaForzada(Publicacion* array,int limite,int idCliente,int numeroDeRubro,char* texto);
