#include <stdio.h>
#include <stdlib.h>

int sumaEnteros (int primerNum, int segundoNum);
int restaEnteros (int primerNum, int segundoNum);
int divisionEnteros (int primerNum, int segundoNum);
int multiplicaEnteros (int primerNum, int segundoNum);

int main()
{
    int numeroUno;
    int numeroDos;
    int resultadoOperacion;
    int operacion;

    printf("Ingrese el primer numero\n");
    scanf("%d",&numeroUno);

    printf("Ingrese el segundo numero\n");
    scanf("%d",&numeroDos);

    printf("Ingrese el numero de la operacion que desea realizar: \n1_Sumar \n2_Restar \n3Dividir \n4Multilpicar\n");
    scanf("%d",&operacion);

    switch(operacion)
    {
    case 1:
        resultadoOperacion = sumaEnteros(numeroUno,numeroDos);
        break;
    case 2:
        resultadoOperacion = restaEnteros(numeroUno,numeroDos);
        break;
    case 3:
        resultadoOperacion = divisionEnteros(numeroUno,numeroDos);
        break;
    case 4:
        resultadoOperacion = multiplicaEnteros(numeroUno,numeroDos);
        break;
    default:
        printf("Numero de operacion incorrecto");
    }

    if(operacion == 1 || operacion == 2 || operacion == 3 || operacion == 4)
    {
        printf("El resultado es: %d",resultadoOperacion);
    }

    return 0;
}

int sumaEnteros (int primerNum, int segundoNum)
{
    int resultado;
    resultado = primerNum + segundoNum;
    return resultado;
}

int restaEnteros (int primerNum, int segundoNum)
{
    int resultado;
    resultado = primerNum - segundoNum;
    return resultado;
}

int divisionEnteros (int primerNum, int segundoNum)
{
    int resultado;
    resultado = primerNum / segundoNum;
    return resultado;
}

int multiplicaEnteros (int primerNum, int segundoNum)
{
    int resultado;
    resultado = primerNum * segundoNum;
    return resultado;
}
