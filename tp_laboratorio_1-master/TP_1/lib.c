#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/**
*\brief Calcula la suma entre dos numeros
*\param Primer operando de la suma
*\param Segundo operando de la suma
*\param Se pasa por referencia la variable para el resultado de la suma
*\return Si es 0 la operacion salio bien y si es un numero negativo hay un error
*/
int suma (int primerOperando, int segundoOperando, float *resultadoOperacion)
{
    long resultadoSuma;
    int retorno = -1;
    resultadoSuma = primerOperando + segundoOperando;
    if(resultadoSuma <= 32767)
    {
        *resultadoOperacion = resultadoSuma;
        retorno = 0;
    }
    return retorno;
}

/**
*\brief Calcula la resta entre dos numeros
*\param Primer operando de la resta
*\param Segundo operando de la resta
*\param Se pasa por referencia la variable para el resultado de la resta
*\return Si es 0 la operacion salio bien y si es un numero negativo hay un error
*/
int resta (int primerOperando, int segundoOperando, float *resultadoOperacion)
{
    long resultadoResta;
    int retorno = -1;
    resultadoResta = primerOperando - segundoOperando;
    if(resultadoResta <= 32767)
    {
        *resultadoOperacion = resultadoResta;
        retorno = 0;
    }
    return retorno;
}

/**
*\brief Calcula la multilpicacion entre dos numeros
*\param Primer operando de la multilpicacion
*\param Segundo operando de la multilpicacion
*\param Se pasa por referencia la variable para el resultado de la multilpicacion
*\return Si es 0 la operacion salio bien y si es un numero negativo hay un error
*/
int multiplicacion (int primerOperando, int segundoOperando, float *resultadoOperacion)
{
    long resultadoMultiplicacion;
    int retorno = -1;
    resultadoMultiplicacion = primerOperando * segundoOperando;
    if(resultadoMultiplicacion <= 32767)
    {
        *resultadoOperacion = resultadoMultiplicacion;
        retorno = 0;
    }
    return retorno;
}

/**
*\brief Calcula la division entre dos numeros
*\param Dividendo de la division
*\param Divisior de la division
*\param Se pasa por referencia la variable para el resultado de la divion
*\return Si es 0 la operacion salio bien y si es un numero negativo hay un error
*/
int division (int primerOperando, int segundoOperando, float *resultadoOperacion)
{
    float resultadoDivision;
    int retorno = -1;
    if(segundoOperando == 0)
    {
        printf("No se puede dividor por cero\n");
    }
    else
    {
        resultadoDivision = (float)primerOperando / segundoOperando;
        if(resultadoDivision <= 32767)
        {
            *resultadoOperacion = resultadoDivision;
            retorno = 0;
        }
    }

    return retorno;
}

/**
*\brief Calcula el factorial de un numero
*\param Numero del que se va a obtener su factorial
*\param Se pasa por referencia la variable donde se va a guardar el resultado
*\return Si es 0 la operacion salio bien y si es un numero negativo hay un error
*/
int factorial (int numero, float *resultadoOperacion)
{
    long resultadoFactorial;
    int retorno = -1;
    int i;
    resultadoFactorial = 1;

    if(numero == 1 || numero == 0)
    {
        resultadoFactorial = 1;
    }
    else
    {
        for(i=1;i<=numero;i++)
        {
            resultadoFactorial = resultadoFactorial * i;
        }
    }

    if(resultadoFactorial <=32767)
    {
        *resultadoOperacion = resultadoFactorial;
        retorno = 0;
    }
    return retorno;
}

