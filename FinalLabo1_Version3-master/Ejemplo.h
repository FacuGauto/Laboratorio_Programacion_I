#ifndef DEPOSITO_H_INCLUDED
#define DEPOSITO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[128];
    int cantidad;
}Deposito;