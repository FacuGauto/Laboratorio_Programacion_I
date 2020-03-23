#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "movie.h"
#include "utn.h"

Movie* movie_new()
{
    return (Movie*) malloc(sizeof(Movie));
}

void movie_delete(Movie* this)
{
    free(this);
}

Movie* movie_newParametros(char* titulo, char* genero, int* duracion, char* descripcion, int* puntaje, char* linkImagen, int id)
{
    Movie* auxMovie = movie_new();
    if(     !movie_setTitulo(auxMovie,titulo)
       &&   !movie_setGenero(auxMovie,genero)
       &&   !movie_setDuracion(auxMovie,duracion)
       &&   !movie_setDescripcion(auxMovie,descripcion)
       &&   !movie_setPuntaje(auxMovie,puntaje)
       &&   !movie_setLinkImagen(auxMovie,linkImagen)
       &&   !movie_setId(auxMovie,id))
    {
        return auxMovie;
    }
    movie_delete(auxMovie);
    return NULL;
}

int movie_setTitulo(Movie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        retorno = 0;
        strcpy(this->titulo, titulo);
    }
    return retorno;
}
int movie_getTitulo(Movie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        retorno = 0;
        strcpy(titulo, this->titulo);
    }
    return retorno;
}

int movie_setGenero(Movie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        retorno = 0;
        strcpy(this->genero, genero);
    }
    return retorno;
}
int movie_getGenero(Movie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        retorno = 0;
        strcpy(genero, this->genero);
    }
    return retorno;
}

int movie_setDuracion(Movie* this, int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        retorno = 0;
        this->duracion = *duracion;
    }
    return retorno;
}
int movie_getDuracion(Movie* this, int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        retorno = 0;
    }
    return retorno;
}

int movie_setDescripcion(Movie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        retorno = 0;
        strcpy(this->descripcion, descripcion);
    }
    return retorno;
}
int movie_getDescripcion(Movie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        retorno = 0;
        strcpy(descripcion, this->descripcion);
    }
    return retorno;
}


int movie_setPuntaje(Movie* this, int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        retorno = 0;
        this->puntaje = *puntaje;
    }
    return retorno;
}
int movie_getPuntaje(Movie* this, int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        *puntaje = this->puntaje;
        retorno = 0;
    }
    return retorno;
}

int movie_setLinkImagen(Movie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL)
    {
        retorno = 0;
        strcpy(this->linkImagen, linkImagen);
    }
    return retorno;
}
int movie_getLinkImagen(Movie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL)
    {
        retorno = 0;
        strcpy(linkImagen, this->linkImagen);
    }
    return retorno;
}

int movie_setId(Movie* this, int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        retorno = 0;
        if(id >= 0)
        {
            this->id = id;
            if(id > maximoId)
                maximoId = id;
        }
        else
        {
            maximoId++;
            this->id = maximoId;
        }
    }
    return retorno;
}

int movie_getId(Movie* this, int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}
