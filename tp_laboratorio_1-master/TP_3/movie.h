#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int id;
}Movie;


#endif // MOVIE_H_INCLUDED
Movie* movie_new();
Movie* movie_newParametros(char* titulo, char* genero, int* duracion, char* descripcion, int* puntaje, char* linkImagen, int id);
int movie_setTitulo(Movie* this, char* titulo);
int movie_getTitulo(Movie* this, char* titulo);
int movie_setGenero(Movie* this, char* genero);
int movie_getGenero(Movie* this, char* genero);
int movie_setDuracion(Movie* this, int* duracion);
int movie_getDuracion(Movie* this, int* duracion);
int movie_setDescripcion(Movie* this, char* descripcion);
int movie_getDescripcion(Movie* this, char* descripcion);
int movie_setPuntaje(Movie* this, int* puntaje);
int movie_getPuntaje(Movie* this, int* puntaje);
int movie_setLinkImagen(Movie* this, char* linkImagen);
int movie_getLinkImagen(Movie* this, char* linkImagen);
int movie_setId(Movie* this, int id);
int movie_getId(Movie* this, int* id);
