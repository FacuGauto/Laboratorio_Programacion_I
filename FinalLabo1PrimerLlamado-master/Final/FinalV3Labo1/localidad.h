#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
}Localidad;

Localidad* Localidad_new();
void Localidad_delete();
Localidad* Localidad_newConParametros(int id,char* nombre);

int Localidad_setId(Localidad* this,int id);
int Localidad_getId(Localidad* this,int* id);

int Localidad_setNombre(Localidad* this,char* nombre);
int Localidad_getNombre(Localidad* this,char* nombre);

#endif // LOCALIDAD_H_INCLUDED
