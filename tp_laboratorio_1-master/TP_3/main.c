#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "movie.h"
#include "utn.h"

Movie* crearPelicula(void);
void cargarArchivo(Movie* pelicula);


int main()
{
    Movie* pelicula = NULL;
    char seguir='s';
    int opcion=0;
/*
    char titulo[] = "volver al futuro";
    char genero[] = "ciencia ficcion";
    int duracion = 106;
    char descripcion[] = "Doc Brown crea la maquina del tiempo";
    int puntaje = 10;
    char linkImagen[] = "http://volverAlFuturo.jpg";
    int id = 01;

    char auxTitulo[50];
    pelicula = movie_newParametros(titulo,genero,&duracion,descripcion,&puntaje,linkImagen,id);
    movie_getTitulo(pelicula,auxTitulo);


    //cargarDatos(&pelicula);
//    mostrar(&pelicula);
    //char titulo[20];
    //char auxTitulo[20];

    //getString("Ingrese el titulo:",titulo);
    //movie_setTitulo(&pelicula,titulo);
    //movie_getTitulo(&pelicula,auxTitulo);
    //printf("titulo: %s",auxTitulo);

//    char path[] = "pepe.txt";
  //  fd = fopen(path,"wt");
    //char nombre[50];

    if(fd != NULL)
    {
        printf("\n\t.:Creando listado de peliculas\n");
        fprintf(fd,"\n\t.:LISTADO DE PELICULAS\n");

        //printf("Ingrese un nombre:");
        //scanf("%s",nombre);

    //    fprintf(fd,"Nombre: ");
     //   fwrite(auxTitulo,1,strlen(auxTitulo),fd);
    }
*/

    while(seguir=='s')
    {
        printf("\n\tMENU:\n\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                pelicula = crearPelicula();
                cargarArchivo(pelicula);
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }
    return 0;
}

void cargarArchivo(Movie* pelicula)
{
    FILE *fd;
    char titulo[20],genero[20],descripcion[50],linkImagen[50], auxDuracion[20];
    int duracion,id,puntaje;

    char direccion[] = "pepe.txt";
    fd = fopen(direccion,"wt");

    if (fd != NULL)
    {
        printf("ARCHIVO CREADO");
        fprintf(fd,"\n\tPELICULAS.");

        movie_getTitulo(pelicula,titulo);
        movie_getGenero(pelicula,genero);
        movie_getDescripcion(pelicula,descripcion);
        movie_getLinkImagen(pelicula,linkImagen);
        movie_getDuracion(pelicula,&duracion);
        movie_getPuntaje(pelicula,&puntaje);
        movie_getId(pelicula,&id);

        sprintf(auxDuracion,"%d",duracion);

        fprintf(fd,"\n\nTitulo: ");
        fwrite(titulo,1,strlen(titulo),fd);
        fprintf(fd,"\nGenero: ");
        fwrite(genero,1,strlen(genero),fd);
        fprintf(fd,"\nDuracion: ");
        fwrite(&auxDuracion,1,strlen(auxDuracion),fd);
        fprintf(fd,"\nDescripcion: ");
        fwrite(descripcion,1,strlen(descripcion),fd);
        fprintf(fd,"\nPuntaje: ");
        //fwrite(&puntaje,1,sizeof(puntaje),fd);
        fprintf(fd,"\nLink de la imagen: ");
        fwrite(linkImagen,1,strlen(linkImagen),fd);
        fprintf(fd,"\nId: ");
        //fwrite(&id,1,sizeof(id),fd);
    }

    fclose(fd);
}

Movie* crearPelicula(void)
{
    Movie* pelicula;
    char titulo[20],genero[20],descripcion[50],linkImagen[50];
    int duracion,id,puntaje;
    fflush(stdin);
    getString("\nIngrese el titulo:",titulo);
    getString("Ingrese el genero:",genero);
    duracion = getInt("Ingrese la duracion:");
    getString("Ingrese la descripcion:",descripcion);
    puntaje = getInt("Ingrese el puntaje:");
    getString("Ingrese el link a la imagen:",linkImagen);
    id = getInt("Ingrese el id:");

    pelicula = movie_newParametros(titulo,genero,&duracion,descripcion,&puntaje,linkImagen,id);
    return pelicula;
}
/*
void cargarDatos(Movie* this)
{

    char titulo[20] = "falopa";
    char genero[20] = "accion";
    int duracion = 10;
    char descripcion[50] = "sdsdsdsd";
    int puntaje = 4;
    char linkImagen[50] = "dsds.jpg";
    int id = 6;

    getString("Ingrese el titulo:",titulo);
    getString("Ingrese el genero:",genero);
    duracion=getInt("Ingrese la duracion:");
    getString("Ingrese la descripcion:",descripcion);
    puntaje=getInt("Ingrese el puntaje:");
    getString("Ingrese el link a la imagen:",linkImagen);
    id=getInt("Ingrese el id:");

    this = movie_newParametros(titulo,genero,&duracion,descripcion,&puntaje,linkImagen,id);
    getString("Ingrese el titulo:",titulo);
    movie_setTitulo(this,titulo);
    movie_getTitulo(this,auxtitulo);

    printf("tituuuulo: %s",auxtitulo);

}



void mostrar(Movie* this)
{
    int puntaje;
    char titulo[20];

        movie_getPuntaje(this,&puntaje);
        movie_getTitulo(this,titulo);
        printf("\nPuntaje:%d-Titulo:%s",puntaje,titulo);
}



void crear(char* titulo)
{
    char path[] = "pepe.txt";
    fd = fopen(path,"wt");
    //char nombre[50];

    if(fd != NULL)
    {
        printf("\n\t.:Creando listado de peliculas\n");
        fprintf(fd,"\n\t.:LISTADO DE PELICULAS\n");

        //printf("Ingrese un nombre:");
        //scanf("%s",nombre);

        fprintf(fd,"Nombre: ");
        fwrite(titulo,1,strlen(titulo),fd);
    }
}



int savePerson(Movie* this)
{
    FILE* fp;
    fp=fopen("bin.dat","ab+"); // append binario, lo crea si no existe
    if(fp==NULL)
    {
        printf("Error opening file");
        return 0;
    }
    fwrite(this,sizeof(Movie),1,fp); // escribo una struct al final

    fclose(fp);
    return 1;
}
*/
