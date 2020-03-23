#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED

#endif // INFORMAR_H_INCLUDED


int cliente_mostrar_con_publicaciones_activas(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones);
int cliente_cant_publicaciones_activas(int idCliente,Publicacion* publicaciones,int limitePublicaciones);
int imprimir_publicaciones(Publicacion* publicaciones,int limitePublicaciones,Cliente* clientes,int limiteClientes);
int clientes_con_mas_publicaciones_activas(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones);
int cantidad_publicaciones_por_rubro(Publicacion* publicaciones, int limitePublicaciones);
int publicaciones_rubro_cant_publicaciones_activas(int numeroDeRubro,Publicacion* publicaciones,int limitePublicaciones);
int rubro_mas_publicaciones(Publicacion* publicaciones, int limitePublicaciones);
int rubro_menos_publicaciones(Publicacion* publicaciones, int limitePublicaciones);
int publicaciones_listar_por_idCliente(Publicacion* publicaciones, int limitePublicaciones, int idCliente);
int clientes_con_mas_publicaciones_pausadas(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones);
int clientes_con_mas_publicaciones(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones);
int publicaciones_minimo_activas(Publicacion* publicaciones, int limitePublicaciones);
int publicaciones_maximo_activas(Publicacion* publicaciones, int limitePublicaciones);


//int cliente_con_mas_publicaciones_activas(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones);
//int cliente_con_mas_publicaciones_pausadas(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones);
//int cliente_con_mas_publicaciones(Cliente* clientes,int limiteClientes,Publicacion* publicaciones,int limitePublicaciones);
