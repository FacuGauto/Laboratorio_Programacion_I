#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
typedef struct
{
    char nombre[128];
    char email[128];
}EPersona;

EPersona* persona_new();
void persona_delete();

int persona_setNombre(EPersona* this,char* nombre);
int persona_getNombre(EPersona* this,char* nombre);

int persona_setEmail(EPersona* this,char* email);
int persona_getEmail(EPersona* this,char* email);

#endif // PERSONA_H_INCLUDED
