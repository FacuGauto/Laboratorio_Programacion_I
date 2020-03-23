#ifndef PIBE_H_INCLUDED
#define PIBE_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int edad;
}Pibe;

Pibe* Pibe_new();
void Pibe_delete();
Pibe* Pibe_newConParametros(int id,char* nombre,int edad);

int Pibe_setId(Pibe* this,int id);
int Pibe_getId(Pibe* this,int* id);

int Pibe_setNombre(Pibe* this,char* nombre);
int Pibe_getNombre(Pibe* this,char* nombre);

int Pibe_setEdad(Pibe* this,int edad);
int Pibe_getEdad(Pibe* this,int* edad);

#endif // PIBE_H_INCLUDED
