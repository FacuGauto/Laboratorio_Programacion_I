#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

int persona_alta(EPersona* array,int limite);
int persona_mostrar(EPersona* array,int limite);
int persona_altaForzada(EPersona* array,int limite,char* nombre,int edad, int dni);
int persona_init(EPersona* array,int limite);
int persona_baja(EPersona* array,int limite, int dni);
int persona_ordenar(EPersona* array,int limite);
int persona_buscarPorDni(EPersona* array,int limite, int dni);
int persona_edades(EPersona* array,int limite);

#endif // FUNCIONES_H_INCLUDED
